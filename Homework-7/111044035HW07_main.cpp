/*
*
*   Created by sort1 KAYA on 19/12/2013
*   ID : 111044035
*
*   This program has one base class and two derived class.
*   This classes remove element,add element,find number of element in class
*   Also this classes have overloading +,+=,% operators.User can access elements
*   of list like nameObje.at(5).
*
*/
#include <iostream>
#include "111044035HW07_UniqueList.cpp"
#include "111044035HW07_SortedList.cpp"
#include "111044035HW07_List.cpp"


using namespace std;
using namespace KayaList;

int main()
{
    SortedList<char> sort1,*intersection,*newSortL;
    SortedList<char> sort2;
    intersection = new SortedList<char>;
    newSortL = new SortedList<char>;

	sort1.addElement('m');
	sort1.addElement('e');
	sort1.addElement('r');
	sort1.addElement('v');
	sort1.addElement('e');
	sort2.addElement('k');
	sort2.addElement('a');
	sort2.addElement('y');
	sort2.addElement('a');
	sort2.addElement('y');
	sort2.addElement('g');
	sort2.addElement('y');
	sort2.addElement('t');
	sort2.addElement('e');

	cout << "This is sort1\n";
	//This shows overloading << operator.
	cout << sort1;
	cout << "\n----------------------------------------------------" << endl;

	cout << "This is sort2\n";
	cout << sort2;
	cout << "\n----------------------------------------------------" << endl;

	// sort1 + sort2
	cout << "sort1 + sort2 \n";
	newSortL =  dynamic_cast<SortedList<char>* >(&(sort1 + sort2));
	cout << *newSortL<< " " << endl;
	cout << "\n------------------------------------------------" << endl;

	cout << "Intersection of sort1 and sort2" << endl;
	intersection = dynamic_cast<SortedList<char>* >(&(sort1 % sort2));
	cout << *intersection<< "  " << endl;
	cout << "\n------------------------------------------------" << endl;


	sort2.removeElement('g');
	sort2.removeElement('y');
	sort2.removeElement('t');
	sort2.removeElement('e');
	cout << "After remove g,y,t,e" << endl;
	cout << sort2 << "  ";
	cout << "\n------------------------------------------------" << endl;



	// This is sort1 += sort2
	cout << "This is sort1 += sort2" << endl;
	sort1 += sort2;
	cout << sort1 ;
	cout << "\n------------------------------------------------" << endl;
	
	UniqueList<int> unique1,*intersect;
	UniqueList<int> unique2,*newUniq;
	intersect = new UniqueList<int>;
	newUniq = new UniqueList<int>;

	for(int i = 0 ; i < 10 ; ++i)
		unique1.addElement(i*2 + 4);
	for(int i = 0 ; i < 5 ; ++i)
		unique2.addElement(i + 2);

		// This shows overloading << operator.
		cout << "Unique1 : " << endl;
		cout << unique1 << " " << endl;
		cout << "\n------------------------------------------------" << endl;

	  cout << "Unique2 :" << endl;
		cout << unique2 << " ";
		cout << "\n------------------------------------------------" << endl;
	
	cout << "\nIntersection of unique1 and unique2" << endl;
	intersect = dynamic_cast<UniqueList<int>* >(&(unique1 % unique2));
	cout << *intersect << "  " << endl;
	
	cout << "\n------------------------------------------------" << endl;

	newUniq = dynamic_cast<UniqueList<int>* >(&(unique1 + unique2));
	cout << "unique1 + unique2" << endl;
	cout << *newUniq << " " << endl;
	cout << "\n------------------------------------------------" << endl;
	
	newUniq->removeElement(10);
	newUniq->removeElement(12);
	newUniq->removeElement(14);
	
	cout << "After remove 10,12,14" << endl;
	cout << *newUniq << " " << endl;
	cout << "\n------------------------------------------------" << endl;
	
	SortedList<int> sorted;
	UniqueList<int> unique;
	
	for(int i = 0 ; i < 6 ; ++i)
			sorted.addElement(3*i + 1);
	
	cout << "This is sorted :\n";
	cout << sorted << endl;
	cout << "\n------------------------------------------------" << endl;
	
	sorted += unique1;
	cout << "sorted += unique1 .return sorted list" << endl;
		cout << sorted << " " << endl;
	cout << "\n------------------------------------------------" << endl;
	
	unique += sorted;
	cout << "unique += sorted .return unique list" << endl;
	cout << unique << endl;
	cout << "\n------------------------------------------------" << endl;
	
	SortedList<double> sortDouble1,*interDoub;
	SortedList<double> sortDouble2,*newDoub;
	
	interDoub = new SortedList<double>;
	newDoub = new SortedList<double>;
	
	for(int i = 0 ; i < 10 ; ++i)
			sortDouble1.addElement(1.25*i);
	for(int i = 0 ; i < 6 ; ++i)
		  sortDouble2.addElement(2.50*i);
	cout << "This is sortDouble1\n";
	//This shows overloading << operator.
	cout << sortDouble1;
	cout << "\n----------------------------------------------------" << endl;

	cout << "This is sortDouble2\n";
	cout << sortDouble2;
	cout << "\n----------------------------------------------------" << endl; 
	
	cout << "sortDouble1 + sortDouble2 \n";
	newDoub =  dynamic_cast<SortedList<double>* >(&(sortDouble1 + sortDouble2));
	cout << *newDoub<< " " << endl;
	cout << "\n------------------------------------------------" << endl;

	cout << "Intersection of sortDouble1 and sortDouble2" << endl;
	interDoub = dynamic_cast<SortedList<double>* >(&(sortDouble1 % sortDouble2));
	cout << *interDoub<< "  " << endl;
	cout << "\n------------------------------------------------" << endl;
	
	sortDouble2.removeElement(5.0);
	sortDouble1.removeElement(7.50);
	sort1 += sort2;
	cout << "After remove 5 and 7.50 sortDouble1 += sortDouble2" << endl;
	cout << sortDouble1 << "  ";
	cout << "\n------------------------------------------------" << endl;
	
	UniqueList <double> uniqueDouble;
	for(int i = 1 ; i < 5 ; ++i )
		uniqueDouble.addElement(i*1.25);
		
	cout << "This is uniqueDouble \n";
	cout << uniqueDouble << endl;
	cout << "\n------------------------------------------------" << endl;
	
	uniqueDouble += sortDouble2;
	cout << "uniqueDouble += sortDouble2 .return unique list" << endl;
	cout << uniqueDouble << " " << endl;
	cout << "\n------------------------------------------------" << endl;
	
	sortDouble2 += uniqueDouble;
	cout << "sortDouble2 += uniqueDOuble .return sortList" << endl;
	cout << sortDouble2 << endl;
	cout << "\n------------------------------------------------" << endl;
	
	delete interDoub;
	delete newDoub;
	delete intersect;
	delete newUniq;
	delete intersection;
	delete newSortL;
	    return 0;
}
