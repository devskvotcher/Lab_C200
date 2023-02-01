#pragma once
class MyString
{
    char* m_pStr;	//строка-член класса
    

public:
  //  MyString();
    MyString(const char* pName = "adfasd");
    MyString(const MyString& other); // конструктор копировани€
    
 

    const char* GetString() const; // объ€вление константного метода 
    const char* SetNewString(const char* pNewString);
    ~MyString();
};
