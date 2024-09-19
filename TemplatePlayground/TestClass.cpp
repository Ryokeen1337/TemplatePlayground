#include "TestClass.h"
#include <iostream>

TestClass::TestClass()
{

}

TestClass::~TestClass()
{

}

void TestClass::PrintInt(int x, int y)
{
	std::cout << "Print integer "<< x << " : " << y;
}

void TestClass::PrintFloat(float x, float y)
{
	std::cout << "Print float " << x << " : " << y;
}