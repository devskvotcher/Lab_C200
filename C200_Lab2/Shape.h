#pragma once

//Возьмем фигуру, которую описывает базовый класс четерехугольник.
class Shape
{
public:
    enum COLOR
    {
        RED, GREEN, BLUE, BLACK, WHITE
    };
protected:
   //unsigned int m_left, m_right, m_top, m_bottom; //строка-член класса, определяющая стороны фигуры
    COLOR color;	//строка-член класса, определяющая цвет фигуры
public:
    Shape(COLOR x);
    void WhereAmI();
    virtual void WhereAmIVirtual();
    //virtual void Inflate(int x)=0;
    virtual void Inflate(int x);
    virtual ~Shape();
};
//Возьмем фигуру, которую описывает производный класс прямоугольник.
class Rect:public Shape
{
    friend class Circle;
protected:
    unsigned int m_sideA, m_sideB, m_sideC, m_sideD;
public:
    Rect(unsigned int sideA, unsigned int sideB, unsigned int sideC, unsigned int sideD, COLOR color);    //Конструктор по умолчанию
    Rect(const Rect& rect);     //Конструктор копирования
    void WhereAmI();
    void WhereAmIVirtual() override;
    int GetsideA();
    int GetsideD();
    void Inflate(int x) override;
	
    virtual ~Rect();
};
//Возьмем фигуру, которую описывает производный класс круг.
class Circle :public Shape
{
    friend class Rect;
protected:
    unsigned int m_radius, m_x, m_y;
public:
    Circle();
    Circle(unsigned int r, unsigned int x, unsigned int y, COLOR color);   //Конструктор по умолчанию
    Circle(const Circle& circle);                    //Конструктор копирования
    Circle(const Rect& r);
    void WhereAmI();
    void WhereAmIVirtual() override;
    void Inflate(int x) override;
    virtual ~Circle();

};

