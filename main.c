#include <stdio.h>
#include <stdlib.h>

#include "cli.h"
#include "game.h"

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
		int key = -1;
		do 
		{
			// prompt
			printf("Press arrow key, then click enter: ");

			char ch1 = getchar(); // take out ESC (27)
			if (ch1 != 27) 
			{
				if (ch1 == '\n') continue;

				// clear input stream
				int ch;
				while ((ch = getchar()) != '\n' && ch != EOF){}

				continue;
			}

			char ch2 = getchar(); // take out [ (91)
			if (ch2 != '[')
			{
				if (ch2 == '\n') continue;

				// clear input stream
				int ch;
				while ((ch = getchar()) != '\n' && ch != EOF){}

				continue;
			}

			key = getchar();

			// clear input stream
			char ch;
			while ((ch = getchar()) != '\n' && ch != EOF){}			
		} while (key != 65 && key != 66 && key != 67 && key != 68);

		// upon each click, add, shift, add
		add_values(key, board);
		shift_values(key, board);
		add_two(board);
	}
}