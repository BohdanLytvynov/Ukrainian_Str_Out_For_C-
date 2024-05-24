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
			ukrString str1("������� ");
			ukrString str2("���");

			ukrString res = str1 + str2;

			size_t length = res.getLength();

			const char* test = "������� ���";

			for (size_t i = 0; i < length; i++)
			{
				Assert::IsTrue(test[i] == res[i]);
			}

			ukrString str3("������� ");
			ukrString str4("���");

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

			ukrString str1("�����");
			ukrString str2("�����");

			Assert::IsTrue(str1 == str2);
		}

		TEST_METHOD(IsNotEqualsCorrect)
		{
			using namespace strings;

			ukrString str1("�����");
			ukrString str2("����� �������");

			Assert::IsTrue(str1 != str2);
		}

		TEST_METHOD(IsSplitIsCorrect)
		{
			using namespace strings;

			ukrString str2("����� �������");

			ukrString res1("�����");
			ukrString res2("�������");

			std::vector<ukrString> word_set;

			char delim[] = { ' ' };

			ukrString::Split(str2, word_set, delim);

			Assert::IsTrue(word_set[0] == res1 && word_set[1] == res2);
		}
	};
}
