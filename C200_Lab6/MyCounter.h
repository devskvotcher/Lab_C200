#pragma once
#include "MyString.h"
#include <stdio.h>
#include <string.h>

class Counter {
    static Counter* Head;
    static unsigned int m_curCounters;//������� ����������
    int m_nOwners; // ���������� ������������� ������ ������
    char* m_pStr;
    Counter* pNext;       
public:    
    Counter(const char* str);   
    static Counter* init(const char* str);
    char* getStr() const;
    int getOwners() const;
    void RomoveOwner();
    void AddOwner();
    static void ConsoleOutCounter();
    void del();
    static void toLow();
    ~Counter();
    friend class MyString;   
};