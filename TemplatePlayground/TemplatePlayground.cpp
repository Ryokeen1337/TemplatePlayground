#include <iostream>
#include "TestClass.h"

template<typename ClassType,typename FuncType, typename ParamType1, typename ParamType2>
class TestTemplate
{
public:
    typedef void (ClassType::* FunctionToCall)(ParamType1 x, ParamType2 y) const;  // Please do this!

    void TestCall(ClassType& tClass, FuncType f, ParamType1 x, ParamType2 y) const
    {
        FunctionToCall funcToCall = f;
        ((tClass).*(funcToCall))(x, y);
    }
};

template<typename ParamType1, typename ParamType2, typename ClassType, void (ClassType::* FunctionToCall)(ParamType1, ParamType2)const>
void TestCall(ClassType& tClass, ParamType1 x, ParamType2 y)
{
    ((tClass).*(FunctionToCall))(x, y);
}

int main()
{
    std::unique_ptr<ITestClass> tClass = std::make_unique<TestClass>();

    TestTemplate<ITestClass, decltype(ITestClass::PrintFloat),float, float> testT;
    testT.TestCall(*tClass, &ITestClass::PrintFloat , 1, 3);

    TestCall<int, int, ITestClass, &ITestClass::PrintInt>(*tClass, 1, 3);
}