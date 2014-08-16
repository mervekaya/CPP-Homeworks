//This is the header file 111044035HW06_CommunicationSoftware.h
//This is the interface for the class CommunicationSoftware.

// This class has two data members.
// chatDate : First chat date
// nameFirstChat : Name of first chat

#ifndef COMMUNICATIONSOFTWARE_H
#define COMMUNICATIONSOFTWARE_H

#include <iostream>
#include "111044035HW06_ApplicationSoftware.h"

namespace KayaSoftware 
{
	class CommunicationSoftware : public ApplicationSoftware
	{
		public:
			CommunicationSoftware();
			CommunicationSoftware(string newname,bool access,string nameSystem,int date,string firstName);
			int getFirstChatDate() const; 
			void setFirstChatDate(const int date);
			string getFirstChatName() const;
			void setFirstChatName(const string chatName);
			int static getNumAliveObjects() { return aliveObjects;}
		private:
		      	int chatDate;
			string nameFirstChat;
			static int aliveObjects;	
	};
}

#endif // COMMUNICATIONSOFTWARE_H
