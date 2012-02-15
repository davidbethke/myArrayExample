#include "ArrayTest.h"
#include <iostream>
using namespace std;


ArrayDaveTest::ArrayDaveTest(void):arr(),arrC(),arrCpy()
{
}


ArrayDaveTest::~ArrayDaveTest(void)
{
}

TEST_F(ArrayDaveTest, checkSize)
{
	EXPECT_EQ(10,arr.getSize());

}

TEST_F(ArrayDaveTest, checkPrint)
{
	std::cout.rdbuf(oss.rdbuf());
	cout << arr << endl;
	EXPECT_EQ("0 0 0 0 0 0 0 0 0 0 \n",oss.str());

}
TEST_F(ArrayDaveTest, checkPrintC)
{
	std::cout.rdbuf(oss.rdbuf());
	cout << arrC << endl;
	EXPECT_EQ("0 0 0 0 0 0 0 0 0 0 \n",oss.str());

}
TEST_F(ArrayDaveTest, checkInsert)
{
	arr[2]=21;
	std::cout.rdbuf(oss.rdbuf());
	cout << arr << endl;
	EXPECT_EQ("0 0 21 0 0 0 0 0 0 0 \n",oss.str());
}
TEST_F(ArrayDaveTest, checkInsertC)
{
	//arrC is a const array,subscript operator should return value unaltered
	EXPECT_EQ(0,arrC[2]);
}
TEST_F(ArrayDaveTest, checkCopyCtr)
{
	ArrayDave arrCp(arr);
	std::cout.rdbuf(oss.rdbuf());
	cout << arrCp << endl;
	EXPECT_EQ("0 0 0 0 0 0 0 0 0 0 \n",oss.str());
}
TEST_F(ArrayDaveTest, checkCopyCtr2)
{
	arr[3]=44;
	ArrayDave arrCp(arr);
	std::cout.rdbuf(oss.rdbuf());
	cout << arrCp << endl;
	EXPECT_EQ("0 0 0 44 0 0 0 0 0 0 \n",oss.str()); //initial value after copy
	//verify copy changes differently than the orig
	arrCp[0]=23;
	oss.str(""); //clear string to no val
	cout << arrCp << endl;
	EXPECT_EQ("23 0 0 44 0 0 0 0 0 0 \n",oss.str()); //initial value after copy
	oss.str("");
	cout << arr << endl;
	EXPECT_EQ("0 0 0 44 0 0 0 0 0 0 \n",oss.str())<<"Original changed, likely failed copy constructor"; //orig value after insert, unchanged if pass
}
TEST_F(ArrayDaveTest, checkAssign)
{
	arr[0]=23;
	arr[3]=44;
	ArrayDave arrAssign;
	std::cout.rdbuf(oss.rdbuf());
	cout << arrAssign << endl;
	EXPECT_EQ("0 0 0 0 0 0 0 0 0 0 \n",oss.str())<<"Fail initial construction check"; //initial value after construction
	//assign
	oss.str(""); //clear string to no val
	arrAssign=arr;
	cout << arrAssign << endl;
	EXPECT_EQ("23 0 0 44 0 0 0 0 0 0 \n",oss.str())<<"Fail assignment"; //value after assignment
	oss.str(""); //clear string to no val
	cout << arr<< endl;
	EXPECT_EQ("23 0 0 44 0 0 0 0 0 0 \n",oss.str())<<"Fail assignment"; //sanity check after assignmen
	

}

TEST_F(ArrayDaveTest, checkAssignMult)
{
	arr[0]=23;
	arr[3]=44;
	ArrayDave arrAssign, arrAssign2;
	std::cout.rdbuf(oss.rdbuf());
	cout << arrAssign << endl;
	EXPECT_EQ("0 0 0 0 0 0 0 0 0 0 \n",oss.str())<<"Fail initial construction check"; //initial value after construction
	//assign
	oss.str(""); //clear string to no val
	arrAssign=arr;
	cout << arrAssign << endl;
	EXPECT_EQ("23 0 0 44 0 0 0 0 0 0 \n",oss.str())<<"Fail assignment"; //value after assignment
	oss.str(""); //clear string to no val
	cout << arr<< endl;
	EXPECT_EQ("23 0 0 44 0 0 0 0 0 0 \n",oss.str())<<"Fail assignment"; //sanity check after assignmen
	arrAssign2=arrAssign=arr;
	oss.str(""); //clear string to no val
	cout << arrAssign2<< endl;
	EXPECT_EQ("23 0 0 44 0 0 0 0 0 0 \n",oss.str())<<"Fail Multiple assignment"; //check mult assignment
	

}