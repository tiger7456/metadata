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
	_ClassInfoByIdMap.insert(std::make_pair(Info->GetClassId(), Info));
}

void MetaType::RegisterCallbackInfo( CallableInfo * Info )
{
	_CallbackByIdMap.insert(std::make_pair(Info->GetCallableId(), Info));
}

bool MetaType::RegisterEnumInfo( const std::string &Name, size_t Val )
{
	_EnumInfoByIdMap[_Hash(Name.c_str(), Name.size())] = Val;

	return false;
}


size_t MetaType::FindEnumInfoById( size_t Id )
{
	auto it = _EnumInfoByIdMap.find(Id);

	if(it != _EnumInfoByIdMap.end())
	{
		return it->second;
	}

	return 0;
}

size_t MetaType::FindEnumInfoByName( const std::string &Name )
{
	size_t id = _Hash(Name.c_str(), Name.size());

	return FindEnumInfoById(id);
}

ClassInfo * MetaType::FindClassInfoById( size_t Id )
{
	auto it = _ClassInfoByIdMap.find(Id);

	if( it != _ClassInfoByIdMap.end())
		return it->second;

	return nullptr;
}

ClassInfo * MetaType::FindClassInfoByName( const std::string &Name )
{
	size_t id = _Hash(Name.c_str(), Name.size());

	return FindClassInfoById(id);
}

CallableInfo * MetaType::FindCallbackInfoById( size_t Id )
{
	auto it = _CallbackByIdMap.find(Id);

	if( it != _CallbackByIdMap.end())
		return it->second;

	return nullptr;
}

CallableInfo * MetaType::FindCallbackInfoByName( const std::string &Name )
{
	size_t id = _Hash(Name.c_str(), Name.size());

	return FindCallbackInfoById(id);
}


void MetaType::RegisterClassIdByTypeId( size_t ClassId, size_t TypeId )
{
	_ClassIdByTypeIdMap.insert(ClassInfoIdByTypeIdMap::value_type(TypeId, ClassId));
}

size_t MetaType::FindClassIdByTypeId( size_t TypeId )
{
	auto it = _ClassIdByTypeIdMap.find(TypeId);

	if( it != _ClassIdByTypeIdMap.end())
		return it->second;

	return 0;
}
