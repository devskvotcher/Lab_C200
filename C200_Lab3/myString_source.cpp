#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include "myString.h"
#include <iostream>
#include <cstdarg>
#include <ctype.h>
using namespace std;


// Ii?aaaeaiea eiino?oeoi?a.
MyString::MyString()   //ii oiie?aie? 
{		
		m_pStr = nullptr;		
}

MyString::MyString(const char* pName)
{	
		m_pStr = new char[strlen(pName) + 1];
		strcpy(m_pStr, pName);
}
MyString& MyString::operator=(const char* str)
{
    delete[] m_pStr;
    m_pStr = new char[strlen(str) + 1];
    strcpy(m_pStr, str);
    
    return *this;
}
MyString::MyString(const MyString& other)			// eiino?oeoi? eiie?iaaiey
{
	if (other.m_pStr)
	{
		m_pStr = new char[strlen(other.m_pStr) + 1];
		strcpy(m_pStr, other.m_pStr);
	}
	else
	{
		m_pStr = 0;
	}
	
}

MyString::MyString(int memory)
{

	this->m_pStr = new char[memory];
	
}

const char* MyString::GetString() const // ii?aaaeaiea eiinoaioiiai iaoiaa
{	
		return m_pStr;		
}
const char* MyString::ConcatenationString(const char* pNewStr)
{
	if (m_pStr != nullptr)
	{
		strcpy(m_pStr, strcat(m_pStr, pNewStr));		
	}
	return m_pStr;	
}

const char* MyString::SetNewString(const char* pNewString)
{
	delete[] m_pStr;
	m_pStr = new char[strlen(pNewString) + 1];
	strcpy(m_pStr, pNewString);
	return m_pStr;
}

MyString MyString::f(const char* first, ...)
{
    if (strcmp(first, "*") == 0)
        return MyString();

    char* result = nullptr;
    int length = 0;

    length = strlen(first);
    result = new char[length + 1];
    strcpy(result, first);

    va_list args;
    va_start(args, first);

    const char* nextStr = va_arg(args, const char*);
    while (strcmp(nextStr, "*") != 0) {    // aeeia neaao?uae no?iee-a?aoiaioa aac o?aoa ioeaaiai neiaiea
        int nextStrLength = strlen(nextStr); // ?acia? ?aaai = aeeia noa?ie no?iee aac o?aoa '\0' + aeeia iiaie no?iee
        // aac o?aoa '\0' + ianoi iia '\0'
        char* newResult = new char[length + nextStrLength + 1];
        // nia?aea eiie?o? noa?o? no?ieo a iiaue aooa?
        // neiaieu n eiaaenaie [0 .. length - 1] - neiaieu noa?iai aooa?a
        // ia iiceoee [length] - '\0'
        strcpy(newResult, result); //II?AIO A EA?ANOAA AEEEIU ENIIEUCOAON? I?INOI AEEIA I?AAUAOUAE NO?IEE

        // eiie?o? neaao?uo? no?ieo-a?aoiaio a iiaue aooa?
        // newResult + length cia?eo, ?oi iu ia?eiaai anoaaeyou neiaieu n iiceoee
        // [length], ia eioi?ie o ian nae?an caienai '\0' iinea i?ioeiai strcpy.
        // Iai ii ia io?ai, oae eae a no?iea aie?ai auou oieuei iaei '\0', e ii
        // aie?ai auou a eiioa no?iee, iiyoiio ia?acaienuaaai aai.
        // Ia iiceoee iiaiai aooa?a [length .. length + nextStrLength] aoaoo
        // caienaiu neiaieu [0 .. nextStrLength] no?iee nextStr, aee??ay '\0'.
        strcpy_s(newResult + length, nextStrLength + 1, nextStr);

        // Oae eae iu auaaeeee iiao? iaiyou iia iiaue aooa?, inaiai?aaai noa?o?
        // e iaiiaeyai cia?aiey ia?aiaiiuo result e length aey neaao?uaai oeeea.
        delete[] result;
        result = newResult;
        length += nextStrLength;
        nextStr = va_arg(args, const char*);
    }

    va_end(args);
    //return MyString(result);
    return MyString(result);
}

MyString& MyString::operator=(const MyString& str2)
{
    // i?iaa?ea ia naiii?enaaeaaiea
    if (this == &str2)
        return *this;

    // anee aaiiua nouanoao?o a oaeouae no?iea, oaaeeou eo
    if (m_pStr)
    {
        delete[] m_pStr;
    }

    int m_length = strlen(str2.m_pStr)+1;

    // eiie?oai aaiiua ec str a iayaiue iauaeo
    m_pStr = new char[strlen(str2.m_pStr) + 1];

    for (int i = 0; i < m_length; ++i)
        m_pStr[i] = str2.m_pStr[i];

    // aica?auaai nouanoao?uee iauaeo,
    // ii?ii auei aee??eou yoio iia?aoi? a oaii?eo
    return *this;
}
std::ostream& operator<< (std::ostream& out, const MyString& str)
{
    out << "Contains:" << str.m_pStr;
    return out;
}
//MyString& operator+(MyString& str1, const MyString& str2)
//{
//    char* newStr = nullptr;    
//    newStr = new char[strlen(str1.GetString()) + strlen(str2.GetString() + 1)];
//    strcpy(newStr, str1.GetString());
//    strcat(newStr, str2.GetString());    
//    str1.SetNewString(newStr);
//    return str1;
//}
MyString operator+(MyString& str1, const MyString& str2)
{
    char* newStr = nullptr;
    newStr = new char[strlen(str1.GetString()) + strlen(str2.GetString() + 1)];
    strcpy(newStr, str1.GetString());
    strcat(newStr, str2.GetString());
    return MyString(newStr);
}
MyString& operator+=(MyString& str1, const MyString& str2)
{
    char* newStr = nullptr;
    newStr = new char[strlen(str1.GetString()) + strlen(str2.GetString() + 1)];
    strcpy(newStr, str1.GetString());
    strcat(newStr, str2.GetString());
    str1.SetNewString(newStr);
    delete[] newStr;
    return str1;
}
MyString MyString::operator--(int c)
{
    MyString str=*this;

    for (size_t i = 0; i < strlen(m_pStr); i++)
    {
        m_pStr[i] = tolower(static_cast<int>(m_pStr[i]));
    }
    return *this;
}
MyString& operator++(MyString& str)
{
    char* tmp = nullptr;
    tmp = new char[strlen(str.GetString())+1];
    strcpy(tmp, str.GetString());
    
    for (size_t i = 0; i < strlen(str.GetString()); i++)
    {
        tmp[i] = toupper(static_cast<int>(tmp[i]));
    }
    str.SetNewString(tmp);
    delete[] tmp;
    return str;
}
// Ii?aaaeaiea aano?oeoi?a.
MyString::~MyString()
{
	delete[] m_pStr;
}
