// This is the implementation file 111044035HW07_SortedList.cpp of the class SortedList.
//The interface for the class SortedList is in the header file 111044035HW07_SortedList.h

#include "111044035HW07_SortedList.h"
#include <ostream>
#include <new>

using std::bad_alloc;
using::std::cout;

namespace KayaList
{
	template <class T>
	SortedList<T>::SortedList() 
	{
		try
		{
			this->used = 0;
			this->capacity = 50;
			this->list = new T[this->capacity];
		}
		catch(bad_alloc)
		{
			cout << "Run out of memory.!\n";
		}
	}

	template<class T>
	SortedList<T>::SortedList(int number) 
	{
		try
		{
			this->used = 0;
			this->capacity = number;
			this->list = new T[this->capacity];
		}
		catch(bad_alloc)
		{
			cout << "Run out of memory.!"<< endl;
		}
	}

	// This function make binary search.
    template <class T>
    int SortedList<T>::searchElement(T element)
    {
        int first = 0,
            middle,
            last = this->numberOfElement() - 1;

        while(last >= first)
        {
            middle = (first + last ) / 2;
            if(element > this->list[middle])
                first = middle + 1;
						else if(element < this->list[middle])
                    last = middle - 1;
             else
                return middle;
        }

        return 0; //If it is not found
    }

	//In this function if input smaller than an element 
	//within the list ,it copies after element to another list,
	// add element and then add copy list in real list.
   template <class T>
	List<T>& SortedList<T>:: addElement(T element)
	{
		try
		{
			T *temp = new T[this->numberOfElement()];
			int i;

			for(i = 0 ; i < this->numberOfElement() ; ++i)
				temp[i] = this->list[i];
			this->list = new T[this->numberOfElement() * 2];

			for(i = 0 ; i < this->numberOfElement() ; ++i)
				this->list[i] = temp[i];

			delete [] temp;

		
			for(i  = 0 ; i < this->numberOfElement() ; ++i)
			{
				if(element <= this->list[i])
				{
					T *temp = new T[this->numberOfElement() - i];
					int j,k;
					k = i;
					for(j = 0 ; j < this->numberOfElement() - i; ++j,++k)
						temp[j] = this->list[k];

					this->list[this->numberOfElement() - j] = element;
					for(k = 0 ; k < j ; ++k)
						this->list[this->numberOfElement() - j + k + 1] = temp[k];
					delete [] temp;
					++this->used;
					return *this;
				}
			}
	
			this->list[this->used] = element;
			++this->used;
			return *this;
		}
		catch(bad_alloc)
		{
			cout << "Run out of memory.!" << endl;
		}
			
	}

	//In this function if the element is in the list
	//(search element) remove element and increase used.
    	template <class T>
	List<T>& SortedList<T>::removeElement(T element)
	{
	    int index,i;
	    index = searchElement(element);
	    if(index != 0)
        {
            for(i = index ; i < this->numberOfElement() - 1 ; ++i)
                this->list[i] = this->list[i + 1];
                --this->used;

        }
       	 return *this;
	}

   //returning a new List which is the union of two parameters 
    template<class T>
   List<T>& SortedList<T>::operator +(const List<T>& otherList)
    {
        	int i = 0;
       	        List<T> *newList = new SortedList<T>;

	    for( i = 0 ; i < this->numberOfElement() ; ++i)
					newList->addElement(this->list[i]);

	    for(i = 0; i < otherList.numberOfElement() ; ++i)
            newList->addElement(otherList.at(i));

            return *newList;
    }

   //  returning a new List which is the intersection of two parameters 
    template<class T>
    List<T>& SortedList<T>::operator %(const List<T>& otherList)
    {
        int i,j;
				try
				{
       	 	List<T> *intersection = new SortedList<T>;

        	for(i = 0 ; i < this->numberOfElement() ; ++i)
       		 {
							for(j = 0; j < otherList.numberOfElement() ; ++j)
                		if(this->list[i] == otherList.at(j))
                		{
                    			intersection->addElement(this->list[i]);
                		}
        	}
					return *intersection;
    	}
			catch(bad_alloc)
			{
				cerr << "Run out of memory.!" << endl;
			}
 		}


}
