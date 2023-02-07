#include "MyData.h"
#include "MyString.h"
#include <iomanip>
#include <string>
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

std::ostream& operator<<(std::ostream& os, const MyData& d)
{
    switch (d.sex)
    {
    case MyData::UNDEF:
    {
        os << std::setw(8) << "Н";
        break;
    }
    case MyData::MALE:
    {
        os << std::setw(8) << "М";       // мужской" << endl;
        break;
    }
    case MyData::FEMALE:
    {
        os << std::setw(8) << "Ж";        //"женский" << endl;
        break;
    }
    }

    os << std::setw(13) << d.m_age;
    os << std::setw(14) << d.m_job.GetString();
    os << std::setw(19) << d.m_salary << std::endl;

    return os;
}