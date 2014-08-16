//This is the header file 111044035HW06_SystemSoftware.h
//This is the interface for the class SystemSoftware.


#ifndef SYSTEMSOFTWARE_H
#define SYSTEMSOFTWARE_H

#include <iostream>
#include "111044035HW06_Software.h"

namespace KayaSoftware 
{
	class SystemSoftware : public Software
	{
		public:
			SystemSoftware();
			SystemSoftware(string softname,bool priority,string newname,string othername);
			string getFirstName() const;
			string getSecondName() const;
			void setFirstIntType(const string firstIntType);
			void setSecIntType(const string secIntType);
			bool getPriority() const;
			void setPriority(const bool priority);
			int static getNumAliveObjects() { return aliveObjects;}
		protected:
		        bool _priority; // When computer is opened , first system software works.
			string firstInterfaceType; // System Software is between hardware and application software.
			string secInterfaceType;
			static int aliveObjects;	
	};
}

#endif //SYSTEMSOFTWARE_H
