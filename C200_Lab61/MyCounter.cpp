#define _CRT_SECURE_NO_WARNINGS
#include "myCounter.h"
Counter* Head = nullptr;
unsigned int m_curCounters = 0;

Counter::Counter(char* str)
{
    m_pStr = new char[strlen(str) + 1];
    strcpy(m_pStr, str);
    m_nOwners = 1;
    pNext = nullptr;
    m_curCounters++;
}
//std::ostream& operator << (std::ostream& os, Counter& count)
//{
//    Counter* p = count.Head->pNext;
//    for (p; p != nullptr; p->pNext)
//    {
//        std::cout << "Строка: " << p->m_pStr << "  Количество пользователей строки: " << p->m_nOwners;
//    }
//    return os;
//}
Counter* Counter::init(char* str)
{
    if (m_curCounters == 0)
    {
        Head = new Counter(str);

        return Head;
    }
    else
    {
        Counter* temp = Head;
        while (1) 
        {
            if (!(strcmp(temp->m_pStr, str)))
            {
                temp->m_nOwners++;
                return temp;
            }
            else
            {
                if (temp->pNext == nullptr) break;
                temp = temp->pNext;
            }
        }
        temp->pNext = new Counter(str);

        return temp->pNext;
    }
}

char* Counter::getStr()
{
    return m_pStr;
}
int Counter::getOwners()
{
    return m_nOwners;
}

void Counter::del() {//<--!!!
    m_nOwners--;
    if (m_nOwners > 0) return;
    //если m_nOwners==0, то ищем предыдущий элемент
    if (strcmp(Head->m_pStr, m_pStr) == 0) {
        Head = Head->pNext;
        delete this;//<--
        m_curCounters--;
        return;
    }
    Counter* temp = Head;
    do {
        if (strcmp(temp->pNext->m_pStr, m_pStr) == 0) {//нашли
            temp->pNext = pNext;
            delete this;//<--
            m_curCounters--;
            return;
        }
        temp = temp->pNext;
    } while (temp);
    puts("error!");
}