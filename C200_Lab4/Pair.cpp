#include "Pair.h"
#include <iomanip>
Pair::Pair()
{

}

Pair::Pair(const char* k, const MyData& d)
{
    this->key.SetString(k);
    this->data = d;
}

bool Pair::operator==(const char* k)
{
    return !strcmp(this->key.GetString(), k);
}

std::ostream& operator<<(std::ostream& os, const Pair& pair)
{
    os << std::setw(21) << pair.key.GetString();
    os << pair.data;

    return os;
}