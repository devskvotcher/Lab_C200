#include "Shape.h"
#include <iostream>
Shape::Shape(COLOR x)
{
	this->color = x;
    std::cout << "Конструктор базового класса Shape" << std::endl;
}

void Shape::WhereAmI()
{
    std::cout << "Now I am in class Shape" << std::endl;
}

void Shape::WhereAmIVirtual()
{
    std::cout << "Now I am in class Shape" << std::endl;
}

Shape::~Shape()
{
    std::cout << "Деструктор базового класса Shape"<<std::endl;
}

Rect::Rect(unsigned int sideA, unsigned int sideB, unsigned int sideC, unsigned int sideD, COLOR color) :Shape(color)    //Конструктор по умолчанию
{
    this->m_sideA = sideA;
    this->m_sideB = sideB;
    this->m_sideC = sideC;
    this->m_sideD = sideD;
    std::cout << "Конструктор наследуемого класса Rect" << std::endl;
    
}
Rect::Rect(const Rect& rect) : Shape(rect)                   //Конструктор копирования
{
    this->m_sideA = rect.m_sideA;
    this->m_sideB = rect.m_sideB;
    this->m_sideC = rect.m_sideC;
    this->m_sideD = rect.m_sideD;
}

void Rect::WhereAmI()
{
    std::cout << "Now I am in class Rect" << std::endl;
}

void Rect::WhereAmIVirtual()
{
    std::cout << "Now I am in class Rect" << std::endl;
}

Rect::~Rect()
{
    std::cout << "Деструктор наследуемого класса Rect" << std::endl;
}

Circle::Circle() :Shape(color)
{
    this->m_x = 0;
    this->m_y = 0;
    this->m_radius = 0;
}

Circle::Circle(unsigned int r, unsigned int x, unsigned int y, COLOR color) :Shape(color)    //Конструктор по умолчанию
{
    this->m_radius = r;
    this->m_x = x;
    this->m_y = y;
    std::cout << "Конструктор наследуемого класса Circle" << std::endl;
}
Circle::Circle(const Circle& circle):Shape(circle)                    //Конструктор копирования
{
    this->m_radius = circle.m_radius;
    this->m_x = circle.m_x;
    this->m_y = circle.m_y;
}

void Circle::WhereAmI()
{
    std::cout << "Now I am in class Сircle" << std::endl;
}

void Circle::WhereAmIVirtual()
{
    std::cout << "Now I am in class Сircle" << std::endl;
}

Circle::~Circle()
{
    std::cout << "Деструктор наследуемого класса Circle" << std::endl;
}