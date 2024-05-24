#include <iostream>
#include"..\ukrString\ukrString.h"
#include<crtdbg.h>
#include<fstream>


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
		using namespace strings;

		int flag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
		flag |= _CRTDBG_LEAK_CHECK_DF;
		_CrtSetDbgFlag(flag);

		std::cout << "Memory Leak Testing!\n";

		strings::ukrString res = Returning();

		DisposingTest();

		ExcepTest();

		std::ofstream file("..\\test.txt");

		if (file)
		{
			file << ukrString("Тестова українська стрічка");
		}
		else
		{
			std::cout << "Failed!" << std::endl;
		}
		file.close();
		std::ifstream read("..\\test.txt");

		ukrString str;

		if (read)
		{
			while (!read.eof())
			{
				ukrString::getLine(read, str);
			}
		}

		read.close();

		return EXIT_SUCCESS;

	}


