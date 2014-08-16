// This is the implementation file 111044035HW06_GraphicsSoftware.cpp of the class GraphicsSoftware.
//The interface for the class GraphicsSoftware is in the header file 111044035HW06_GraphicsSoftware.h

#include "111044035HW06_GraphicsSoftware.h"

namespace KayaSoftware
{
	GraphicsSoftware::GraphicsSoftware() : ApplicationSoftware()
	{
		nameGrapSoft = "No name yet.";
		classNameGrap = "No name yet.";
		++aliveObjects;
	}
	GraphicsSoftware::GraphicsSoftware(string newname,bool access,string nameSystem,string nameGrap,string nameClass)
			 :ApplicationSoftware(newname,access,nameSystem)
	{
		setNameGrapSoft(nameGrap);
		setClassName(nameClass);
		++aliveObjects;
	}
	string GraphicsSoftware::getNameGrapSoft() const
	{
		return nameGrapSoft;
	}
	void GraphicsSoftware::setNameGrapSoft(const string name)
	{
		nameGrapSoft = name;	
	}
	string GraphicsSoftware::getClassName() const
	{
		return classNameGrap;
	}
	void GraphicsSoftware::setClassName(const string name)
	{
		classNameGrap = name;
	}
}
