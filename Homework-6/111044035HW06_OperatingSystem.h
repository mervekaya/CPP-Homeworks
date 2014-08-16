//This is the header file 111044035HW06_OperatingSystem.h
//This is the interface for the class OperatingSystem.

#ifndef OPERATINGSYSTEM_H
#define OPERTATINGSYSTEM_H

#include <iostream>
#include "111044035HW06_SystemSoftware.h"

namespace KayaSoftware 
{
	class OperatingSystem : public SystemSoftware
	{
		public:
			OperatingSystem();
			OperatingSystem(string sysname,bool priority,string newname,string othername,bool isOpen,int number);
			bool getIsOpenSource() const;
			void setIsOpenSource(const bool source);
			int getNumOfOpeSystem() const;
			void setNumOfOpeSystem(const int number);
			int static getNumAliveObjects() { return aliveObjects;}
		private:
		        int numberSystem; // Number of operating system
			bool _source; // Is open source?
			static int aliveObjects;	
	};
}

#endif //OPERATINGSYSTEM_H
