//
// Created by 郑元庆 on 16/9/29.
//

#ifndef METADATA_METATYPE_H
#define METADATA_METATYPE_H

#include "Util.h"

#include "Variable.h"

#include "ClassInfo.h"
#include "ConstructInfo.h"
#include "CallableInfo.h"
#include "MethodInfo.h"
#include "PropertyInfo.h"

#include "CallbackInfo.h"

namespace xts
{

	class XTS_DECL MetaType
	{
		friend class ClassInfo;

		friend class AbstractVariable;

	public:
		typedef std::map < size_t, ClassInfo * > ClassInfoByIdMap;

		typedef std::map < size_t, std::map < size_t, ClassInfo * > > ClassInfoFromNameSpaceMap;

		typedef std::map < size_t, CallableInfo * > CallbackInfoByIdMap;

		typedef std::map < size_t, std::map < size_t, CallableInfo * > > CallbackInfoFromNameSpaceMap;

		typedef std::map < size_t, size_t > ClassInfoIdByTypeIdMap;

		typedef std::map < std::string, size_t > EnumInfoMap;

		typedef std::map < std::string, EnumInfoMap > EnumInfoByNameMap;

	public:
		MetaType();

		~MetaType();

		static MetaType * Instance();

	public:
		void RegisterClassInfo( ClassInfo * Info, const std::string &Space = "" );

		void RegisterCallbackInfo( CallableInfo * Info, const std::string &Space = "" );

		bool RegisterEnumInfo( const std::string &Owner, const std::string &Name, size_t Data );

		ClassInfo * FindClassInfoById( size_t ClassId );

		ClassInfo * FindClassInfoByName( const std::string &ClassName, const std::string &Space = "" );

		CallableInfo * FindCallbackInfoById( size_t CallbackId );

		CallableInfo * FindCallbackInfoByName( const std::string &CallbackName, const std::string &Space = "" );

		size_t FindEnumInfo( const std::string &Owner, const std::string &Name );

	private:
		void RegisterClassIdByTypeId( size_t ClassId, size_t Typeid );

		size_t FindClassIdByTypeId( size_t TypeId );

	private:
		EnumInfoByNameMap _EnumInfoByNameMap;

		CallbackInfoByIdMap _CallbackByIdMap;
		CallbackInfoFromNameSpaceMap _CallbackInfoFromNameSpaceMap;

		ClassInfoByIdMap _ClassInfoByIdMap;
		ClassInfoFromNameSpaceMap _ClassInfoFromNameSpaceMap;

		ClassInfoIdByTypeIdMap _ClassIdByTypeIdMap;

		std::__murmur2_or_cityhash < size_t > _Hash;
	};

}


#define META_CLASS_BEGIN( THISTYPE, NAMESPACE... ) \
struct Register_Class_##THISTYPE \
{ \
    typedef THISTYPE this_type; \
    Register_Class_##THISTYPE() \
    { \
        ClassInfo * Class = new ClassInfo( #THISTYPE, typeid(this_type).hash_code(), ##NAMESPACE ); \
        xts::MetaType::Instance()->RegisterClassInfo( Class ); \
        Class->SetConstructInfo( MakeConstruct<this_type>() ); \
        Class->SetDestructInfo( MakeDestruct<this_type>() );

#define REG_SUPER( SUPERTYPE ) \
    Class->SetSuperClass( xts::MetaType::Instance()->FindClassInfoByName( #SUPERTYPE ) )

#define REG_PROPERTY( PORP, PN... ) \
    Class->PushProperty( MakePropertyInfo(#PORP, &this_type::PORP, ##PN) )

#define REG_METHOD( METHOD, PN... ) \
    Class->PushMethod( MakeMethodInfo(#METHOD, &this_type::METHOD, ##PN) )

#define REG_METHOD_STATIC( CALLBACK, PN... ) \
    Class->PushMethod( MakeCallbackInfo(#CALLBACK, &this_type::CALLBACK, ##PN) )

#define META_CLASS_END( THISTYPE ) \
    }  \
}; \
static Register_Class_##THISTYPE __register_class_##THISTYPE##_XTS_static_;


#define META_REG_FUNC( CALLBACK, PN... ) \
struct Register_Callback_##CALLBACK \
{ \
    Register_Callback_##CALLBACK() \
    { \
        xts::MetaType::Instance()->RegisterCallbackInfo( MakeCallbackInfo(#CALLBACK, CALLBACK, ##PN) ); \
    } \
}; \
static Register_Callback_##CALLBACK __register_callback_##CALLBACK##_XTS_static_;


#define META_ENUM_BEGIN( OWNER ) \
struct Register_Enum_##OWNER \
{ \
    Register_Enum_##OWNER() \
    { \
        const char * Owner = #OWNER;

#define REG_ENUM( NAME, DATA ) xts::MetaType::Instance()->RegisterEnumInfo( Owner, #NAME, (size_t)DATA )

#define META_ENUM_END( OWNER ) \
    } \
}; \
static Register_Enum_##OWNER __register_enum_##OWNER##_XTS_static_;

#endif //METADATA_METATYPE_H
