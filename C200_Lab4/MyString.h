#pragma once
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