//
// Created by 郑元庆 on 16/9/29.
//

#include "MetaType.h"

using namespace xts;


class RegisterBasicType
{
public:
	RegisterBasicType()
	{
		xts::ClassInfo * Class = new xts::ClassInfo("null", typeid(nullptr).hash_code());
		xts::MetaType::Instance()->RegisterClassInfo(Class);

		Class = new xts::ClassInfo("bool", typeid(bool).hash_code());
		xts::MetaType::Instance()->RegisterClassInfo(Class);

		Class = new xts::ClassInfo("int8_t", typeid(int8_t).hash_code());
		xts::MetaType::Instance()->RegisterClassInfo(Class);

		Class = new xts::ClassInfo("uint8_t", typeid(uint8_t).hash_code());
		xts::MetaType::Instance()->RegisterClassInfo(Class);

		Class = new xts::ClassInfo("int16_t", typeid(int16_t).hash_code());
		xts::MetaType::Instance()->RegisterClassInfo(Class);

		Class = new xts::ClassInfo("uint16_t", typeid(uint16_t).hash_code());
		xts::MetaType::Instance()->RegisterClassInfo(Class);

		Class = new xts::ClassInfo("int32_t", typeid(int32_t).hash_code());
		xts::MetaType::Instance()->RegisterClassInfo(Class);

		Class = new xts::ClassInfo("uint32_t", typeid(uint32_t).hash_code());
		xts::MetaType::Instance()->RegisterClassInfo(Class);

		Class = new xts::ClassInfo("int64_t", typeid(int64_t).hash_code());
		xts::MetaType::Instance()->RegisterClassInfo(Class);

		Class = new xts::ClassInfo("uint64_t", typeid(uint64_t).hash_code());
		xts::MetaType::Instance()->RegisterClassInfo(Class);

		Class = new xts::ClassInfo("float", typeid(float).hash_code());
		xts::MetaType::Instance()->RegisterClassInfo(Class);

		Class = new xts::ClassInfo("double", typeid(double).hash_code());
		xts::MetaType::Instance()->RegisterClassInfo(Class);
	}
};

static RegisterBasicType g__RegisterBasicType_RegisterBasicType_;

std::__murmur2_or_cityhash < size_t > MetaType::_Hash;

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

void MetaType::RegisterClassInfo( ClassInfo * Info, const std::string &Space )
{
	size_t id = _Hash(Space.c_str(), Space.size());
	
	auto it = _ClassInfoFromNameSpaceMap[id].find(Info->GetClassId());

	assert(it == _ClassInfoFromNameSpaceMap[id].end() && "");

	_ClassInfoFromNameSpaceMap[id].insert(std::make_pair(Info->GetClassId(), Info));
	
	_ClassInfoByIdMap.insert(std::make_pair(Info->GetClassId(), Info));
}

void MetaType::RegisterCallbackInfo( CallableInfo * Info, const std::string &Space )
{
	size_t id = _Hash(Space.c_str(), Space.size());

	auto it = _CallbackInfoFromNameSpaceMap[id].find(Info->GetCallableId());

	assert(it == _CallbackInfoFromNameSpaceMap[id].end() && "");

	_CallbackInfoFromNameSpaceMap[id].insert(std::make_pair(Info->GetCallableId(), Info));
	
	_CallbackByIdMap.insert(std::make_pair(Info->GetCallableId(), Info));
}

bool MetaType::RegisterEnumInfo( const std::string &Owner, const std::string &Name, size_t Data )
{
	auto it = _EnumInfoByNameMap.find(Owner);

	if( it == _EnumInfoByNameMap.end())
	{
		_EnumInfoByNameMap.insert(EnumInfoByNameMap::value_type(Owner, EnumInfoMap()));
	}

	auto eit = it->second.find(Name);
	if( eit == it->second.end())
	{
		_EnumInfoByNameMap[Owner][Name] = Data;
		return true;
	}

	return false;
}

ClassInfo * MetaType::FindClassInfoById( size_t ClassId )
{
	auto it = _ClassInfoByIdMap.find(ClassId);

	if( it != _ClassInfoByIdMap.end())
		return it->second;

	return nullptr;
}

ClassInfo * MetaType::FindClassInfoByName( const std::string &ClassName, const std::string &Space )
{
	size_t space = _Hash(Space.c_str(), Space.size());

	auto it = _ClassInfoFromNameSpaceMap.find(space);
	if( it != _ClassInfoFromNameSpaceMap.end())
	{
		size_t id = _Hash(ClassName.c_str(), ClassName.size());

		auto item = it->second.find(id);
		
		if(item != it->second.end())
		{
			return item->second;
		}
	}

	return nullptr;
}

CallableInfo * MetaType::FindCallbackInfoById( size_t CallbackId )
{
	auto it = _CallbackByIdMap.find(CallbackId);

	if( it != _CallbackByIdMap.end())
		return it->second;

	return nullptr;
}

CallableInfo * MetaType::FindCallbackInfoByName( const std::string &CallbackName, const std::string &Space )
{
	size_t space = _Hash(Space.c_str(), Space.size());

	auto it = _CallbackInfoFromNameSpaceMap.find(space);

	if( it != _CallbackInfoFromNameSpaceMap.end())
	{
		size_t id = _Hash(CallbackName.c_str(), CallbackName.size());

		auto item = it->second.find(id);
		if(item != it->second.end())
		{
			return item->second;
		}
	}

	return nullptr;
}

void MetaType::RegisterClassIdByTypeId( size_t ClassId, size_t Typeid )
{
	_ClassIdByTypeIdMap.insert(ClassInfoIdByTypeIdMap::value_type(Typeid, ClassId));
}

size_t MetaType::FindClassIdByTypeId( size_t TypeId )
{
	auto it = _ClassIdByTypeIdMap.find(TypeId);

	if( it != _ClassIdByTypeIdMap.end())
		return it->second;

	return 0;
}

size_t MetaType::FindEnumInfo( const std::string &Owner, const std::string &Name )
{
	auto it = _EnumInfoByNameMap.find(Owner);

	if( it != _EnumInfoByNameMap.end())
	{
		auto eit = it->second.find(Name);
		if( eit != it->second.end())
		{
			return eit->second;
		}
	}

	return SIZE_T_MAX;
}
