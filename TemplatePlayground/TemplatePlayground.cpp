#include <iostream>
#include "TestClass.h"

template<typename ClassType, typename RetType,typename FuncType, typename ParamType1, typename ParamType2>
class TestTemplate
{
public:
    typedef RetType (ClassType::* FunctionToCall)(ParamType1 x, ParamType2 y) const;  // Please do this!

    void TestCall(ClassType& tClass, FuncType f, ParamType1 x, ParamType2 y) const
    {
        FunctionToCall funcToCall = f;
        ((tClass).*(funcToCall))(x, y);
    }
};

template<typename ParamType1, typename ParamType2, typename ClassType, typename RetType,
    RetType( ClassType::* FunctionToCall )( ParamType1, ParamType2 ) const >
void TestCall(ClassType& tClass, ParamType1 x, ParamType2 y )
{
    ((tClass).*(FunctionToCall))(x, y);
}

int main()
{
    std::unique_ptr<ITestClass> tClass = std::make_unique<TestClass>();

    TestTemplate<ITestClass, void, decltype(&ITestClass::PrintInt),int, int> test1;
    test1.TestCall(*tClass, &ITestClass::PrintInt, 1, 3);

    TestTemplate<ITestClass, int, decltype(&ITestClass::AddInt), int, int> test2;
    test2.TestCall(*tClass, &ITestClass::AddInt, 1, 3);

    TestTemplate<ITestClass, std::unique_ptr<int>, decltype(ITestClass::ReturnUniquePtr), int, int> test3;
    test3.TestCall(*tClass, &ITestClass::ReturnUniquePtr, 1, 3);

    TestTemplate<ITestClass, void, decltype(&ITestClass::PrintFloat), float, float> test4;
    test4.TestCall( *tClass, &ITestClass::PrintFloat, 1.0f, 3.0f );


    TestCall<int, int, ITestClass, void, &ITestClass::PrintInt>(*tClass, 1, 3);
}