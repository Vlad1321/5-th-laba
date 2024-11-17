#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\garus\source\repos\5_laba\5_laba\5_laba.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(calculate_Tests)
	{
	public:
		TEST_METHOD(calculate_PositiveX)
		{
			double x = 1;
			int n = 5;
			int expected = 0;
			int actual = calculate(x, n);

			Assert::AreEqual(expected, actual);
		}
	public:
		TEST_METHOD(calculate_NegativeX)
		{
			double x = -5;
			int n = 5;
			int expected = 355;
			int actual = calculate(x, n);

			Assert::AreEqual(expected, actual);
		}
	};
	TEST_CLASS(CheckValidParams_Tests)
	{
	public:
		TEST_METHOD(CheckValidParams_get10_exceptionNotThrown)
		{
			int n = 10;
			double h = 2;

			try
			{
				CheckValidParams(n, h);
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::Fail();
			}
		}
	public:
		TEST_METHOD(CheckValidParams_get3_exceptionThrown)
		{
			int n = 3;
			double h = 0;

			try
			{
				CheckValidParams(n, h);
				Assert::Fail();
			}
			catch (...)
			{
				Assert::IsTrue(true);
			}
		}
	};
}