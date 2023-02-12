#pragma once
#include "MyString.h"
#include <stdio.h>
#include <string.h>

class Counter {
    static Counter* Head;
    static unsigned int m_curCounters;//счетчик указателей
    int m_nOwners; // количество пользователей данной строки
    char* m_pStr;
    Counter* pNext;       
public:    
    Counter(char* str);   
    static Counter* init(char* str);
    char* getStr();
    int getOwners();
    void del();
   // friend std::ostream& operator << (std::ostream& os, Counter& count);
};