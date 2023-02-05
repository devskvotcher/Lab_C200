#include "BYTE.h"
#include <iostream>

void Bin::Show()
{
    std::cout << (int)m_bin0 << (int)m_bin1 << (int)m_bin2 << (int)m_bin3 << (int)m_bin4 << (int)m_bin5 << (int)m_bin6 << (int)m_bin7 << std::endl;
}
void/*int*/ Bin::ShowPos(int pos)
{
    switch (pos)
    {
    case 0:std::cout << (int)m_bin0 << std::endl; break;
    case 1:std::cout << (int)m_bin1 << std::endl; break;
    case 2:std::cout << (int)m_bin2 << std::endl; break;
    case 3:std::cout << (int)m_bin3 << std::endl; break;
    case 4:std::cout << (int)m_bin4 << std::endl; break;
    case 5:std::cout << (int)m_bin5 << std::endl; break;
    case 6:std::cout << (int)m_bin6 << std::endl; break;
    case 7:std::cout << (int)m_bin7 << std::endl; break;
    default: std::cout << "bad pos argument" << std::endl;
        break;
    }
}
void/*int*/ Bin::Edit(int pos, int val)
{
    if (val > 1 || val < 0) { std::cout << "bad val argument" << std::endl; return; }
    switch (pos)
    {
    case 0:m_bin0 = val; break;
    case 1:m_bin1 = val; break;
    case 2:m_bin2 = val; break;
    case 3:m_bin3 = val; break;
    case 4:m_bin4 = val; break;
    case 5:m_bin5 = val; break;
    case 6:m_bin6 = val; break;
    case 7:m_bin7 = val; break;
    default: std::cout << "bad pos argument" << std::endl;
        break;
    }
}
void Bytes::ShowBin()
{
    m_bin.Show();
}
void Bytes::ShowPos(int pos)
{
    m_bin.ShowPos(pos);
}
void Bytes::EditBin(int pos, int val)
{
    m_bin.Edit(pos, val);
}
void Hex::Show()
{
    std::cout << std::hex << (int)m_hex0 << (int)m_hex1 << std::endl;
}
void/*int*/Hex::ShowPos(int pos)
{
    switch (pos)
    {
    case 0:std::cout << std::hex << (int)m_hex0 << std::endl; break;
    case 1:std::cout << std::hex << (int)m_hex1 << std::endl; break;
    default: std::cout << "bad pos argument" << std::endl;
        break;
    }
}
void/*int*/ Hex::Edit(int pos, int val)
{
    if (val > 15 || val < 0) { std::cout << "bad val argument" << std::endl; return; }
    switch (pos)
    {
    case 0:m_hex0 = val; break;
    case 1:m_hex1 = val; break;
    default: std::cout << "bad pos argument" << std::endl;
        break;
    }
}
Bytes::Bytes(unsigned char byte)
{
    m_dec = byte;
}
void Bytes::ShowDec()
{
    std::cout << std::dec << (int)m_dec << std::endl;
}
void Bytes::ShowChar()
{
    if ((m_dec >= 32 && m_dec <= 127) || (m_dec >= 128 && m_dec <= 254))
    {
        std::cout << (char)m_dec << std::endl;
    }
}
void Bytes::ShowHex()
{
    m_hex.Show();
}
void Bytes::ShowHexPos(int pos)
{
    m_hex.ShowPos(pos);
}
void Bytes::EditHex(int pos, int val)
{
    m_hex.Edit(pos, val);
}

void Oct::Show()
{
    std::cout << std::oct << (int)m_oct0 << (int)m_oct1 << (int)m_oct2 << std::endl;
}
void/*int*/ Oct::ShowPos(int pos)
{
    switch (pos)
    {
    case 0:std::cout << std::oct << (int)m_oct0 << std::endl; break;
    case 1:std::cout << std::oct << (int)m_oct1 << std::endl; break;
    case 2:std::cout << std::oct << (int)m_oct2 << std::endl; break;
    default: std::cout << "bad pos argument" << std::endl;
        break;
    }
}
void/*int*/ Oct::Edit(int pos, int val)
{
    //if (val > 8 || val < 0) { std::cout << "bad val argument" << std::endl; return; }
    switch (pos)
    {
    case 0:
    {
        if (val > 3 || val < 0) { std::cout << "bad val argument" << std::endl; return; }
        m_oct0 = val; break;
    }
    case 1:
    {
        if (val > 7 || val < 0) { std::cout << "bad val argument" << std::endl; return; }
        m_oct1 = val; break;
    }
    case 2:
    {
        if (val > 7 || val < 0) { std::cout << "bad val argument" << std::endl; return; }
        m_oct2 = val; break;
    }
    default: std::cout << "bad pos argument" << std::endl;
        break;
    }
}
void Bytes::ShowOct()
{
    m_oct.Show();
}
void Bytes::ShowOctPos(int pos)
{
    m_oct.ShowPos(pos);
}
void Bytes::EditOct(int pos, int val)
{
    m_oct.Edit(pos, val);
}