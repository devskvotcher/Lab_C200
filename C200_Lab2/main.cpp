// ����:
// ������� ������������. ����������� �������. ����������� ������.
// ������� ����.


#include <tchar.h>
#include <iostream>
#include "myString.h"
#include "Shape.h"
#define	  stop __asm nop

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Rus");
	std::cout << "������� 1.������ �������� ������.\n";
	//������� 1.������ �������� ������.
	{
		//�������� � ������������������ ������ ar �� ��������
		// ���� MyString. 
		//MyString str1[N]= {...};
		{
		const int N = 3;
		MyString str1[N] = { "C++", "C", "hard" };
		//�������� - ������ �����-������ ������
		for (size_t i = 0; i < sizeof(str1)/sizeof(str1[0]); i++)
		{
			std::cout << str1[i].GetString() << std::endl;
		}
		}
		//�������� ������ const int N=5; , �� ������� ������ ���������������.
		{
			const int N = 5;
			MyString str1[N] = { "C++", "C", "hard" };
			for (size_t i = 0; i < N; i++)
			{			
				std::cout << str1[i].GetString() << std::endl;
			}
		}			
	}
	stop


		//������� 2.������ ���������� �� ������� ������.
	{
		std::cout << "������� 2.������ ���������� �� ������� ������.\n";
		//�������� � ������������������ ������ arPtr �� N
		//���������� �� ������� ���� MyString (���� ������� 
		//��������� �����������!).
		const int N=3;
		MyString *arPtr[N]={new MyString("C++"), new MyString("C"), new MyString("hard")};
			for (size_t i = 0; i < N; i++)
			{
				std::cout<<arPtr[i]->GetString()<< std::endl;
			}
	//������ �����-������ ������

   	//�������� ������ const int N=5; , �� ������� ������ ���������������.
			{
				const int N = 5;
				MyString* arPtr[N] = { new MyString("C++"), new MyString("C"), new MyString("hard") };
				//for (size_t i = 3; i < N; i++)
				/*{
					arPtr[i] = new MyString();
				}*/
				
				for (size_t i = 0; i < N; i++)
				{
					if (arPtr[i] != nullptr)
					{
						std::cout << arPtr[i]->GetString() << std::endl;
					}
					
				}
				for (size_t i = 0; i < N; i++)
				{
					delete arPtr[i];
				}
			}

	}
		stop
		//�::A(){int x, int y}

	//������� 3.������� ������������.��������� ������������,
	// ������������ � ������� �����.

	//�������� �������� �������:
	//������� ����� Shape (������� ��������� ����� ������)
	//� ��� ����������� ������ Rect � Circle.
	//���������: ����� ������ � ������ ����� ������ � �������
	//� ����������� ������ (��������, ����� ������ ����� �������
	//������� => � ������� ������ ����� ������ ����������, �������
	//����� ���������� ���� ������.
	//���������: ��� �������� ����� �������� ������������ (RED,GREEN,BLUE...);



	//� ������������� ����������� ������� ������������� ��������
	//���������-����� ������������ �������� ������.
	//��� �������� � ����������� ������� ������������ ���� ����������
	//������������������ ������� ������������� � ������������ ��������
	//� ������������ �������
		std::cout << "Create a Shape-object" << std::endl;
		Shape shape(Shape::COLOR::RED);
		std::cout << "Create a Rect-object" << std::endl;
		Rect rect(2,4,2,4, Shape::COLOR::BLUE);
		std::cout << "Create a Circle-object" << std::endl;
		Circle circle(2, 4, 2, Shape::COLOR::WHITE);
