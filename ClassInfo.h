//
// Created by 郑元庆 on 16/9/25.
//

#ifndef METADATA_CLASS_H
#define METADATA_CLASS_H

#include "Util.h"

namespace xts
{

	class PropertyInfo;

	class CallableInfo;

	class ConstructInfo;

	class DestructInfo;

	class XTS_DECL ClassInfo
	{
	public:
		typedef std::list < ClassInfo * > ClassList;
		typedef std::map < std::string, CallableInfo * > MethodInfoMap;
		typedef std::map < std::string, CallableInfo * > CallbackInfoMap;
		typedef std::map < std::string, PropertyInfo * > PropertyInfoMap;

	public:
		ClassInfo( const std::string &name );

		ClassInfo( const std::string &name, size_t id );

		~ClassInfo();

	public:
		size_t GetClassId() const;

		const std::string &GetClassName() const;

		ClassInfo * GetSuperClass();

		void SetSuperClass( ClassInfo * super );

		ClassList GetSuperClassList();

		ConstructInfo * GetConstructInfo();

		void SetConstructInfo( ConstructInfo * info );

		DestructInfo * GetDestructInfo();

		void SetDestructInfo( DestructInfo * info );

		CallableInfo * FindMethod( const std::string &name );

		PropertyInfo * FindProperty( const std::string &name );

		bool PushMethod( CallableInfo * info );

		bool PushProperty( PropertyInfo * info );

	private:
		void PushClassInfoToList( ClassList &list );

	private:
		size_t _Id;
		std::string _Name;
		ClassInfo * _Super;
		ConstructInfo * _ConstructInfo;
		DestructInfo * _DestructInfo;
		MethodInfoMap _MethodInfoMap;
		PropertyInfoMap _PropertyInfoMap;
	};

}


#endif //METADATA_CLASS_H
