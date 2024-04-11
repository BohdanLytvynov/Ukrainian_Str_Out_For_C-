#include <iostream>
#include"..\ukrString\ukrString.h"
#include<crtdbg.h>

strings::ukrString Returning()
{
	return strings::ukrString("Тест");	
}

void DisposingTest()
{
	allocator::smart_allocator<int> alloc(23);

	strings::ukrString text("Test String");
}

void ExcepTest()
{
	try
	{
		allocator::smart_allocator<char> test('e');

		strings::ukrString text("Test String");

		throw std::exception("Test");
	}
	catch (const std::exception&)
	{
		return;
	}
}

int main()
{
	int flag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
	flag |= _CRTDBG_LEAK_CHECK_DF;
	_CrtSetDbgFlag(flag);

	std::cout << "Memory Leak Testing!\n";

	strings::ukrString res = Returning();

	DisposingTest();

	ExcepTest();
}