//--------------------//NB.������� ������������������ ������� ������������� � ������������	



		stop
			//////////////////////////////////////////////////////////////////////

				//������� 4.����������� �������.
				//4�) ������������� ������ Shape,Rect � Circle:
				//�������� � ������ ����� public ����� void WhereAmI().
				//���������� ������ ������� ������ �������� ��������� 
				//���������� ���� "Now I am in class Shape(Rect ��� Circle)".
				//��������� ����������� ��������, ��������� ���������.

			std::cout << "������� 4�" << std::endl;
	{
		Shape s(Shape::COLOR::RED);
		Rect r(2, 4, 2, 4, Shape::COLOR::BLUE);
		Circle c(2, 4, 2, Shape::COLOR::WHITE);

		std::cout << "����� ����������� ������� ��������� � �������" << std::endl;
		//����� ������ ������ ���������� � ��������� ��������???
		s.WhereAmI();	//	������ Shape
		r.WhereAmI();	//	������ Shape, �� ���������������� � ������ Circle
		c.WhereAmI();	//	������ Shape, �� ���������������� � ������ Rect
		stop

			std::cout << "����� ����������� ���������" << std::endl;
		Shape* pShape = &s;
		Shape* pRect = &r;
		Shape* pCircle = &c;
    	pShape->WhereAmI();	//	������ Shape
		pRect->WhereAmI();	//	������ Rect, ��� � ��������� �������� ������ �������� ������ �� ����������� �����.
		pCircle->WhereAmI(); //	������ Circle, ��� � ��������� �������� ������ �������� ������ �� ����������� �����.
		stop

			std::cout << "����� ����������� ������" << std::endl;
		Shape &rShape = s;
		Shape& rRect = r;
		Shape& rCircle = c;
        rShape.WhereAmI();	//����� ����������� rShape	����� Shape
		rRect.WhereAmI();	//����� �����������	rRect	����� Rect
		rCircle.WhereAmI(); //����� ����������� rCircle	����� Circle
		stop
	}
	std::cout << "������� 4�" << std::endl;
	//4�) �������� � ������� � ����������� ������ �����������
	// ����� WhereAmIVirtual(). �� �������� � 4� ��������
	// ����������� ����� ����������� ��������, ���������� �
	// ������, ������������ � ���������� ���������.
	//��������� ����� ��������, ��������� �������.
	{
		Shape s(Shape::COLOR::RED);
		Rect r(2, 4, 2, 4, Shape::COLOR::BLUE);
		Circle c(2, 4, 2, Shape::COLOR::WHITE);

		std::cout << "����� ����������� ������� ��������� � �������" << std::endl;
		//����� ������ ������ ���������� � ��������� ��������???
		s.WhereAmIVirtual();	//	������ Shape
		r.WhereAmIVirtual();	//	������ Shape, �� ���������������� � ������ Circle
		c.WhereAmIVirtual();	//	������ Shape, �� ���������������� � ������ Rect
		stop

			std::cout << "����� ����������� ���������" << std::endl;
		Shape* pShape = &s;
		Shape* pRect = &r;
		Shape* pCircle = &c;
		pShape->WhereAmIVirtual();	//	������ Shape
		pRect->WhereAmIVirtual();	//	������ Rect, ��� � ��������� �������� ������ �������� ������ �� ����������� �����.
		pCircle->WhereAmIVirtual(); //	������ Circle, ��� � ��������� �������� ������ �������� ������ �� ����������� �����.
		stop

			std::cout << "����� ����������� ������" << std::endl;
		Shape& rShape = s;
		Shape& rRect = r;
		Shape& rCircle = c;
		rShape.WhereAmIVirtual();	//����� ����������� rShape	����� Shape
		rRect.WhereAmIVirtual();	//����� �����������	rRect	����� Rect
		rCircle.WhereAmIVirtual(); //����� ����������� rCircle	����� Circle
		stop
	}


