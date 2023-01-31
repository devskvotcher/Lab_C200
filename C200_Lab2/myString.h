#pragma once
class MyString
{
    char* m_pStr;	//строка-член класса
    

public:
    MyString();
    MyString(const char* pName);
    MyString(const MyString& other); // конструктор копировани€
    
    MyString CreateString();

    const char* GetString() const; // объ€вление константного метода 
    const char* SetNewString(const char* pNewString);
    ~MyString();
};
