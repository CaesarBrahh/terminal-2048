#include <stdio.h>
#include <stdlib.h>

#include "cli.h"
#include "game.h"
#include "bot.h"

int collect_key();

int main()
{
	// define initial state 
	int board[4][4] = {
		{0, 0, 0, 0},
		{0, 0, 0, 2},
		{2, 0, 0, 0},
		{0, 0, 0, 0}
	};

	// determine mode
	char mode;
	printf("Press 'b' for Bot Mode or any other key for Play Mode: ");
	scanf("%c", &mode);

	// begin loop
	while(1)
	{
		// start game by clearing screen displaying the board and two 2's
		printf("\033[2J\033[H");
		display_board(board);

		// listen for arrow key clicks 
		int key;
		if (mode == 'b')
		{
			key = best_move(board);
		}
		else
		{
			key = collect_key();
		}

		// upon each click, add, shift, add
		add_values(key, board);
		shift_values(key, board);
		add_two(board);
	}
}

int collect_key()
{
	int key;

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

	return key;
}