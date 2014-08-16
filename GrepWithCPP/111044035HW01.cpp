/*############################################################################*/
/*                                                                            */
/*  Cse241 HW#01                                                              */
/*  --------------                                                            */
/* Created on 01/10/2013 by Merve KAYA                                        */
/*                                                                            */
/*  111044035HW01.cpp This program works like grep                            */
/*                                                                            */
/*                                                                            */
/*############################################################################*/

/*----------------------------------------------------------------------------*/
/*                        Includes                                            */
/*----------------------------------------------------------------------------*/

#include<iostream>
#include<cstring>
#include<cstdlib>

/*----------------------------------------------------------------------------*/
/*                        #defines                                            */
/*----------------------------------------------------------------------------*/
#define SIZE 150

using namespace std;

/*----------------------------------------------------------------------------*/
/*                       Functions Prototypes    			      */
/*----------------------------------------------------------------------------*/

void strCpy(const char sourceStr[], char targetStr[]);
int strLength(const char ch[]);
void convertToSlower(char tempLineString[SIZE]);
int sgrep(char *lineString,const char *searchingString);
int myStrncmpFunc(const char firstString[SIZE],const char searchingString[SIZE],int sizeOfSearchString);
void writeOutput(const char strings[SIZE][SIZE],int size);
void writeOutput(const char strings[SIZE][SIZE],int size,int lineNumber[SIZE]);
void introduction(void);

int main(int argc , char *argv[])
{

	int i = 0,count = 1,lineNum[SIZE];

	char searchingStrings[SIZE][SIZE],
	     argument[SIZE],
             lineString[SIZE] = " ",
             tempLineString[SIZE];

	string line;

	
	if(argc != 2 && argc != 3 && argc != 4)
	{
		cout << "Missing argument .Check your arguments ."<< endl;
		cout << "Exiting..." << endl;
		exit(1);
	}
	
	// Eger -n -i ya da -i -n ve bir string girildiyse if icerisindeki adimlari takip eder.
	else if(((argv[1][0] == '-' && argv[1][1] == 'n') &&( argv[2][0] == '-' && argv[2][1] == 'i' )) || 
		((argv[1][0] == '-' && argv[1][1] == 'i') && (argv[2][0] == '-' && argv[2][1] == 'n' )))
	{
		introduction();
		strCpy(argv[3],argument);
		convertToSlower(argument);

		while(myStrncmpFunc(lineString,"-1",2 ) != 0 && getline(cin,line))
		{
			strcpy(lineString,line.c_str());
			strCpy(lineString,tempLineString);
			convertToSlower(tempLineString);
		
			if(sgrep(tempLineString,argument) == 0)	
			{
				strCpy(lineString,searchingStrings[i]);
				lineNum[i] = count;
				++i;
				
			}

			++count;
		}

		writeOutput(searchingStrings,i,lineNum);
	}
	
	// Eger -n ve string girildiyse asadaki adimlari takip eder. 
	else if(argv[1][0] == '-' && argv[1][1] == 'n')
	{
		introduction();
		strCpy(argv[2],argument);

		while(myStrncmpFunc(lineString,"-1",2 ) != 0 && getline(cin,line))
		{
			strcpy(lineString,line.c_str());

			if(sgrep(lineString,argument) == 0)	
			{
				strCpy(lineString,searchingStrings[i]);
				lineNum[i] = count;
				++i;
			}
			++count;			
		}
		writeOutput(searchingStrings,i,lineNum);
	}
	
	// Eger -i ve string girildiyse asadaki adimlari takip eder.
	else if(argv[1][0] == '-' && argv[1][1] == 'i')
	{
		introduction();
		strCpy(argv[2],argument);
		convertToSlower(argument);

		while(myStrncmpFunc(lineString,"-1",2 ) != 0 && getline(cin,line))
		{
			strcpy(lineString,line.c_str());
			strCpy(lineString,tempLineString);
			convertToSlower(tempLineString);
			
			if(sgrep(tempLineString,argument) == 0)	
			{
				strCpy(lineString,searchingStrings[i]);
				++i;
				
			}
		}

		writeOutput(searchingStrings,i);
	}
	else 
	{
		introduction();
		while(myStrncmpFunc(lineString,"-1",2 ) != 0 && getline(cin,line) )
		{
			strcpy(lineString,line.c_str());
			if(sgrep(lineString,argv[1]) == 0)	
			{
				strCpy(lineString,searchingStrings[i]);
				++i;
			}

		}
		writeOutput(searchingStrings,i);
	}
		
		
	return 0;
}

