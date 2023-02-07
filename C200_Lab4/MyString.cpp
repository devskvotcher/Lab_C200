#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include "MyString.h"
MyString::MyString()
{
    this->s = NULL;
}

MyString::MyString(const char* s)
{
    this->s = new char[strlen(s) + 1];
    strcpy(this->s, s);
}

MyString::MyString(const MyString& ms)
{
    if (ms.s)
    {
        this->s = new char[strlen(ms.s) + 1];
        strcpy(this->s, ms.s);
    }
    else
    {
        this->s = NULL;
    }
}

MyString MyString::operator=(const MyString& ms)
{
    if (this->s != NULL)
    {
        delete[]this->s;
    }

    this->s = new char[strlen(ms.s) + 1];
    strcpy(this->s, ms.s);

    return *this;
}

const char* MyString::GetString() const
{
    return this->s;
}

void MyString::SetString(const char* s)
{
    delete[]this->s;
    this->s = new char[strlen(s) + 1];
    strcpy(this->s, s);
}

bool MyString::operator>(const MyString& ms)
{
    return (strcmp(this->s, ms.s) > 0);
}

MyString::~MyString()
{
    delete[]this->s;
}