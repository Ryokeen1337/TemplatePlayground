#pragma once

class ITestClass
{
public:
	virtual void PrintInt(int x, int y) const = 0;
	virtual int AddInt(int x, int y) const = 0;
	virtual int SubInt( int x, int y ) const = 0;
	virtual std::unique_ptr<int> ReturnUniquePtr(int x, int y) const = 0;
	virtual void PrintFloat(float x, float y) const = 0;
};

class TestClass : public ITestClass
{
public:
	TestClass();
	~TestClass();

	void PrintInt(int x, int y) const override;
	int AddInt(int x, int y) const override;
	int SubInt( int x, int y ) const override;
	std::unique_ptr<int> ReturnUniquePtr(int x, int y) const override;
	void PrintFloat(float x, float y)const override;
private:
};