// This is the implementation file 111044035HW06_CommunicationSoftware.cpp of the class CommunicationSoftware.
//The interface for the class CommunicationSoftware is in the header file 111044035HW06_CommunicationSoftware.h

#include "111044035HW06_CommunicationSoftware.h"

namespace KayaSoftware
{
	CommunicationSoftware::CommunicationSoftware() : ApplicationSoftware()
	{
		chatDate = 0;
		nameFirstChat = "No name yet.";
		++aliveObjects;
	}
	CommunicationSoftware::CommunicationSoftware(string newname,bool access,string nameSystem,int date,string firstName)
			      :ApplicationSoftware(newname,access,nameSystem)
	{
		chatDate = date;
		nameFirstChat = firstName;
		++aliveObjects;
	}
	int CommunicationSoftware::getFirstChatDate() const 
	{
		return chatDate;
	}
	void CommunicationSoftware::setFirstChatDate(const int date)
	{
		chatDate = date;
	}
	string CommunicationSoftware::getFirstChatName() const
	{
		return nameFirstChat;
	}
	void CommunicationSoftware::setFirstChatName(const string chatName)
	{
		nameFirstChat = chatName;
	}
}

