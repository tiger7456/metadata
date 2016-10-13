//
// Created by 郑元庆 on 16/9/27.
//

#ifndef METADATA_METHODINFO_H
#define METADATA_METHODINFO_H

#include "CallableInfo.h"

namespace xts
{

	template < typename RT, typename OT, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8 >
	class XTS_DECL MethodInfo8 : public CallableInfo
	{
	public:
		typedef RT result_type;
		typedef OT object_type;
		typedef A1 param1_type;
		typedef A2 param2_type;
		typedef A3 param3_type;
		typedef A4 param4_type;
		typedef A5 param5_type;
		typedef A6 param6_type;
		typedef A7 param7_type;
		typedef A8 param8_type;

		typedef result_type (object_type::*function_type)( param1_type, param2_type, param3_type, param4_type, param5_type, param6_type, param7_type, param8_type );

	public:
		MethodInfo8( const std::string &name, const function_type &func )
				:_func(func)
		{
			_Name = name; _CallableId = _Hash(_Name.c_str(), _Name.size());
			_Type = CallableType::T_METHOD;
			_ParamCount = 9;
			_ReturnType = typeid(result_type).hash_code();
			_ParamTypes.push_back(typeid(object_type).hash_code());
			_ParamTypes.push_back(typeid(param1_type).hash_code());
			_ParamTypes.push_back(typeid(param2_type).hash_code());
			_ParamTypes.push_back(typeid(param3_type).hash_code());
			_ParamTypes.push_back(typeid(param4_type).hash_code());
			_ParamTypes.push_back(typeid(param5_type).hash_code());
			_ParamTypes.push_back(typeid(param6_type).hash_code());
			_ParamTypes.push_back(typeid(param7_type).hash_code());
			_ParamTypes.push_back(typeid(param8_type).hash_code());
		}

		~MethodInfo8()
		{
		}

	protected:
		virtual Variable Run( ParamArray &params )
		{
			assert(params.size() == _ParamTypes.size() && "the number of parameters does not match !");

			return IsMethodSame < result_type, void >::Call(params[0].Value < object_type * >(), _func, params[1].Value < param1_type >(), params[2].Value < param2_type >(), params[3].Value < param3_type >(), params[4].Value < param4_type >(), params[5].Value < param5_type >(), params[6].Value < param6_type >(), params[7].Value < param7_type >(), params[8].Value < param8_type >());
		}

	private:
		function_type _func;
	};

	template < typename RT, typename OT, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7 >
	class XTS_DECL MethodInfo7 : public CallableInfo
	{
	public:
		typedef RT result_type;
		typedef OT object_type;
		typedef A1 param1_type;
		typedef A2 param2_type;
		typedef A3 param3_type;
		typedef A4 param4_type;
		typedef A5 param5_type;
		typedef A6 param6_type;
		typedef A7 param7_type;

		typedef result_type (object_type::*function_type)( param1_type, param2_type, param3_type, param4_type, param5_type, param6_type, param7_type );

	public:
		MethodInfo7( const std::string &name, const function_type &func )
				:_func(func)
		{
			_Name = name; _CallableId = _Hash(_Name.c_str(), _Name.size());
			_Type = CallableType::T_METHOD;
			_ParamCount = 8;
			_ReturnType = typeid(result_type).hash_code();
			_ParamTypes.push_back(typeid(object_type).hash_code());
			_ParamTypes.push_back(typeid(param1_type).hash_code());
			_ParamTypes.push_back(typeid(param2_type).hash_code());
			_ParamTypes.push_back(typeid(param3_type).hash_code());
			_ParamTypes.push_back(typeid(param4_type).hash_code());
			_ParamTypes.push_back(typeid(param5_type).hash_code());
			_ParamTypes.push_back(typeid(param6_type).hash_code());
			_ParamTypes.push_back(typeid(param7_type).hash_code());
		}

		~MethodInfo7()
		{
		}

	protected:
		virtual Variable Run( ParamArray &params )
		{
			assert(params.size() == _ParamTypes.size() && "the number of parameters does not match !");

			return IsMethodSame < result_type, void >::Call(params[0].Value < object_type * >(), _func, params[1].Value < param1_type >(), params[2].Value < param2_type >(), params[3].Value < param3_type >(), params[4].Value < param4_type >(), params[5].Value < param5_type >(), params[6].Value < param6_type >(), params[7].Value < param7_type >());
		}

	private:
		function_type _func;
	};

