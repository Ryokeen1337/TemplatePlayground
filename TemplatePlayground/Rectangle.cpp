#include <iostream>
#include "Rectangle.h"

Rectangle::Rectangle()
{
    _dimensionX = new Dimension();
    _dimensionY = new Dimension();
}

Rectangle::~Rectangle()
{
    delete _dimensionX;
    delete _dimensionY;
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