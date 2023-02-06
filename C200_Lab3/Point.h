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
	friend Point &operator += (Point& obj1, const Point& obj2);
	friend Point &operator += (Point& obj1, int x);	
	friend Point& operator -= (Point& obj1, const Point& obj2);
	friend Point& operator -= (Point& obj1, int x);
	friend Point& operator + (Point& obj1, const Point& obj2);
	friend Point& operator + (Point& obj1, int x);
	friend Point& operator + (int x, Point& obj1);
	friend Point& operator - (Point& obj1, const Point& obj2);
	//friend Point operator - (Point& obj1, int x);
	//friend Point& operator - (int x, Point& obj1);
	Point operator +();
	friend std::ostream& operator<< (std::ostream& out, const Point& point);
};

