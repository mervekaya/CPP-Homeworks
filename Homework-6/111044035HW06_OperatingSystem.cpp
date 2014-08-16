// This is the implementation file 111044035HW06_OperatingSystem.cpp of the class OperatingSystem.
//The interface for the class OperatingSystem is in the header file 111044035HW06_OperatingSystem.h


#include "111044035HW06_OperatingSystem.h"

namespace KayaSoftware
{
	OperatingSystem::OperatingSystem() : SystemSoftware()
	{
		numberSystem = 0;
		_source = false;
	}
	OperatingSystem::OperatingSystem(string sysname,bool priority,string newname,string othername,bool isOpen,int number)
			:SystemSoftware(sysname,priority,newname,othername)
	{
		
		setIsOpenSource(isOpen);
		setNumOfOpeSystem(number);
		++aliveObjects;
	}
	bool OperatingSystem::getIsOpenSource() const
	{
		return _source;
	}
	void OperatingSystem::setIsOpenSource(const bool source)
	{
		_source = source;
	}
	int OperatingSystem::getNumOfOpeSystem() const
	{
		return numberSystem;
	}
	void OperatingSystem::setNumOfOpeSystem(const int number)
	{
		numberSystem = number;	
	}
	
}


