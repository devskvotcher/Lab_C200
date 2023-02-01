#include "Shape.h"

Shape::Shape(COLOR *x, unsigned int right, unsigned int left, unsigned int bottom, unsigned int top)
{
	this->m_right = right;
	this->m_left = left;
	this->m_bottom = bottom;
	this->m_top = top;
	this->color = x;
}

Shape::~Shape()
{
	delete[] color;
}
Rect: public Shape::Rect : public Shape(* x,  right,  left,  bottom, top)
{
}

Rect:public Shape::~Rect : public Shape()
{
}