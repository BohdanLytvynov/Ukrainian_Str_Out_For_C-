#include "pch.h"
#include "CppUnitTest.h"
#include"..\ukrString\ukrString.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ukrString_Tests
{
	TEST_CLASS(UkrString_Tests)
	{
	public:
		TEST_METHOD(IsConcatCorrect)
		{
			using namespace strings;
			ukrString str1("Гарного ");
			ukrString str2("Дня");

			ukrString res = str1 + str2;

			size_t length = res.getLength();

			const char* test = "Гарного Дня";

			for (size_t i = 0; i < length; i++)
			{
				Assert::IsTrue(test[i] == res[i]);
			}

			ukrString str3("Гарного ");
			ukrString str4("Дня");

			str3 += str4;

			length = str3.getLength();

			for (size_t i = 0; i < length; i++)
			{
				Assert::IsTrue(str3[i] == res[i]);
			}
		}

		TEST_METHOD(IsEqualsCorrect)
		{
			using namespace strings;

			ukrString str1("Добре");
			ukrString str2("Добре");

			Assert::IsTrue(str1 == str2);
		}

		TEST_METHOD(IsNotEqualsCorrect)
		{
			using namespace strings;

			ukrString str1("Добре");
			ukrString str2("Добре почуття");

			Assert::IsTrue(str1 != str2);
		}

		TEST_METHOD(IsSplitIsCorrect)
		{
			using namespace strings;

			ukrString str2("Добре почуття");

			ukrString res1("Добре");
			ukrString res2("почуття");

			std::vector<ukrString> word_set;

			char delim[] = { ' ' };

			ukrString::Split(str2, word_set, delim);

			Assert::IsTrue(word_set[0] == res1 && word_set[1] == res2);
		}
	};
}
