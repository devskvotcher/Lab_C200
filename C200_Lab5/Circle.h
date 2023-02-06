#pragma once
#include "Point.h"
class Circle
{
		Point point;
		int m_r;
	public:
		Circle();  //����������� �� ���������
		Circle(const Point& point, int r);  //����������� � �����������
	//	Circle(const Circle& other); //����������� �����������
		int GetR(); //������ ��� r
		int GetX(); //������ ��� �
		int GetY(); //������ ��� y
	//	~Circle();
		friend std::ostream& operator<< (std::ostream& out, const Circle& circle);
		friend std::ifstream& operator>> (std::ifstream& in, Circle& circle);
		friend class Node;
};

