// This is the implementation file 111044035HW06_FreeMultimediaSoftware.cpp of the class FreeMultimediaSoftware.
//The interface for the class FreeMultimediaSoftware is in the header file 111044035HW06_FreeMultimediaSoftware.h

#include "111044035HW06_FreeMultimediaSoftware.h"

namespace KayaSoftware
{
	FreeMultimediaSoftware::FreeMultimediaSoftware() : ApplicationSoftware()
	{
		subcategory = 0;
		modify = false;
		++aliveObjects;
	}
	FreeMultimediaSoftware::FreeMultimediaSoftware(string newname,bool access,string nameSystem,int category,bool change)
			       :ApplicationSoftware(newname,access,nameSystem)
	{
		subcategory = category;
		modify = change;
		++aliveObjects;
	}
	int FreeMultimediaSoftware::getNumOfSubcategory() const
	{
		return subcategory;
	}
	void FreeMultimediaSoftware::setNumOfSubcategory(const int number)
	{
		subcategory = number;
	}
	bool FreeMultimediaSoftware::getcanModify() const
	{
		return modify;
	}
	void FreeMultimediaSoftware::setCanModify(const bool change)
	{
		modify = change;
	}
}
