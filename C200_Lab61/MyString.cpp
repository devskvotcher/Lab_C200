#define _CRT_SECURE_NO_WARNINGS
#include "MyString.h"
#include <iostream>
using namespace std;

MyString::MyString(const char* str) {
    char* str1 = new char[strlen(str)+1];
    strcpy(str1, str);
    m_pMyCounter = Counter::init(str1);
    delete[]str1;
}

void MyString::print() {
    std::cout << "Строка" << m_pMyCounter->getStr() << "Пользователей" << m_pMyCounter->getOwners() << std::endl;;
}

bool MyString::operator==(char* other)
{
    if (strcmp(other, m_pMyCounter->getStr()))
    {
        return true;
    }
    else
    {
        return false;
    }
}

MyString::~MyString()
{
    del();
}

void MyString::del()
{
    m_pMyCounter->del();
}