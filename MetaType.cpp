//
// Created by 郑元庆 on 16/9/29.
//

#include "MetaType.h"

using namespace xts;

static RegisterBasicType g__RegisterBasicType_RegisterBasicType_;

MetaType::MetaType()
{

}

MetaType::~MetaType()
{
	for( auto &it : _CallbackByIdMap )
	{
		delete it.second;
	}

	for( auto &it : _ClassInfoByIdMap )
	{
		delete it.second;
	}
}

MetaType * MetaType::Instance()
{
	static MetaType meta;

	return &meta;
}

void MetaType::RegisterClassInfo( ClassInfo * Info )
{
	auto it = _ClassInfoByIdMap.find(Info->GetClassId());

	assert(it == _ClassInfoByIdMap.end() && "");

	_ClassInfoByIdMap.insert(ClassInfoByIdMap::value_type(Info->GetClassId(), Info));
}

void MetaType::RegisterCallbackInfo( CallableInfo * Info )
{
	static std::__murmur2_or_cityhash < size_t > hash;
	size_t id = hash(Info->GetName().c_str(), Info->GetName().size());

	auto it = _CallbackByIdMap.find(id);

	assert(it == _CallbackByIdMap.end() && "");

	_CallbackByIdMap.insert(CallbackByIdMap::value_type(id, Info));
}

ClassInfo * MetaType::FindClassInfoById( size_t ClassId )
{
	auto it = _ClassInfoByIdMap.find(ClassId);

	if( it != _ClassInfoByIdMap.end())
		return it->second;

	return nullptr;
}

ClassInfo * MetaType::FindClassInfoByName( const std::string &ClassName )
{
	static std::__murmur2_or_cityhash < size_t > hash;
	size_t id = hash(ClassName.c_str(), ClassName.size());

	auto it = _ClassInfoByIdMap.find(id);

	if( it != _ClassInfoByIdMap.end())
		return it->second;

	return nullptr;
}

CallableInfo * MetaType::FindCallbackInfoById( size_t CallbackId )
{
	auto it = _CallbackByIdMap.find(CallbackId);

	if( it != _CallbackByIdMap.end())
		return it->second;

	return nullptr;
}

CallableInfo * MetaType::FindCallbackInfoByName( const std::string &CallbackName )
{
	static std::__murmur2_or_cityhash < size_t > hash;
	size_t id = hash(CallbackName.c_str(), CallbackName.size());


	auto it = _CallbackByIdMap.find(id);

	if( it != _CallbackByIdMap.end())
		return it->second;

	return nullptr;
}

void MetaType::RegisterClassIdByTypeId( size_t ClassId, size_t Typeid )
{
	_ClassInfoIdByTypeIdMap.insert(ClassInfoIdByTypeIdMap::value_type(Typeid, ClassId));
}

size_t MetaType::FindClassIdByTypeId( size_t TypeId )
{
	auto it = _ClassInfoIdByTypeIdMap.find(TypeId);

	if( it != _ClassInfoIdByTypeIdMap.end())
		return it->second;

	return 0;
}
