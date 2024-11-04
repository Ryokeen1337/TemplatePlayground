#include <iostream>
#include "TestClass.h"
#include "Rectangle.h"

//Long readable version
template<typename ClassType, typename RetType,typename FuncType, typename ParamType1, typename ParamType2>
class TestTemplate1
{
public:
    typedef RetType (ClassType::* FunctionToCall)(ParamType1 x, ParamType2 y) const;  // Please do this!

    void TestCall(ClassType& tClass, FuncType f, ParamType1 x, ParamType2 y) const
    {
        FunctionToCall funcToCall = f;
        ((tClass).*(funcToCall))(x, y);
    }
};

//shorter version
//template instance can be reused for other methods of an object as long as the signature matches
template<typename ClassType, typename RetType, typename ParamType1, typename ParamType2>
class TestTemplate2
{
public:
    typedef RetType( ClassType::* FunctionToCall )( ParamType1 x, ParamType2 y ) const;  // Please do this!

    template<typename FuncType>
    void TestCall( ClassType& tClass, FuncType f, ParamType1 x, ParamType2 y ) const
    {
        FunctionToCall funcToCall = f;
        ( ( tClass ).*( funcToCall ) )( x, y );
    }
};

//compact version as the method pointer typedef is not really necessary
template<typename ClassType, typename FuncType, typename ParamType1, typename ParamType2>
class TestTemplate3
{
public:
    void TestCall( ClassType& tClass, FuncType f, ParamType1 x, ParamType2 y ) const
    {
        ( ( tClass ).*( f ) )( x, y );
    }
};

//same as above just with the reusability of TestTemplate2
template<typename ClassType, typename ParamType1, typename ParamType2>
class TestTemplate4
{
public:
    template<typename FuncType>
    void TestCall( ClassType& tClass, FuncType f, ParamType1 x, ParamType2 y ) const
    {
        ( ( tClass ).*( f ) )( x, y );
    }
};

//Version without decltype
template<typename ClassType, typename ParamType1, typename ParamType2>
class TestTemplate5
{
public:
    template<typename RetType, RetType( ClassType::* FunctionToCall )( ParamType1, ParamType2 ) const>
    void TestCall( ClassType& tClass, ParamType1 x, ParamType2 y ) const
    {
        ( ( tClass ).*( FunctionToCall ) )( x, y );
    }
};

template<typename ParamType1, typename ParamType2, typename ClassType, typename RetType,
    RetType( ClassType::* FunctionToCall )( ParamType1, ParamType2 ) const >
void TestCall(ClassType& tClass, ParamType1 x, ParamType2 y )
{
    ((tClass).*(FunctionToCall))(x, y);
}

void TestTemplates()
{
    std::unique_ptr<ITestClass> tClass = std::make_unique<TestClass>();

    std::cout << "-------TestTemplate1-------" << std::endl;
    TestTemplate1<ITestClass, void, decltype( &ITestClass::PrintInt ), int, int> test1;
    test1.TestCall( *tClass, &ITestClass::PrintInt, 1, 3 );

    TestTemplate1<ITestClass, int, decltype( &ITestClass::AddInt ), int, int> test2;
    test2.TestCall( *tClass, &ITestClass::AddInt, 1, 3 );

    TestTemplate1<ITestClass, std::unique_ptr<int>, decltype( ITestClass::ReturnUniquePtr ), int, int> test3;
    test3.TestCall( *tClass, &ITestClass::ReturnUniquePtr, 1, 3 );

    TestTemplate1<ITestClass, void, decltype( &ITestClass::PrintFloat ), float, float> test4;
    test4.TestCall( *tClass, &ITestClass::PrintFloat, 1.0f, 3.0f );

    std::cout << "-------TestTemplate2-------" << std::endl;
    TestTemplate2<ITestClass, int, int, int> test5;
    test5.TestCall<decltype( &ITestClass::AddInt )>( *tClass, &ITestClass::AddInt, 1, 3 );
    test5.TestCall<decltype( &ITestClass::SubInt )>( *tClass, &ITestClass::SubInt, 1, 3 );

    std::cout << "-------TestTemplate3-------" << std::endl;
    TestTemplate3<ITestClass, decltype( &ITestClass::PrintFloat ), float, float> test6;
    test6.TestCall( *tClass, &ITestClass::PrintFloat, 1.0f, 3.0f );

    std::cout << "-------TestTemplate4-------" << std::endl;
    TestTemplate4<ITestClass, int, int> test7;
    test7.TestCall<decltype( &ITestClass::AddInt )>( *tClass, &ITestClass::AddInt, 1, 3 );
    test7.TestCall<decltype( &ITestClass::SubInt )>( *tClass, &ITestClass::SubInt, 1, 3 );

    std::cout << "-------TestTemplate5-------" << std::endl;
    TestTemplate5<ITestClass, int, int> test8;
    test8.TestCall<int, &ITestClass::AddInt>( *tClass, 1, 3 );
    test8.TestCall<int, &ITestClass::SubInt>( *tClass, 1, 3 );

    std::cout << "-------TestCall Template-------" << std::endl;
    TestCall<int, int, ITestClass, void, &ITestClass::PrintInt>( *tClass, 1, 3 );
}

void TestConst()
{
    Rectangle rect{2,3};

    int area = rect.GetArea();

    std::cout << "-------Area: " << area << " -------" << std::endl;

    //call to const method
    rect.SetDimensionY( 4 );
    area = rect.GetArea();

    std::cout << "-------Area: " << area << " -------" << std::endl;
}

int main()
{
    //TestTemplates();
    TestConst();
}