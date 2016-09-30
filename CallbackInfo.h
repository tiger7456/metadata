//
// Created by 郑元庆 on 16/9/27.
//

#ifndef METADATA_CALLBACKINFO_H
#define METADATA_CALLBACKINFO_H

#include "CallableInfo.h"

namespace xts
{

	template < typename RT, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8 >
	class XTS_DECL CallbackInfo8 : public CallableInfo
	{
	public:
		typedef RT result_type;

		typedef A1 param1_type;
		typedef A2 param2_type;
		typedef A3 param3_type;
		typedef A4 param4_type;
		typedef A5 param5_type;
		typedef A6 param6_type;
		typedef A7 param7_type;
		typedef A8 param8_type;

		typedef result_type (* function_type)( param1_type, param2_type, param3_type, param4_type, param5_type, param6_type, param7_type, param8_type );

	public:
		CallbackInfo8( const std::string &name, const function_type &func )
				:_func(func)
		{
			_Name = name;
			_Type = CallableType::T_CALLBACK;
			_ParamCount = 8;
			_ReturnType = typeid(result_type).hash_code();

			_ParamTypes.push_back(typeid(param1_type).hash_code());
			_ParamTypes.push_back(typeid(param2_type).hash_code());
			_ParamTypes.push_back(typeid(param3_type).hash_code());
			_ParamTypes.push_back(typeid(param4_type).hash_code());
			_ParamTypes.push_back(typeid(param5_type).hash_code());
			_ParamTypes.push_back(typeid(param6_type).hash_code());
			_ParamTypes.push_back(typeid(param7_type).hash_code());
			_ParamTypes.push_back(typeid(param8_type).hash_code());
		}

		~CallbackInfo8()
		{
		}

	protected:
		virtual Variable Run( ParamArray &params )
		{
			assert(params.size() == _ParamTypes.size() && "the number of parameters does not match !");

			return IsCallbackSame < result_type, void >::Call(_func, UnParam < param1_type >(params[0]), UnParam < param2_type >(params[1]), UnParam < param3_type >(params[2]), UnParam < param4_type >(params[3]), UnParam < param5_type >(params[4]), UnParam < param6_type >(params[5]), UnParam < param7_type >(params[6]), UnParam < param8_type >(params[7]));
		}

	private:
		template < typename T > T UnParam( Variable &var )
		{
			return var.Value < T >();
		}

	private:
		function_type _func;
	};

	template < typename RT, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7 >
	class XTS_DECL CallbackInfo7 : public CallableInfo
	{
	public:
		typedef RT result_type;

		typedef A1 param1_type;
		typedef A2 param2_type;
		typedef A3 param3_type;
		typedef A4 param4_type;
		typedef A5 param5_type;
		typedef A6 param6_type;
		typedef A7 param7_type;

		typedef result_type (* function_type)( param1_type, param2_type, param3_type, param4_type, param5_type, param6_type, param7_type );

	public:
		CallbackInfo7( const std::string &name, const function_type &func )
				:_func(func)
		{
			_Name = name;
			_Type = CallableType::T_CALLBACK;
			_ParamCount = 7;
			_ReturnType = typeid(result_type).hash_code();

			_ParamTypes.push_back(typeid(param1_type).hash_code());
			_ParamTypes.push_back(typeid(param2_type).hash_code());
			_ParamTypes.push_back(typeid(param3_type).hash_code());
			_ParamTypes.push_back(typeid(param4_type).hash_code());
			_ParamTypes.push_back(typeid(param5_type).hash_code());
			_ParamTypes.push_back(typeid(param6_type).hash_code());
			_ParamTypes.push_back(typeid(param7_type).hash_code());
		}

		~CallbackInfo7()
		{
		}

	protected:
		virtual Variable Run( ParamArray &params )
		{
			assert(params.size() == _ParamTypes.size() && "the number of parameters does not match !");

			return IsCallbackSame < result_type, void >::Call(_func, UnParam < param1_type >(params[0]), UnParam < param2_type >(params[1]), UnParam < param3_type >(params[2]), UnParam < param4_type >(params[3]), UnParam < param5_type >(params[4]), UnParam < param6_type >(params[5]), UnParam < param7_type >(params[6]));
		}

