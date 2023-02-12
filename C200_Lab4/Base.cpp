#include "Base.h"
#include <iomanip>
Base::Base()
{
    this->count = 0;
    this->capacity = 1;
    this->pbase = new Pair[this->capacity];
}

Base::Base(const Base& bd)
{
    this->count = bd.count;
    this->capacity = bd.count + 1;
   // if (bd.count != 0)
    {
        this->pbase = new Pair[this->capacity];
    }
  //  else
  //      this->pbase = nullptr;
  //  }
        
    for (size_t i = 0; i < bd.count; i++)
    {
        this->pbase[i] = bd.pbase[i];
    }
}

Base::Base(Base&& bd) noexcept
{
   // delete[]this->pbase;
    this->count = bd.count;
    this->capacity = bd.capacity;
    this->pbase = bd.pbase;
    bd.pbase = nullptr;
    bd.count = bd.capacity = 0;
}

Base& Base::operator=(const Base& bd)
{
    
    if (this->capacity < bd.count)
    {
        delete[]this->pbase;
        this->capacity = bd.count+1;
        this->pbase = new Pair[this->capacity];
    }
    this->count = bd.count;
    
    for (size_t i = 0; i < bd.count; i++)
    {
        this->pbase[i] = bd.pbase[i];
    }

    return *this;
}

Base& Base::operator=(Base&& bd)
{
    delete[]this->pbase;
    this->count = bd.count;
    this->capacity = bd.capacity;
    this->pbase = bd.pbase;
    bd.pbase = nullptr;
    bd.count = bd.capacity = 0;

    return *this;
}

MyData& Base::operator[](const char* key)
{
    // перед тем, как добавить нового сотрудника в БД, нужно убедиться, что
    // в БД нет сотрудника с таким же ключом ( фамилией )
    for (size_t i = 0; i < this->count; i++)
    {
        if (this->pbase[i] == key)
        {
            return this->pbase[i].data;
        }
    }

    if (this->count == this->capacity)
    {
        // емкость БД увеличивается в 2 раза ( фактор увеличения = 2 )
        this->capacity += 2;
        Pair* tmp = new Pair[this->capacity];
        for (size_t i = 0; i < this->count; i++)
        {
            tmp[i] = std::move(this->pbase[i]);
        }
        delete[]this->pbase;
        this->pbase = tmp;
    }
    this->count++;
    this->pbase[this->count - 1].key.SetString(key);

    return this->pbase[this->count - 1].data;
}

int Base::Delete_pair(const char* key)
{
    int deleted = 0;
    for (size_t i = 0; i < this->count; i++)
    {
        if (this->pbase[i] == key)
        {
            
           //Pair* tmp_base = new Pair[this->count - 1];
           //size_t insert_position = 0;
           for (size_t k = i; k < this->count-1; k++)
           {
               pbase[k] = std::move(pbase[k + 1]);
               //if (k != i)
               //{
               //    tmp_base[insert_position++] = this->pbase[k];
               //}
           }
           //
           //delete[]this->pbase;
           //this->pbase = tmp_base;
           //this->count--;
            deleted = 1;
            this->count--;
            break;
        }
    }

    return deleted;
}

void Base::Sort()
{
    for (size_t i = 0; i < this->count - 1; i++)
    {
        for (size_t j = 0; j < this->count - i - 1; j++)
        {
            if (this->pbase[j].key > this->pbase[j + 1].key)
            {
                Pair swap = std::move(this->pbase[j]);
                this->pbase[j] = std::move(this->pbase[j + 1]);
                this->pbase[j + 1] = std::move(swap);
            }
        }
    }
}

Base::~Base()
{
    delete[]this->pbase;
}

std::ostream& operator<<(std::ostream& os, const Base& bd)
{
    if (bd.count == 0)
    {
        os << std::endl << std::endl << "В настоящий момент в базе данных нет ни одного сотрудника, т е БД пуста!" << std::endl;
    }
    else
    {
        os << std::endl << std::endl << "Текущая информация о сотрудниках из базы данных имеет вид: " << std::endl;
        os << "--------------------------------------------------------------------------------------------" << std::endl;
        os << " #      Фамилия ( ключ )     Пол     Возраст     Профессия     Зарплата, руб." << std::endl;
        os << "--------------------------------------------------------------------------------------------" << std::endl;
        for (size_t i = 0; i < bd.count; i++)
        {
            os << std::setw(2) << i + 1;
            os << bd.pbase[i];
        }
        os << "--------------------------------------------------------------------------------------------" << std::endl;
    }

    return os;
}