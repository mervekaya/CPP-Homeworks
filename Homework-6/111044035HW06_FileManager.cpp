//This is the implementation file 111044035HW06_FileManager.cpp of the class FileManager.
//The interface for the class FileManager is in the header file 111044035HW06_FileManager.h

#include "111044035HW06_FileManager.h"

namespace KayaSoftware
{
	FileManager::FileManager() : SystemSoftware()
	{
		_operation = "No operation name yet.";
		_protocol = "No protocol name yet.";
		++aliveObjects;
	}
	FileManager::FileManager(string newname,bool priority,string name,string othername,string operation,string protocol)
		    :SystemSoftware(newname,priority,name,othername)
	{
		_operation = operation;
		_protocol = protocol;
		++aliveObjects;	
	}
	string FileManager::getOperation() const 
	{
		return _operation;
	}
	string FileManager::getProtocol() const
	{
		return _protocol;
	}
	void FileManager::setProtocol(const string newProtocol)
	{
		_protocol = newProtocol;
	}
	void FileManager::setOperation(const string ope)
	{
		_operation = ope;
	}
}
