#define _CRT_SECURE_NO_WARNINGS
#include "MyString.h"
#include <iostream>
using namespace std;

MyString::MyString(const char* str) {
    char* str1 = new char[strlen(str)+1];
    strcpy(str1, str);
 //   delete str;
    m_pMyCounter = Counter::init(str1);
}

void MyString::print() {
    printf("%s\n", m_pMyCounter->get());
}

bool MyString::operator==(char* other)
{
    if (strcmp(other, m_pMyCounter->get()))
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