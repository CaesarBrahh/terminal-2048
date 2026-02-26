#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "bot.h"
#include "game.h"

void print_board_debug(int board[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            printf("%4d", board[i][j]);
        printf("\n");
    }
    printf("\n");
}

int best_move(int board[4][4])
{
	score scores[4];
	scores[0].move = 65; 
	scores[1].move = 66;
	scores[2].move = 67;
	scores[3].move = 68;

	int best_index;
	int best_score = -1;

	for (int i = 0; i < 4; i++)
	{
		// copy board
		memcpy(scores[i].board, board, sizeof(scores[i].board));

		// add and shift values of copied board
		add_values(scores[i].move, scores[i].board);
		shift_values(scores[i].move, scores[i].board);

		// evaluate
		scores[i].points = evaluate(scores[i].board);

		// determine
		if (scores[i].points > best_score)
		{
			best_score = scores[i].points;
			best_index = i;
		}
	}
	printf("Up: %i, Down:%i, Right:%i, Left:%i\n", scores[0].points, scores[1].points, scores[2].points, scores[3].points);
	usleep(200000);
	return scores[best_index].move;
}

int evaluate(int board[4][4])
{
	int count = 0;

	// count all values in board[4][4] that are 0
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (board[i][j] == 0)
			{
				count++;
			}
			
			// compare right and up neighbor
			if (board[i][j-1] == board[i][j])
			{
				count++;
			}
			if (board[i+1][j] == board[i][j])
			{
				count++;
			}
		}
	}

	// return count
	return count;
}