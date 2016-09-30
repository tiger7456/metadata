//
// Created by 郑元庆 on 16/9/26.
//

#include "Variable.h"
#include "MetaType.h"

using namespace xts;

AbstractVariable::~AbstractVariable()
{

}

size_t AbstractVariable::TypeIdToClassId( size_t TypeId )
{
	return xts::MetaType::Instance()->FindClassIdByTypeId(TypeId);
}

Variable::Variable()
		:_value(nullptr)
{

}

Variable::~Variable()
{
	if( _value )
		delete _value;
}

Variable::Variable( Variable &var )
{
	_value = var._value->Clone();
}

Variable::Variable( const Variable &var )
{
	_value = var._value->Clone();
}

Variable &Variable::operator =( const Variable &var )
{
	if( _value )
		delete _value;

	_value = var._value->Clone();

	return *this;
}

bool Variable::Empty() const
{
	return _value == nullptr;
}

size_t Variable::GetClassId() const
{
	return _value != nullptr ? _value->GetClassId() : 0;
}

size_t Variable::GetTypeId() const
{
	return _value != nullptr ? _value->GetTypeId() : 0;
}

ValueType Variable::GetType() const
{
	return _value != nullptr ? _value->GetType() : ValueType::T_NULL;
}

Variable Variable::FromValue( const Variable &val )
{
	Variable v;
	v._value = val._value->Clone();
	return v;
}
