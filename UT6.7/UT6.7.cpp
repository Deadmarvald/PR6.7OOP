#include "pch.h"
#include "CppUnitTest.h"
#include "../PR6.7/Array.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UT67
{
	TEST_CLASS(UT67)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Array a;

			int t = a.size();

			Assert::AreEqual(t, 10);
		}
	};
}