	private:
		template < typename T > T UnParam( Variable &var )
		{
			return var.Value < T >();
		}

	private:
		function_type _func;
	};

	template < typename RT, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6 >
	class XTS_DECL CallbackInfo6 : public CallableInfo
	{
	public:
		typedef RT result_type;

		typedef A1 param1_type;
		typedef A2 param2_type;
		typedef A3 param3_type;
		typedef A4 param4_type;
		typedef A5 param5_type;
		typedef A6 param6_type;

		typedef result_type (* function_type)( param1_type, param2_type, param3_type, param4_type, param5_type, param6_type );

	public:
		CallbackInfo6( const std::string &name, const function_type &func )
				:_func(func)
		{
			_Name = name;
			_Type = CallableType::T_CALLBACK;
			_ParamCount = 6;
			_ReturnType = typeid(result_type).hash_code();

			_ParamTypes.push_back(typeid(param1_type).hash_code());
			_ParamTypes.push_back(typeid(param2_type).hash_code());
			_ParamTypes.push_back(typeid(param3_type).hash_code());
			_ParamTypes.push_back(typeid(param4_type).hash_code());
			_ParamTypes.push_back(typeid(param5_type).hash_code());
			_ParamTypes.push_back(typeid(param6_type).hash_code());
		}

		~CallbackInfo6()
		{
		}

	protected:
		virtual Variable Run( ParamArray &params )
		{
			assert(params.size() == _ParamTypes.size() && "the number of parameters does not match !");

			return IsCallbackSame < result_type, void >::Call(_func, UnParam < param1_type >(params[0]), UnParam < param2_type >(params[1]), UnParam < param3_type >(params[2]), UnParam < param4_type >(params[3]), UnParam < param5_type >(params[4]), UnParam < param6_type >(params[5]));
		}

	private:
		template < typename T > T UnParam( Variable &var )
		{
			return var.Value < T >();
		}

	private:
		function_type _func;
	};

	template < typename RT, typename A1, typename A2, typename A3, typename A4, typename A5 >
	class XTS_DECL CallbackInfo5 : public CallableInfo
	{
	public:
		typedef RT result_type;

		typedef A1 param1_type;
		typedef A2 param2_type;
		typedef A3 param3_type;
		typedef A4 param4_type;
		typedef A5 param5_type;

		typedef result_type (* function_type)( param1_type, param2_type, param3_type, param4_type, param5_type );

	public:
		CallbackInfo5( const std::string &name, const function_type &func )
				:_func(func)
		{
			_Name = name;
			_Type = CallableType::T_CALLBACK;
			_ParamCount = 5;
			_ReturnType = typeid(result_type).hash_code();

			_ParamTypes.push_back(typeid(param1_type).hash_code());
			_ParamTypes.push_back(typeid(param2_type).hash_code());
			_ParamTypes.push_back(typeid(param3_type).hash_code());
			_ParamTypes.push_back(typeid(param4_type).hash_code());
			_ParamTypes.push_back(typeid(param5_type).hash_code());
		}

		~CallbackInfo5()
		{
		}

	protected:
		virtual Variable Run( ParamArray &params )
		{
			assert(params.size() == _ParamTypes.size() && "the number of parameters does not match !");

			return IsCallbackSame < result_type, void >::Call(_func, UnParam < param1_type >(params[0]), UnParam < param2_type >(params[1]), UnParam < param3_type >(params[2]), UnParam < param4_type >(params[3]), UnParam < param5_type >(params[4]));
		}

	private:
		template < typename T > T UnParam( Variable &var )
		{
			return var.Value < T >();
		}

	private:
		function_type _func;
	};

	template < typename RT, typename A1, typename A2, typename A3, typename A4 >
	class XTS_DECL CallbackInfo4 : public CallableInfo
	{
	public:
		typedef RT result_type;

		typedef A1 param1_type;
		typedef A2 param2_type;
		typedef A3 param3_type;
		typedef A4 param4_type;

		typedef result_type (* function_type)( param1_type, param2_type, param3_type, param4_type );

