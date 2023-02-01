enum COLOR
{ RED, GREEN, BLUE, BLACK, WHITE
};
//Возьмем фигуру, которую описывает базовый класс четерехугольник.
class Shape
{
protected:
    unsigned int m_left, m_right, m_top, m_bottom; //строка-член класса, определяющая стороны фигуры
    COLOR *color;	//строка-член класса, определяющая цвет фигуры
public:
    Shape(COLOR* x, unsigned int right, unsigned int left, unsigned int bottom, unsigned int top);
    ~Shape();
};
//Возьмем фигуру, которую описывает производный класс прямоугольник.
class Rect:public Shape
{
    
public:
	Rect(): Shape(* x,  right,  left,  bottom, top);
	~Rect(): Shape();
};
//Возьмем фигуру, которую описывает производный класс круг.
class Rect :public Shape
{

};

