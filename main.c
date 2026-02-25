/*
TODO:
- Fix input stream bug
- add colors to numbers
- make values array in add_two function increase and decrease size dynamically
- remove need to click "enter" after each move select
*/

#include "stdio.h"
#include "stdlib.h"

#define RESET "\033[0m"
#define BOLD "\033[1m"

int display_board(int board[4][4]);
char* tile_style(int n);
int add_values(int key, int board[4][4]);
int shift_values(int key, int board[4][4]);
int add_two(int board[4][4]);

typedef struct
{
	int i;
	int j;
} empty;

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
			getchar(); // take out ESC (91)
			getchar(); // take out [ (27)
			key = getchar();
			getchar(); // take out \n (10)
		} while (key != 65 && key != 66 && key != 67 && key != 68);

		// upon each click, add, shift, add
		add_values(key, board);
		shift_values(key, board);
		add_two(board);
	}
}

int display_board(int board[4][4])
{
	for (int i = 0; i < 4; i++) // for each row
	{
		// print seperator
		printf("+----+----+----+----+\n");

		for (int j = 0; j < 4; j++) // for each column
		{
			// print cell
			if (board[i][j] == 0)
			{
				printf("|%4c", ' ');
			}
			else
			{
				printf("|%s%4d%s", tile_style(board[i][j]), board[i][j], RESET);
			} 
		}
		printf("|\n");
	}
	// print seperator
	printf("+----+----+----+----+\n");

	return 0;
}

char* tile_style(int n)
{
	if (n == 2)   return "\033[30;46m" BOLD; // black on cyan
	if (n == 4)   return "\033[37;44m" BOLD; // black on blue
    if (n == 8)   return "\033[30;43m" BOLD; // black on yellow
    if (n == 16)  return "\033[30;43m" BOLD;
    if (n == 32)  return "\033[37;41m" BOLD; // white on red
    if (n == 64)  return "\033[37;41m" BOLD;
    if (n >= 128 && n < 1024) return "\033[37;45m" BOLD; // white on magenta
    if (n >= 1024) return "\033[30;47m" BOLD;       // black on white
    return ""; // default
}

// ASCIIs: up -> 27, 91, 65; down -> 27, 91, 66; right -> 27, 91, 67; left -> 27, 91, 68
int add_values(int key, int board[4][4])
{
	if (key == 65) // up
	{
		for (int j = 0; j < 4; j++)
		{
			for (int i = 0; i < 3; i++)
			{
				for (int k = i+1; k < 4; k++)
				{
					if (board[i][j] == board[k][j])
					{
						board[i][j] = board[i][j] + board[k][j];
						board[k][j] = 0;
						break;
					}
					else if (board[k][j] != 0)
					{
						break;
					}
				}
			}
		}
	}
	else if (key == 66) // down
	{
		for (int j = 0; j < 4; j++)
		{
			for (int i = 0; i < 3; i++)
			{
				for (int k = i+1; k < 4; k++)
				{
					if (board[i][j] == board[k][j])
					{
						board[i][j] = board[i][j] + board[k][j];
						board[k][j] = 0;
						break;
					}
					else if (board[k][j] != 0)
					{
						break;
					}
				}
			}
		}
	}
	else if (key == 67) // right
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				for (int k = j+1; k < 4; k++)
				{
					if (board[i][j] == board[i][k])
					{
						board[i][j] = board[i][j] + board[i][k];
						board[i][k] = 0;
						break;
					}
					else if (board[i][k] != 0)
					{
						break;
					}
				}
			}
		}
	}
	else // left
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				for (int k = j+1; k < 4; k++)
				{
					if (board[i][j] == board[i][k])
					{
						board[i][j] = board[i][j] + board[i][k];
						board[i][k] = 0;
						break;
					}
					else if (board[i][k] != 0)
					{
						break;
					}
				}
			}
		}
	}

	return 0;
}

int shift_values(int key, int board[4][4])
{
	if (key == 65) // up
	{
		for (int j = 0; j < 4; j++)
		{
			for (int i = 0; i < 3; i++)
			{
				if (board[i][j] == 0)
				{
					for (int k = i; k < 4; k++)
					{
						if (board[k][j] != 0)
						{
							board[i][j] = board[k][j];
							board[k][j] = 0;
							break;
						}
					}
				}
			}
		}	
	}
	else if (key == 66) // down
	{
		for (int j = 0; j < 4; j++)
		{
			for (int i = 3; i > 0; i--)
			{
				if (board[i][j] == 0)
				{
					for (int k = i; k >= 0; k--)
					{
						if (board[k][j] != 0)
						{
							board[i][j] = board[k][j];
							board[k][j] = 0;
							break;
						}
					}
				}
			}
		}
	}
	else if (key == 67) // right
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 3; j > 0; j--)
			{
				if (board[i][j] == 0)
				{
					for (int k = j; k >= 0; k--)
					{
						if (board[i][k] != 0)
						{
							board[i][j] = board[i][k];
							board[i][k] = 0;
							break;
						}
					}
				}
			}
		}
	}
	else // left
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (board[i][j] == 0)
				{
					for (int k = j; k < 4; k++)
					{
						if (board[i][k] != 0)
						{
							board[i][j] = board[i][k];
							board[i][k] = 0;
							break;
						}
					}
				}
			}
		}
	}

	return 0;
}

// add new "2" randomly in a zero space
int add_two(int board[4][4])
{
	empty values[14];
	int value_size = 0;

	// find all 0 values
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (board[i][j] == 0)
			{
				values[value_size].i = i;
				values[value_size].j = j;
				value_size++;
			}
		}
	}

	// choose random space
	int random_index = rand() % value_size;

	// add 2 to chosen block space
	board[values[random_index].i][values[random_index].j] = 2;

	return 0;
}