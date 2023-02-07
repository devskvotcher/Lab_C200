#pragma once
class MyString
{
private:
    char* s;
public:
    MyString();                             // ����������� �� ���������
    MyString(const char*);                  // ��������������� �����������
    MyString(const MyString&);              // ����������� �����������
    MyString operator=(const MyString&);    // ������������� �������� ������������
    const char* GetString() const;
    void SetString(const char*);
    bool operator>(const MyString&);
    ~MyString();                            // ����������
};