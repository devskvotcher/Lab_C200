// Темы:
// Перегрузка операторов.

//#include "stdafx.h"	//если Вы используете предкомпиляцию заголовочных
					//файлов, раскомментируйте эту строчку
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
		day = "Воскресенье";
		break;
	case 1:
		day = "Понедельник";
		break;
	case 2:
		day = "Вторник";
		break;
	case 3:
		day = "Среда";
		break;
	case 4:
		day = "Четверг";
		break;
	case 5:
		day = "Пятница";
		break;
	case 6:
		day = "Суббота";
		break;
	}
	out << "WeekDay:" << day;
	return out;
}
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Rus");
//////////////////////////////////////////////////////////////////////


	//Задание 1
	//Создайте класс Point, который будет содержать координаты
	//"точки". Объявите конструктор (конструкторы) класса   

	//1a. "Перегрузите" оператор += так, чтобы при выполнении
	//операции типа pt2+=pt1; складывались
	//одноименные переменные объектов pt1 и pt2, а сумма
	//присваивалась соответствующим переменным объекта pt2 или
	// в случае  pt2+=1; обе переменные объекта pt2 увеличивались на
	// указанное значение
	// (!) Перегрузку выполните с помощью метода класса (оператор +=)
	//Проверьте корректность работы перегруженного оператора
	{
		Point pt1(1,1);
		Point pt2(2,2);
		pt2+=pt1;
      	pt2+=1;
		Point pt3(3,3);
		pt2 += pt1 += pt3;
		stop
	}
	//1b. "Перегрузите" оператор -= так, чтобы при выполнении
	//операции типа pt2-=pt1; вычитались
	//одноименные переменные объектов pt1 и pt2, а разность
	//присваивалась соответствующим переменным объекта pt2 или
	// в случае  pt2-=1; обе переменные объекта pt2 уменьшались на
	// указанное значение
	//(!) Перегрузку выполнитес помощью глобальной функции (оператор -=)
	//Проверьте корректность работы перегруженного оператора
	{
		Point pt1(1,1);
		Point pt2(2,2);
		pt2-=pt1;
      	pt2-=1;
		Point pt3(3,3);
   		pt2-=pt1-=pt3;
		stop
	}


 	//Задание 2
	//2a. Перегрузите оператор + 
	//с помощью методов класса, где это возможно 
	//так, чтобы любая из закомментированных строк
	//кода выполнялась корректно
	{
		Point pt1(1,1);
		Point pt2(2,2);
		Point pt3;

		pt3 = pt1 + 5;
      	pt3 = 2 + pt1;
		pt3 = pt1 + pt2;

	stop
	}
	//2b. Перегрузите оператор -
	// с помощью  глобальных функций (оператор -)
	//так, чтобы любая из закомментированных строк
	//кода выполнялась корректно
	{
		Point pt1(1,1);
		Point pt2(2,2);
		Point pt3;

		pt3 = pt1 - 5;
      	pt3 = 2 - pt1;
		pt3 = pt1 - pt2;
		stop
	}
	//Задание 3
	// Перегрузите унарный оператор +/- 
	{
		Point pt1(1,1);
		Point pt3;

		pt3 = -pt1;  // с помощью глобальной функции,
		pt3 = +pt1;  // с помощью метода класса 
	}
	//Задание 4. Перегрузите оператор << (вывода в поток) для
	// класса Point  таким образом, чтобы при выводе отображались координаты точки
	{
		Point pt(10,20);
		std::cout << pt << std::endl;//например, так:x=10, y=20
		stop
	}



	//Задание 5.Перегрузка оператора  =.

//Подключите к проекту файлы MyString.cpp и MyString.h
//класса MyString, разработанного Вами на предыдущем занятии
// Перегрузите оператор присваивания для класса MyString
//Проверьте корректность работы перегруженного оператора

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




	//Задание 6. Перегрузите оператор << (вывода в поток) для
	//класса MyString таким образом, чтобы при выполнении приведенной строки
	//на экран было выведено:
	//contents:  "QWERTY"

	MyString s("QWERTY");
	std::cout<<s<< std::endl;


	stop


	//Задание 7. Перегрузите операторы + и += для класса MyString таким образом,
  	//чтобы происходила конкатенация строк
	{
	MyString s1("QWERTY"), s2("AAA"), s3, s4("BBB");
	s3 = s1+s2;
	std::cout << s3 << std::endl;    
	s4 += s1; 
	//Марина Геннадьевна, вот если исправить,как мы исправили на занятии,
	//то все время ошибки по поводу переполнения кучи
	std::cout << s4 << std::endl;
	stop
	}


	//Задание 8. Перегрузите операторы  постфиксный декремент -- и префиксный инкремент
	//для класса MyString таким образом, при применении декремента производился перевод в нижний регистр всех символов, 
	// являющихся буквами латинского алфавита, а при применении инкремента производился перевод в верхний регистр.
	// при работе можно воспользоваться следующими функциями <ctype.h>:
	//int  isupper( int C);
	//int  islower( int C);
	//int  toupper( int C);
	//int  tolower( int C);
	{

		MyString str1("Hello World!!!");
		std::cout << "Исходная строка" << str1 << std::endl;
		MyString str1_2 = str1--;
		std::cout << "str1_2, должна не поменяться была" << str1_2 << std::endl;
		std::cout << "str1 декремент" << str1 << std::endl;
		//std::cout << "Результат метода" << str1_2 << std::endl;
		MyString str2("Hello World!");
		MyString str2_2 = ++str2;
		std::cout << "Результат функции" << str2_2 << std::endl;
		stop


	}
	//Задание 9. Перегрузите операторы + и +=   для enum WEEKDAY
	{
		enum WD wd1 = SATURDAY;
		wd1 = wd1 + 2;
		WD wd2 = wd1 + 1;
//		wd2 += 2;
	}
	stop
	//Задание 10. Перегрузите оператор << (вывода в поток) для
	//перечисления WD таким образом, чтобы при выводе отображалась строка, 
	// соответствующая именованной константе:
	{
		enum WD wd = SATURDAY;
		std::cout << wd << std::endl;//например, так:saturday
		stop
	}

	return 0;
}//endmain

