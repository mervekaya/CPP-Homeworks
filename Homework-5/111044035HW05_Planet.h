//This is the header file Planet.h.This is the interface for the class
//Planet.This file include name of planet,diameter of planet,weight of planet 
// and distance from main star.This file also include overload postfix prefix increment 
// and decrement,== , <= , <, >,>= , stream insertion and exraction opreator.

#ifndef PLANET_H
#define PLANET_H

#include <iostream>
#include <string>

using namespace std;

class Planet
{
public:
	
	Planet();
	//Initializes weight ,diameter , distance 0 and name ' '
	Planet(string nameOfPlanet);
	Planet(string name,int diameter,double distance,double weight);
	void setPlanetName(const string nameOfPlanet);
	void setDiameterOfPlanet(long int diameter);
	void setWeightOfPlanet(long double weight);
	void setDistanceFromMainStar(long double distance);
	string getName() const;
	int getDiameter() const;
	long double getWight() const;
	long double getDistance() const;
	Planet operator ++(); // Prefix version
	Planet operator ++(int ignore); // Postfix versiyon
	Planet operator --(); // Prefix version
	Planet operator --(int ignore); // Postfix version
	bool operator ==(const Planet& planet) const;
	bool operator <(const Planet& planet) const;
	bool operator >(const Planet& planet) const;
	bool operator <=(const Planet& planet) const;
	bool operator >=(const Planet& planet) const;
	friend ostream& operator <<(ostream& outputStream,const Planet& planet);
	friend istream& operator >>(istream& inputStream,Planet& planet);

private:
	string planetName;
	int diameterOfPlanet;
    long double distanceFromMainStar;
	long double weightInTons;

};

#endif

