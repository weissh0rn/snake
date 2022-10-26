#ifndef APPLE_H
#define APPLE_H

#include "snake.h"
#include "main.h"

/* extern const unsigned int WIDTH;  */
/* extern const unsigned int HEIGHT; */

Coords *create_apple(Snake *snake);
bool is_coords_occupied(SnakeNode *head, int x, int y);
bool is_ate_apple(SnakeNode *snake, Coords *apple);

#endif
