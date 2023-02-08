#include "Circle.h"
#include "Point.h"
#include "Node.h"
Circle::Circle()  //Конструктор по умолчанию
{
	//this->point = 0;
	this->m_r = 0;
}
//Circle::Circle(Point& opoint, int r): point(opoint)
Circle::Circle(const Point& opoint, int r): point(opoint)  //Конструктор с параметрами
{
	//this->point. = opoint.GetPointX();   //Нужен ли Setter?
	//point = opoint;
	this->m_r = r;
}
//Circle::Circle(const Circle& other) //Конструктор копирования
//{
//	this->point = other.point;
//	this->m_r = other.m_r;
//
//}
int Circle::GetR() //Геттер для r
{
	return this->m_r;
}
int Circle::GetX()//Геттер для х
{
	return this->point.GetPointX();
}
int Circle::GetY() //Геттер для y
{
	return this->point.GetPointY();
}

std::ostream& operator<< (std::ostream& out, const Circle& circle)
{
	out << circle.point;
	out << " "<<circle.m_r << std::endl;
	return out;
}
std::ifstream& operator>> (std::ifstream& in, Circle& circle)
{
	in >> circle.point >> circle.m_r;
	return in;
}
bool Circle::operator==(const Circle& c)
{
	return (this->point == c.point) && (this->m_r == c.m_r);
}
//Circle::~Circle()
//{
//
//}