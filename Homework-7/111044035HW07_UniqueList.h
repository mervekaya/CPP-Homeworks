//This is the header file 111044035HW07_UniqueList.h
//This is the interface for the class UniqueList.

//This class has not data member.Becaause it is inherited from
//base class 'List'.

#ifndef UNIQUELIST_H
#define UNIQUELIST_H

#include <iostream>
#include "111044035HW07_List.h"

namespace KayaList
{
	template<class T>
	class UniqueList : public List<T>
	{
	public:
		UniqueList<T>();
		UniqueList<T>(int number);

    int searchElement(T element);
    List<T>& addElement(T element);
		List<T>& removeElement(T element);

		List<T>& operator +(const List<T>& otherList);
		List<T>& operator %(const List<T>& otherList);
	};
}
#endif // !UNIQUELIST_H

