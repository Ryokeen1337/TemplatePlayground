#include <iostream>
#include "TestClass.h"

TestClass::TestClass()
{

}

TestClass::~TestClass()
{

}

int TestClass::AddInt(int x, int y) const
{
	std::cout << "Print integer and add " << x << " + " << y << " = " << ( x + y ) << std::endl;
	return x+y;
}

int TestClass::SubInt( int x, int y ) const
{
	std::cout << "Print integer and sub  " << x << " - " << y << " = " << ( x - y ) << std::endl;
	return x + y;
}

std::unique_ptr<int> TestClass::ReturnUniquePtr(int x, int y) const
{
	std::cout << "ReturnUniquePtr<int>" << "(" << x + y << ")" << std::endl;
	return std::make_unique<int>(x+y);
}

void TestClass::PrintInt(int x, int y) const
{
	std::cout << "Print integer "<< x << " , " << y << std::endl;
}

void TestClass::PrintFloat(float x, float y) const
{
	std::cout << "Print float " << x << " , " << y << std::endl;
}