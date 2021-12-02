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
		TEST_METHOD(iteratorS_test)
		{
			heap a;
			a.begin();
			a.insert(1);
			a.insert(2);
			a.insert(3);
			a.insert(4);
			a.insert(5);
			iteratorS* a_iteratorS = a.create_iteratorS();
			int i = 1;
			while (a_iteratorS->has_next()) {
				Assert::IsTrue((a_iteratorS->next())==i);
					i++;
			}
		}
		TEST_METHOD(iteratorG_test)
		{
			heap a;
			a.begin();
			a.insert(1);
			a.insert(2);
			a.insert(3);
			a.insert(4);
			a.insert(5);
			iteratorG* a_iteratorG = a.create_iteratorG();
			int masss[6];
			masss[0] = 1;
			masss[1] = 2;
			masss[2] = 4;
			masss[3] = 5;
			masss[4] = 3;
			int ii = 0;
			while (ii < a.size()) {
				Assert::IsTrue((a_iteratorG->Next()) == masss[ii]);
				ii++;
			}
		}
	};
}
