#include <iostream>
#include "111044035HW07_List.h"
#include <new>
using std::bad_alloc;
using namespace std;

namespace KayaList
{
	template <class T>
	List<T>::List() : capacity(50),used(0)
	{
		try
	 {
			list = new T[capacity];
	  }
    catch(bad_alloc)
	  {
			cout << "Ran out of memory.!\n";
	   }
		}

    template <class T>
    List<T>::List(int capacityValue) :capacity(capacityValue)
    {
				used = 0;
        	try
	        {
						list = new T[capacity];
	        }
          catch(bad_alloc)
					{
						cout << "Ran out of memory.!\n";
					}
    }

	template<class T>
	T& List<T>::getList() const
	{
		return *list;
	}

	template<class T>
	void List<T>::setList(T *newList)
	{
		list = newList;
	}

	template <class T>
	int List<T>::numberOfElement() const
	{
		return used;
	}

	template<class T>
	List<T>::List(const List<T>& oldList)
	{
		list = new T[oldList.numberOfElement()];
		int i = 0;
		for(i ; i < oldList.numberOfElement() ; ++i)
			list[i] = oldList.list[i];
		used = oldList.numberOfElement();
	}

	template<class T>
	List<T>& List<T>::operator =(const List<T>& rightside)
	{
		if(numberOfElement() != rightside.numberOfElement())
		{
			delete [] list;
			list = new T[rightside.numberOfElement()];
		}
		used = rightside.numberOfElement();
		int i = 0;
		for(i ; i < numberOfElement() ; ++i)
            list[i] = rightside.list[i];

		return *this;
	}

	template<class T>
	List<T>& List<T>::addElement(T element)
	{
		try
		{
			T *tempList = new T[numberOfElement()];
			int i;
			for(i = 0 ; i < numberOfElement() ; ++i)
				tempList[i] = list[i];

			list = new T[numberOfElement()* 2];
			for(i = 0 ; i < numberOfElement() ; ++i)
				list[i] = tempList[i];

			list[used] = element;
		    	++used;

			delete [] tempList;
			return *this;
		}
		catch(bad_alloc)
		{
			cout << "Ran out of memory.!\n";
		}
	}

   	 template<class T>
	T List<T>::at(int index) const
	{
	    try
	    {
				if (index >= numberOfElement())
                 	throw index;
           	 return list[index];
       }  
       catch(int e)
       {
            cerr << "No index such -> " << e  << endl;
        }

	}

	template <class T>
	List<T>& List<T>::operator +=(const List<T>& newList)
	{
		int i = 0;
		for(i; i < newList.numberOfElement() ; ++i)
			this->addElement(newList.list[i]);

		return *this;
	}

	template<class T>
	List<T>::~List()
	{
	    delete [] list;
	}
}
