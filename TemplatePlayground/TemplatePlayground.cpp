#include <iostream>
#include "TestClass.h"

template<typename ClassType,typename FuncType, typename ParamType1, typename ParamType2>
class TestTemplate
{
public:
    typedef void (ClassType::* FunctionToCall)(ParamType1 x, ParamType2 y);  // Please do this!

    void TestCall(ClassType& tClass, FuncType f, ParamType1 x, ParamType2 y)
    {
        FunctionToCall funcToCall = f;
        ((tClass).*(funcToCall))(x, y);
    }
};

template<typename ParamType1, typename ParamType2, typename ClassType, void (ClassType::* FunctionToCall)(ParamType1, ParamType2)>
void TestCall(ClassType& tClass, ParamType1 x, ParamType2 y)
{
    ((tClass).*(FunctionToCall))(x, y);
}

int main()
{
    TestClass* tClass = new TestClass();

    TestTemplate<TestClass, decltype(TestClass::PrintFloat),float, float> testT;
    testT.TestCall(*tClass, &TestClass::PrintFloat , 1, 3);

    TestCall<int, int, TestClass, &TestClass::PrintInt>(*tClass, 1, 3);
}