	template < typename RT, typename OT, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6 >
	class XTS_DECL MethodInfo6 : public CallableInfo
	{
	public:
		typedef RT result_type;
		typedef OT object_type;
		typedef A1 param1_type;
		typedef A2 param2_type;
		typedef A3 param3_type;
		typedef A4 param4_type;
		typedef A5 param5_type;
		typedef A6 param6_type;

		typedef result_type (object_type::*function_type)( param1_type, param2_type, param3_type, param4_type, param5_type, param6_type );

	public:
		MethodInfo6( const std::string &name, const function_type &func )
				:_func(func)
		{
			_Name = name; _CallableId = _Hash(_Name.c_str(), _Name.size());
			_Type = CallableType::T_METHOD;
			_ParamCount = 7;
			_ReturnType = typeid(result_type).hash_code();
			_ParamTypes.push_back(typeid(object_type).hash_code());
			_ParamTypes.push_back(typeid(param1_type).hash_code());
			_ParamTypes.push_back(typeid(param2_type).hash_code());
			_ParamTypes.push_back(typeid(param3_type).hash_code());
			_ParamTypes.push_back(typeid(param4_type).hash_code());
			_ParamTypes.push_back(typeid(param5_type).hash_code());
			_ParamTypes.push_back(typeid(param6_type).hash_code());
		}

		~MethodInfo6()
		{
		}

	protected:
		virtual Variable Run( ParamArray &params )
		{
			assert(params.size() == _ParamTypes.size() && "the number of parameters does not match !");

			return IsMethodSame < result_type, void >::Call(params[0].Value < object_type * >(), _func, params[1].Value < param1_type >(), params[2].Value < param2_type >(), params[3].Value < param3_type >(), params[4].Value < param4_type >(), params[5].Value < param5_type >(), params[6].Value < param6_type >());
		}

	private:
		function_type _func;
	};

	template < typename RT, typename OT, typename A1, typename A2, typename A3, typename A4, typename A5 >
	class XTS_DECL MethodInfo5 : public CallableInfo
	{
	public:
		typedef RT result_type;
		typedef OT object_type;
		typedef A1 param1_type;
		typedef A2 param2_type;
		typedef A3 param3_type;
		typedef A4 param4_type;
		typedef A5 param5_type;

		typedef result_type (object_type::*function_type)( param1_type, param2_type, param3_type, param4_type, param5_type );

	public:
		MethodInfo5( const std::string &name, const function_type &func )
				:_func(func)
		{
			_Name = name; _CallableId = _Hash(_Name.c_str(), _Name.size());
			_Type = CallableType::T_METHOD;
			_ParamCount = 6;
			_ReturnType = typeid(result_type).hash_code();
			_ParamTypes.push_back(typeid(object_type).hash_code());
			_ParamTypes.push_back(typeid(param1_type).hash_code());
			_ParamTypes.push_back(typeid(param2_type).hash_code());
			_ParamTypes.push_back(typeid(param3_type).hash_code());
			_ParamTypes.push_back(typeid(param4_type).hash_code());
			_ParamTypes.push_back(typeid(param5_type).hash_code());
		}

		~MethodInfo5()
		{
		}

	protected:
		virtual Variable Run( ParamArray &params )
		{
			assert(params.size() == _ParamTypes.size() && "the number of parameters does not match !");

			return IsMethodSame < result_type, void >::Call(params[0].Value < object_type * >(), _func, params[1].Value < param1_type >(), params[2].Value < param2_type >(), params[3].Value < param3_type >(), params[4].Value < param4_type >(), params[5].Value < param5_type >());
		}

	private:
		function_type _func;
	};

	template < typename RT, typename OT, typename A1, typename A2, typename A3, typename A4 >
	class XTS_DECL MethodInfo4 : public CallableInfo
	{
	public:
		typedef RT result_type;
		typedef OT object_type;
		typedef A1 param1_type;
		typedef A2 param2_type;
		typedef A3 param3_type;
		typedef A4 param4_type;

		typedef result_type (object_type::*function_type)( param1_type, param2_type, param3_type, param4_type );

	public:
		MethodInfo4( const std::string &name, const function_type &func )
				:_func(func)
		{
			_Name = name; _CallableId = _Hash(_Name.c_str(), _Name.size());
			_Type = CallableType::T_METHOD;
			_ParamCount = 5;
			_ReturnType = typeid(result_type).hash_code();
			_ParamTypes.push_back(typeid(object_type).hash_code());
			_ParamTypes.push_back(typeid(param1_type).hash_code());
			_ParamTypes.push_back(typeid(param2_type).hash_code());
			_ParamTypes.push_back(typeid(param3_type).hash_code());
			_ParamTypes.push_back(typeid(param4_type).hash_code());
		}

