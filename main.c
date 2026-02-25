/*
TODO:
- add colors to numbers
- make zeros just an empty space
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int display_board(int board[4][4]);
int shift_values(int key, int board[4][4]);

int main()
{
	// define initial state 
	int board[4][4] = {
		{0, 0, 0, 0},
		{0, 0, 0, 2},
		{2, 0, 0, 0},
		{0, 0, 0, 0}
	};

	// begin loop
	while(1)
	{
		// start game by clearing screen displaying the board and two 2's
		printf("\033[2J\033[H");
		display_board(board);

		// listen for arrow key clicks 
		int key;
		do
		{
			getchar();
			getchar();
			scanf("%i", &key);
		} while (key != 65 && key != 66 && key != 67 && key != 68);

		// upon each click, shift and add values, restart loop
		shift_values(key, board);
	}
}

// add colors!
int display_board(int board[4][4])
{
	for (int i = 0; i < 4; i++) // for each row
	{
		// print seperator
		printf("+----+----+----+----+\n");

		for (int j = 0; j < 4; j++) // for each column
		{
			// print cell
			printf("|%4d", board[i][j]); 
		}
		printf("|\n");
	}
	// print seperator
	printf("+----+----+----+----+\n");

	return 0;
}


// ASCIIs: up -> 27, 91, 65; down -> 27, 91, 66; right -> 27, 91, 67; left -> 27, 91, 68
int shift_values(int key, int board[4][4])
{
	// stack

	// add new "2" randomly in a zero space

	return 0;
}