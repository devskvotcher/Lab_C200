#pragma once
class MyString
{
    char* m_pStr;	//������-���� ������
    

public:
    MyString();
    MyString(const char* pName);
    MyString(const MyString& other); // ����������� �����������
    
    const char* GetString() const; // ���������� ������������ ������ 
    const char* SetNewString(const char* pNewString);
    ~MyString();
};
