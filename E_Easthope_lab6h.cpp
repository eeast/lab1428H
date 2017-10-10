

#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int main()
{
	//NUMBER OF ROWS AND COLUMNS
	const int ROWS = 10;
	const int COLS = 10;
	char life[ROWS][COLS];
	char life_2[ROWS][COLS];

	//RANDOM NUMBER GENERATOR TO CREATE INITIAL GENERATION
	srand (time(NULL));
	int cell, iterations;

	for(int r=0; r<ROWS; r++)
	{
		for(int c =0; c<COLS;c++)
		{
			cell = rand() % 7;
			if(cell >= 5)
			{
				life[r][c] = '*';
			}
			else
			{
				life[r][c]=' ';
			}
		}
	}

	cout << "How many generations would you like to run?\n";
	cin >> iterations;

    for (int x=0; x<iterations; x++) {

        cout << "Generation " << x+1 << ":\n";

        for(int r=0; r<ROWS; r++) {
            for(int c =0; c<COLS;c++) {
                //Print the new generation

                cout << life[r][c] << " ";
            }
            cout << endl;
        }

        for(int r=0; r<ROWS; r++) {
            for(int c =0; c<COLS;c++) {
                int cell_count=0;
                //Counting the neighbors

                if((r-1)>=0 && (c-1)>=0 && life[r-1][c-1]=='*')
                    cell_count++;
                if((c-1)>=0&&life[r][c-1]=='*')
                    cell_count++;
                if((r+1)<10&&(c-1)>=0&&life[r+1][c-1]=='*')
                    cell_count++;
                if((r-1)>=0&&life[r-1][c]=='*')
                    cell_count++;
                if((r+1)<10&&life[r+1][c]=='*')
                    cell_count++;
                if((r-1)>=0&&(c+1)<10&&life[r-1][c+1]=='*')
                    cell_count++;
                if((c+1)<10&&life[r][c+1]=='*')
                    cell_count++;
                if((r+1)<10&&(c+1)<10&&life[r+1][c+1]=='*')
                    cell_count++;

                //Creating the new array

                if (cell_count==2)
                    life_2[r][c]=life[r][c];
                else  if (cell_count==3)
                    life_2[r][c]='*';
                else
                    life_2[r][c]=' ';
            }
        }

        for(int r=0; r<ROWS; r++) {
            for(int c =0; c<COLS;c++) {
                //Copy to original array
                life[r][c]=life_2[r][c];
            }
        }
    }

	return 0;

}
