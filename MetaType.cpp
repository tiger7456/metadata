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
	_ClassIdByTypeIdMap.insert(ClassInfoIdByTypeIdMap::value_type(Typeid, ClassId));
}

size_t MetaType::FindClassIdByTypeId( size_t TypeId )
{
	auto it = _ClassIdByTypeIdMap.find(TypeId);

	if( it != _ClassIdByTypeIdMap.end())
		return it->second;

	return 0;
}
