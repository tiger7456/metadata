//
// Created by 郑元庆 on 16/9/26.
//

#ifndef METADATA_VARIABLE_H
#define METADATA_VARIABLE_H

#include "Util.h"

namespace xts
{

	class METADATA_DECL AbstractVariable
	{
	public:
		virtual ~AbstractVariable();

	public:
		virtual ValueType GetType() = 0;

		virtual bool IsPtr() = 0;

		virtual size_t GetClassId() = 0;

		virtual size_t GetTypeId() = 0;

		virtual AbstractVariable * Clone() = 0;

		virtual void * Data() = 0;

		size_t TypeIdToClassId( size_t TypeId );
	};

	template < typename T > class TempVariable : public AbstractVariable
	{
	public:
		TempVariable()
				:_data(nullptr), _IsPtr(false), _Type(xts::ValueType::T_NULL)
		{
		}

		TempVariable( T data )
				:_data(nullptr), _IsPtr(false), _Type(xts::ValueType::T_USERCLASS)
		{
			_data = new T(data);

			make_data(data);
		}

		TempVariable( T * data )
				:_data(nullptr), _IsPtr(true), _Type(xts::ValueType::T_USERCLASS)
		{
			_data = (T*)(new T*(data));

			make_data(*data);
		}

		template < typename PT > void make_data( PT &data )
		{
			_Type = ValueType::T_USERCLASS;
		}

		void make_data( bool data )
		{
			_Type = ValueType::T_BOOL;
		}

		void make_data( int8_t data )
		{
			_Type = ValueType::T_CHAR;
		}

		void make_data( u_int8_t data )
		{
			_Type = ValueType::T_UCHAR;
		}

		void make_data( int16_t data )
		{
			_Type = ValueType::T_INT16;
		}

		void make_data( u_int16_t data )
		{
			_Type = ValueType::T_UINT16;
		}

		void make_data( int32_t data )
		{
			_Type = ValueType::T_INT32;
		}

		void make_data( u_int32_t data )
		{
			_Type = ValueType::T_UINT32;
		}

		void make_data( int64_t data )
		{
			_Type = ValueType::T_INT64;
		}

		void make_data( u_int64_t data )
		{
			_Type = ValueType::T_UINT64;
		}

		void make_data( float data )
		{
			_Type = ValueType::T_FLOAT;
		}

		void make_data( double data )
		{
			_Type = ValueType::T_DOUBLE;
		}


		~TempVariable()
		{
			if( _data && !_IsPtr )
				free(_data);
		}

	public:
		virtual ValueType GetType()
		{
			return _Type;
		}

		virtual bool IsPtr()
		{
			return _IsPtr;
		}

		virtual size_t GetClassId()
		{
			return TypeIdToClassId(RelievePointer(_data));
		}

		virtual size_t GetTypeId()
		{
			return _IsPtr ? typeid(T *).hash_code() : typeid(T).hash_code();
		}

		virtual AbstractVariable * Clone()
		{
			TempVariable < T > * res = new TempVariable < T >();

			if( _Type != ValueType::T_NULL )
			{
				res->_data = _IsPtr ? _data : new T(*_data);

				res->_IsPtr = _IsPtr;

				res->_Type = _Type;
			}

			return res;
		}

		virtual void * Data()
		{
			return _data;
		}

	private:
		template < typename TT > size_t RelievePointer( TT * data )
		{
			return RelievePointer(*data);
		}

		template < typename TT > size_t RelievePointer( TT &data )
		{
			return typeid(TT).hash_code();
		}


	public:
		T * _data;
		ValueType _Type;
		bool _IsPtr;
	};

	class METADATA_DECL Variable
	{
	public:
		Variable();

		Variable( Variable &var );

		Variable( const Variable &var );

		Variable &operator =( const Variable &var );

		template < typename T > Variable( T &val )
		{
			_value = new TempVariable < T >(val);
		}

		~Variable();

	public:
		bool Empty() const;

		size_t GetClassId() const;

		size_t GetTypeId() const;

		ValueType GetType() const;

	public:
		template < typename T > T Value()
		{
			assert(typeid(T).hash_code() == _value->GetTypeId() && "value type mismatch!");

			return *( static_cast<T *>(_value->Data()));
		}

	public:
		static Variable FromValue( const Variable& val );

		template < typename T > static Variable FromValue( T val )
		{
			Variable var;

			var._value = new TempVariable < T >(val);

			return var;
		}

		template < typename T > static Variable FromValue( T * val )
		{
			Variable var;

			var._value = new TempVariable < T >(val);

			return var;
		}

	private:
		AbstractVariable * _value;
	};

}


#endif //METADATA_VARIABLE_H
