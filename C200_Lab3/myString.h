#pragma once
class MyString
{
    char* m_pStr;	//строка-член класса
 //   int m_memory;

public:
    MyString();
    //explicit MyString(const char* pName = "adfasd");
    explicit MyString(const char* pName);
    MyString(const MyString& other); // конструктор копировани€
    MyString(MyString&& other) noexcept; //ѕеремещающий конструктор копировани€
    MyString& operator=(MyString&& other) noexcept;
    MyString(int memory);
    const char* ConcatenationString(const char* pNewStr);
    const char* GetString() const; // объ€вление константного метода 
    const char* SetNewString(const char* pNewString);
    MyString f(const char* first, ...);
    MyString& operator=(const MyString& str2);
    MyString& operator=(const char* str);
    friend std::ostream& operator<< (std::ostream& out, const MyString& point);
    //friend MyString& operator+(MyString& str1, const MyString& str2);
    //”нарный оператор +, если €вл€етс€ членом класса, то принемает лдин параметр
    //в св€зи с чем реализуетс€ глобальна€ функци€.
    friend MyString operator+(MyString& str1, const MyString& str2);    
    friend MyString& operator+=(MyString& str1, const MyString& str2);
    MyString operator--(int c);
    friend MyString& operator++(MyString& str);    
    ~MyString();
};
