#define _CRT_SECURE_NO_WARNINGS
#include "MyString.h"
#include <iostream>
using namespace std;

MyString::MyString(const char* str)
{ 
    if (str)
    {
       // m_pMyCounter = new Counter(str);
        m_pMyCounter = Counter::init(str);
    }
    else
    {
        m_pMyCounter = nullptr;
    }
}
MyString::MyString(const MyString &str)
{
    m_pMyCounter = str.m_pMyCounter;
    m_pMyCounter->AddOwner();
}
MyString MyString::operator=(const MyString& other)
{
    if (m_pMyCounter != other.m_pMyCounter)
    {
        m_pMyCounter->RomoveOwner();
        m_pMyCounter = other.m_pMyCounter;
        m_pMyCounter->AddOwner();
    }
    return *this;
}
bool MyString::operator==(const char* other)
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
    if (m_pMyCounter)
    {
        m_pMyCounter->RomoveOwner();
    }    
}

