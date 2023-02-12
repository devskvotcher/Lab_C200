#include "Point.h"
#include <iostream>
Point::Point()
{
	m_x = 0;
	m_y = 0;
}
Point::Point(int x, int y)
{
	this->m_x = x;
	this->m_y = y;
}
int Point::Getm_x(Point& obj) const
{
	return obj.m_x;
}
int Point::Getm_y(Point& obj) const
{
	return obj.m_y;
}
Point Point::operator +()        
{	
	return *this;
}
Point& Point::operator += (const Point &obj2)
{
	this->m_x = this->m_x + obj2.m_x;
	this->m_y = this->m_y + obj2.m_y;
	return *this;
}
Point& Point::operator += (int x)
{
	this->m_x = this->m_x + x;
	this->m_y = this->m_y + x;
	return *this;
}
Point& operator -= (Point& obj1, const Point& obj2)
{
	obj1.m_x = obj1.m_x - obj2.m_x;
	obj1.m_y = obj1.m_y - obj2.m_y;
	return obj1;
}
Point& operator -= (Point& obj1, int x)
{
	obj1.m_x = obj1.m_x - x;
	obj1.m_y = obj1.m_y - x;
	return obj1;
}
Point Point::operator + (const Point& obj2)
{
	return Point(this->m_x + obj2.m_x, this->m_x + obj2.m_y);
}
Point Point::operator + (const int x)
{
	return Point(this->m_x + x, this->m_y + x);
}
Point operator + (const int x, const Point& obj1)
{
	return Point(obj1.m_x + x, obj1.m_y + x);
}
Point operator - (const Point& obj1, const Point& obj2)
{
	
	return Point(obj1.m_x - obj2.m_x, obj1.m_y - obj2.m_y);
}
Point operator - (const Point& obj1, int d)
{
	return Point(obj1.m_x - d, obj1.m_y - d);
}
//Point operator - (int d, Point& obj1)
//{
//	int x = d - obj1.Getm_x(obj1);
//	int y = d - obj1.Getm_y(obj1);
//	return Point(x, y);
//}
//+ Методом класса
//- Глобальная функция
Point operator -(const Point& obj2)
{
	return Point(-(obj2.m_x), -(obj2.m_y));
}

Point operator - (int x, const Point& obj1)
{
	return Point(-obj1.m_x + x, -obj1.m_y + x);
}
std::ostream& operator<< (std::ostream& out, const Point& point)
{
	out << "x=" << point.m_x << ", у=" << point.m_y;
	return out;
}

