#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include "myString.h"
#include <iostream>
#include <cstdarg>

using namespace std;


// Определение конструктора.
//MyString::MyString()   //по умолчанию 
//{		
//		m_pStr = nullptr;		
//}

MyString::MyString(const char* pName)
{	
		m_pStr = new char[strlen(pName) + 1];
		strcpy(m_pStr, pName);
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
MyString::MyString(MyString&& other) noexcept     //Перемещающий конструктор копирования
{
    delete[]this->m_pStr;
    this->m_pStr = other.m_pStr;    
    other.m_pStr = nullptr;
}
MyString::MyString(int memory)
{

	this->m_pStr = new char[memory];
    m_pStr[0] = 0;
}
MyString& MyString::operator=(MyString&& other)
{
    delete[]this->m_pStr;
    this->m_pStr = other.m_pStr;
    other.m_pStr = nullptr;

    return *this;
}
const char* MyString::GetString() const // определение константного метода
{	
		return m_pStr;		
}
const char* MyString::ConcatenationString(const char* pNewStr)
{
	if (m_pStr != nullptr)
	{
		strcat(m_pStr, pNewStr);		
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
    MyString str2(result);
    delete[] result;
    return str2;

   // return result;
}

// Определение деструктора.
MyString::~MyString()
{
	delete[] m_pStr;
}


