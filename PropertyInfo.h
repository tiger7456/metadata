//
// Created by 郑元庆 on 16/9/25.
//

#ifndef METADATA_PROPERTYINFO_H
#define METADATA_PROPERTYINFO_H


#include "Variable.h"

namespace xts
{

	class XTS_DECL PropertyInfo
	{
	public:
		PropertyInfo()
		{}

		virtual ~PropertyInfo()
		{}

	public:
		template < typename T > Variable Get( T obj )
		{
			return _Get(Variable::FromValue(obj));
		}

		template < typename T1, typename T2 > void Set( T1 obj, T2 val )
		{
			_Set(Variable::FromValue(obj), Variable::FromValue(val));
		}

	protected:
		virtual Variable _Get( Variable obj ) = 0;

		virtual void _Set( Variable obj, Variable var ) = 0;

	public:
		size_t TypeId() const
		{
			return _ValueId;
		}

		const std::string& GetName() const
		{
			return _Name;
		}

	protected:
		size_t _ValueId;
		std::string _Name;
	};


	template < typename OT, typename VT > class TempPropertyInfo : public PropertyInfo
	{
	public:
		typedef OT object_type;
		typedef VT value_type;
		typedef value_type (object_type::*member_type);

	public:
		TempPropertyInfo( const std::string& name, member_type off)
				:_offset(off)
		{
			_Name = name;
			_ValueId = typeid(value_type).hash_code();
		}

		~TempPropertyInfo()
		{
		}

	public:
		virtual Variable _Get( Variable obj )
		{

			return Variable::FromValue(obj.Value < object_type * >()->*_offset);
		}

		virtual void _Set( Variable obj, Variable var )
		{
			obj.Value < object_type * >()->*_offset = var.Value < value_type >();
		}

	private:
		member_type _offset;
	};


	template < typename OT, typename VT > PropertyInfo * MakePropertyInfo(  const std::string& name, VT (OT::*offset),  const std::string& pname = "" )
	{
		return new TempPropertyInfo < OT, VT >(pname == "" ? name : pname, offset);
	};

}


#endif //METADATA_PROPERTYINFO_H
