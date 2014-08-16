// This is the implementation file 111044035HW06_Software.cpp of the class Software.
//The interface for the class Software is in the header file 111044035HW06_Software.h

#include "111044035HW06_Software.h"

using std::string;

namespace KayaSoftware
{
    Software::Software() : name("No name yet.")
    {
	++aliveObjects;
    }
    Software::Software(string newName) : name(newName)
    {
        ++aliveObjects;
    }
    string Software::getName() const
    {
        return name;
    }
    void Software::setName(const string newName)
    {
        name = newName;
    }
}

