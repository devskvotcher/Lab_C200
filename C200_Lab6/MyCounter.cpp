#define _CRT_SECURE_NO_WARNINGS
#include "myCounter.h"
Counter* Counter::Head = nullptr;
unsigned int Counter::m_curCounters = 0;

Counter::Counter(const char* str) :m_nOwners(1)
{
    m_pStr = new char[strlen(str) + 1];
    strcpy(m_pStr, str);   
    m_curCounters++;
}
Counter* Counter::init(const char* str)
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
                temp->AddOwner();
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

char* Counter::getStr() const
{
    return m_pStr;
}
int Counter::getOwners() const
{
    return m_nOwners;
}

void Counter::RomoveOwner()
{
    m_nOwners--;
    if (m_nOwners ==0)
    {
        delete this;
    }
}

void Counter::AddOwner()
{
    m_nOwners++;
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
void Counter::toLow()
{
    Counter* p = Head;
    for (p; p != nullptr; p = p->pNext)
    {
        for (size_t i = 0; i < strlen(p->m_pStr); i++)
        {
            p->m_pStr[i] = tolower(static_cast<int>(p->m_pStr[i]));
        }
    }
}
//void Sort()
//{
//    for (size_t i = 0; i < this->count - 1; i++)
//    {
//        for (size_t j = 0; j < this->count - i - 1; j++)
//        {
//            if (this->pbase[j].key > this->pbase[j + 1].key)
//            {
//                Pair swap = std::move(this->pbase[j]);
//                this->pbase[j] = std::move(this->pbase[j + 1]);
//                this->pbase[j + 1] = std::move(swap);
//            }
//        }
//    }
//}
void Counter::ConsoleOutCounter()
{
    Counter* p = Head;
    std::cout << "Итак, что хранится в нашем чудном списке" << std::endl;

    for (p; p != nullptr; p = p->pNext)
    {
        std::cout << "Строка: " << p->m_pStr << "  Количество пользователей строки: " << p->m_nOwners << std::endl;
    }
}
Counter::~Counter()
{
    delete[] m_pStr;
}