#pragma once
#include "MyString.h"
#include <iostream>
// класс, описывающий информацию о сотруднике ( без учета фамилии )
class MyData
{
public:
    enum Sex
    {
        UNDEF,
        MALE,
        FEMALE
    };
private:
    Sex sex;
    size_t m_age;
    MyString m_job;
    float m_salary;
public:
    MyData();
    MyData(Sex, size_t, const char*, float);
   // MyData& operator=(const MyData&);
    friend std::ostream& operator<<(std::ostream&, const MyData&);
};