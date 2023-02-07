#pragma once
class MyString
{
    char* m_pStr;	//строка-член класса
 //   int m_memory;

public:
   // MyString();
    MyString(const char* pName = "adfasd");
    MyString(const MyString& other); // конструктор копировани€
    MyString(MyString&& other) noexcept; //ѕеремещающий конструктор копировани€
    MyString(int memory);
    MyString& operator=(MyString&& other) noexcept;
    //ѕеремешающий конструктор копировани€
    const char* ConcatenationString(const char* pNewStr);
    const char* GetString() const; // объ€вление константного метода 
    const char* SetNewString(const char* pNewString);
    MyString f(const char* first, ...);
    ~MyString();
};
