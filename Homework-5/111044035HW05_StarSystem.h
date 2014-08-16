//This is the header file StarSystem.h . This is the interface for the class
//StarSystem. This file include array of planets,overload +=,-=,[],insertion operator 
// and big three.

#ifndef STAR_H
#define STAR_H

#include <iostream>
#include <string>
#include "111044035HW05_Planet.h"

class StarSystem{

public:
	
	StarSystem();
	//Initializes name ' ',number of planet 0 and *planet = NULL
	StarSystem(string name,int numberPlanet,Planet *planet);
	StarSystem(string name);
	StarSystem(string name,Planet *_planet);
	void setSystem(string name,int numberStar,Planet *planet);
	string getName() const;
	int getNumber() const;
	StarSystem& operator +=(const Planet& _planet);
	StarSystem& operator -=(const Planet& _planet);
	Planet& operator [](int index) const;
	StarSystem(const StarSystem& starObject); // copy constructor
	StarSystem& operator =(const StarSystem& rightSide); // overloaded assigment
	friend ostream& operator <<(ostream& outputStream,const StarSystem& star);
	~StarSystem(); // destructor

private:
	Planet *planet;
	int numberOfPlanets;
	string nameOfStar;
};

#endif 
