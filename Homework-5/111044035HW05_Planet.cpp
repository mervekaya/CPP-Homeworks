//This is the implementation file Planet.cpp of the class Planet.
//The interface for the class Planet is in the header file Planet.h

#include "111044035HW05_Planet.h"

Planet::Planet()
{
	planetName = " ";
	diameterOfPlanet = 0;
	weightInTons = 0;
	distanceFromMainStar = 0;
}

Planet::Planet(string nameOfPlanet)
	   :planetName(nameOfPlanet)
{
	// Body intentionally empty.
}

Planet::Planet(string name,int diameter,double distance,double weight)
{
	setPlanetName(name);
	setDiameterOfPlanet(diameter);
	setDistanceFromMainStar(distance);
	setWeightOfPlanet(weight);
}
void Planet::setPlanetName(const string nameOfPlanet)
{
	planetName = nameOfPlanet;
}

void Planet::setDiameterOfPlanet(long int diameter)
{
	if(diameter < 0)
	{
		Planet();
	}
	else
		diameterOfPlanet = diameter;
}

void Planet::setWeightOfPlanet(long double weight)
{
	if(weight < 0)
	{
		Planet();
	}
	else
		weightInTons = weight;
}

void Planet::setDistanceFromMainStar(long double distance)
{
	if(distance < 0)
	{
		Planet();
	}
	else
		distanceFromMainStar = distance;
}

//Uses string
string Planet::getName() const
{
	return planetName;
}
int Planet::getDiameter() const
{
	return diameterOfPlanet;
}
long double Planet::getWight() const
{
	return weightInTons;
}
long double Planet::getDistance() const
{
	return distanceFromMainStar;
}

Planet Planet::operator ++()
{
	++diameterOfPlanet;
	return Planet(planetName,diameterOfPlanet,distanceFromMainStar,weightInTons);
}

Planet Planet::operator ++(int ignore)
{
	int tempDiameter = diameterOfPlanet;
	diameterOfPlanet++;
	return Planet(planetName,tempDiameter,distanceFromMainStar,weightInTons);
}

Planet Planet::operator --()
{
	--diameterOfPlanet;
	return Planet(planetName,diameterOfPlanet,distanceFromMainStar,weightInTons);
}
Planet Planet::operator --(int ignore)
{
	int tempDiameter = diameterOfPlanet;
	diameterOfPlanet--;
	return Planet(planetName,tempDiameter,distanceFromMainStar,weightInTons);
}
bool Planet::operator ==(const Planet& planet) const
{
	return ((diameterOfPlanet == planet.diameterOfPlanet) && 
            (distanceFromMainStar == planet.distanceFromMainStar) &&
		    (weightInTons == planet.weightInTons ));
}

bool Planet::operator <(const Planet& planet) const
{
	return (weightInTons < planet.weightInTons);
}

bool Planet::operator >(const Planet& planet) const
{
	return (weightInTons > planet.weightInTons);
}

bool Planet::operator <=(const Planet& planet) const
{
	return (weightInTons <= planet.weightInTons);
}

bool Planet::operator >=(const Planet& planet) const
{
	return (weightInTons >= planet.weightInTons);
}

//Uses iostream:
ostream& operator <<(ostream& outputStream,const Planet& planet)
{
	outputStream << "Planet Name : " << planet.planetName << endl;
	outputStream << "Diameter    : " << planet.diameterOfPlanet << endl;
	outputStream << "Distance From Main Star : " << planet.distanceFromMainStar << endl;
	outputStream << "Weight in Tons : " << planet.weightInTons << endl;

	return outputStream;
}
//Uses iostream
istream& operator >>(istream& inputStream,Planet& planet)
{
	inputStream >> planet.planetName;
	inputStream >> planet.diameterOfPlanet;
	inputStream >> planet.distanceFromMainStar;
	inputStream >> planet.weightInTons;

	return inputStream;
}


