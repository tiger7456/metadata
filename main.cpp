#include <iostream>

#include "MetaType.h"

using namespace xts;

void func()
{
	std::cout << "Hello, World!!!!!func" << std::endl;
}

int funci( int i )
{

	std::cout << "Hello, World!!!!!func" << i << std::endl;
	return i;
}

class super
{
};

META_CLASS_BEGIN(super)
META_CLASS_END(super)


class test : public super
{
public:
	test()
	{
		std::cout << "Construct!!!!!" << std::endl;
	}

	~test()
	{
		std::cout << "Destruct!!!!!" << std::endl;
	}

	int i;

	void func()
	{
		std::cout << "Hello, World!!!!!" << i << std::endl;
	}

	static int funci( int a )
	{
		int i = 12345;
		i += a;
		return i;
	}

	int funca( int a )
	{
		int i = 12345;
		i += a;
		return i;
	}
};

META_CLASS_BEGIN(test)
		REG_SUPER(super);
		REG_PROPERTY(i);
		REG_METHOD(func);
		REG_METHOD(funca, "funcaa");
		REG_METHOD_STATIC(funci, "funcii");
META_CLASS_END(test)

META_REG_FUNC(func, "funca");

enum class aa
{
	a1,a2,a3
};

META_ENUM_BEGIN(aa)
		REG_ENUM(a1, aa::a1);
		REG_ENUM(a2, aa::a2);
		REG_ENUM(a3, aa::a3);
META_ENUM_END(aa)


int main()
{
	ClassInfo * info = MetaType::Instance()->FindClassInfoByName("test");

	if( info != nullptr )
	{
		std::cout << info->GetSuperClass()->GetClassName() << std::endl;

		Variable inst = info->GetConstructInfo()->New();

		PropertyInfo * prop = info->FindProperty("i");

		prop->Set(inst, 1);

		CallableInfo * func = info->FindMethod("func");

		func->Invoke(inst);

		func = info->FindMethod("funcaa");

		Variable vv = func->Invoke(inst, 222);

		std::cout << vv.Value < int >() << std::endl;

		func = info->FindMethod("funcii");

		vv = func->Invoke(1);

		std::cout << vv.Value < int >() << std::endl;

		info->GetDestructInfo()->Delete(inst);


		func = MetaType::Instance()->FindCallbackInfoByName("funca");

		func->Invoke();

	}

	return 0;
}

