//
// Created by 郑元庆 on 16/9/25.
//

#ifndef METADATA_TYPEOF_H
#define METADATA_TYPEOF_H

#include <map>
#include <set>
#include <list>
#include <stack>
#include <deque>
#include <queue>
#include <vector>
#include <string>

#include <cassert>

#if defined(_WIN32)
	#ifdef METADATA_EXPORT
	#define XTS_DECL __declspec(dllexport)
	#else
	#define XTS_DECL __declspec(dllimport)
	#endif
#elif defined(__clang__)
	#ifdef METADATA_EXPORT
	#define XTS_DECL __attribute__ ((__type_visibility__("default")))
	#else
	#define XTS_DECL
	#endif
#elif defined(__GNUC__)
	#ifdef METADATA_EXPORT
	#define XTS_DECL __declspec(dllexport)
	#else
	#define XTS_DECL __declspec(dllimport)
	#endif
#endif

static std::__murmur2_or_cityhash < size_t > _Hash;

namespace xts
{

	enum class CallableType
	{
		T_METHOD,
		T_CALLBACK,
	};

	enum class ValueType
	{
		T_NULL = 0,
		T_BOOL,
		T_CHAR,
		T_UCHAR,
		T_INT16,
		T_UINT16,
		T_INT32,
		T_UINT32,
		T_INT64,
		T_UINT64,
		T_FLOAT,
		T_DOUBLE,
		T_USERCLASS,
	};

}


#endif //METADATA_TYPEOF_H
