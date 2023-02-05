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
int Point::Getm_x(Point& obj)
{
	return obj.m_x;
}
int Point::Getm_y(Point& obj)
{
	return obj.m_y;
}
const Point& Point::operator +(const Point& obj2) const        //       Не получилось что-то с перегрузкой +
{
	//return Point (obj2.m_x, obj2.m_y);	
	return obj2;
}
Point &operator += (Point& obj1, const Point &obj2)
{
	obj1.m_x = obj1.m_x+obj2.m_x;
	obj1.m_y = obj1.m_y + obj2.m_y;
	return obj1;
}
Point &operator += (Point &obj1, int x)
{
	obj1.m_x = obj1.m_x + x;
	obj1.m_y = obj1.m_y + x;
	return obj1;
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
Point& operator + (Point& obj1, const Point& obj2)
{
	obj1.m_x = obj1.m_x + obj2.m_x;
	obj1.m_y = obj1.m_y + obj2.m_y;
	return obj1;
}
Point& operator + (Point& obj1, int x)
{
	obj1.m_x = obj1.m_x + x;
	obj1.m_y = obj1.m_y + x;
	return obj1;
}
Point& operator + (int x, Point& obj1)
{
	obj1.m_x = obj1.m_x + x;
	obj1.m_y = obj1.m_y + x;
	return obj1;
}
Point& operator - (Point& obj1, const Point& obj2)
{
	obj1.m_x = obj1.m_x - obj2.m_x;
	obj1.m_y = obj1.m_y - obj2.m_y;
	return obj1;
}
//Point& operator - (Point& obj1, int x)
//{
//	obj1.m_x = obj1.m_x - x;
//	obj1.m_y = obj1.m_y - x;
//	return obj1;
//}
//Point& operator - (int x, Point& obj1)
//{
//	obj1.m_x = -obj1.m_x + x;
//	obj1.m_y = -obj1.m_y + x;
//	return obj1;
//}
std::ostream& operator<< (std::ostream& out, const Point& point)
{
	out << "x=" << point.m_x << ", у=" << point.m_y;
	return out;
}

