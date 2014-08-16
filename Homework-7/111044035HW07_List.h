#ifndef LIST_H
#define LIST_H

#include <iostream>

using namespace std;
namespace KayaList
{
	
	template<class T>
	class List
	{
	public:
		List<T>();
		T& getList() const;
		void setList(T *newList);

		List<T>(int capasityValue);
	  int getCapacity() const {return capacity;}
       

		List<T>(const List<T>& newList) ;
    List<T>& operator =(const List<T>& rightside);
		virtual ~List();

		virtual List<T>& addElement(T element);
		virtual List<T>& removeElement(T element) = 0;

    int numberOfElement () const;
    T at(int index) const;


		virtual List<T>& operator +=(const List<T>& otherList) ;

		virtual List<T>& operator +(const List<T>& otherList) = 0;
		virtual List<T>& operator %(const List<T>& otherList) = 0;
   	virtual int searchElement(T element) = 0;

		inline friend ostream& operator <<(ostream& outputStream,const List<T>& newList)
	{
		for(int i = 0 ; i < newList.numberOfElement() ; ++i)
			outputStream << newList.at(i) << " /";

		return outputStream;
	}


	protected:
		T *list;
		int capacity;
		int used;

	};
}
#endif // !LIST_H
