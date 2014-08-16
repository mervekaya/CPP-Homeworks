//This is the header file 111044035HW06_FileManager.h
//This is the interface for the class FileManager.

#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include "111044035HW06_SystemSoftware.h"

namespace KayaSoftware 
{
	class FileManager : public SystemSoftware
	{
		public:
			FileManager();
			FileManager(string newname,bool priority,string name,string othername,string operation,string protocol);
			string getOperation() const; // operations performed on files
			string getProtocol() const; // Some file managers provide network connectivity via protocols, such as FTP, NFS, SMB 
			void setProtocol(const string newProtocol);
			void setOperation(const string ope);
			int static getNumAliveObjects() { return aliveObjects;}
		private:
		      	string _operation; 
			string _protocol;
			static int aliveObjects;	
	};
}

#endif //FILEMANAGER_H
