#pragma once
#include <iostream>
class Point
{
private:
	int m_x;
	int m_y;
public:
	Point();
	Point(int x, int y);
	int Getm_x(Point& obj);
	int Getm_y(Point& obj);
	//Методом класса
	Point operator +();
	Point operator += (const Point& obj2);
	Point operator += (int x);	
	Point operator + (const Point& obj2);
	Point operator + (const int x);
	friend Point operator + (const int x, const Point& obj1);
	
	friend std::ostream& operator<< (std::ostream& out, const Point& point);
	//Глобальная функция
	friend Point& operator -= (Point& obj1, const Point& obj2);
	friend Point& operator -= (Point& obj1, int x);
	friend Point& operator - (Point& obj1, const Point& obj2);
	friend Point operator - (Point& obj1, int x);
	friend Point& operator - (int x, Point& obj1);
	friend Point operator -(Point& obj2);
};

