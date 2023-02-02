#pragma once

//������� ������, ������� ��������� ������� ����� ���������������.
class Shape
{
public:
    enum COLOR
    {
        RED, GREEN, BLUE, BLACK, WHITE
    };
protected:
   //unsigned int m_left, m_right, m_top, m_bottom; //������-���� ������, ������������ ������� ������
    COLOR color;	//������-���� ������, ������������ ���� ������
public:
    Shape(COLOR x);
    void WhereAmI();
    virtual void WhereAmIVirtual();
    virtual ~Shape();
};
//������� ������, ������� ��������� ����������� ����� �������������.
class Rect:public Shape
{
protected:
    unsigned int m_sideA, m_sideB, m_sideC, m_sideD;
public:
    Rect(unsigned int sideA, unsigned int sideB, unsigned int sideC, unsigned int sideD, COLOR color);    //����������� �� ���������
    Rect(const Rect& rect);     //����������� �����������
    void WhereAmI();
    void WhereAmIVirtual() override;
    

	
    virtual ~Rect();
};
//������� ������, ������� ��������� ����������� ����� ����.
class Circle :public Shape
{
protected:
    unsigned int m_radius, m_x, m_y;
public:
    Circle();
    Circle(unsigned int r, unsigned int x, unsigned int y, COLOR color);   //����������� �� ���������
    Circle(const Circle& circle);                    //����������� �����������
    void WhereAmI();
    void WhereAmIVirtual() override;
    virtual ~Circle();

};