		~MethodInfo4()
		{
		}

	protected:
		virtual Variable Run( ParamArray &params )
		{
			assert(params.size() == _ParamTypes.size() && "the number of parameters does not match !");

			return IsMethodSame < result_type, void >::Call(params[0].Value < object_type * >(), _func, params[1].Value < param1_type >(), params[2].Value < param2_type >(), params[3].Value < param3_type >(), params[4].Value < param4_type >());
		}

	private:
		function_type _func;
	};

	template < typename RT, typename OT, typename A1, typename A2, typename A3 >
	class XTS_DECL MethodInfo3 : public CallableInfo
	{
	public:
		typedef RT result_type;
		typedef OT object_type;
		typedef A1 param1_type;
		typedef A2 param2_type;
		typedef A3 param3_type;

		typedef result_type (object_type::*function_type)( param1_type, param2_type, param3_type );

	public:
		MethodInfo3( const std::string &name, const function_type &func )
				:_func(func)
		{
			_Name = name; _CallableId = _Hash(_Name.c_str(), _Name.size());
			_Type = CallableType::T_METHOD;
			_ParamCount = 4;
			_ReturnType = typeid(result_type).hash_code();
			_ParamTypes.push_back(typeid(object_type).hash_code());
			_ParamTypes.push_back(typeid(param1_type).hash_code());
			_ParamTypes.push_back(typeid(param2_type).hash_code());
			_ParamTypes.push_back(typeid(param3_type).hash_code());
		}

		~MethodInfo3()
		{
		}

	protected:
		virtual Variable Run( ParamArray &params )
		{
			assert(params.size() == _ParamTypes.size() && "the number of parameters does not match !");

			return IsMethodSame < result_type, void >::Call(params[0].Value < object_type * >(), _func, params[1].Value < param1_type >(), params[2].Value < param2_type >(), params[3].Value < param3_type >());
		}

	private:
		function_type _func;
	};

	template < typename RT, typename OT, typename A1, typename A2 > class XTS_DECL MethodInfo2 : public CallableInfo
	{
	public:
		typedef RT result_type;
		typedef OT object_type;
		typedef A1 param1_type;
		typedef A2 param2_type;

		typedef result_type (object_type::*function_type)( param1_type, param2_type );

	public:
		MethodInfo2( const std::string &name, const function_type &func )
				:_func(func)
		{
			_Name = name; _CallableId = _Hash(_Name.c_str(), _Name.size());
			_Type = CallableType::T_METHOD;
			_ParamCount = 3;
			_ReturnType = typeid(result_type).hash_code();
			_ParamTypes.push_back(typeid(object_type).hash_code());
			_ParamTypes.push_back(typeid(param1_type).hash_code());
			_ParamTypes.push_back(typeid(param2_type).hash_code());
		}

		~MethodInfo2()
		{
		}

	protected:
		virtual Variable Run( ParamArray &params )
		{
			assert(params.size() == _ParamTypes.size() && "the number of parameters does not match !");

			return IsMethodSame < result_type, void >::Call(params[0].Value < object_type * >(), _func, params[1].Value < param1_type >(), params[2].Value < param2_type >());
		}

	private:
		function_type _func;
	};

	template < typename RT, typename OT, typename A1 > class XTS_DECL MethodInfo1 : public CallableInfo
	{
	public:
		typedef RT result_type;
		typedef OT object_type;
		typedef A1 param1_type;

		typedef result_type (object_type::*function_type)( param1_type );

	public:
		MethodInfo1( const std::string &name, const function_type &func )
				:_func(func)
		{
			_Name = name; _CallableId = _Hash(_Name.c_str(), _Name.size());
			_Type = CallableType::T_METHOD;
			_ParamCount = 2;
			_ReturnType = typeid(result_type).hash_code();
			_ParamTypes.push_back(typeid(object_type).hash_code());
			_ParamTypes.push_back(typeid(param1_type).hash_code());
		}

		~MethodInfo1()
		{
		}

	protected:
		virtual Variable Run( ParamArray &params )
		{
			assert(params.size() == _ParamTypes.size() && "the number of parameters does not match !");

			return IsMethodSame < result_type, void >::Call(params[0].Value < object_type * >(), _func, params[1].Value < param1_type >());
		}

	private:
		function_type _func;
	};

