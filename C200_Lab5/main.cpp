#include <iostream>
#include "Point.h"
#include "Circle.h"
#include "List.h"
int main()
{
	setlocale(0, "Rus");
	Point point(2,2);
	Circle circle(point, 4);
	//Перегрузить ostream для Point +
	//Перегрузить ostream для Circle   отдельные для каждого +
	//Перегрузить ostream для класса List +
	//Добавить несколько элементов в список и распечатать  +
	//Добавить метод удаления одного элемента +
	//Добавить метод удаления нескольких элементов элементов +
	//Добавить метод запись в файл +
	//Добавить метод чтения из файла +
	List ls;
	ls.push_back(Circle(Point(4, 4), 10));
	std::cout << ls << std::endl;
	std::cin >> ls;
	std::cout << ls << std::endl;
	std::cout << "Чтение из файла" << std::endl;
	List ls1;
	ReadFromFile(ls1);
	std::cout << ls1 << std::endl;
	//std::cout << ls << std::endl;
	//ls.push_back(circle);
	//ls.push_back(Circle(Point(4, 4), 10));
	//ls.push_back(Circle(Point(4, 4), 20));
	//ls.push_back(Circle(Point(4, 4), 40));
	//ls.push_back(Circle(Point(4, 4), 30));
	//ls.push_back(Circle(Point(4, 4), 5));
	////std::cout << (Circle(Point(4, 4), 10)) << std::endl;
	//std::cout << ls << std::endl;
	//ls.sort();
	//std::cout << ls << std::endl;
	//ls.RemoveOne((Circle(Point(4, 4), 30)));
	//std::cout << ls << std::endl;
	//
	//List ls1;
	//ls1.push_back(circle);
	//ls1.push_back(Circle(Point(4, 4), 10));
	//ls1.push_back(Circle(Point(4, 4), 20));
	//ls1.push_back(Circle(Point(4, 4), 40));
	//ls1.push_back(Circle(Point(4, 4), 30));
	//ls1.push_back(Circle(Point(4, 4), 30));
	//ls1.push_back(Circle(Point(4, 4), 30));
	//ls1.push_back(Circle(Point(4, 4), 30));
	//ls1.push_back(Circle(Point(4, 4), 5));
	//std::cout << ls1 << std::endl;
	//ls1.sort();
	//std::cout << ls1 << std::endl;
	//ls1.RemoveAll((Circle(Point(4, 4), 30)));
	//std::cout << ls1 << std::endl;
	//WriteFile(ls1);
	return 0;
}