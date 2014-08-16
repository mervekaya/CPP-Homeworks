//This is the header file 111044035HW06_ApplicationSoftware.h
//This is the interface for the class ApplicationSoftware.

// This class has two data members.
// canAcces : People can access,use easily application software
// nameOfSystem : Some applications work on only specific operating system.

#ifndef APPLICATIONSOFTWARE_H
#define APPLICATIONSOFTWARE_H

#include <iostream>
#include "111044035HW06_Software.h"

namespace KayaSoftware 
{
	class ApplicationSoftware : public Software
	{
		public:
			ApplicationSoftware();
			ApplicationSoftware(string newname,bool access,string nameSystem);
			void setCanAccess(const bool access);
			bool getCanAccess() const;
			string getNameOfOpe() const;
			void setNameOfOpe(const string name);
			int static getNumAliveObjects() { return aliveObjects;}
		protected:
			static int aliveObjects;
			bool canAccess;
			string nameOfSystem;
	};
}

#endif //APPLICATIONSOFTWARE_H
