// ����:
// ���������� ����������.

//#include "stdafx.h"	//���� �� ����������� �������������� ������������
					//������, ���������������� ��� �������
#include <tchar.h>
#include "Point.h"
#include <iostream>
#include "myString.h"
#define	  stop __asm nop
enum WD
{
	SUNDAY,
	MONDAY,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY
};
WD &operator+(WD &wd1, int x)
{
	int tmp = 0;
	//wd1 =static_cast<WD>(static_cast<int>(wd1)+ x);
	//std::cout << (static_cast<int>(wd1) > 6) ? static_cast<WD>((wd1 + x) % 6) : static_cast<WD>((wd1 + x));
//	if (static_cast<int>(wd1) + x > 6)
//	{
		tmp = static_cast<int>(wd1)+x;
		tmp %= 7;
		//t = static_cast<WD>(tmp);
		wd1 = static_cast<WD>(tmp);
//	}
//	else
//	{
//		tmp = static_cast<int>(wd1) + x;
//		wd1 = static_cast<WD>(tmp);
//	}
	//((wd1 + x) > 6) ? wd1 = static_cast<WD>((wd1 + x) % 6) : wd1 = static_cast<WD>((wd1 + x));
	//(static_cast<int>(wd1) > 6) ? tmp = (static_cast<int>(wd1 + x) % 6) : tmp = static_cast<int>((wd1 + x));
	//std::cout << tmp;
	//return t;
	return wd1;
}
//WD& operator+=(WD &wd1, int x)
//{
//	return wd1+x;
//}
std::ostream& operator<< (std::ostream& out, const WD& wd1)
{
	const char* day = nullptr;
	switch (static_cast<int>(wd1))
	{
	case 0:
		day = "�����������";
		break;
	case 1:
		day = "�����������";
		break;
	case 2:
		day = "�������";
		break;
	case 3:
		day = "�����";
		break;
	case 4:
		day = "�������";
		break;
	case 5:
		day = "�������";
		break;
	case 6:
		day = "�������";
		break;
	}
	out << "WeekDay:" << day;
	return out;
}
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Rus");
//////////////////////////////////////////////////////////////////////


	//������� 1
	//�������� ����� Point, ������� ����� ��������� ����������
	//"�����". �������� ����������� (������������) ������   

	//1a. "�����������" �������� += ���, ����� ��� ����������
	//�������� ���� pt2+=pt1; ������������
	//����������� ���������� �������� pt1 � pt2, � �����
	//������������� ��������������� ���������� ������� pt2 ���
	// � ������  pt2+=1; ��� ���������� ������� pt2 ������������� ��
	// ��������� ��������
	// (!) ���������� ��������� � ������� ������ ������ (�������� +=)
	//��������� ������������ ������ �������������� ���������
	{
		Point pt1(1,1);
		Point pt2(2,2);
		pt2+=pt1;
      	pt2+=1;
		Point pt3(3,3);
		pt2 += pt1 += pt3;
		stop
	}
	//1b. "�����������" �������� -= ���, ����� ��� ����������
	//�������� ���� pt2-=pt1; ����������
	//����������� ���������� �������� pt1 � pt2, � ��������
	//������������� ��������������� ���������� ������� pt2 ���
	// � ������  pt2-=1; ��� ���������� ������� pt2 ����������� ��
	// ��������� ��������
	//(!) ���������� ���������� ������� ���������� ������� (�������� -=)
	//��������� ������������ ������ �������������� ���������
	{
		Point pt1(1,1);
		Point pt2(2,2);
		pt2-=pt1;
      	pt2-=1;
		Point pt3(3,3);
   		pt2-=pt1-=pt3;
		stop
	}


 	//������� 2
	//2a. ����������� �������� + 
	//� ������� ������� ������, ��� ��� �������� 
	//���, ����� ����� �� ������������������ �����
	//���� ����������� ���������
	{
		Point pt1(1,1);
		Point pt2(2,2);
		Point pt3;

		pt3 = pt1 + 5;
      	pt3 = 2 + pt1;
		pt3 = pt1 + pt2;

	stop
	}
	//2b. ����������� �������� -
	// � �������  ���������� ������� (�������� -)
	//���, ����� ����� �� ������������������ �����
	//���� ����������� ���������
	{
		Point pt1(1,1);
		Point pt2(2,2);
		Point pt3;

		pt3 = pt1 - 5;
      	pt3 = 2 - pt1;
		pt3 = pt1 - pt2;
		stop
	}
	//������� 3
	// ����������� ������� �������� +/- 
	{
		Point pt1(1,1);
		Point pt3;

		pt3 = -pt1;  // � ������� ���������� �������,
		pt3 = +pt1;  // � ������� ������ ������ 
	}
	//������� 4. ����������� �������� << (������ � �����) ���
	// ������ Point  ����� �������, ����� ��� ������ ������������ ���������� �����
	{
		Point pt(10,20);
		std::cout << pt << std::endl;//��������, ���:x=10, y=20
		stop
	}



	//������� 5.���������� ���������  =.

