#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include "myString.h"
#include <iostream>
#include <cstdarg>
#include <ctype.h>
using namespace std;


// Определение конструктора.
MyString::MyString()   //по умолчанию 
{		
		m_pStr = nullptr;		
}

MyString::MyString(const char* pName)
{	
		m_pStr = new char[strlen(pName) + 1];
		strcpy(m_pStr, pName);
}
MyString& MyString::operator=(const char* str)
{
    m_pStr = new char[strlen(str) + 1];
    strcpy(m_pStr, str);
    return *this;
}
MyString::MyString(const MyString& other)			// конструктор копирования
{
	if (other.m_pStr)
	{
		m_pStr = new char[strlen(other.m_pStr) + 1];
		strcpy(m_pStr, other.m_pStr);
	}
	else
	{
		m_pStr = 0;
	}
	
}

MyString::MyString(int memory)
{

	this->m_pStr = new char[memory];
	
}

const char* MyString::GetString() const // определение константного метода
{	
		return m_pStr;		
}
const char* MyString::ConcatenationString(const char* pNewStr)
{
	if (m_pStr != nullptr)
	{
		strcpy(m_pStr, strcat(m_pStr, pNewStr));		
	}
	return m_pStr;	
}

const char* MyString::SetNewString(const char* pNewString)
{
	delete[] m_pStr;
	m_pStr = new char[strlen(pNewString) + 1];
	strcpy(m_pStr, pNewString);
	return m_pStr;
}

MyString MyString::f(const char* first, ...)
{
    if (strcmp(first, "*") == 0)
        return MyString();

    char* result = nullptr;
    int length = 0;

    length = strlen(first);
    result = new char[length + 1];
    strcpy(result, first);

    va_list args;
    va_start(args, first);

    const char* nextStr = va_arg(args, const char*);
    while (strcmp(nextStr, "*") != 0) {    // длина следующей строки-аргумента без учета нулевого символа
        int nextStrLength = strlen(nextStr); // размер равен = длина старой строки без учета '\0' + длина новой строки
        // без учета '\0' + место под '\0'
        char* newResult = new char[length + nextStrLength + 1];
        // сначала копирую старую строку в новый буфер
        // символы с индексами [0 .. length - 1] - символы старого буфера
        // на позиции [length] - '\0'
        strcpy(newResult, result); //ПОЧЕМУ В КАЧЕСТВЕ ДЛИИНЫ ИСПОЛЬЗУЕТСЯ ПРОСТО ДЛИНА ПРЕДЫДУЩЕЙ СТРОКИ

        // копирую следующую строку-аргумент в новый буфер
        // newResult + length значит, что мы начинаем вставлять символы с позиции
        // [length], на которой у нас сейчас записан '\0' после прошлого strcpy.
        // Нам он не нужен, так как в строке должен быть только один '\0', и он
        // должен быть в конце строки, поэтому перезаписываем его.
        // На позиции нового буфера [length .. length + nextStrLength] будут
        // записаны символы [0 .. nextStrLength] строки nextStr, включая '\0'.
        strcpy_s(newResult + length, nextStrLength + 1, nextStr);

        // Так как мы выделили новую память под новый буфер, освобождаем старую
        // и обновляем значения переменных result и length для следующего цикла.
        delete[] result;
        result = newResult;
        length += nextStrLength;
        nextStr = va_arg(args, const char*);
    }

    va_end(args);
    //return MyString(result);
    return MyString(result);
}

MyString& MyString::operator=(const MyString& str2)
{
    // проверка на самоприсваивание
    if (this == &str2)
        return *this;

    // если данные существуют в текущей строке, удалить их
    if (m_pStr)
    {
        delete[] m_pStr;
    }

    int m_length = strlen(str2.m_pStr)+1;

    // копируем данные из str в неявный объект
    m_pStr = new char[strlen(str2.m_pStr) + 1];

    for (int i = 0; i < m_length; ++i)
        m_pStr[i] = str2.m_pStr[i];

    // возвращаем существующий объект,
    // можно было включить этот оператор в цепочку
    return *this;
}
std::ostream& operator<< (std::ostream& out, const MyString& str)
{
    out << "Contains:" << str.m_pStr;
    return out;
}
//MyString& operator+(MyString& str1, const MyString& str2)
//{
//    char* newStr = nullptr;    
//    newStr = new char[strlen(str1.GetString()) + strlen(str2.GetString() + 1)];
//    strcpy(newStr, str1.GetString());
//    strcat(newStr, str2.GetString());    
//    str1.SetNewString(newStr);
//    return str1;
//}
MyString operator+(MyString& str1, const MyString& str2)
{
    char* newStr = nullptr;
    newStr = new char[strlen(str1.GetString()) + strlen(str2.GetString() + 1)];
    strcpy(newStr, str1.GetString());
    strcat(newStr, str2.GetString());
    return MyString(newStr);
}
MyString& operator+=(MyString& str1, const MyString& str2)
{
    char* newStr = nullptr;
    newStr = new char[strlen(str1.GetString()) + strlen(str2.GetString() + 1)];
    strcpy(newStr, str1.GetString());
    strcat(newStr, str2.GetString());
    str1.SetNewString(newStr);
    return str1;
}
MyString& MyString::operator--(int c)
{
    for (size_t i = 0; i < strlen(m_pStr); i++)
    {
        m_pStr[i] = tolower(static_cast<int>(m_pStr[i]));
    }
    return *this;
}
MyString& operator++(MyString& str)
{
    char* tmp = nullptr;
    tmp = new char[strlen(str.GetString())+1];
    strcpy(tmp, str.GetString());
    
    for (size_t i = 0; i < strlen(str.GetString()); i++)
    {
        tmp[i] = toupper(static_cast<int>(tmp[i]));
    }
    str.SetNewString(tmp);
    return str;
}
// Определение деструктора.
MyString::~MyString()
{
	delete[] m_pStr;
}


