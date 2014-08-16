/*
*
*	Created by Merve KAYA on 26/10/2013
*
*	This program include only one class which point board position.
*
*/

#include <iostream>
#include <cstdlib>

using namespace std;

const int LINE_NUMBER = 8;
const int COLUMN_NUMBER = 8;
const int SIZE = 8;

class BoardPosition{

public:
	/* Eger kullanici sacma bir deger girerse A1'i referans olarak alir.*/
	BoardPosition() :columnLetter('A'),RowNum (1) { }
	BoardPosition(char firstChar,int firstNum);
	void setBoardPosition(char character,int number);
	void input();
	void output();
	char getCharacter() const;
	int getNumber() const;
	static int getNumberOfPosition() { return numberOfPosition ;}

private:
	static int numberOfPosition;
	bool checkBoardPosition();
	char columnLetter;
	int RowNum;
};

int BoardPosition::numberOfPosition = 0;

int main(void)
{
	int i;
	BoardPosition position1,position2('B',2),position3;
	// Test etmek icin.
	position1.input();
	position1.output();
	position2.output();
	position3 = BoardPosition('C',3);
	position3.output();
	cout << BoardPosition::getNumberOfPosition() << " item move was entered." << endl;
	
	return 0;
}

BoardPosition::BoardPosition(char firstChar,int firstNum)
{
	setBoardPosition(firstChar,firstNum);
	++numberOfPosition;	
}

/*Eger tasin bulundugu pozisyon beyaz ise true siyah ise false dondurur. */
bool BoardPosition::checkBoardPosition()
{
	if(((RowNum + static_cast<int>(columnLetter - 'A')) % 2 ) == 0)
	{
		return true;
	}
	else
		return false;
}

/* Satranc tahtasini kurar. */
void BoardPosition::setBoardPosition(char character,int number)
{
	if(character >= 'A' && character <= 'H'
	   && number >= 1 && number <= 8)
	{
		columnLetter = character;
		RowNum = number;
	}
	else
	{
		cerr << "Illegal character or number \n";
		cout << "Exiting !...\n";
		exit(1);
	}
}

int BoardPosition::getNumber() const
{
	return RowNum ;
}

char BoardPosition::getCharacter() const
{
	return columnLetter;
}

void BoardPosition::input()
{
	char tempLine[SIZE];

	cout << "Please enter position (char (A - H) and num (1 - 8))" << endl ;
	cin >> tempLine;
	
	setBoardPosition(tempLine[0],tempLine[1] - '0');
	++numberOfPosition;	
}

void BoardPosition::output()
{
	//Calisip calismadigini test etmek icin 
	cout << "    " << columnLetter << RowNum << endl;
	if(checkBoardPosition())
		cout << "Board position is white. " << endl;
}

