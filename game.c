#include "game.h"
#include <stdlib.h>

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

