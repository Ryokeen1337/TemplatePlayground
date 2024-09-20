#pragma once

class ITestClass
{
public:
	virtual void PrintInt(int x, int y) = 0;
	virtual void PrintFloat(float x, float y) = 0;
};

class TestClass : public ITestClass
{
public:
	TestClass();
	~TestClass();

	void PrintInt(int x, int y) override;
	void PrintFloat(float x, float y) override;
private:
};