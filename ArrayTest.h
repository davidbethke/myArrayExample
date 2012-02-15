#pragma once
#include "d:\users\dave\documents\visual studio 2010\projects\gtest\include\gtest\gtest.h"
#include "ArrayDave.h"
class ArrayDaveTest :
	public ::testing::Test
{
protected:
	virtual void SetUp()
	{
		p_cout_streambuf = std::cout.rdbuf();

	}
	virtual void TearDown()
	{
		std::cout.rdbuf(p_cout_streambuf); // restore
	}
	ArrayDave arr;
	const ArrayDave arrC,arrCpy;
	std::ostringstream oss;
    std::streambuf* p_cout_streambuf;

public:
	ArrayDaveTest(void);
	~ArrayDaveTest(void);
};

