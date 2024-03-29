#pragma once
#include <iostream>
#include "MyCounter.h"
class Counter;
class MyString {
private:
    friend class Counter;
    Counter* m_pMyCounter;
public:
    ~MyString();
    MyString(const char* str);
    MyString(const MyString& str);
    MyString operator=(const MyString& other);    
    bool operator==(const char* other);
};