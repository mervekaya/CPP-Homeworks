//This is the header file 111044035HW06_FreeMultimediaSoftware.h
//This is the interface for the class FreeMultimediaSoftware.

#ifndef FREEMULTIMEDIASOFTWARE_H
#define FREEMULTIMEDIASOFTWARE_H

#include <iostream>
#include "111044035HW06_ApplicationSoftware.h"

namespace KayaSoftware 
{
	class FreeMultimediaSoftware : public ApplicationSoftware
	{
		public:
			FreeMultimediaSoftware();
			FreeMultimediaSoftware(string newname,bool access,string nameSystem,int category,bool change);
			int getNumOfSubcategory() const;
			void setNumOfSubcategory(const int number);
			bool getcanModify() const;
			void setCanModify(const bool change);
			int static getNumAliveObjects() { return aliveObjects;}
		private:
		      	int subcategory;
			bool modify; // since open source , people can modify,change code. 
			static int aliveObjects;	
	};
}

#endif //FREEMULTIMEDIASOFTWARE_H