// C de strcpy fonksiyonun yaptigi kopyalama isini yapar.
void strCpy(const char sourceStr[], char targetStr[])
{
    int i;

    for(i = 0 ; sourceStr[i] != '\0' ; ++i)
   	targetStr[i] = sourceStr[i];

    targetStr[i] = '\0';
}

// C de strlen fonksiyonun yaptigi gibi verilen bir stringin uzunlugunu bulur.
int strLength(const char ch[])
{
    int i = 0;

    for(i = 0; ch[i] != '\0' ; ++i)
        if(ch[i] == '\0')
            break;

    return i;
}

// Verilen stringteki harfler buyuk harf ise onlari kucuk harfe cevirir.
void convertToSlower(char tempLineString[SIZE])
{
	int i;

	for(i = 0 ; tempLineString[i] != '\0'; ++i)
	{
		if(tempLineString[i] < 'a' && tempLineString[i] >= 'A')
			tempLineString[i] = tempLineString[i] + 32;
				
	}

}

// Bu fonksiyon bir stringi diger bir string icerinde arar.
// Eger ? isareti varsa yokmus gibi davranir.
int sgrep(char *lineString,const char *searchingString)
{
	int i = 0,
            counter = 0;

	while (lineString[i] != '\0')
	{
		if (lineString[i] == searchingString[counter] && searchingString[counter]!='\0' && lineString[i] != ' ')
		{
			++counter;
			if(counter == strLength(searchingString))
				return 0;
			
		}
		else if(searchingString[counter] == '?')
		{
			++counter;
			if(counter == strLength(searchingString))
				return 0;
		}
		else		
			counter = 0;

			++i;
	}

	return 1;
}

// Bu fonksiyon C de bulunan strncmp fonksiyon gibi stringlerin belirli bir kismini karsilastirir.
int myStrncmpFunc(const char firstString[SIZE],const char searchingString[SIZE],int sizeOfSearchString)
{
	
	int count = 0;

	for(int i = 0 ; i < sizeOfSearchString ; ++i)
	{
		if(firstString[i] == searchingString[i])
			++count;
	}

	if(count == sizeOfSearchString)
		return 0;
	else 
		return 2; 
}

// Bu fonksiyon bulunan stringleri terminale basar.
void writeOutput(const char strings[SIZE][SIZE],int size)
{
	int j;

	cout << "\n\n";
	cout << "Outputs\n" ;
	cout << "--------" << endl;

	for(j = 0 ; j < size ; ++j)
		cout << strings[j] << endl;
	cout << endl;
}

//Bu fonksiyon bulunan stringleri bulunduklari sira numarasiyla yazar.
void writeOutput(const char strings[SIZE][SIZE],int size,int lineNumber[SIZE])
{
	int j;

	cout << "\n\n";
	cout << "Outputs\n" ;
	cout << "--------" << endl;

	for(j = 0 ; j < size ; ++j)
		cout << lineNumber[j] << "-" << strings[j] << endl;
	cout << endl;
}

void introduction(void)
{
	cout << "If you work on terminal please enter string.(To quit enter -1)" << endl;
	cout << "Inputs \n" ;
	cout << "---------"<< endl; 
}
/*############################################################################*/
/* 		  End of 111044035HW01.cpp	               	              */
/*############################################################################*/

