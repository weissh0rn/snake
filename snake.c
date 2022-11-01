#include "snake.h"

Snake *create_snake(void)
{
	Snake *snake = malloc(sizeof(*snake));

	if (snake == NULL) {
		fprintf(stderr, "Error: out of memory\n");
		exit(EXIT_FAILURE);
	}

	snake->head = snake->tail = NULL;
	snake->length = 0;

	return snake;
}

SnakeNode *create_snake_node(SnakeNode* const tail)
{
	SnakeNode *snake_node = malloc(sizeof(*snake_node));

	if (snake_node == NULL) {
		fprintf(stderr, "Error: out of memory\n");
		exit(EXIT_FAILURE);
	}

	if (tail == NULL) {
		snake_node->coords.x = 1 + rand() % (WIDTH - 2);
		snake_node->coords.y = 1 + rand() % (HEIGHT - 2);
		snake_node->next = snake_node->prev = NULL;
		return snake_node;
	}

	snake_node->coords.x = tail->coords.x;
	snake_node->coords.y = tail->coords.y;
	snake_node->next = snake_node->prev = NULL;

	return snake_node;
}

void add_snake_node(Snake* const snake, SnakeNode* const snake_node)
{
	++snake->length;

	if (snake->head != NULL) {
		snake_node->prev = snake->tail;
		snake->tail->next = snake_node;
		snake->tail = snake_node;
		return ;
	} else {
		snake->head = snake->tail = snake_node;
		return ;
	}
}

void move_snake(Snake * const snake, int direction)
{
	if (snake->tail == NULL) {
		return ;
	}

	SnakeNode *tmp = snake->tail;

	while (tmp->prev != NULL) {
		tmp->coords.x = tmp->prev->coords.x;
		tmp->coords.y = tmp->prev->coords.y;
		tmp = tmp->prev;
	}

	switch (direction) {
		case UP:
			tmp->coords.y -= 1;
			if (tmp->coords.y == 0) {
				tmp->coords.y = HEIGHT - 1;
			}
			break;
		case LEFT:
			tmp->coords.x -= 1;
			if (tmp->coords.x == 0) {
				tmp->coords.x = WIDTH - 2;
			}
			break;
		case DOWN:
			tmp->coords.y += 1;
			if (tmp->coords.y == HEIGHT) {
				tmp->coords.y = 1;
			}
			break;
		case RIGHT:
			tmp->coords.x += 1;
			if (tmp->coords.x == WIDTH - 1) {
				tmp->coords.x = 1;
			}
			break;
	}
}

bool is_same_coords(SnakeNode* const fst, SnakeNode* const tmp)
{
	if (fst->coords.x == tmp->coords.x && fst->coords.y == tmp->coords.y) {
		return true;
	} else {
		return false;
	}
}

bool game_over(Snake * const snake)
{
	if (snake->length > 4) {
		SnakeNode *tmp = snake->head->next;
		while (tmp != NULL) {
			if (is_same_coords(snake->head, tmp)) {
				return true;
			}
			tmp = tmp->next;
		}
	}

	return false;
}
