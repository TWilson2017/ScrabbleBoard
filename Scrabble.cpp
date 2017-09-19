//------------------------------------------------------------------
// File name:   Scrabble.cpp
// Assign ID:   PROG2 
// Due Date:    09/16/17 at 11pm 
//
// Purpose:   Design and write a program that processes an input file 
//             containing a sequence of triples:
//             <row> <col> <character> <row><col><character> ... 0 0 X
//             The square "board" can contain up to 9 rows and 9 columns.
//             Keyboard inputs:
//             (1) name of the input file;
//             (2) board size. 
//
// Author:     twilson
//
//------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <stdio.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>


using namespace std;

int main()
{
   //-------------------------------------------- --------------------------
   //  Declare variables
   //----------------------------------------------------------------------
   char filename[80];
   int boardsize, row, col;
   char symbol;
   char Board[9][9] = {};
   int  Row[9];
   int  Col[9];
   ifstream inF;

   //-| ----------------------------------------------------------------------
   //-| Print the copyright notice declaring authorship.
   //-| ----------------------------------------------------------------------
   cout << endl << "(c) 2017, twilson" << endl << endl; 


   //-| ----------------------------------------------------------------------
   //-| 1. Get file name and open file.
   //-| ---------------------------------------------------------------------- 
   cout << "Enter name of input file: "; 
   cin >> filename;
   cout << endl;

   inF.open(filename);
   if (inF.fail())
   {
      cout << "FATAL ERROR: Can not open file " << "'" << filename << "'" << endl;
      exit(1);
   }//if end

   //-| ----------------------------------------------------------------------
   //-| 2. Get board size and init the board.
   //-| ----------------------------------------------------------------------
   cout << "Enter board size [1-9]: ";
   cin >> boardsize;
   cout << endl;

   for(int i = 0; i < boardsize; i++)
   	for (int j = 0; j < boardsize; j++)
    	Board[i][j] = ' ';
	
	
   //-| ----------------------------------------------------------------------
   //-| 3. Read in file values and output ROW, COL, and LETTER on scrabble board.
   //-| ----------------------------------------------------------------------
   int Tiles = 0;

	// Read in file, count each tile and print or scrabble table.
	
	cout << "ROW" << " " << "COL" << " " << "LETTER" << endl;
	cout << "===" << " " << "===" << " " << "======" << endl;
  
  
	int a = 0;
	while(inF >> row >> col >> symbol)
	{   
		
			if(!isalpha(symbol))
			{
				cout << "REJECTED CELL " << row << " " << col << " "
					 << symbol << " NOT A LETTER" << endl << endl;
			}//if ended
			else if(row < 1 || row > boardsize)
			{
				cout << "REJECTED CELL " << row << " " << col << " "
					 << symbol << " BAD ROW" << endl << endl;
			}//else if ended
			else if(col < 1 || col > boardsize)
			{
				cout << "REJECTED CELL " << row << " " << col << " "
					 << symbol << " BAD COL" << endl << endl;
			}//else if ended
			else if(Board[row - 1][col - 1] != ' ')
			{
				cout << "REJECTED CELL " << row << " " << col << " "
					 << symbol << " CELL ALREADY MARKED" << endl << endl;
			}//else if ended
			else
			{
				Board[row - 1][col - 1] = symbol;
				Row[row - 1] = row;
				Col[col - 1] = col;
				cout << " " << Row[row - 1] << "   " << Col[col - 1]  
				 << "    " << Board[row - 1][col - 1] << endl;
				cout << "===" << " " << "===" << " " << "======" << endl;
				Tiles++;
			}//else ended
	}//while loop ended
	cout << endl << endl;
		
	cout << Tiles << " TILES on Scrabble Board" << endl << endl;
	cout << endl;
	
	
   //-| ----------------------------------------------------------------------
   //-| 4.Output Board Size and Display Column Numbers at the top of board
   //-| ----------------------------------------------------------------------
	cout << boardsize << " x " << boardsize << " " << "SCRABBLE BOARD " << endl << endl;
	
	cout << setw(15);
	
	for(int i = 1; i <= boardsize; i++)
	{
		cout << i << " ";
	}//for loop ended
	cout << endl;
	
	cout << setw(13);
	for(int i = 1; i <= ((boardsize - boardsize) + 1); i++)
	{
		cout << "+" << " ";
	}//for loop ended
	
	for(int i = 1; i <= boardsize; i++)
	{
		cout << "-" << " ";
	}//for loop ended
	
	for(int i = (boardsize + 1); i > boardsize; i--)
	{
		cout << "+";
	}//for loop ended
	cout << endl;
	
   //-| ----------------------------------------------------------------------
   //-| 5. Display each Row and Letter associated with each Column
   //-| ----------------------------------------------------------------------
    cout << setw(11);
	for (int i = 0; i < boardsize; i++) 
	{
        // print the first character as part of the opener.
        cout << setw(8);
		cout << "row" << (i+1) << "=> | " << Board[i][0];
        for (int j = 1; j < boardsize; j++) 
		{
           // only add spaces for subsequent characters.
           cout << " " << Board[i][j];
        }
        cout << " |" << endl;
    }
    cout << setw(15);
	
   //-| ----------------------------------------------------------------------
   //-| 6. Display Column Numbers at the bottom of board
   //-| ----------------------------------------------------------------------
	cout << setw(13);
	for(int i = 1; i <= ((boardsize - boardsize) + 1); i++)
	{
		cout << "+" << " ";
	}//for loop ended
	
	for(int i = 1; i <= boardsize; i++)
	{
		cout << "-" << " ";
	}//for loop ended
	
	for(int i = (boardsize + 1); i > boardsize; i--)
	{
		cout << "+";
	}//for loop ended
	cout << endl;
	
	cout << setw(15);
	for(int i = 1; i <= boardsize; i++)
	{
		cout << i << " ";
	}//for loop ended
	cout << endl;
   //-| ----------------------------------------------------------------------
   //-| 7. Display Words and # of Words on Scrabble Board
   //-| ----------------------------------------------------------------------
   cout << "WORDS ON " << boardsize << " x " << boardsize << " SCRABBLE BOARD " << endl;
	
   // Output Horizontal Word Row
   
	char prev;
	char curr;
	int Wordcount = 0;
	int Letter = 0;
	char Temp;
	char Temp2;
  
	cout << "HORIZONTAL: ";
	   for(int i=0; i < boardsize; ++i)
	   {
   			for(int j= 0; j< (boardsize); ++j)
			{
				
				curr = Board[i][j];
    	        if (Board[i][j] != ' ')
		        {
        	       Wordcount++;
		        }// if ended
		
		        if(Wordcount >= 2)
		        {
			       Letter = 1;
		        }// if ended
				
				if(Wordcount >= 2 && Letter >= 1)
				{
				   Letter += 1 ;
				}// if ended
				if(curr == ' '|| curr != ' ')
				{
					if(curr != ' ')
					{
						prev = curr;
					}// if ended
					
					if(curr == ' ')
					{
						prev = curr;
					}//if ended
					
				}//if ended
		
				if(Wordcount >= 2)
				{
					cout << Temp;
				}//if ended
				
				if(curr == ' ' && Wordcount >= 2)
					{
						cout << " ";
					}//if ended
				
				if(Wordcount >= 1)
				{
					Temp = prev;
				}//if ended
				
				if(Board[i][j] == ' ')
				{
					Wordcount = 0;
	    		}//if ended
     		}//inner for ended
	   }//outer for ended
			cout << Letter << " WORDS";
			cout << endl;
				
	// Output Vertical Word Row
   
	char Prev;
	char Curr;
	int WCount = 0;
	int letter = 0;
	char Ttemp;
	
	cout << "VERTICAL: ";
	   for(int i=0; i < boardsize; ++i)
	   {
   			for(int j= 0; j< (boardsize); ++j)
			{
				
				Curr = Board[j][i];
    	        if (Board[j][i] != ' ')
		        {
        	       WCount++;
		        }//if ended
		
		        if(WCount >= 2)
		        {
			       letter = 1;
		        }//if ended
				
				if(WCount >= 2 && letter >= 1)
				{
				   letter += 1 ;
				}//if ended
				if(Curr == ' '|| Curr != ' ')
				{
					if(Curr != ' ')
					{
						Prev = Curr;
					}//if ended
					
					if(curr == ' ')
					{
						Prev = Curr;
					}//if ended
					
				}//if ended
		
				if(WCount >= 2)
				{
					cout << Ttemp;
				}//if ended
				
				if(Curr == ' ' && WCount >= 2)
				{
					cout << " ";
				}//if ended
				
				if(WCount >= 1)
				{
					Ttemp = Prev;
				}//if ended
				
				if(Board[j][i] == ' ')
				{
					WCount = 0;
	    		}//if ended
     		}//inner for loop ended
	   }//outer for loop ended
			cout << letter << " WORDS";
			cout << endl;
				
		cout << (letter + Letter) << " SCRABBLE WORDS";
	    cout << endl;
   //-| ----------------------------------------------------------------------
   //-| Print the copyright notice declaring authorship again.
   //-| ----------------------------------------------------------------------
   cout << endl << "(c) 2017, twilson" << endl << endl; 


   return 0;

}//main
