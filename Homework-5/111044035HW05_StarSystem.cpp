//This is the implemantation file StarSystem.cpp of the class StarSystem
//The interface for the class StarSystem is in the header file StarSystem.h

#include "111044035HW05_StarSystem.h"

StarSystem::StarSystem()
{
	numberOfPlanets = 0;
	nameOfStar = " ";
	planet = NULL;
}

//Uses string:
StarSystem::StarSystem(string name,int numberPlanet,Planet *_planet)
{
	setSystem(name,numberPlanet,_planet);
}

//Uses string:
StarSystem::StarSystem(string name)
{
	nameOfStar = name;
	planet = NULL;
}

//Uses string
StarSystem::StarSystem(string name,Planet *_planet)
{
	nameOfStar = name;
	int i;
	for(i = 0 ; _planet != NULL ; ++i)
		planet[i] = _planet[i];
	numberOfPlanets = i - 1;
}
StarSystem::StarSystem(const StarSystem& starObject)
{
	numberOfPlanets = starObject.getNumber();
	nameOfStar = starObject.getName();
	planet = new Planet[numberOfPlanets];

	int i;
	for(i = 0 ; i < numberOfPlanets ; ++i)
		planet[i] = starObject[i];
}

void StarSystem::setSystem(string name,int numberPlanet,Planet *_planet)
{
    int i;
	nameOfStar = name;

	if(numberPlanet < 0 )
		numberOfPlanets = 0;
	else
		numberOfPlanets = numberPlanet;

	planet = new Planet[numberPlanet];

	for(i = 0 ; i < numberOfPlanets ; ++i)
		planet[i] = _planet[i];

}

string StarSystem::getName() const
{
	return nameOfStar;
}
int StarSystem::getNumber() const
{
	return numberOfPlanets;
}

StarSystem& StarSystem::operator =(const StarSystem& rightSide)
{
	if(numberOfPlanets != rightSide.getNumber() )
	{
		delete [] planet;
		planet = new Planet[rightSide.getNumber()];
	}
	numberOfPlanets = rightSide.getNumber();
	int i ;
	for(i = 0 ; i < numberOfPlanets ; ++i)
		planet[i] = rightSide[i];

	return *this;
}

//Uses iostream
ostream& operator <<(ostream& outputStream,const StarSystem& star)
{
	outputStream << "Star Name : " << star.nameOfStar << endl;
	outputStream << "Number of planets that orbit the star = " << star.numberOfPlanets << endl;
	int i;
	for(i = 0 ; i < star.getNumber() ; ++i)
		outputStream << star.planet[i] << endl << endl;
	
	return outputStream;
}
StarSystem& StarSystem::operator +=(const Planet& _planet)
{
	Planet *tempPlanet = new Planet[numberOfPlanets];
	int i;
	for(i = 0 ; i < numberOfPlanets ; ++i)
		tempPlanet[i] = planet[i];

	planet = new Planet[numberOfPlanets + 1];
	for(i = 0 ; i < numberOfPlanets ; ++i)
		planet[i] = tempPlanet[i];

	planet[numberOfPlanets] = _planet;
        numberOfPlanets++;

	delete [] tempPlanet;
	return *this;
	
}
StarSystem& StarSystem::operator -=(const Planet& _planet)
{
	int i;
	for(i = 0 ; i < numberOfPlanets ; ++i)
	{
		if(planet[i] == _planet)
		{
			for(i;i < numberOfPlanets - 1 ; ++i)
				planet[i] = planet[i + 1];
			--numberOfPlanets;
			return *this;
		}
	}
	return *this;
}
Planet& StarSystem::operator [](int index) const
{
	return planet[index];
}
StarSystem::~StarSystem()
{
	delete [] planet;
}















