//
// Created by 郑元庆 on 16/9/28.
//

#ifndef METADATA_CONSTRUCTINFO_H
#define METADATA_CONSTRUCTINFO_H

#include "Variable.h"

namespace xts
{

	class METADATA_DECL ConstructInfo
	{
	public:
		virtual ~ConstructInfo()
		{
		}

	public:
		virtual Variable New() = 0;
	};


	template < typename T > class TempConstructInfo : public ConstructInfo
	{
	public:
		virtual Variable New()
		{
			return Variable::FromValue(new T());
		}
	};


	template < typename T > ConstructInfo * MakeConstruct()
	{
		return new TempConstructInfo < T >();
	}


	class METADATA_DECL DestructInfo
	{
	public:
		virtual ~DestructInfo()
		{
		}

	public:
		virtual void Delete( Variable &var ) = 0;
	};


	template < typename T > class TempDestructInfo : public DestructInfo
	{
	public:
		virtual void Delete( Variable &var )
		{
			assert(var.GetTypeId() == typeid(T *).hash_code() && "");

			delete var.Value < T * >();
		}
	};


	template < typename T > DestructInfo * MakeDestruct()
	{
		return new TempDestructInfo < T >();
	}

}


#endif //METADATA_CONSTRUCTINFO_H
