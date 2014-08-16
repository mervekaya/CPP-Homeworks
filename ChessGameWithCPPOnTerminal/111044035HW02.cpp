/*
*       CSE 241 HW#02
*
*	Created by Merve KAYA on 15/10/2012
*
*	This is a chess program.
*
*	111044035HW02.cpp
*
*/


#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <cstring>

using namespace std;

typedef enum{ H,G,F,
	      E,D,C,
	      B,A			  
}boardCharacter_t;

const int LINE_NUMBER = 8;
const int COLUMN_NUMBER = 8;

void printChessBoard(const char chess[][COLUMN_NUMBER],int size);
void introduction(void);
int getMovement(char chess[][COLUMN_NUMBER],int size);
bool checkNumAndChar(const char move[],int size);
void convertToUpper(char tempLineString[],int size);
void charToNum(const char move[],int size,int &firstNum,int &secondNum,int &thirdNum,int &forthNum);
bool pown(const char move[],const char chess[][COLUMN_NUMBER],int size,int first,int second,int third,int forth);
bool Rook(const char move[],const char chess[][COLUMN_NUMBER],int size);
bool isEmptyColumn(const char chess[][COLUMN_NUMBER],int size,int first,int second,int third,int forth);
bool isEmptyLine(const char chess[][COLUMN_NUMBER],int size,int first,int second,int third,int forth);
bool Knight(const char chess[][COLUMN_NUMBER],int size,int first,int second,int third,int forth);
bool Bishop(const char chess[][COLUMN_NUMBER],const char move[],int size,int first,int second,int third,int forth);
bool Queen(const char chess[][COLUMN_NUMBER],const char move[],int size,int first,int second,int third,int forth);
bool King(const char chess[][COLUMN_NUMBER],int size,int first,int second,int third,int forth);
bool isFirstMove(const char chess[][COLUMN_NUMBER],const char move[],int size);
void randomMovements(char chess[][COLUMN_NUMBER],int size);
void firstChessBoard(void);
void endOfGame(void);
char numberToBoardChar(int value);
void computerMovement(int val1,int val2,int val3,int val4);

int main(void)
{
	char chess[LINE_NUMBER][COLUMN_NUMBER] = {
						  'k','a','f','v','s','f','a','k',
						  'p','p','p','p','p','p','p','p', 
						  '.','.','.','.','.','.','.','.',
						  '.','.','.','.','.','.','.','.',
						  '.','.','.','.','.','.','.','.',
						  '.','.','.','.','.','.','.','.',
						  'P','P','P','P','P','P','P','P',
						  'K','A','F','V','S','F','A','K',	
										    } ;
	firstChessBoard();
	introduction();
   	printChessBoard(chess,LINE_NUMBER);
	getMovement(chess,LINE_NUMBER);

	
	return 0;

}

