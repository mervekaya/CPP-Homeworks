// **********************************************************
// Created on 14/11/2013 by Merve KAYA
// ID No : 111044035
//This program make star system and overload some operators.
//***********************************************************

#include <iostream>
#include <string>
#include <cstdlib>
#include "111044035HW05_StarSystem.h"

using namespace std;

void testFuncForCallByReference(StarSystem &solarSystem,Planet &planet);
void testFuncCallByValue(StarSystem system,Planet _planet);

int main(void)
{
	Planet mercury("Mercury",4878,5.79e7,3.3e20),
	       venus("Venus",12104,1.082e8,4.87e21),
	       earth("Earth",12756,1.496e8,5.976e21),
	       mars("Mars",6794,2.279e8,6.42e20),
	       jupiter("Jupiter",142800,7.783e8,1.90e24),
	       saturn("Saturn",120536,14294e9,5.68e23),
	       neptune("Neptune",49532,4.504e9,1.02447e23),
	       uranus("Uranus",51118,2.87099e9,8.63e22);

	Planet planetB("Planet b",51400,7.236e10,9.64e20),
	       planetC("Planet c",27845,6.24e20,8.45e21);

	Planet *epsilonPlanets = new Planet[2];
	epsilonPlanets[0] = planetB;
	epsilonPlanets[1] = planetC;

	Planet *planets = new Planet[8];
	planets[0] = mercury;
	planets[1] = venus;
	planets[2] = earth;
	planets[3] = mars;
	planets[4] = jupiter;
	planets[5] = saturn;
	planets[6] = neptune;
	planets[7] = uranus;


	StarSystem solarSystem("Solar System",8,planets);
	StarSystem epsilonEridani("Epsilon Eridani",2,epsilonPlanets);

	StarSystem *stars = new StarSystem[2];
	// This prove overload [] operator.
	stars[0] = solarSystem;
	stars[1] = epsilonEridani;

	int i,number;
	for( i = 0 ; i < 2 ; ++i)
		cout << stars[i] << endl;

	cout << "To test Call by reference press 1 , to test call by value press 2" << endl;
	cin >> number;

	if(number == 1)
		testFuncForCallByReference(solarSystem,jupiter);
	else if(number == 2)
		testFuncCallByValue(epsilonEridani,planetB);
	else
	{
		cerr << "Wrong number.\nExiting..." << endl;
		exit(1);
	}
	
	cout << "Test for == and >= operator. \n" << endl;
	// For test <= overload 
	if(mars >= saturn)
		cout << "Wight of mars greater than saturn." << endl;
	else
		cout << "Weight of saturn greater than mars." << endl;

	// For test == overload
	if(jupiter == venus)
		cout << "Weight of jupiter equal venus." << endl;
	else
		cout << "Weight of jupiter not equal venus." << endl << endl;

	delete [] epsilonPlanets;
	delete [] planets;
	delete [] stars;
	return 0;
}

void testFuncForCallByReference(StarSystem &solarSystem,Planet &planet)
{
	
	int number;
	cout << "To test exract operator(-=) press 1 , to test insert operator(+=) press 2" << endl;
	cin >> number;

	// For test -= operator.
	if(number == 1)
	{
		solarSystem -= planet;
		cout << solarSystem << endl;
	}

	// For test += operator.
	else if(number == 2)
	{
		solarSystem += planet;
		cout << solarSystem << endl;
	}
	else
	{
		cerr << "Wrong number !\nExiting.... ";
		exit(1);
	}
}
void testFuncCallByValue(StarSystem system,Planet _planet)
{
	int number;
	cout << "To test exract operator(-=) press 1 , to test insert operator(+=) press 2" << endl;
	cin >> number;

	// For test -= operator.
	if(number == 1)
	{
		system -= _planet;
		cout << system << endl;
	}

	// For test += operator.
	else if(number == 2)
	{
		system += _planet;
		cout << system << endl;
	}
	else
	{
		cerr << "Wrong number !\nExiting.... ";
		exit(1);
	}
}
