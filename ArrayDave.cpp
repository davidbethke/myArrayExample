#include "ArrayDave.h"
#include <iostream>
using namespace std;


ArrayDave::ArrayDave(int s, int v):size(s)
{
	ptr= new int[size];
	for(int i=0;i<size;++i)
		ptr[i]=v;
}
ArrayDave::ArrayDave(const ArrayDave& other):size(other.size)
{
	ptr= new int[size];
	for(int i=0;i<size;++i)
		ptr[i]=other.ptr[i];
}

ArrayDave& ArrayDave::operator=(const ArrayDave &other)
{
	if(this!=&other)
	{
		delete[] ptr;
		size=other.size;
		ptr= new int[size];
		for(int i=0;i<size;++i)
			ptr[i]=other.ptr[i];

	}
	return *this;

}

ArrayDave::~ArrayDave(void)
{
	delete[] ptr;
}

int ArrayDave::getSize() const
{
	return size;
}
ostream& operator<<(ostream& out, const ArrayDave& arr)
{
	for(int i=0; i<arr.size; ++i)
		cout << arr.ptr[i]<< " ";
	return out;
}
void doNothing()
{
}
int& ArrayDave::operator[](int i) 
{
	if(i<0 || i>=size)
	{
		std::cerr<<"Bad Val Entered"<<endl;
		int garbage;
		return garbage;
	}
	return ptr[i];
}
int ArrayDave::operator[](int i) const
{
	if(i<0 || i>=size)
	{
		std::cerr<<"Bad Val Entered"<<endl;
		int garbage;
		return garbage;
	}
	return ptr[i];
}