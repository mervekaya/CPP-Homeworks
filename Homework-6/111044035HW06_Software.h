//This is the header file 111044035HW06_Software.h
//This is the interface for the class Software.

#ifndef SOFTWARE_H
#define SOFTWARE_H

#include <iostream>
#include <string>
using std::string;

namespace KayaSoftware
{
    class Software
    {
      public:
            Software();
            Software(string newName);
            string getName() const;
            void setName(const string newName);
            int static getNumAliveObjects() { return aliveObjects;}
      protected:
            string name;
            static int aliveObjects;
    };
}

#endif //SOFTWARE_H
