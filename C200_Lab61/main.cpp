#include "MyString.h"
#include "MyCounter.h"

#define   stop __asm nop

int main(int argc, char** argv)
{
    MyString s1("hello");
    MyString s2("hello2");
    MyString s3("hello2");
    s1.print();
    s2.print();
    s3.print();

    //std::cout << s1 <<"\n"<< s2<<"\n" << s3 << std::endl;
    stop
}