#include "TestClass.h"
#include <iostream>

TestClass::TestClass()
{

}

TestClass::~TestClass()
{

}

void TestClass::PrintInt(int x, int y) const
{
	std::cout << "Print integer "<< x << " : " << y << std::endl;
}

void TestClass::PrintFloat(float x, float y) const
{
	std::cout << "Print float " << x << " : " << y << std::endl;
}