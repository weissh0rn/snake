#include "apple.h"
/* #include "main.h"	add in the apple.h */
/* #include "snake.h"	add in the apple.h */

Coords *create_apple(Snake *snake)
{
	Coords *apple = malloc(sizeof(*apple));

	if (apple == NULL) {
		fprintf(stderr, "");
		exit(EXIT_FAILURE);
	}

	int x, y;

	do {
		x = 1 + rand() % (WIDTH - 2);
		y = 1 + rand() % (HEIGHT - 2);
	} while (is_coords_occupied(snake->head, x, y));

	apple->x = x;
	apple->y = y;

	return apple;
}


bool is_ate_apple(SnakeNode *head, Coords *apple)
{
	if (head->coords.x == apple->x && head->coords.y == apple->y) {
		return true;
	} else {
		return false;
	}
}

bool is_coords_occupied(SnakeNode *head, int x, int y)
{
	while (head != NULL) {
		if (head->coords.x == x && head->coords.y == y) {
			return true;
		}
		head = head->next;
	}

	return false;
}