//////////////////////////////////////////////////////////////////////
//*
	std::cout << "������� �5.����������� �����������." << std::endl;
	{
	//������� 5.����������� �����������.
	//������������� ������:
	//a) ������� ���������������
	// ����������� (��� ��������� ����� virtual).
	//���������� ������� �����������
	//������ �������� ��������� ���������� ����
	// "Now I am in Shape's destructor!" ���
	// "Now I am in Rect's destructor!"
	//��������� ��������. ��������� ���������.
		Shape s(Shape::COLOR::RED);
		Rect r(2, 4, 2, 4, Shape::COLOR::BLUE);
		Circle c(2, 4, 2, Shape::COLOR::WHITE);
		/*
		* ����������� �������� ������ Shape
		* 
				����������� �������� ������ Shape
					����������� ������������ ������ Rect

						����������� �������� ������ Shape
							����������� ������������ ������ Circle

							���������� ������������ ������ Circle
						���������� �������� ������ Shape

					���������� ������������ ������ Rect
				���������� �������� ������ Shape

			���������� �������� ������ Shape
			���������� ������������ ������ Circle
			���������� �������� ������ Shape
			���������� ������������ ������ Rect
			���������� �������� ������ Shape
			���������� �������� ������ Shape
		*/
	// b) �������� � ���������� ������������ �������� ����� virtual 
	//��������� ��������.��������� �������.
		/*
		* ����������� �������� ������ Shape
				����������� �������� ������ Shape
						����������� ������������ ������ Rect

							����������� �������� ������ Shape
								����������� ������������ ������ Circle
								���������� ������������ ������ Circle
							���������� �������� ������ Shape
						���������� ������������ ������ Rect
				���������� �������� ������ Shape

���������� �������� ������ Shape
���������� ������������ ������ Circle
���������� �������� ������ Shape
���������� ������������ ������ Rect
���������� �������� ������ Shape
���������� �������� ������ Shape
		*/
	//------//NB-------������� ������-�� �� ����������, ������ ��� ������ ���� � ����������� ���, ��� ��� ������������
		//����������� �������� ������ ������, ������ ��� ���������� �������� ������ �� ����� � ������������� �����������
		//������������ ������
	
	//���������: ����� ������������ ���������� � ��������� ������?
		//���� � ������������� ������� �����-�� �������������
		//�� ������� - ����������
		//���� �� ��������, ��� � ����������� ��������� ����-��
		//�� ������� - ��������

	
		Rect r(2, 4, 2, 4, Shape::COLOR::BLUE);
		//Shape* ar[] = { new Shape(r), new Rect(r), new Circle(r), new Circle() };
		//�������� ��� ������� �������� ������� ����� WhereAmIVirtual()
	}
		
	

	stop
//*/

/*
	//������� 6*. � ��� ����������� ������� 1) � 2)
	{
		Shape* pShapes = new Rect[10];//1)
		Rect* pRects = new Rect[10];//2)

		//���������� ������� ����� WhereAmIVirtual() ��� ������� �������� ����� �������� -
		//� ��� ����������� ��������???


		//���������� ����������� ����������� ������

	}

*/

//////////////////////////////////////////////////////////////////////
/*
	//������� 7.����������� ������� � �������� ���������� ������� ���������. 

	{
		Rect r(...);
		Shape* p = &r;	
		p->WhereAmIVirtual();//...
		stop
	
		
		//4a �������� ���������� ������� ���������.
		//����������� ������� r � ��������� p �������� ����������� �������
		//WhereAmIVirtual()������ Shape
		
		
	}
*/

//////////////////////////////////////////////////////////////////////
/*
	//������� 8.����� ����������� �������. 
	//������� � ������� ����� ����� void Inflate(int); ���������:
	//����� �� ����������� ����� ����� ��� �������� ������? => ��� ��� ����� ��������.
	//���������� ���� ����� ��� ����������� �������.
	{
		Rect r(...);
		Shape* p = &r;
		p->Inflate(5);
		Circle c(...);
		p = &c;
		p->Inflate(5);
	}
*/


//////////////////////////////////////////////////////////////////////
	//������� 9. �������� ���������� �������, ������� ����� ��������� �����
	//���������� ���������� �� ������, � ���������� ������ MyString,
	//� ������� ������ ����� ������������� ����������

////////////////////////////////////////////////////////////////////////
/*
	//������� 10.����������� (union) C++. ������� ����.
	//1.
	//�������� ��������� ������ ��� ��������� ������������� �������� �����:
	//Bin - ��� ��������� �������������
	//Hex - ��� ����������������� �������������
	//Oct - ��� ������������� �������������.
	//��������� 1: - ��� �������� ����������� ������� ����.
	//��������� 2: - ������������� � ����� ��������������� ������� ���� �� ������,
	//��� ��� ��� ��� ����� ������� ����������� (union).
	//2.
	//� ������ ������ ������� ����� Show, ������� ������ �������� �������� �
	//��������������� ����
	//3.
	//����������� ����������� MyByte ������������ ������������ ����������� ��������������
	//����� � ��� �� ��������� ��-�������:
	//�) ��������: ����������, �����������������, ������������, �������� �������� ����� 
	//          � ����� ������, ��������������� ��������� �������� (���� ���� ������������);
	//�) �������� ��������� (��������� ����������� ���������) �����������������,
	//			������������, �������� �����;
	//�) �������� ��������� ��������, ������������ ��� ����������������� �����;

	MyByte byte(0x1f);
	byte.ShowHex();
	byte.ShowBin();
	//...


*/
	return 0;
}//endmain

