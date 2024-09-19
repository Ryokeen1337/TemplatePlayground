#include <iostream>
#include "TestClass.h"

template<typename T, typename U>
class TestTemplate
{
public:
    typedef void (TestClass::* FunctionToCall)(T x, U y);  // Please do this!

    template<typename FType>
    void TestCall(TestClass& tClass, FType f, T x, U y)
    {
        FunctionToCall funcToCall = f;
        ((tClass).*(funcToCall))(x, y);
    }
};

int main()
{
    TestClass* tClass = new TestClass();

    TestTemplate<int, int> testT;
    testT.TestCall(*tClass, &TestClass::PrintInt, 1, 3);
}