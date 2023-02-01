enum COLOR
{ RED, GREEN, BLUE, BLACK, WHITE
};
//������� ������, ������� ��������� ������� ����� ���������������.
class Shape
{
protected:
    unsigned int m_left, m_right, m_top, m_bottom; //������-���� ������, ������������ ������� ������
    COLOR *color;	//������-���� ������, ������������ ���� ������
public:
    Shape(COLOR* x, unsigned int right, unsigned int left, unsigned int bottom, unsigned int top);
    ~Shape();
};
//������� ������, ������� ��������� ����������� ����� �������������.
class Rect:public Shape
{
    
public:
	Rect(): Shape(* x,  right,  left,  bottom, top);
	~Rect(): Shape();
};
//������� ������, ������� ��������� ����������� ����� ����.
class Rect :public Shape
{

};

