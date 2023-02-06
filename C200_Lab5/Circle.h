#pragma once
#include "Point.h"
class Circle
{
		Point point;
		int m_r;
	public:
		Circle();  //Конструктор по умолчанию
		Circle(const Point& point, int r);  //Конструктор с параметрами
	//	Circle(const Circle& other); //Конструктор копирования
		int GetR(); //Геттер для r
		int GetX(); //Геттер для х
		int GetY(); //Геттер для y
	//	~Circle();
		friend std::ostream& operator<< (std::ostream& out, const Circle& circle);
		friend std::ifstream& operator>> (std::ifstream& in, Circle& circle);
		friend class Node;
};

