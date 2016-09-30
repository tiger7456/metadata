//
// Created by 郑元庆 on 16/9/25.
//

#include "CallableInfo.h"

using namespace xts;

CallableInfo::CallableInfo()
	:_ParamCount(0), _ReturnType(0)
{

}

CallableInfo::~CallableInfo()
{

}

const std::string &CallableInfo::GetName() const
{
	return _Name;
}

size_t CallableInfo::GetParamCount() const
{
	return _ParamCount;
}

const CallableInfo::ParamTypeArray &CallableInfo::GetParamTypes() const
{
	return _ParamTypes;
}

size_t CallableInfo::GetReturnType() const
{
	return _ReturnType;
}

CallableType CallableInfo::GetType() const
{
	return _Type;
}
