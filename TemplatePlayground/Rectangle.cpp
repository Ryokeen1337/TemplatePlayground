#include <iostream>
#include "Rectangle.h"

Rectangle::Rectangle()
{
    _dimensionX = std::make_unique<Dimension>();
    _dimensionY = std::make_unique<Dimension>();
}

Rectangle::Rectangle(int x, int y) : Rectangle()
{
    SetDimensionX(x);
    SetDimensionY(y);
}

Rectangle::~Rectangle()
{
}

int Rectangle::GetArea() const
{
    return _dimensionX->GetDimension() * _dimensionY->GetDimension();
}

void Rectangle::SetDimensionX( int value )
{
    _dimensionX->SetDimension( value );
}

void Rectangle::SetDimensionY( int value ) const
{
    _dimensionY->SetDimension(value);
}