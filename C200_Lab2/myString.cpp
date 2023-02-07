#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include "myString.h"
#include <iostream>
#include <cstdarg>

using namespace std;


// ����������� ������������.
//MyString::MyString()   //�� ��������� 
//{		
//		m_pStr = nullptr;		
//}

MyString::MyString(const char* pName)
{	
		m_pStr = new char[strlen(pName) + 1];
		strcpy(m_pStr, pName);
}

MyString::MyString(const MyString& other)			// ����������� �����������
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
MyString::MyString(MyString&& other) noexcept     //������������ ����������� �����������
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
const char* MyString::GetString() const // ����������� ������������ ������
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
    while (strcmp(nextStr, "*") != 0) {    // ����� ��������� ������-��������� ��� ����� �������� �������
        int nextStrLength = strlen(nextStr); // ������ ����� = ����� ������ ������ ��� ����� '\0' + ����� ����� ������
        // ��� ����� '\0' + ����� ��� '\0'
        char* newResult = new char[length + nextStrLength + 1];
        // ������� ������� ������ ������ � ����� �����
        // ������� � ��������� [0 .. length - 1] - ������� ������� ������
        // �� ������� [length] - '\0'
        strcpy(newResult, result); //������ � �������� ������ ������������ ������ ����� ���������� ������

        // ������� ��������� ������-�������� � ����� �����
        // newResult + length ������, ��� �� �������� ��������� ������� � �������
        // [length], �� ������� � ��� ������ ������� '\0' ����� �������� strcpy.
        // ��� �� �� �����, ��� ��� � ������ ������ ���� ������ ���� '\0', � ��
        // ������ ���� � ����� ������, ������� �������������� ���.
        // �� ������� ������ ������ [length .. length + nextStrLength] �����
        // �������� ������� [0 .. nextStrLength] ������ nextStr, ������� '\0'.
        strcpy_s(newResult + length, nextStrLength + 1, nextStr);

        // ��� ��� �� �������� ����� ������ ��� ����� �����, ����������� ������
        // � ��������� �������� ���������� result � length ��� ���������� �����.
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

// ����������� �����������.
MyString::~MyString()
{
	delete[] m_pStr;
}


