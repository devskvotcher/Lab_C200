#pragma once
#include "MyString.h"
#include <stdio.h>
#include <string.h>

class Counter {
private:
    static Counter* Head;
    static unsigned int m_curCounters;//������� ����������
    int m_nOwners; // ���������� ������������� ������ ������
    char* m_pStr;
    Counter* pNext;
    Counter(char* str);
public:
    static Counter* init(char* str);
    char* get();
    //void Clean();
    void del();
};