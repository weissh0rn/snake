#ifndef SNAKE_H
#define SNAKE_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"

typedef struct snake_node_struct {
	Coords coords;
	struct snake_node_struct *next;
	struct snake_node_struct *prev;
} SnakeNode;

typedef struct {
	SnakeNode *head;
	SnakeNode *tail;
	unsigned int length;
} Snake;


Snake *create_snake(void);
SnakeNode *create_snake_node(SnakeNode* const tail);
void add_snake_node(Snake* const snake, SnakeNode* const snake_node);
void move_snake(Snake * const snake, int direction);
bool can_move(Snake * const snake);

bool is_same_coords(SnakeNode* const fst, SnakeNode* const tmp);

#endif
