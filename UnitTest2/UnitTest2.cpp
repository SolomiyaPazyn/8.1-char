#include "pch.h"
#include "CppUnitTest.h"
#include "../lab 8.1 char.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char str1[] = "Hello,-world";
			Assert::IsTrue(Search(str1), L"Test 1 Failed");
			
		}
	};
}
