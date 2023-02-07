#pragma once
#include "Pair.h"
// класс, описывающий архитектуру базы данных
class Base
{
private:
    Pair* pbase;
    size_t count;
    size_t capacity;
public:
    Base();
    Base(const Base&);
    Base(Base&&) noexcept;
    Base& operator=(const Base&);
    Base& operator=(Base&&);
    MyData& operator[](const char*);
    int Delete_pair(const char*);
    void Sort();
    ~Base();
    friend std::ostream& operator<<(std::ostream&, const Base&);
};