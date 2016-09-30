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

	class METADATA_DECL MetaType
	{
		friend class ClassInfo;

		friend class AbstractVariable;

	public:
		typedef std::map < size_t, ClassInfo * > ClassInfoByIdMap;

		typedef std::map < size_t, CallableInfo * > CallbackByIdMap;

		typedef std::map < size_t, size_t > ClassInfoIdByTypeIdMap;

	public:
		MetaType();

		~MetaType();

		static MetaType * Instance();

	public:
		void RegisterClassInfo( ClassInfo * Info );

		void RegisterCallbackInfo( CallableInfo * Info );

		ClassInfo * FindClassInfoById( size_t ClassId );

		ClassInfo * FindClassInfoByName( const std::string &ClassName );

		CallableInfo * FindCallbackInfoById( size_t CallbackId );

		CallableInfo * FindCallbackInfoByName( const std::string &CallbackName );

	private:
		void RegisterClassIdByTypeId( size_t ClassId, size_t Typeid );

		size_t FindClassIdByTypeId( size_t TypeId );

	private:
		ClassInfoByIdMap _ClassInfoByIdMap;

		ClassInfoIdByTypeIdMap _ClassInfoIdByTypeIdMap;

		CallbackByIdMap _CallbackByIdMap;
	};

}


#define META_BEGIN( THISTYPE ) \
struct THISTYPE##_XTS \
{ \
    typedef THISTYPE this_type; \
    THISTYPE##_XTS() \
    { \
        ClassInfo * Class = new ClassInfo( #THISTYPE, typeid(this_type).hash_code() ); \
        xts::MetaType::Instance()->RegisterClassInfo( Class ); \
		Class->SetConstructInfo( MakeConstruct<this_type>() ); \
		Class->SetDestructInfo( MakeDestruct<this_type>() );

#define REG_SUPER(SUPERTYPE) \
	Class->SetSuperClass( xts::MetaType::Instance()->FindClassInfoByName( #SUPERTYPE ) )

#define REG_PROPERTY(PORP, PN...) \
	Class->PushProperty( MakePropertyInfo(#PORP, &this_type::PORP, ##PN) )

#define REG_METHOD(METHOD, PN...) \
	Class->PushMethod( MakeMethodInfo(#METHOD, &this_type::METHOD, ##PN) )

#define REG_METHOD_STATIC(CALLBACK, PN...) \
	Class->PushMethod( MakeCallbackInfo(#CALLBACK, &this_type::CALLBACK, ##PN) )

#define META_END( THISTYPE ) \
    }  \
}; \
static THISTYPE##_XTS __##THISTYPE##_XTS_static_;


#define META_REG_FUNC(CALLBACK, PN...) \
struct Register_Callback_##CALLBACK \
{ \
	Register_Callback_##CALLBACK() \
	{ \
		xts::MetaType::Instance()->RegisterCallbackInfo( MakeCallbackInfo(#CALLBACK, CALLBACK, ##PN) ); \
	} \
}; \
static Register_Callback_##CALLBACK __register_callback_##CALLBACK__


#endif //METADATA_METATYPE_H