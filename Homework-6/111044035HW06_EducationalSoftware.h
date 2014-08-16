//This is the header file 111044035HW06_EducationalSoftware.h
//This is the interface for the class EducationalSoftware.

// This class has two data members.
// majorType : the major type of educational software

#ifndef EDUCATIONALSOFTWARE_H
#define EDUCATIONALSOFTWARE_H

#include <iostream>
#include "111044035HW06_SystemSoftware.h"

namespace KayaSoftware 
{
	class EducationalSoftware : public SystemSoftware
	{
		public:
			EducationalSoftware();
			EducationalSoftware(string sysname,bool priority,string newname,string othername,string age,string type);
			string getAge() const;
			void setAge(const string age);
			string getMajorType() const;
			void setMajorType(const string type);
			int static getNumAliveObjects() { return aliveObjects;}
		private:
		        string majorType;
			string _age;
			static int aliveObjects;	
	};
}

#endif //EDUCATIONALSOFTWARE_H