	template < typename RT, typename OT > class XTS_DECL MethodInfo0 : public CallableInfo
	{
	public:
		typedef RT result_type;
		typedef OT object_type;

		typedef result_type (object_type::*function_type)();

	public:
		MethodInfo0( const std::string &name, const function_type &func )
				:_func(func)
		{
			_Name = name; _CallableId = _Hash(_Name.c_str(), _Name.size());
			_Type = CallableType::T_METHOD;
			_ParamCount = 1;
			_ReturnType = typeid(result_type).hash_code();
			_ParamTypes.push_back(typeid(object_type).hash_code());
		}

		~MethodInfo0()
		{
		}

	protected:
		virtual Variable Run( ParamArray &params )
		{
			assert(params.size() == _ParamTypes.size() && "the number of parameters does not match !");

			return IsMethodSame < result_type, void >::Call(params[0].Value < object_type * >(), _func);
		}

	private:
		function_type _func;
	};


	template < typename RT, typename OT, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8 >
	XTS_DECL CallableInfo *
	MakeMethodInfo( const std::string &name, RT(OT::*func)( A1, A2, A3, A4, A5, A6, A7, A8 ), const std::string &pname = "" )
	{
		return new MethodInfo8 < RT, OT, A1, A2, A3, A4, A5, A6, A7, A8 >(pname == "" ? name : pname, func);
	};

	template < typename RT, typename OT, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7 >
	XTS_DECL CallableInfo *
	MakeMethodInfo( const std::string &name, RT(OT::*func)( A1, A2, A3, A4, A5, A6, A7 ), const std::string &pname = "" )
	{
		return new MethodInfo7 < RT, OT, A1, A2, A3, A4, A5, A6, A7 >(pname == "" ? name : pname, func);
	};

	template < typename RT, typename OT, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6 >
	XTS_DECL CallableInfo *
	MakeMethodInfo( const std::string &name, RT(OT::*func)( A1, A2, A3, A4, A5, A6 ), const std::string &pname = "" )
	{
		return new MethodInfo6 < RT, OT, A1, A2, A3, A4, A5, A6 >(pname == "" ? name : pname, func);
	};

	template < typename RT, typename OT, typename A1, typename A2, typename A3, typename A4, typename A5 >
	XTS_DECL CallableInfo *
	MakeMethodInfo( const std::string &name, RT(OT::*func)( A1, A2, A3, A4, A5 ), const std::string &pname = "" )
	{
		return new MethodInfo5 < RT, OT, A1, A2, A3, A4, A5 >(pname == "" ? name : pname, func);
	};

	template < typename RT, typename OT, typename A1, typename A2, typename A3, typename A4 > XTS_DECL CallableInfo *
	MakeMethodInfo( const std::string &name, RT(OT::*func)( A1, A2, A3, A4 ), const std::string &pname = "" )
	{
		return new MethodInfo4 < RT, OT, A1, A2, A3, A4 >(pname == "" ? name : pname, func);
	};

	template < typename RT, typename OT, typename A1, typename A2, typename A3 > XTS_DECL CallableInfo *
	MakeMethodInfo( const std::string &name, RT(OT::*func)( A1, A2, A3 ), const std::string &pname = "" )
	{
		return new MethodInfo3 < RT, OT, A1, A2, A3 >(pname == "" ? name : pname, func);
	};

	template < typename RT, typename OT, typename A1, typename A2 > XTS_DECL CallableInfo *
	MakeMethodInfo( const std::string &name, RT(OT::*func)( A1, A2 ), const std::string &pname = "" )
	{
		return new MethodInfo2 < RT, OT, A1, A2 >(pname == "" ? name : pname, func);
	};

	template < typename RT, typename OT, typename A1 > XTS_DECL CallableInfo *
	MakeMethodInfo( const std::string &name, RT(OT::*func)( A1 ), const std::string &pname = "" )
	{
		return new MethodInfo1 < RT, OT, A1 >(pname == "" ? name : pname, func);
	};

	template < typename RT, typename OT >
	XTS_DECL CallableInfo * MakeMethodInfo( const std::string &name, RT(OT::*func)(), const std::string &pname = "" )
	{
		return new MethodInfo0 < RT, OT >(pname == "" ? name : pname, func);
	};

}


#endif //METADATA_METHODINFO_H
