//This is the header file 111044035HW07_SortedList.h
//This is the interface for the class SortedList.

//This class has not data member.Becaause it is inherited from
//base class 'List'.

#ifndef SORTEDLIST_H
#define SORTEDLIST_H

#include <iostream>
#include "111044035HW07_List.h"

namespace KayaList
{
	template<class T>
	class SortedList : public List<T>
	{
	public:
		SortedList<T>();
		SortedList<T>(int number);

    int searchElement(T element);
    List<T>& addElement(T element);
		List<T>& removeElement(T element);

		List<T>& operator +(const List<T>& otherList);
		List<T>& operator %(const List<T>& otherList);
	};
}

#endif // !SORTEDLIST_H
