#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include "myString.h"

using namespace std;


// Определение конструктора.
//MyString::MyString()   //по умолчанию 
//{
//		const char* ptr = "nullptr";
//		m_pStr = new char[strlen(ptr) + 1];
//		strcpy(m_pStr, ptr);
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

const char* MyString::GetString() const // определение константного метода
{	
		return m_pStr;		
}
		


const char* MyString::SetNewString(const char* pNewString)
{
	delete[] m_pStr;
	m_pStr = new char[strlen(pNewString) + 1];
	strcpy(m_pStr, pNewString);
	return m_pStr;
}



// Определение деструктора.
MyString::~MyString()
{
	delete[] m_pStr;
}
