#include <iostream>
#include "Point.h"
#include "Circle.h"
#include "List.h"
int main()
{
	Point point(2,2);
	Circle circle(point, 4);
	//����������� ostream ��� Point +
	//����������� ostream ��� Circle   ��������� ��� ������� +
	//����������� ostream ��� ������ List
	//�������� ��������� ��������� � ������ � �����������

	List ls;
	ls.push_back(circle);
	ls.push_back(Circle(Point(4, 4), 10));
	std::cout << (Circle(Point(4, 4), 10)) << std::endl;
	//std::cout << ls << std::endl;

	return 0;
}