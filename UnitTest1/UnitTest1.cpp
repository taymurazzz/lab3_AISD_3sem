#include "pch.h"
#include "CppUnitTest.h"
#include "../lab3/Header.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(contais_test)
		{
			heap a;
			a.begin();
			a.insert(1);
			a.insert(2);
			a.insert(3);
			a.insert(4);
			Assert::IsTrue(a.contains(3) == 1);
		}

		TEST_METHOD(inser_test)
		{
			heap a;
			a.begin();
			a.insert(1);
			Assert::IsTrue(a.at(0) == 1);
		}

		TEST_METHOD(remove_test)
		{
			heap a;
			a.begin();
			a.insert(1);
			a.insert(2);
			a.insert(3);
			a.remove(2);
			Assert::IsTrue(a.at(1) == 3);
		}
	};
}
