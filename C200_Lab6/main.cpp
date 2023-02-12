#include "MyString.h"
#include "MyCounter.h"

#define   stop __asm nop

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Rus");
    MyString s1("HELLO");
    MyString s2("HELLO2");
    MyString s3("HELLO2");
    MyString s4("HELLO2");
    MyString s5("HELLO2");
    MyString s6("HELLO2");  
    MyString s7=s6;    
    Counter::ConsoleOutCounter();

   // s5.del();
   // s6.del();
    Counter::toLow();
    Counter::ConsoleOutCounter();
    //std::cout << s1 <<"\n"<< s2<<"\n" << s3 << std::endl;
    stop
}