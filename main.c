#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <ncurses.h>

#include "main.h"
#include "snake.h"
#include "apple.h"

/*
void show(Snake *snake, Coords *apple)
{
	int i = 0;
	SnakeNode *tmp = snake->head;
	while(tmp != NULL) {
		printf("NODE = %d, coords.x = %d coords.y = %d\n", i, tmp->coords.x, tmp->coords.y);
		tmp = tmp->next;
	}

	printf("APPLE: coords.x = %d, coords.y = %d\n", apple->x, apple->y);
}
*/


int main(void)
{
	srand((unsigned int)time(0));

	Snake *snake = create_snake();
	add_snake_node(snake, create_snake_node(snake->tail));
	Coords *apple = create_apple(snake);
	show(snake, apple);
	printf("\n\n");
	add_snake_node(snake, create_snake_node(snake->tail));
	move_snake(snake, UP);
	move_snake(snake, UP);
	add_snake_node(snake, create_snake_node(snake->tail));
	move_snake(snake, UP);
	apple = create_apple(snake);
	show(snake, apple);

	return 0;
}