	public:
		CallbackInfo4( const std::string &name, const function_type &func )
				:_func(func)
		{
			_Name = name;
			_Type = CallableType::T_CALLBACK;
			_ParamCount = 4;
			_ReturnType = typeid(result_type).hash_code();

			_ParamTypes.push_back(typeid(param1_type).hash_code());
			_ParamTypes.push_back(typeid(param2_type).hash_code());
			_ParamTypes.push_back(typeid(param3_type).hash_code());
			_ParamTypes.push_back(typeid(param4_type).hash_code());
		}

		~CallbackInfo4()
		{
		}

	protected:
		virtual Variable Run( ParamArray &params )
		{
			assert(params.size() == _ParamTypes.size() && "the number of parameters does not match !");

			return IsCallbackSame < result_type, void >::Call(_func, UnParam < param1_type >(params[0]), UnParam < param2_type >(params[1]), UnParam < param3_type >(params[2]), UnParam < param4_type >(params[3]));
		}

	private:
		template < typename T > T UnParam( Variable &var )
		{
			return var.Value < T >();
		}

	private:
		function_type _func;
	};

	template < typename RT, typename A1, typename A2, typename A3 > class XTS_DECL CallbackInfo3 : public CallableInfo
	{
	public:
		typedef RT result_type;

		typedef A1 param1_type;
		typedef A2 param2_type;
		typedef A3 param3_type;

		typedef result_type (* function_type)( param1_type, param2_type, param3_type );

	public:
		CallbackInfo3( const std::string &name, const function_type &func )
				:_func(func)
		{
			_Name = name;
			_Type = CallableType::T_CALLBACK;
			_ParamCount = 3;
			_ReturnType = typeid(result_type).hash_code();

			_ParamTypes.push_back(typeid(param1_type).hash_code());
			_ParamTypes.push_back(typeid(param2_type).hash_code());
			_ParamTypes.push_back(typeid(param3_type).hash_code());
		}

		~CallbackInfo3()
		{
		}

	protected:
		virtual Variable Run( ParamArray &params )
		{
			assert(params.size() == _ParamTypes.size() && "the number of parameters does not match !");

			return IsCallbackSame < result_type, void >::Call(_func, UnParam < param1_type >(params[0]), UnParam < param2_type >(params[1]), UnParam < param3_type >(params[2]));
		}

	private:
		template < typename T > T UnParam( Variable &var )
		{
			return var.Value < T >();
		}

	private:
		function_type _func;
	};

	template < typename RT, typename A1, typename A2 > class XTS_DECL CallbackInfo2 : public CallableInfo
	{
	public:
		typedef RT result_type;

		typedef A1 param1_type;
		typedef A2 param2_type;

		typedef result_type (* function_type)( param1_type, param2_type );

	public:
		CallbackInfo2( const std::string &name, const function_type &func )
				:_func(func)
		{
			_Name = name;
			_Type = CallableType::T_CALLBACK;
			_ParamCount = 2;
			_ReturnType = typeid(result_type).hash_code();

			_ParamTypes.push_back(typeid(param1_type).hash_code());
			_ParamTypes.push_back(typeid(param2_type).hash_code());
		}

		~CallbackInfo2()
		{
		}

	protected:
		virtual Variable Run( ParamArray &params )
		{
			assert(params.size() == _ParamTypes.size() && "the number of parameters does not match !");

			return IsCallbackSame < result_type, void >::Call(_func, UnParam < param1_type >(params[0]), UnParam < param2_type >(params[1]));
		}

	private:
		template < typename T > T UnParam( Variable &var )
		{
			return var.Value < T >();
		}

	private:
		function_type _func;
	};

	template < typename RT, typename A1 > class XTS_DECL CallbackInfo1 : public CallableInfo
	{
	public:
		typedef RT result_type;

		typedef A1 param1_type;

		typedef result_type (* function_type)( param1_type );

	public:
		CallbackInfo1( const std::string &name, const function_type &func )
				:_func(func)
		{
			_Name = name;
			_Type = CallableType::T_CALLBACK;
			_ParamCount = 1;
			_ReturnType = typeid(result_type).hash_code();

			_ParamTypes.push_back(typeid(param1_type).hash_code());
		}

		~CallbackInfo1()
		{
		}

	protected:
		virtual Variable Run( ParamArray &params )
		{
			assert(params.size() == _ParamTypes.size() && "the number of parameters does not match !");

			return IsCallbackSame < result_type, void >::Call(_func, UnParam < param1_type >(params[0]));
		}

	private:
		template < typename T > T UnParam( Variable &var )
		{
			return var.Value < T >();
		}

	private:
		function_type _func;
	};

