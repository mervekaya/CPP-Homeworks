// This is the implementation file 111044035HW07_UniqueList.cpp of the class UniqueList.
//The interface for the class UniqueList is in the header file 111044035HW07_UniqueList.h

#include "111044035HW07_UniqueList.h"

namespace KayaList
{
	template<class T>
	UniqueList<T>::UniqueList()
	{
		try
		{
			this->used = 0;
			this->capacity = 50;
			this->list = new T[this->capacity];
		}
		catch(bad_alloc)
		{
			cerr << "Run out of memory.!" << endl;
		}
	}

	template<class T>
	UniqueList<T>::UniqueList(int number) 
	{
		try
		{
			this->used = 0;
			this->capacity = number;
			this->list = new T[this->capacity];
		}
		catch(bad_alloc)
		{
			cerr << "Run out of memory.!" << endl;
		}
	}

	// This function search element.If it is found
	// return index of element,if it not found return 0.
	template<class T>
	int UniqueList<T>::searchElement(T number)
	{
		int i = 0;
		for(i ; i < this->numberOfElement(); ++i)
		{
			if(this->list[i] == number)
				return i;
		}
		return -1;
	}

	//This function ,firstly search element in list.
	// If it not found add element in list.
	template<class T>
	List<T>& UniqueList<T>::addElement(T element)
	{
		try
		{
			if(searchElement(element) < 0)
			{
				T *tempList = new T[this->numberOfElement()];
				int i;
				for(i = 0 ; i < this->numberOfElement() ; ++i)
					tempList[i] = this->list[i];

				this->list = new T[this->numberOfElement() * 2];
				for(i = 0 ; i < this->numberOfElement() ; ++i)
					this->list[i] = tempList[i];

				this->list[this->used] = element;
		      		  ++this->used;

				delete [] tempList;
			}
		return *this;
		}
		catch(bad_alloc)
		{
			cerr << "Run out of memory.!"<<endl;
		}
	}

	//In this function if the element is in the list
	//(search element) remove element and increase used.
	template<class T>
	List<T>& UniqueList<T>::removeElement(T element)
	{
		int index = searchElement(element);
		if(index >= 0)
		{
			for(index ; index < this->numberOfElement() - 1 ; ++index)
				this->list[index] = this->list[index+1];
				--this->used;
		}
		return *this;
	}

	//returning a new List which is the union of two parameters 
	template<class T>
	List<T>& UniqueList<T>::operator +(const List<T>& otherList)
	{
		int i = 0;
		try
		{
			List<T> *newList = new UniqueList<T>;

			 i = 0;
			for(i ; i < this->numberOfElement() ; ++i)
				newList->addElement(this->list[i]);
       			 for(i = 0; i < otherList.numberOfElement() ; ++i)
          		  	newList->addElement(otherList.at(i));
			return *newList;
		}
		catch(bad_alloc)
		{
			cerr << "Run out of memory.!"<< endl;
		}

            
	}

	//  returning a new List which is the intersection of two parameters 
	template<class T>
	List<T>& UniqueList<T>::operator %(const List<T>& otherList)
	{
	    int i,j,k = 0;
		try
		{
			List<T> *intersection = new UniqueList<T>;

       			 for(i = 0 ; i < this->numberOfElement() ; ++i)
        			 {
           			 for(j = 0 ; j < otherList.numberOfElement() ; ++j)
               				 if(this->list[i] == otherList.at(j))
               				 {
						if(intersection->searchElement(this->list[i]) < 0)
							intersection->addElement(this->list[i]);
														
               				 }
               				 
        		    }
        		    return *intersection;
		}
		catch(bad_alloc)
		{
			cerr << "Run out of memory.!\n";
		}
		
	}
}
