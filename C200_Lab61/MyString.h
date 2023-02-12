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
    void print();
    void del();
    bool operator==(char* other);
   // friend std::ostream& operator << (std::ostream& os, Counter& count);
};