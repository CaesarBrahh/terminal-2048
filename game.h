#ifndef GAME_H
#define GAME_H

int add_values(int key, int board[4][4]);
int shift_values(int key, int board[4][4]);
int add_two(int board[4][4]);

typedef struct
{
	int i;
	int j;
} empty;

#endif