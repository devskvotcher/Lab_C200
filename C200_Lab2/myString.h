#pragma once
class MyString
{
    char* m_pStr;	//������-���� ������
 //   int m_memory;

public:
   // MyString();
    MyString(const char* pName = "adfasd");
    MyString(const MyString& other); // ����������� �����������
    MyString(int memory);
    //������������ ����������� �����������
    const char* ConcatenationString(const char* pNewStr);
    const char* GetString() const; // ���������� ������������ ������ 
    const char* SetNewString(const char* pNewString);
    MyString f(const char* first, ...);
    ~MyString();
};
