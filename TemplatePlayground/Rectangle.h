#pragma once

class Dimension
{
public:
	Dimension(){};
	~Dimension(){};

	void SetDimension(const int value)
	{
		_dimension = value;
	}

	int GetDimension() const
	{
		return _dimension;
	}
private:
	int _dimension;
};

class Rectangle
{
public:
	Rectangle();
	~Rectangle();

	void SetDimensionY(const int value) const;
	void SetDimensionX(const int value);

	int GetArea() const;
private:
	Dimension* _dimensionX;
	Dimension* _dimensionY;
};