	template < typename RT > class XTS_DECL CallbackInfo0 : public CallableInfo
	{
	public:
		typedef RT result_type;


		typedef result_type (* function_type)();

	public:
		CallbackInfo0( const std::string &name, const function_type &func )
				:_func(func)
		{
			_Name = name;
			_Type = CallableType::T_CALLBACK;
			_ParamCount = 0;
			_ReturnType = typeid(result_type).hash_code();

		}

		~CallbackInfo0()
		{
		}

	protected:
		virtual Variable Run( ParamArray &params )
		{
			assert(params.size() == _ParamTypes.size() && "the number of parameters does not match !");

			return IsCallbackSame < result_type, void >::Call(_func);
		}

	private:
		template < typename T > T UnParam( Variable &var )
		{
			return var.Value < T >();
		}

	private:
		function_type _func;
	};


	template < typename RT, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8 >
	XTS_DECL CallableInfo *
	MakeCallbackInfo( const std::string &name, RT(* func)( A1, A2, A3, A4, A5, A6, A7, A8 ), const std::string &pname = "" )
	{
		return new CallbackInfo8 < RT, A1, A2, A3, A4, A5, A6, A7, A8 >(pname == "" ? name : pname, func);
	};

	template < typename RT, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7 >
	XTS_DECL CallableInfo *
	MakeCallbackInfo( const std::string &name, RT(* func)( A1, A2, A3, A4, A5, A6, A7 ), const std::string &pname = "" )
	{
		return new CallbackInfo7 < RT, A1, A2, A3, A4, A5, A6, A7 >(pname == "" ? name : pname, func);
	};

	template < typename RT, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6 >
	XTS_DECL CallableInfo *
	MakeCallbackInfo( const std::string &name, RT(* func)( A1, A2, A3, A4, A5, A6 ), const std::string &pname = "" )
	{
		return new CallbackInfo6 < RT, A1, A2, A3, A4, A5, A6 >(pname == "" ? name : pname, func);
	};

	template < typename RT, typename A1, typename A2, typename A3, typename A4, typename A5 > XTS_DECL CallableInfo *
	MakeCallbackInfo( const std::string &name, RT(* func)( A1, A2, A3, A4, A5 ), const std::string &pname = "" )
	{
		return new CallbackInfo5 < RT, A1, A2, A3, A4, A5 >(pname == "" ? name : pname, func);
	};

	template < typename RT, typename A1, typename A2, typename A3, typename A4 > XTS_DECL CallableInfo *
	MakeCallbackInfo( const std::string &name, RT(* func)( A1, A2, A3, A4 ), const std::string &pname = "" )
	{
		return new CallbackInfo4 < RT, A1, A2, A3, A4 >(pname == "" ? name : pname, func);
	};

	template < typename RT, typename A1, typename A2, typename A3 >
	XTS_DECL CallableInfo * MakeCallbackInfo( const std::string &name, RT(* func)( A1, A2, A3 ), const std::string &pname = "" )
	{
		return new CallbackInfo3 < RT, A1, A2, A3 >(pname == "" ? name : pname, func);
	};

	template < typename RT, typename A1, typename A2 >
	XTS_DECL CallableInfo * MakeCallbackInfo( const std::string &name, RT(* func)( A1, A2 ), const std::string &pname = "" )
	{
		return new CallbackInfo2 < RT, A1, A2 >(pname == "" ? name : pname, func);
	};

	template < typename RT, typename A1 >
	XTS_DECL CallableInfo * MakeCallbackInfo( const std::string &name, RT(* func)( A1 ), const std::string &pname = "" )
	{
		return new CallbackInfo1 < RT, A1 >(pname == "" ? name : pname, func);
	};

	template < typename RT >
	XTS_DECL CallableInfo * MakeCallbackInfo( const std::string &name, RT(* func)(), const std::string &pname = "" )
	{

		return new CallbackInfo0 < RT >(pname == "" ? name : pname, func);
	};

}


#endif //METADATA_CALLBACKINFO_H
