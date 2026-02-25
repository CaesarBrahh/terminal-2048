#include "cli.h"
#include <stdio.h>

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