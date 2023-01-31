#include "myRect.h"
#include <iostream>

/*void Rect::printCoord()
{
	std::cout << Rect::m_left << " " << Rect::m_right << " " << Rect::m_top << " " << Rect::m_bottom << "\n";
}*/

Rect::Rect(const Rect& other)
{
	m_left = other.m_left;
	m_right = other.m_right;
	m_top = other.m_top;
	m_bottom = other.m_bottom;
}

void Rect::Correction()											// метод нормализации размеров
{
	int temp;
	if (m_right < m_left)
	{
		temp = m_right;
		m_right = m_left;
		m_left = temp;		
	}	
	if (m_top > m_bottom)
	{
		temp = m_bottom;
		m_bottom = m_top;
		m_top = temp;	
	}	
}


/*void Rect::InflateRect(int dl, int dr, int dt, int db)
{		
	m_left = m_left - dl;
	m_right = m_right + dr;
	m_top = m_top - dt;
	m_bottom = m_bottom + db;
	Correction();
}
*/

void Rect::InflateRect(int dl, int dr)
{
	m_left = m_left - dl;
	m_right = m_right + dr;
	Correction();
}

void Rect::InflateRect(int dl , int dr, int dt, int db)
{
	m_left = m_left - dl;
	m_right = m_right + dr;
	m_top = m_top - dt;
	m_bottom = m_bottom + db;
	Correction();
}

void Rect::SetAll(int dl, int dr, int dt, int db)
{
	m_left = dl;
	m_right = dr;
	m_top = dt;
	m_bottom =db;
}

void Rect::GetAll(int& dl,int& dr,int& dt,int& db)  const
{
	dl = this->m_left;
	dr = this->m_right;
	dt = this->m_top;
	db = this->m_bottom;
}

Rect Rect::BoundingRect(const Rect& r1)  
{	
	Rect rect;

	rect.m_left = (r1.m_left > this->m_left)?this->m_left:r1.m_left;
	rect.m_right = (r1.m_right > this->m_right) ? r1.m_right : this->m_right;
	rect.m_top=(r1.m_top > this->m_top) ? this->m_top : r1.m_top;
	rect.m_bottom=(r1.m_bottom > this->m_bottom) ? r1.m_bottom : this->m_bottom;
	
	return rect;
}



Rect BoundingRect(Rect r1, Rect r2)
{	
	Rect rect;
	int t_l1, t_l2, t_r1, t_r2, t_t1, t_t2, t_b1, t_b2;  // переменные куда записываем координаты двух прямоугольников 
	r1.GetAll(t_l1, t_r1, t_t1, t_b1);
	r2.GetAll(t_l2, t_r2, t_t2, t_b2);
	int t_l, t_r, t_t, t_b;
	t_l = (t_l1 > t_l2) ? t_l2 : t_l1;
	t_r = (t_r1 > t_r2) ? t_r1 : t_r2;
	t_t = (t_t1 > t_t2) ? t_t2 : t_t1;
	t_b = (t_b1 > t_b2) ? t_b1 : t_b2;
	rect.SetAll(t_l, t_r, t_t, t_b);
	return rect;
}

Rect  BoundingRect2(const Rect& r1, const Rect& r2)
{
	Rect rect;	
	int t_l1, t_l2, t_r1, t_r2, t_t1, t_t2, t_b1, t_b2;
	r1.GetAll(t_l1, t_r1, t_t1, t_b1);
	r2.GetAll(t_l2, t_r2, t_t2, t_b2);
	int t_l, t_r, t_t, t_b;
	t_l = (t_l1 > t_l2) ? t_l2 : t_l1;
	t_r = (t_r1 > t_r2) ? t_r1 : t_r2;
	t_t = (t_t1 > t_t2) ? t_t2 : t_t1;
	t_b = (t_b1 > t_b2) ? t_b1 : t_b2;
	rect.SetAll(t_l, t_r, t_t, t_b);
	return rect;
}