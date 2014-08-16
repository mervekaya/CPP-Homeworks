// This is the implementation file 111044035HW06_EducationalSoftware.cpp of the class EducationalSoftware.
//The interface for the class EducationalSoftware is in the header file 111044035HW06_EducationalSoftware.h

#include "111044035HW06_EducationalSoftware.h"

namespace KayaSoftware{

	EducationalSoftware::EducationalSoftware() :SystemSoftware()
	{
		_age = "  ";
		majorType = " ";
		++aliveObjects;
	}
	EducationalSoftware::EducationalSoftware(string sysname,bool priority,string newname,string othername,string age,string type)
			    :SystemSoftware(sysname,priority,newname,othername)
	{
		setAge(age);
		setMajorType(type);
		++aliveObjects;
	}
	string EducationalSoftware::getAge() const
	{
		return _age;
	}
	void EducationalSoftware::setAge(const string age)
	{
		_age = age;
	}
	string EducationalSoftware::getMajorType() const
	{
		return majorType;
	}
	void EducationalSoftware::setMajorType(const string type)
	{
		majorType = type;
	}
}
