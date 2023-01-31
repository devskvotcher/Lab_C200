#pragma once
class Rect{
	
	int m_left, m_right, m_top, m_bottom;

	public:
		Rect()														// конструктор по умолчанию
		{
			m_left = 0;
			m_right = 1;
			m_top = 1;
			m_bottom = 0;

		}

				
		Rect(int left, int  right=1, int top=1, int bottom=0)				// конструктор с параметрами
		{
			if (right < left)
			{
				m_left = right;
				m_right = left;
			}
			else
			{
				m_left = left;
				m_right = right;
			}
			if (top > bottom)
			{
				m_top = bottom;
				m_bottom = top;
			}
			else
			{		
				m_top = top;
				m_bottom = bottom;
			}			
		}

		Rect(const Rect& other);
		
		void Correction();                                      // метод нормализации размеров

		//void printCoord();

		//void InflateRect(int dl=1, int dr=1, int dt=0, int db=0);

		void InflateRect(int dl = 1, int dr = 1);
		void InflateRect(int, int, int, int);
		
		void SetAll(int dl, int dr, int dt, int db);
	
		void GetAll(int& dl,int& dr,int& dt,int& db) const;

		Rect BoundingRect(const Rect&);

		~Rect()														// деструктор
		{

		}
};

 Rect BoundingRect(Rect, Rect );								// глобальная функция с передачей параметров по значению

 Rect BoundingRect2(const Rect&, const Rect&);								// Глобальная функция с передачей параметров по ссылке