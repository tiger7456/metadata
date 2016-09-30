//
// Created by 郑元庆 on 16/9/25.
//

#ifndef METADATA_CALLABLEINFO_H
#define METADATA_CALLABLEINFO_H

#include "Variable.h"

namespace xts
{

	class XTS_DECL CallableInfo
	{
	public:
		typedef std::vector < Variable > ParamArray;
		typedef std::vector < size_t > ParamTypeArray;

	protected:
		template < class _Tp, class _Up > struct IsMethodSame
		{
			template < typename OT, typename FT, typename ... PT > static Variable Call( OT * obj, FT f, PT ... args )
			{
				return Variable::FromValue(( obj->*f )(args...));
			}
		};

		template < class _Tp > struct IsMethodSame < _Tp, _Tp >
		{
			template < typename OT, typename FT, typename ... PT > static Variable Call( OT * obj, FT f, PT ... args )
			{
				( obj->*f )(args...);

				return Variable();
			}
		};

		template < class _Tp, class _Up > struct IsCallbackSame
		{
			template < typename FT, typename ... PT > static Variable Call( FT f, PT ... args )
			{
				return Variable::FromValue(f(args...));
			}
		};

		template < class _Tp > struct IsCallbackSame < _Tp, _Tp >
		{
			template < typename FT, typename ... PT > static Variable Call( FT f, PT ... args )
			{
				f(args...);

				return Variable();
			}
		};

	public:
		CallableInfo();

		virtual ~CallableInfo();

	public:
		const std::string &GetName() const;

		size_t GetReturnType() const;

		size_t GetParamCount() const;

		const ParamTypeArray &GetParamTypes() const;

		CallableType GetType() const;

	protected:
		virtual Variable Run( ParamArray &params ) = 0;

	public:
		template < typename ... PARAMS > Variable Invoke( PARAMS ... params )
		{
			ParamArray Params;

			Unpack(Params, params...);

			return Run(Params);
		}

		Variable Invoke()
		{
			ParamArray Params;

			return Run(Params);
		}

	private:
		template < typename T, typename ... TS > void Unpack( ParamArray &params, T &t, TS...ts )
		{
			params.push_back(t);
			Unpack(params, ts...);
		}

		template < typename T > void Unpack( ParamArray &params, T &t )
		{
			params.push_back(t);
		}

	protected:
		std::string _Name;
		CallableType _Type;
		size_t _ParamCount;
		size_t _ReturnType;
		ParamTypeArray _ParamTypes;
	};

}

#endif //METADATA_CALLABLEINFO_H
