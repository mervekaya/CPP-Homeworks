//This is the header file 111044035HW06_GraphicsSoftware.h
//This is the interface for the class GraphicsSoftware .

#ifndef GRAPHICSSOFTWARE_H
#define GRAPHICSSOFTWARE_H

#include <iostream>
#include "111044035HW06_ApplicationSoftware.h"

namespace KayaSoftware 
{
	class GraphicsSoftware : public ApplicationSoftware
	{
		public:
			GraphicsSoftware();
			GraphicsSoftware(string newname,bool access,string nameSystem,string nameGrap,string nameClass);
			string getNameGrapSoft() const;// such as adobe photoshop
			void setNameGrapSoft(const string name);// most used and best-known graphics programs in the Americas
			string getClassName() const; // vector and raster
			void setClassName(const string name);
			int static getNumAliveObjects() { return aliveObjects;}
		private:
		      	string nameGrapSoft;
			string classNameGrap;
			static int aliveObjects;	
	};
}

#endif // GRAPHICSSOFTWARE_H
