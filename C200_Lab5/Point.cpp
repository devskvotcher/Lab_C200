#include "Point.h"
Point::Point()  //����������� �� ���������
{
	m_x = 0;
	m_y = 0;
}
Point::Point(int x, int y)  //����������� � �����������
{
	this->m_x = x;
	this->m_y = y;
}
//Point::Point(const Point& other) //����������� �����������
//{
//	this->m_x = other.m_x;
//	this->m_y = other.m_y;
//}
int Point::GetPointX() //������ ��� �
{
	return this->m_x;
}
int Point::GetPointY() //������ ��� y
{
	return this->m_y;
}
std::ostream& operator<< (std::ostream& out, const Point& point)
{
	out << point.m_x<<" " << point.m_y;
	return out;
}
std::ifstream& operator>> (std::ifstream& in, Point& point)
{
	in >> point.m_x >> point.m_y;
	return in;
}
//Point::~Point()
//{
//
//}