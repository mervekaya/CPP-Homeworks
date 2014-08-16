// This is the implementation file 111044035HW06_SystemSoftware.cpp of the class SystemSoftware.
//The interface for the class SystemSoftware is in the header file 111044035HW06_SystemSoftware.h

#include "111044035HW06_SystemSoftware.h"

namespace KayaSoftware
{
    SystemSoftware::SystemSoftware() : Software()
    {
        _priority = false;
        firstInterfaceType = " ";
        secInterfaceType = "";
	++aliveObjects;
    }
    SystemSoftware::SystemSoftware(string softname,bool priority,string newname,string othername)
		   : Software(softname)
    { 
        setFirstIntType(newname);
        setSecIntType(othername);
        setPriority(priority);
	++aliveObjects;
    }
    string SystemSoftware::getFirstName() const
    {
        return firstInterfaceType;
    }
    string SystemSoftware::getSecondName() const
    {
        return secInterfaceType;
    }
    void SystemSoftware::setFirstIntType(const string firstIntType)
    {
        firstInterfaceType = firstIntType;
    }
    void SystemSoftware::setSecIntType(const string secIntType)
    {
        secInterfaceType = secIntType;
    }
    bool SystemSoftware::getPriority() const
    {
        return _priority;
    }
    void SystemSoftware::setPriority(const bool priority)
    {
        _priority = priority;
    }

}

