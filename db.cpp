#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class MyString
{
private:
    char* s;
public:
    MyString();                             // конструктор по умолчанию
    MyString(const char*);                  // параметрический конструктор
    MyString(const MyString&);              // конструктор копирования
    MyString operator=(const MyString&);    // перегруженный оператор присваивания
    const char* GetString() const;
    void SetString(const char*);
    bool operator>(const MyString&);
    ~MyString();                            // деструктор
};

MyString::MyString()
{
    this->s = NULL;
}

MyString::MyString(const char* s)
{
    this->s = new char[strlen(s) + 1];
    strcpy(this->s, s);
}

MyString::MyString(const MyString& ms)
{
    if (ms.s)
    {
        this->s = new char[strlen(ms.s) + 1];
        strcpy(this->s, ms.s);
    }
    else
    {
        this->s = NULL;
    }
}

MyString MyString::operator=(const MyString& ms)
{
    if (this->s != NULL)
    {
        delete[]this->s;
    }

    this->s = new char[strlen(ms.s) + 1];
    strcpy(this->s, ms.s);

    return *this;
}

const char* MyString::GetString() const
{
    return this->s;
}

void MyString::SetString(const char* s)
{
    delete[]this->s;
    this->s = new char[strlen(s) + 1];
    strcpy(this->s, s);
}

bool MyString::operator>(const MyString& ms)
{
    return (strcmp(this->s, ms.s) > 0);
}

MyString::~MyString()
{
    delete[]this->s;
}

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
    MyData& operator=(const MyData&);
    friend ostream& operator<<(ostream&, const MyData&);
};

MyData::MyData()
{
    this->sex = UNDEF;
    this->m_age = 0;
    this->m_job.SetString("UNKNOWN");
    this->m_salary = 0;
}

MyData::MyData(Sex s, size_t age, const char* job, float salary)
{
    this->sex = s;
    this->m_age = age;
    this->m_job.SetString(job);
    this->m_salary = salary;
}

MyData& MyData::operator=(const MyData& md)
{
    if (this->sex == UNDEF)
    {
        this->sex = md.sex;
        this->m_age = md.m_age;
        this->m_job = md.m_job;
        this->m_salary = md.m_salary;
    }

    return *this;
}

ostream& operator<<(ostream& os, const MyData& d)
{
    switch (d.sex)
    {
    case MyData::UNDEF:
    {
        os << setw(8) << "Н";
        break;
    }
    case MyData::MALE:
    {
        os << setw(8) << "М";       // мужской" << endl;
        break;
    }
    case MyData::FEMALE:
    {
        os << setw(8) << "Ж";        //"женский" << endl;
        break;
    }
    }

    os << setw(13) << d.m_age;
    os << setw(14) << d.m_job.GetString();
    os << setw(19) << d.m_salary << endl;

    return os;
}

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
    friend ostream& operator<<(ostream&, const Pair&);

    friend class Base;
};

Pair::Pair()
{}

Pair::Pair(const char* k, const MyData& d)
{
    this->key.SetString(k);
    this->data = d;
}

bool Pair::operator==(const char* k)
{
    return !strcmp(this->key.GetString(), k);
}

ostream& operator<<(ostream& os, const Pair& pair)
{
    os << setw(21) << pair.key.GetString();
    os << pair.data;

    return os;
}

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
    friend ostream& operator<<(ostream&, const Base&);
};

Base::Base()
{
    this->count = 0;
    this->capacity = 1;
    this->pbase = new Pair[this->capacity];
}

Base::Base(const Base& bd)
{
    this->count = bd.count;
    this->capacity = bd.capacity;
    this->pbase = new Pair[this->capacity];

    for (size_t i = 0; i < bd.count; i++)
    {
        this->pbase[i] = bd.pbase[i];
    }
}

Base::Base(Base&& bd) noexcept
{
    delete[]this->pbase;
    this->count = bd.count;
    this->capacity = bd.capacity;
    this->pbase = bd.pbase;
    bd.pbase = NULL;
    bd.count = bd.capacity = 0;
}

Base& Base::operator=(const Base& bd)
{
    delete[]this->pbase;
    this->count = bd.count;
    this->capacity = bd.capacity;
    this->pbase = new Pair[this->capacity];

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
    bd.pbase = NULL;
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
        this->capacity *= 2;        
        Pair* tmp = new Pair[this->capacity];
        for (size_t i = 0; i < this->count; i++)
        {
            tmp[i] = this->pbase[i];
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
            Pair* tmp_base = new Pair[this->count - 1];
            size_t insert_position = 0;
            for (size_t k = 0; k < this->count; k++)
            {
                if (k != i)
                {
                    tmp_base[insert_position++] = this->pbase[k];
                }
            }

            delete[]this->pbase;
            this->pbase = tmp_base;
            this->count--;
            deleted = 1;

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
                Pair swap = this->pbase[j];
                this->pbase[j] = this->pbase[j + 1];
                this->pbase[j + 1] = swap;
            }
        }
    }
}

Base::~Base()
{
    delete[]this->pbase;
}

ostream& operator<<(ostream& os, const Base& bd)
{
    if (bd.count == 0)
    {
        os << endl << endl << "В настоящий момент в базе данных нет ни одного сотрудника, т е БД пуста!" << endl;
    }
    else
    {
        os << endl << endl << "Текущая информация о сотрудниках из базы данных имеет вид: " << endl;
        os << "--------------------------------------------------------------------------------------------" << endl;
        os << " #      Фамилия ( ключ )     Пол     Возраст     Профессия     Зарплата, руб." << endl;
        os << "--------------------------------------------------------------------------------------------" << endl;
        for (size_t i = 0; i < bd.count; i++)
        {
            os << setw(2) << i + 1;
            os << bd.pbase[i];
        }
        os << "--------------------------------------------------------------------------------------------" << endl;
    }

    return os;
}

int main(void)
{
    setlocale(LC_ALL, "Russian");

    // задание #1
    Base my_base;
    cout << my_base;

    my_base["Ivanov"] = MyData(MyData::MALE, 35, "Engineer", 125);
    my_base["Petrova"] = MyData(MyData::FEMALE, 30, "Lifter", 44);
    my_base["Sidorov"] = MyData(MyData::MALE, 50, "Driver", 70);
    cout << my_base;

    my_base["Ivanov"] = MyData(MyData::MALE, 19, "Programmer", 68);
    cout << my_base;

    cout << endl << endl << "Информация о сотруднике с фамилией \'Ivanov\' имеет вид:" << endl;
    cout << my_base["Ivanov"];

    my_base.Delete_pair("Petrova");
    cout << my_base;

    // задание #2
    Base my_base2 = my_base;
    cout << my_base2;

    Base my_base3 = my_base;
    cout << my_base3;

    my_base2["Nikonova"] = MyData(MyData::FEMALE, 46, "Fermer", 144);
    my_base2["Zubov"] = MyData(MyData::MALE, 16, "KPI", 21);
    cout << my_base2;

    my_base = my_base2;
    cout << my_base;

    my_base = my_base3;
    cout << my_base;

    // задание #3
    Base my_base4 = move(my_base);
    cout << my_base4;
    cout << my_base;

    my_base3 = move(my_base4);
    cout << my_base3;
    cout << my_base4;

    // задание #4
    my_base3["Nikonova"] = MyData(MyData::FEMALE, 46, "Fermer", 144);
    my_base3["Azimov"] = MyData(MyData::MALE, 16, "KPI", 21);

    cout << my_base3;
    my_base3.Sort();
    cout << my_base3;
   

    cout << endl << endl;
    system("pause");
    return EXIT_SUCCESS;
}