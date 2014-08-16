// This is the implementation file 111044035HW06_ApplicationSoftware.cpp of the class ApplicationSoftware.
//The interface for the class ApplicationSoftware is in the header file 111044035HW06_ApplicationSoftware.h

#include "111044035HW06_ApplicationSoftware.h"

namespace KayaSoftware
{
    ApplicationSoftware::ApplicationSoftware() : Software()
    {
        canAccess = false;
        nameOfSystem = " ";
	++aliveObjects;
    }
    ApplicationSoftware::ApplicationSoftware(string newname,bool access,string nameSystem)
			:Software(newname)
    { 
        setCanAccess(access);
        setNameOfOpe(nameSystem);
	++aliveObjects;
    }
    void ApplicationSoftware::setCanAccess(const bool access)
    {
        canAccess = access;
    }
    bool ApplicationSoftware::getCanAccess() const
    {
        return canAccess;
    }
    void ApplicationSoftware::setNameOfOpe(const string name)
    {
        nameOfSystem = name;
    }
    string ApplicationSoftware::getNameOfOpe() const
    {
        return nameOfSystem;
    }

}

