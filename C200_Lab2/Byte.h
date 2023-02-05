#pragma once
#pragma once
class Bin
{
    unsigned char m_bin0 : 1; //или bool
    unsigned char m_bin1 : 1;
    unsigned char m_bin2 : 1;
    unsigned char m_bin3 : 1;
    unsigned char m_bin4 : 1;
    unsigned char m_bin5 : 1;
    unsigned char m_bin6 : 1;
    unsigned char m_bin7 : 1;
public:
    void Show(); //выводим все двоичные цифры
    void/*int*/ ShowPos(int pos); //выводим цифру в позиции
    void/*int*/ Edit(int pos, int val); //изменяем цифру в позиции
    friend union Bytes;
    //При реализации методов проверьте корректность переданных параметров
    //Используйте потоковый вывод (std::cout)
};

class Hex
{
    unsigned char m_hex1 : 4;
    unsigned char m_hex0 : 4;
public:
    void Show(); //выводим все шестнадцатеричные цифры
    void/*int*/ ShowPos(int pos); //выводим цифру в позиции
    void/*int*/ Edit(int pos, int val); //изменяем цифру в позиции
    friend union Bytes;
};

class Oct
{
    unsigned char m_oct2 : 3;
    unsigned char m_oct1 : 3;
    unsigned char m_oct0 : 2;
public:
    void Show(); //выводим все восьмеричные цифры
    void/*int*/ ShowPos(int pos); //выводим цифру в позиции
    void/*int*/ Edit(int pos, int val); //изменяем цифру в позиции
    friend union Bytes;
};

union Bytes
{
private:
    Bin m_bin;
    Hex m_hex;
    Oct m_oct;
    unsigned char m_dec;
public:
    Bytes(unsigned char byte);
    void ShowBin();
    void ShowPos(int pos);
    void EditBin(int pos, int val);
    void ShowDec();
    void ShowHex();
    void ShowHexPos(int pos);
    void EditHex(int pos, int val);
    void ShowOct();
    void ShowOctPos(int pos);
    void EditOct(int pos, int val);
    void ShowChar();
};

