/*
*   Student ID : 111044035
*   Created by Merve KAYA on 01.12.2013
*  
*/


#include <iostream>
#include "111044035HW06_CommunicationSoftware.h"
#include "111044035HW06_SystemSoftware.h"
#include "111044035HW06_EducationalSoftware.h"
#include "111044035HW06_FileManager.h"
#include "111044035HW06_FreeMultimediaSoftware.h"
#include "111044035HW06_OperatingSystem.h"
#include "111044035HW06_GraphicsSoftware.h"
#include "111044035HW06_ApplicationSoftware.h"

using namespace std;
using namespace KayaSoftware;

int Software::aliveObjects = 0;
int ApplicationSoftware::aliveObjects = 0;
int SystemSoftware::aliveObjects = 0;
int CommunicationSoftware::aliveObjects = 0;
int FileManager::aliveObjects = 0;
int FreeMultimediaSoftware::aliveObjects = 0;
int GraphicsSoftware::aliveObjects = 0;
int OperatingSystem::aliveObjects = 0;
int EducationalSoftware::aliveObjects = 0;

int main()
{
    
    //Test for Software class
    Software software("Kaya Software");
    cout << "----------------------------------------------------------------------------" << endl;
    cout << "This is <Software class> and name of the software is " << software.getName() << endl;
    cout << "There are " << Software::getNumAliveObjects() << " item objects." << endl;
    cout << "----------------------------------------------------------------------------" << endl;
	
   //Test for ApplicationSoftware class
   ApplicationSoftware appSoft("Application Software",true,"Ubuntu");
   cout << "This is <ApplicationSoftware class> and name of the software is " << appSoft.getName() << endl;
   cout << "In this kind of software people can easily access  application, " <<endl;
   cout << "so this is true ."<< appSoft.getCanAccess() << " " << endl;
   cout << "Some applications works on only specific operating system.For example this " << endl;
   cout << "application works on "<< appSoft.getNameOfOpe() << endl;
   cout << "There is " << ApplicationSoftware::getNumAliveObjects() << " item Application Software objects "<<endl;
   cout << "Number of the total objects :  " << Software::getNumAliveObjects() << endl;
   cout << "----------------------------------------------------------------------------" << endl;

   //Test for System Software class
   SystemSoftware sysSoft("System Software",true,"Hardware","Application Software");
   cout << "This is <SystemSoftware class> and name of the software is " << sysSoft.getName() << endl;
   cout << "The priority of this kind of software is first.So this is true." << sysSoft.getPriority() << endl;
   cout << "System software acts as an interface between the " << sysSoft.getFirstName()<< endl;
   cout << "of the computer and the " << sysSoft.getSecondName() << endl;
   cout << "There is " << SystemSoftware::getNumAliveObjects() << " item System Software objects "<<endl;
   cout << "Number of the total objects : " << Software::getNumAliveObjects() << endl;
   cout << "----------------------------------------------------------------------------" << endl;

   //Test for Communication Software class
   CommunicationSoftware comSoft("Communication Software",true,"Windows",1985,"Bitney Relay");
   cout << "This is <CommunicationSoftware class> and name of software is " << comSoft.getName() << endl;
   cout << "Since people can easily access application software,people also can easily access " ;
   cout << "Communication Software . So this is true." << comSoft.getCanAccess() << " " << endl;
   cout << "Communication Software works on " << comSoft.getNameOfOpe() << endl;
   cout << "First chat date : " << comSoft.getFirstChatDate() << endl;
   cout << "The first chat name : " << comSoft.getFirstChatName() << endl;
   cout << "There is " << CommunicationSoftware::getNumAliveObjects() << " item Communication Software objects "<<endl;
   cout << "Number of the total objects : " << Software::getNumAliveObjects() << endl;
   cout << "----------------------------------------------------------------------------" << endl;

   //Test for File Manager class
   FileManager fileMan("File Manager",true,"Hardware","Application Software","Files","FTP");
   cout << "This is <FileManager class> and name of the software is " << fileMan.getName() << endl;
   cout << "Since priority of System Software true also this is true." << fileMan.getPriority() << endl;
   cout << "File Manager acts as an interface between the " << fileMan.getFirstName()<< endl;
   cout << "of the computer and the " << fileMan.getSecondName() << endl;
   cout << "Operations performed on " << fileMan.getOperation() << endl;
   cout << "Some file managers provide network connectivity via protocols, such as " << fileMan.getProtocol() << endl;
   cout << "There is " << FileManager::getNumAliveObjects() << " item File Maneger objects "<<endl;
   cout << "Number of the total objects : " << Software::getNumAliveObjects() << endl;
   cout << "----------------------------------------------------------------------------" << endl;

   //Test for Free Multimedia Software class
   FreeMultimediaSoftware multSoft("Free Multimedia Software",true,"Ubuntu",8,true);
   cout << "This is <FreeMultimediaSoftware class> and name of software is " << multSoft.getName() << endl;
   cout << "Since people can easily access application software,people also can easily access " ;
   cout << "Free Multimedia Software . So this is true." << multSoft.getCanAccess() << " " << endl;
   cout << "Free Multimedia Software works on " << multSoft.getNameOfOpe() << endl;
   cout << "Free Multimedia Software has " << multSoft.getNumOfSubcategory() << " subcategories" << endl;
   cout << "Since of free and open source people can modify or change .So this is true " << multSoft.getcanModify() << endl;
   cout << "There is " << FreeMultimediaSoftware::getNumAliveObjects() << " item Free Multimedia Software objects "<<endl;
   cout << "Number of the total objects : " << Software::getNumAliveObjects() << endl;
   cout << "----------------------------------------------------------------------------" << endl;

   //Test for Operating System class
   OperatingSystem opeSys("Ubuntu",true,"Hardware","Application Software","true",11);
   cout << "This is <OperatingSystem class> and name of the software is " << opeSys.getName() << endl;
   cout << "Priority of Operating System first.So this is true." << opeSys.getPriority() << endl;
   cout << "Operating System acts as an interface between the " << opeSys.getFirstName()<< endl;
   cout << "of the computer and the " << opeSys.getSecondName() << endl;
   cout << "Ubuntu is open source . This is true -> " << opeSys.getIsOpenSource() << endl;
   cout << "Number of operating systems : " << opeSys.getNumOfOpeSystem() << endl;
   cout << "There is " << OperatingSystem::getNumAliveObjects() << " item Operating System objects "<<endl;
   cout << "Number of the total objects : " << Software::getNumAliveObjects() << endl;
   cout << "----------------------------------------------------------------------------" << endl;
   
   //Test for Graphics Software class
   GraphicsSoftware grapSoft("Graphics Software",true,"Windows","Adobe Photoshop","vector");
   cout << "This is <GraphicsSoftware class> and name of software is " << grapSoft.getName() << endl;
   cout << "Since people can easily access application software,people also can easily access " ;
   cout << "Graphics Software. So this is true." << grapSoft.getCanAccess() << " " << endl;
   cout << "Graphics Software works on " << grapSoft.getNameOfOpe() << endl;
   cout << "Most used and best-known graphics programs in the Americas : " << grapSoft.getNameGrapSoft() << endl;
   cout << "The class name of the graphics program : " << grapSoft.getClassName() << endl;
   cout << "There is " << GraphicsSoftware::getNumAliveObjects() << " item Graphics Software objects "<<endl;
   cout << "Number of the total objects : " << Software::getNumAliveObjects() << endl;
   cout << "----------------------------------------------------------------------------" << endl;

   //Test for Educational Software class
   EducationalSoftware eduSoft("DoudouLinux",true,"Hardware","Application Software","young","Courseware");
   cout << "This is <EducationalSoftware class> and name of the software is " << eduSoft.getName() << endl;
   cout << "Priority of Educational is first. So this is true." << eduSoft.getPriority() << endl;
   cout << "Educational Software acts as an interface between the " << eduSoft.getFirstName()<< endl;
   cout << "of the computer and the " << eduSoft.getSecondName() << endl;
   cout << "This software for " << eduSoft.getAge() << endl;
   cout << "The major type of educational software is " << eduSoft.getMajorType() << endl;
   cout << "There is " << EducationalSoftware::getNumAliveObjects() << " item Educational Software objects "<<endl;
   cout << "Number of the total objects : " << Software::getNumAliveObjects() << endl;
   cout << "----------------------------------------------------------------------------" << endl;

    return 0;
}