//���������� � ������� ����� MyString.cpp � MyString.h
//������ MyString, �������������� ���� �� ���������� �������
// ����������� �������� ������������ ��� ������ MyString
//��������� ������������ ������ �������������� ���������

	{
		MyString s1("AAA"), s2;
		s2=s1;
		std::cout << s2 << std::endl;
		s1="CCC";
		std::cout << s1 << std::endl;
		s2= std::move(MyString("tmp"));
		std::cout << s2 << std::endl;
		s1= s1;
		std::cout << s1 << std::endl;
		stop
	}




	//������� 6. ����������� �������� << (������ � �����) ���
	//������ MyString ����� �������, ����� ��� ���������� ����������� ������
	//�� ����� ���� ��������:
	//contents:  "QWERTY"

	MyString s("QWERTY");
	std::cout<<s<< std::endl;


	stop


	//������� 7. ����������� ��������� + � += ��� ������ MyString ����� �������,
  	//����� ����������� ������������ �����
	{
	MyString s1("QWERTY"), s2("AAA"), s3, s4("BBB");
	s3 = s1+s2;
	std::cout << s3 << std::endl;    
	s4 += s1; 
	//������ �����������, ��� ���� ���������,��� �� ��������� �� �������,
	//�� ��� ����� ������ �� ������ ������������ ����
	std::cout << s4 << std::endl;
	stop
	}


	//������� 8. ����������� ���������  ����������� ��������� -- � ���������� ���������
	//��� ������ MyString ����� �������, ��� ���������� ���������� ������������ ������� � ������ ������� ���� ��������, 
	// ���������� ������� ���������� ��������, � ��� ���������� ���������� ������������ ������� � ������� �������.
	// ��� ������ ����� ��������������� ���������� ��������� <ctype.h>:
	//int  isupper( int C);
	//int  islower( int C);
	//int  toupper( int C);
	//int  tolower( int C);
	{

		MyString str1("Hello World!!!");
		std::cout << "�������� ������" << str1 << std::endl;
		MyString str1_2 = str1--;
		std::cout << "str1_2, ������ �� ���������� ����" << str1_2 << std::endl;
		std::cout << "str1 ���������" << str1 << std::endl;
		//std::cout << "��������� ������" << str1_2 << std::endl;
		MyString str2("Hello World!");
		MyString str2_2 = ++str2;
		std::cout << "��������� �������" << str2_2 << std::endl;
		stop


	}
	//������� 9. ����������� ��������� + � +=   ��� enum WEEKDAY
	{
		enum WD wd1 = SATURDAY;
		wd1 = wd1 + 2;
		WD wd2 = wd1 + 1;
//		wd2 += 2;
	}
	stop
	//������� 10. ����������� �������� << (������ � �����) ���
	//������������ WD ����� �������, ����� ��� ������ ������������ ������, 
	// ��������������� ����������� ���������:
	{
		enum WD wd = SATURDAY;
		std::cout << wd << std::endl;//��������, ���:saturday
		stop
	}

	return 0;
}//endmain