/* Bu fonksiyon satranc tahtasini ekrana basar. */
void printChessBoard(const char chess[][COLUMN_NUMBER],int size)
{
	int i,j;
		
	for(i = 0; i < size ; ++i)
	{
		for(j = 0 ; j < COLUMN_NUMBER ; ++j)
			cout << chess[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
}

void introduction(void)
{
	cout << "Welcome Chess Game \n";
	cout << "If you want to quit from game press *."<< endl;
	cout << "Enjoy !...\n\n"<< endl;
}

void firstChessBoard(void)
{
	cout << "   A  B  C  D  E  F  G  H  " << endl << endl;
	cout << "8  k  a  f  v  s  f  a  k  8" << endl;
	cout << "7  p  p  p  p  p  p  p  p  7" << endl;
	cout << "6  .  .  .  .  .  .  .  .  6" << endl;
	cout << "5  .  .  .  .  .  .  .  .  5" << endl;
	cout << "4  .  .  .  .  .  .  .  .  4" << endl;
	cout << "3  .  .  .  .  .  .  .  .  3" << endl;
	cout << "2  P  P  P  P  P  P  P  P  2" << endl;
	cout << "1  K  A  F  V  S  F  A  K  1" << endl << endl;
	cout << "   A  B  C  D  E  F  G  H  " << endl << endl;


}

/* Bu fonksiyon kullanicidan hareketleri alir.
   Hareketi kontrol eder ve ona göre hareketi gerceklestirir.
   Eger hamle yanlis ise tekrar tekrar kullanicidan hamle 
   bekler. */ 
int getMovement(char chess[][COLUMN_NUMBER],int size)
{
	string line;
	char move[LINE_NUMBER] = { };
	int firstNumber,
	    secondNumber,
	    thirdNumber,
	    forthNumber,
	    i,count = 1;
	bool control;

	while(move[0] != '*')
	{
		for(i = 0 ; i < LINE_NUMBER ; ++i) // Arrayi bosaltir. */
				move[i] = ' ';
		cout << "Move " << count << endl ;
		cout << "Enter your move : ";
		getline(cin,line);
		strcpy(move,line.c_str());
		convertToUpper(move,LINE_NUMBER);
			
		
		if(checkNumAndChar(move,LINE_NUMBER))
		{
			charToNum(move,LINE_NUMBER,firstNumber,secondNumber,thirdNumber,forthNumber);
			if(chess[8 - firstNumber][secondNumber] == 'K')
			{
				control = Rook(move,chess,LINE_NUMBER);
			}
			else if(chess[8 - firstNumber][secondNumber] == 'A')
			{
				control = Knight(chess,LINE_NUMBER,firstNumber,secondNumber,thirdNumber,forthNumber);
			}
			else if(chess[8 - firstNumber][secondNumber] == 'F')
			{
				control = Bishop(chess,move,LINE_NUMBER,firstNumber,secondNumber,thirdNumber,forthNumber);
			}
			else if(chess[8 - firstNumber][secondNumber] == 'V')
			{
				control = Queen(chess,move,LINE_NUMBER,firstNumber,secondNumber,thirdNumber,forthNumber);
			}
			else if(chess[8 - firstNumber][secondNumber] == 'S' )
			{
				control = King(chess,LINE_NUMBER,firstNumber,secondNumber,thirdNumber,forthNumber);
			}
			else if(chess[8 - firstNumber][secondNumber] == 'P')
			{
				// Eger piyonun ilk hamlesiyse 2 kare oynamasina izin verir. */
				if(isFirstMove(chess,move,LINE_NUMBER) && (thirdNumber - firstNumber) == 2 && 
					      				  (secondNumber == forthNumber))
					control = true;
				else
					 control = pown(move,chess,LINE_NUMBER,firstNumber,secondNumber,thirdNumber,forthNumber);
			}

			if(control == true)
			{
				if(chess[8 - thirdNumber][forthNumber] == 's')
				{
					chess[8 - thirdNumber][forthNumber] = chess[8 - firstNumber][secondNumber];
					endOfGame();
					printChessBoard(chess,LINE_NUMBER);
					exit(1);
				}
				
				chess[8 - thirdNumber][forthNumber] = chess[8 - firstNumber][secondNumber];
				chess[8 - firstNumber][secondNumber] = '.';
				printChessBoard(chess,LINE_NUMBER);
				++count;
				cout << "\nMove " << count << endl ;
				randomMovements(chess,LINE_NUMBER);
				printChessBoard(chess,LINE_NUMBER);
				++count;
				
			}
			else
			{
				printChessBoard(chess,LINE_NUMBER);
			}
			
		}
		
	}
	return 1;
}

/* Bu fonksiyon kullanicinin girdigi harf ve sayilari
   satranc tahtasinin sinirlari icerisinde olup olmadigini 
   kontrol eder. */
bool checkNumAndChar(const char move[],int size)
{
	bool firstCharControl = (move[0] <= 'H') && (move[0] >= 'A'),
	     firstNumControl = (move[1] <= '9') && (move[1] >= '1'),
	     secondCharControl = (move[3] <= 'H') && (move[0] >= 'A'),
	     secondNumControl = (move[4] <= '9') && (move[4] >= '1');

	return (firstCharControl && firstNumControl && 
	        secondCharControl && secondNumControl);
}

/* Eger kullanici yanlislikla ya da bilerek kucuk harf girerse
   onu buyuk harfe donusturur. */
void convertToUpper(char tempLineString[],int size)
{
	int i;

	for(i = 0 ; tempLineString[i] != '\0'; ++i)
	{
		if(tempLineString[i] >= 'a' && tempLineString[i] <= 'z')
			tempLineString[i] = tempLineString[i] - 32;
				
	}

}

/* Piyonun ilk hareketi olup olmadigini kontrol eder. */
bool isFirstMove(const char chess[][COLUMN_NUMBER],const char move[],int size)
{
	int firstN,secondN,thirdN,forthN;
	charToNum(move,LINE_NUMBER,firstN,secondN,thirdN,forthN);

	if(firstN == 2 || firstN == 7) // Piyonun ilk yerinde olup olmadigini kontrol eder.
		return true;
	else 
		return false;
}

/* Kullanicidan string seklinde aldigi sayilari ve harfleri int ve boardCharacter_t
   tipine cevirir. */
void charToNum(const char move[],int size,int &firstNum,int &secondNum,int &thirdNum,int &forthNum)
{
	firstNum = static_cast<int>(((move[1]) - '0'));
	secondNum = static_cast<boardCharacter_t>(move[0]) - 'A';
	thirdNum = static_cast<int>(((move[4]) - '0'));
	forthNum = static_cast<boardCharacter_t>(move[3]) - 'A';
}

/* Ilk olarak kullanicinin gidecegi yerde kendi takiminin taslari var mi yok
   mu kontrol eder ve sonra piyonun hareketini tanimlar. Eger yanlıssa false 
   dondurur. */
bool pown(const char move[],const char chess[][COLUMN_NUMBER],int size,int first,int second,int third,int forth)
{
	bool control = chess[8 - third][forth] != 'P' && chess[8 - third][forth] != 'K' && chess[8 - third][forth] != 'A' &&
		       chess[8 - third][forth] != 'F' && chess[8 - third][forth] != 'V' && chess[8 - third][forth] != 'S';

	if((third - first == 1))
	{
		if((forth == second) &&  chess[8 - third][forth] == '.' && control)
			return true;
		else if(abs(forth - second) == 1 && abs(third - first) == 1 && chess[8 - third][forth] != '.' )
			return true;
		else 
			return false;
	}
}

/* Ilk olarak kalenin ne tarafta hareket edecegini belirler sonra
   satir ya da sutunu kontrol eder.Eger gidebilecekse true dondurur.*/
bool Rook(const char move[],const char chess[][COLUMN_NUMBER],int size)
{
	int first,second,third,forth;

	charToNum(move,LINE_NUMBER,first,second,third,forth);

	bool control = chess[8 - third][forth] != 'P' && chess[8 - third][forth] != 'K' && chess[8 - third][forth] != 'A' &&
		       chess[8 - third][forth] != 'F' && chess[8 - third][forth] != 'V' && chess[8 - third][forth] != 'S';

	if(control == true)
	{
		if(second == forth)
		{
			if(isEmptyColumn(chess,size,first,second,third,forth) == true)
				return true;
			else 
				return false;
		}
		else if(first == third)
		{
			if(isEmptyLine(chess,size,first,second,third,forth) == true)
				return true;
			else
				return false;
		}

	}

}

/* Gidecegi sutunun varacagı kadarki kismini kontrol eder.
   Kontrol 2 asamali. Ilk olarak kendi tasinin olup olmadigini
   2. olarak gidecegi yerden once karsi takiminin taslarinin
   olup olmadigini kontrol eder. */
bool isEmptyColumn(const char chess[][COLUMN_NUMBER],int size,int first,int second,int third,int forth)
{
	int i ;

	if(third > first)
	{
		for(i = first + 1   ; i < third ; ++i)
		{
			if((chess[8 - i][second] != 'P' && chess[8 - i][second] != 'K' && chess[8 - i][second] != 'A' &&
		       	    chess[8 - i][second] != 'F' && chess[8 - i][second] != 'S' && chess[8 - i][second] != 'V' && 
			    chess[8 -i][second] != 'p' && chess[8 - i][second] != 'k' && chess[8 - i][second] != 'a' &&
		            chess[8 - i][second] != 'f' && chess[8 - i][second] != 's' && chess[8 - i][second] != 'v') == false)
				return false;
		}
	}
	else
	{
		for(i = third + 1 ; i < first ; ++i)
		{
			if((chess[8 - i][second] != 'P' && chess[8 - i][second] != 'K' && chess[8 - i][second] != 'A' &&
		            chess[8 - i][second] != 'F' && chess[8 - i][second] != 'S' && chess[8 - i][second] != 'V'  && 
		            chess[8 -i][second] != 'p' && chess[8 - i][second] != 'k' && chess[8 - i][second] != 'a' &&
		            chess[8 - i][second] != 'f' && chess[8 - i][second] != 's' && chess[8 - i][second] != 'v')== false)
				return false;
		}
	}
	return true;

}

bool isEmptyLine(const char chess[][COLUMN_NUMBER],int size,int first,int second,int third,int forth)
{
	int i = 0;

	if(forth > second)	
	{
		for(i = second + 1; i < forth ; ++i )
		{
			if((chess[8 - first][i] != 'P' && chess[8 - first][i] != 'K' && chess[8 - first][i] != 'A' &&
		       	    chess[8 - first][i] != 'F' && chess[8 - first][i] != 'S' && chess[8 - first][i] != 'V' && 
			    chess[8 - first][i] != 'p' && chess[8 - first][i] != 'k' && chess[8 - first][i] != 'a' &&
		            chess[8 - first][i] != 'f' && chess[8 - first][i] != 's' && chess[8 - first][i] != 'v') == false)
				return false;
		}
	}
	else
	{
		for(i = forth + 1 ; i < second ; ++i)
		{
			if((chess[8 - first][i] != 'P' && chess[8 - first][i] != 'K' && chess[8 - first][i] != 'A' &&
		            chess[8 - first][i] != 'F' && chess[8 - first][i] != 'S' && chess[8 - first][i] != 'V' && 
			    chess[8 - first][i] != 'p' && chess[8 - first][i] != 'k' && chess[8 - first][i] != 'a' &&
		            chess[8 - first][i] != 'f' && chess[8 - first][i] != 's' && chess[8 - first][i] != 'v') == false)
				return false;
		}
	}
	return true;

}

/* Atin hareketlerini tanimlar. */
bool Knight(const char chess[][COLUMN_NUMBER],int size,int first,int second,int third,int forth)
{
	bool control = chess[8 - third][forth] != 'P' && chess[8 - third][forth] != 'K' && chess[8 - third][forth] != 'A' &&
		       chess[8 - third][forth] != 'F' && chess[8 - third][forth] != 'V' && chess[8 - third][forth] != 'S';

	int firstControl = abs(forth - second);
	int secondControl = abs(third - first);
	
	if(control == true)
	{
		if((firstControl == 1 && secondControl == 2 )|| (secondControl == 1 && firstControl == 2))
			return true;
	}
	return false;
}

/* Filin hareketlerini 4 asamada kontrol eder.Ilk olarak sag yukari 
   2. olarak sol yukarisini,3.olarak sag asagisini ve son olarak sol 
   asagisini kontrol eder. */
bool Bishop(const char chess[][COLUMN_NUMBER],const char move[],int size,int first,int second,int third,int forth)
{
	int i = 0,j = 0;
	bool controlLineCol = chess[8 - third][forth] != 'P' && chess[8 - third][forth] != 'K' && chess[8 - third][forth] != 'A' &&
			      chess[8 - third][forth] != 'F' && chess[8 - third][forth] != 'V' && chess[8 - third][forth] != 'S';

	bool controlEqual = abs(forth - second) == abs(third - first);

	if(forth == second)
		return false;
	else if(third == first)
		return false;
	else if(controlEqual && (forth > second && third > first))
	{
		for(i = second + 1 , j = first + 1; i < forth ; ++i,++j)
		{
			if(!(chess[8 - j][i] != 'P' && chess[8 - j][i] != 'K' && chess[8 - j][i] != 'A' &&
		             chess[8 - j][i] != 'F' && chess[8 - j][i] != 'S' && chess[8 - j][i] != 'V' && 
                             chess[8 - j][i] != 'p' && chess[8 - j][i] != 'k' && chess[8 - j][i] != 'a' &&
		             chess[8 - j][i] != 'f' && chess[8 - j][i] != 'a' && chess[8 - j][i] != 'v'))
				return false;
		}
		return true;
	}
	else if(controlEqual && (forth > second) && (first > third))
	{
		for(i = second + 1 ,j = first - 1; i <= forth ; ++i,--j)
		{
			if(!(chess[8 - j][i] != 'P' && chess[8 - j][i] != 'K' && chess[8 - j][i] != 'A' &&
		             chess[8 - j][i] != 'F' && chess[8 - j][i] != 'S' && chess[8 - j][i] != 'V' && 
                             chess[8 - j][i] != 'p' && chess[8 - j][i] != 'k' && chess[8 - j][i] != 'a' &&
		             chess[8 - j][i] != 'f' && chess[8 - j][i] != 's' && chess[8 - j][i] != 'v'))
				return false;
		}
		return true;		
	}
	else if(controlEqual && (forth < second) && (first < third))
	{
		for(i = forth + 1,j = first + 1 ; i < second ; ++i,++j )
		{
			if(!(chess[8 - j][i] != 'P' && chess[8 - j][i] != 'K' && chess[8 - j][i] != 'A' &&
		             chess[8 - j][i] != 'F' && chess[8 - j][i] != 'S' && chess[8 - j][i] != 'V' && 
		             chess[8 - j][i] != 'p' && chess[8 - j][i] != 'k' && chess[8 - j][i] != 'a' &&
		             chess[8 - j][i] != 'f' && chess[8 - j][i] != 's' && chess[8 - j][i] != 'v'))
				return false;
		}
		return true;
	}
	else if(controlEqual && (forth < second) && (first > third))
	{
		for(i = forth + 1,j = third + 1 ; i < second ; ++i,++j )
		{
			if(!(chess[8 - j][i] != 'P' && chess[8 - j][i] != 'K' && chess[8 - j][i] != 'A' &&
		             chess[8 - j][i] != 'F' && chess[8 - j][i] != 'S' && chess[8 - j][i] != 'V' && 
			     chess[8 - j][i] != 'p' && chess[8 - j][i] != 'k' && chess[8 - j][i] != 'a' &&
		             chess[8 - j][i] != 'f' && chess[8 - j][i] != 's' && chess[8 - j][i] != 'v'))
					return false;
		}
		return true;
	}
	
}

/* Vezirin hareketlerini kale ve file gore tanimlar. */
bool Queen(const char chess[][COLUMN_NUMBER],const char move[],int size,int first,int second,int third,int forth)
{
	if(first == third || second == forth)
	{
		if(Rook(move,chess,size))
			return true;
	}
	else if(abs(third - first) == abs(second - forth))
	{
		if(Bishop(chess,move,size,first,second,third,forth))
			return true;
	}
	else
		return false;
}

/* Sahin hareketlerini tanimlar. */
bool King(const char chess[][COLUMN_NUMBER],int size,int first,int second,int third,int forth)
{
	bool control = chess[8 - third][forth] != 'P' && chess[8 - third][forth] != 'K' && chess[8 - third][forth] != 'A' &&
		       chess[8 - third][forth] != 'F' && chess[8 - third][forth] != 'V' && chess[8 - third][forth] != 'S';
	
	 int firstControl = abs(forth - second),
	     secondContol = abs(third - first),
             thirdControl = abs(forth - second),
	     forthControl = abs(third - first);

	 if(control == true)
	 {
		if((firstControl == 1 && secondContol == 1) || (firstControl == 1 && forthControl == 0) || 
		   					       (thirdControl == 0 && secondContol == 1))
			return true;
	 }	
	else
		return false;
}

void randomMovements(char chess[][COLUMN_NUMBER],int size)
{
	int i,empty[15],k = 0,found = 0;
	bool control ;

	srand(time(NULL));

	while(found != 1)
	{
		i = rand() % 8;
		k = rand() % 8;

		if(chess[i][k] == 'k')
		{
			if(chess[i+1][k] == '.' && chess[i+1][k] != 'p' && chess[i+1][k] != 'k' && chess[i+1][k] != 'a' &&
		           chess[i+1][k] != 'f' && chess[i+1][k] != 'v' && chess[i+1][k] != 's')
			{
				computerMovement(i,k,i+1,k);
				swap(chess[i+1][k],chess[i][k]);
				found = 1;
			}
		}
		if(chess[i][k] == 'p' )
		{
			if(chess[i+1][k] == '.' && chess[i+1][k] != 'p' && chess[i+1][k] != 'k' && chess[i+1][k] != 'a' &&
		           chess[i+1][k] != 'f' && chess[i+1][k] != 'v' && chess[i+1][k] != 's'  && chess[i+1][k] != 'P' && 
			   chess[i+1][k] != 'K' && chess[i+1][k] != 'A' &&chess[i+1][k] != 'F' && chess[i+1][k] != 'V' && 
			   chess[i+1][k] != 'S')
			{
				computerMovement(i,k,i+1,k);
				swap(chess[i+1][k],chess[i][k]);
				found = 1;
			}
		}
		if(chess[i][k] == 'a')
		{
			if(chess[i+1][k+2] == '.' && chess[i+1][k+2] != 'p' && chess[i+1][k+2] != 'k' && chess[i+1][k+2] != 'a' &&
		           chess[i+1][k+2] != 'f' && chess[i+1][k+2] != 'v' && chess[i+1][k+2] != 's' && k != 6 && k!= 7 && i!= 7)
			{
				computerMovement(i,k,i+1,k+2);
				swap(chess[i+1][k+2],chess[i][k]);
				found = 1;
			}
			else if(chess[i+2][k+1] == '.' && chess[i+2][k+1] != 'p' && chess[i+2][k+1] != 'k' && chess[i+2][k+1] != 'a' &&
		                chess[i+2][k+1] != 'f' && chess[i+2][k+1] != 'v' && chess[i+2][k+1] != 's' && i != 6 && i != 7 && k!=7)
			{
				computerMovement(i,k,i+2,k+1);
				swap(chess[i+2][k+1],chess[i][k]);
				found = 1;
			}

		}
		if(chess[i][k] == 'f')
		{
			if(chess[i+1][k+1] == '.' && chess[i+1][k+1] != 'p' && chess[i+1][k+1] != 'k' && chess[i+1][k+1] != 'a' &&
		           chess[i+1][k+1] != 'f' && chess[i+1][k+1] != 'v' && chess[i+1][k+1] != 's')
			{
				computerMovement(i,k,i+1,k+1);
				swap(chess[i+1][k+1],chess[i][k]);
				found = 1;
			}
			else if(chess[i+1][k-1] == '.' && chess[i+1][k-1] != 'p' && chess[i+1][k-1] != 'k' && chess[i+1][k-1] != 'a' &&
		                chess[i+1][k-1] != 'f' && chess[i+1][k-1] != 'v' && chess[i+1][k-1] != 's')
			{
				computerMovement(i,k,i+1,k+1);
				swap(chess[i+1][k-1],chess[i][k]);
				found = 1;
			}
			else if(chess[i-1][k-1] == '.' && chess[i-1][k-1] != 'p' && chess[i-1][k-1] != 'k' && chess[i-1][k-1] != 'a' &&
		                chess[i-1][k-1] != 'f' && chess[i-1][k-1] != 'v' && chess[i-1][k-1] != 's' )
			{
				computerMovement(i,k,i-1,k-1);
				swap(chess[i-1][k-1],chess[i][k]);
				found = 1;
			}
			else if(chess[i-1][k+1] == '.' && chess[i-1][k+1] != 'p' && chess[i-1][k+1] != 'k' && chess[i-1][k+1] != 'a' &&
		                chess[i-1][k+1] != 'f' && chess[i-1][k+1] != 'v' && chess[i-1][k+1] != 's')
			{
				computerMovement(i,k,i-1,k+1);
				swap(chess[i-1][k+1],chess[i][k]);
				found = 1;
			}
		}
		if(chess[i][k] == 's')
		{
			if(chess[i+1][k+1] == '.' && chess[i+1][k+1] != 'p' && chess[i+1][k+1] != 'k' && chess[i+1][k+1] != 'a' &&
		           chess[i+1][k+1] != 'f' && chess[i+1][k+1] != 'v' && chess[i+1][k+1] != 's')
			{
				computerMovement(i,k,i+1,k+1);
				swap(chess[i+1][k+1],chess[i][k]);
				found = 1;
			}
			else if(chess[i+1][k-1] == '.' && chess[i+1][k-1] != 'p' && chess[i+1][k-1] != 'k' && chess[i+1][k-1] != 'a' &&
		                chess[i+1][k-1] != 'f' && chess[i+1][k-1] != 'v' && chess[i+1][k-1] != 's')
			{
				computerMovement(i,k,i+1,k-1);
				swap(chess[i+1][k-1],chess[i][k]);
				found = 1;
			}
			else if(chess[i-1][k-1] == '.' && chess[i-1][k-1] != 'p' && chess[i-1][k-1] != 'k' && chess[i-1][k-1] != 'a' &&
		                chess[i-1][k-1] != 'f' && chess[i-1][k-1] != 'v' && chess[i-1][k-1] != 's')
			{
				computerMovement(i,k,i-1,k-1);
				swap(chess[i-1][k-1],chess[i][k]);
				found = 1;
			}
			else if(chess[i-1][k+1] == '.' && chess[i-1][k+1] != 'p' && chess[i-1][k+1] != 'k' && chess[i-1][k+1] != 'a' &&
		                chess[i-1][k+1] != 'f' && chess[i-1][k+1] != 'v' && chess[i-1][k+1] != 's')
			{
				computerMovement(i,k,i-1,k+1);
				swap(chess[i-1][k+1],chess[i][k]);
				found = 1;
			}
		}
		if(chess[i][k] == 'v')
		{
			if(chess[i+1][k+1] == '.' && chess[i+1][k+1] != 'p' && chess[i+1][k+1] != 'k' && chess[i+1][k+1] != 'a' &&
		           chess[i+1][k+1] != 'f' && chess[i+1][k+1] != 'v' && chess[i+1][k+1] != 's')
			{
				computerMovement(i,k,i+1,k+1);
				swap(chess[i+1][k+1],chess[i][k]);
				found = 1;
			}
			else if(chess[i-1][k-1] == '.' && chess[i-1][k-1] != 'p' && chess[i-1][k-1] != 'k' && chess[i-1][k-1] != 'a' &&
		                chess[i-1][k-1] != 'f' && chess[i-1][k-1] != 'v' && chess[i-1][k-1] != 's')
			{
				computerMovement(i,k,i-1,k-1);
				swap(chess[i-1][k-1],chess[i][k]);
				found = 1;
			}
			else if(chess[i][k+1] == '.' && chess[i][k+1] != 'p' && chess[i][k+1] != 'k' && chess[i][k+1] != 'a' &&
		                chess[i][k+1] != 'f' && chess[i][k+1] != 'v' && chess[i][k+1] != 's')
			{
				computerMovement(i,k,i,k+1);
				swap(chess[i][k+1],chess[i][k]);
				found = 1;
			}
		}
	}
			
}


void computerMovement(int val1,int val2,int val3,int val4)
{
	char firstChar,secondChar;
	
	firstChar = numberToBoardChar(val2);
	secondChar = numberToBoardChar(val4);
	val1 = 8 - val1;
	val3 = 8 - val3;
	cout << "Computer Plays "<< firstChar << val1 << " - " << secondChar << val3 << endl << endl; 
}

/* Bilgisayarin hamlelerini harfe cevirir. */
char numberToBoardChar(int value)
{
	char character;

	switch(value)
	{
		case 0: character = 'A';
		break;
		case 1: character = 'B';
		break;
		case 2: character = 'C';
		break;
		case 3: character = 'D';
		break;
		case 4: character = 'E';
		break;
		case 5: character = 'F';
		break;
		case 6: character = 'G';
		break;
		case 7: character = 'H';
		break;
		
	}

	return character;
}
void swap(char &val1,char &val2)
{
	char temp;

	temp = val1;
	val1 = val2;
	val2 = temp;
}


void endOfGame(void)
{
	cout << "\n\nGame Over.\nYou win.\nCongratulations! "<< endl;
}

