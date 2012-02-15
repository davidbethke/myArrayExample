#include <iostream>
#include <sstream>
#include "ArrayDave.h"
using namespace std;
ostream& operator<<(ostream& out, const ArrayDave& arr)
{
	for(int i=0; i<arr.size; ++i)
		cout << arr.ptr[i]<< " ";
	return out;
}