#pragma once
#include "MyString.h"
#include "MyData.h"
// класс, связывающий фамилию сотрудника с его характеристиками
class Pair
{
private:
    MyString key;
    MyData data;
public:
    Pair();
    Pair(const char*, const MyData&);
    bool operator==(const char*);
    friend std::ostream& operator<<(std::ostream&, const Pair&);

    friend class Base;
};