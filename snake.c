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
		snake_node->coords.x = rand() % WIDTH;
		snake_node->coords.y = rand() % HEIGHT;
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
			tmp->coords.y += 1;
			break;
		case LEFT:
			tmp->coords.y -= 1;
			break;
		case DOWN:
			tmp->coords.y += 1;
			break;
		case RIGHT:
			tmp->coords.x += 1;
			break;
		default:
			fprintf(stderr, "Impossible direction\n");
			exit(EXIT_FAILURE);
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

bool can_move(Snake * const snake)
{
	if (snake->length < 5) {
		return true;
	}

	SnakeNode *tmp = snake->head->next;
	while (tmp->next != NULL) {
		if (is_same_coords(snake->head, tmp)) {
			return false;
		}
	}

	return true;
}
