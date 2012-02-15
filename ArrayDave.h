#pragma once
#include <iostream>
class ArrayDave
{
	friend void doNothing();
	friend std::ostream& operator<<(std::ostream&,const ArrayDave&);
public:
	ArrayDave(int=10,int=0);
	ArrayDave(const ArrayDave&); //copy constructor
	~ArrayDave(void);
	ArrayDave& operator=(const ArrayDave &);
	int getSize() const;
	int& operator[](int);
	int operator[](int) const;
private:
	int size;
	int *ptr;
};
