//
// Created by 郑元庆 on 16/9/25.
//

#include "ClassInfo.h"

#include "CallableInfo.h"
#include "PropertyInfo.h"
#include "ConstructInfo.h"

#include "MetaType.h"

using namespace xts;

ClassInfo::ClassInfo( const std::string &name )
		:_Name(name), _Super(nullptr), _ConstructInfo(nullptr)
{
	static std::__murmur2_or_cityhash < size_t > hash;
	_Id = hash(_Name.c_str(), _Name.size());
}

ClassInfo::ClassInfo( const std::string &name, size_t id )
		:_Name(name), _Id(0), _Super(nullptr), _ConstructInfo(nullptr)
{
	static std::__murmur2_or_cityhash < size_t > hash;
	_Id = hash(_Name.c_str(), _Name.size());

	xts::MetaType::Instance()->RegisterClassIdByTypeId(_Id, id);
}

ClassInfo::~ClassInfo()
{
	if(_ConstructInfo)
		delete _ConstructInfo;

	if(_DestructInfo)
		delete _DestructInfo;

	for( auto &it : _MethodInfoMap )
	{
		delete it.second;
	}

	for( auto &it : _PropertyInfoMap )
	{
		delete it.second;
	}
}

size_t ClassInfo::GetClassId() const
{
	return _Id;
}

const std::string &ClassInfo::GetClassName() const
{
	return _Name;
}

ClassInfo * ClassInfo::GetSuperClass()
{
	return _Super;
}

void ClassInfo::SetSuperClass( ClassInfo * super )
{
	_Super = super;
}

ClassInfo::ClassInfoList ClassInfo::GetSuperClassList()
{
	std::list < ClassInfo * > list;

	PushClassInfoToList(list);

	return list;
}

ConstructInfo * ClassInfo::GetConstructInfo()
{
	return _ConstructInfo;
}

void ClassInfo::SetConstructInfo( ConstructInfo * info )
{
	_ConstructInfo = info;
}

DestructInfo * ClassInfo::GetDestructInfo()
{
	return _DestructInfo;
}

void ClassInfo::SetDestructInfo( DestructInfo * info )
{
	_DestructInfo = info;
}

CallableInfo * ClassInfo::FindMethod( const std::string &name )
{
	auto it = _MethodInfoMap.find(name);

	if( it != _MethodInfoMap.end())
	{
		return it->second;
	}

	if(_Super)
	{
		return _Super->FindMethod(name);
	}

	return nullptr;
}

PropertyInfo * ClassInfo::FindProperty( const std::string &name )
{
	auto it = _PropertyInfoMap.find(name);

	if( it != _PropertyInfoMap.end())
	{
		return it->second;
	}

	if(_Super)
	{
		return _Super->FindProperty(name);
	}

	return nullptr;
}

bool ClassInfo::PushMethod( CallableInfo * info )
{
	auto it = _MethodInfoMap.find(info->GetName());

	if( it != _MethodInfoMap.end())
	{
		return false;
	}

	_MethodInfoMap.insert(MethodInfoMap::value_type(info->GetName(), info));

	return true;
}

bool ClassInfo::PushProperty( PropertyInfo * info )
{
	auto it = _PropertyInfoMap.find(info->GetName());

	if( it != _PropertyInfoMap.end())
	{
		return false;
	}

	_PropertyInfoMap.insert(PropertyInfoMap::value_type(info->GetName(), info));

	return true;
}

void ClassInfo::PushClassInfoToList( ClassInfo::ClassInfoList &list )
{
	if( _Super )
	{
		_Super->PushClassInfoToList(list);
	}

	list.push_back(this);
}
