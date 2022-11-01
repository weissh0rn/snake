#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <ncurses.h>
#include <unistd.h>

#include "main.h"
#include "snake.h"
#include "apple.h"

unsigned int delay = 200000;

void init(void)
{
	srand(time(NULL));
	initscr();
	keypad(stdscr, 1);
	noecho();
	curs_set(0);

	timeout(10);

	move(0, 0);
	printw("+--------------------------------------+\n");
	for (int i = 1; i < HEIGHT; ++i) {
		move(i, 0);
		printw("|");
		move(i, WIDTH - 1);
		printw("|\n");
	}
	printw("+--------------------------------------+\n");
	refresh();
}

void show_apple(Coords *apple)
{
	move(apple->y, apple->x);
	printw("*");
	refresh();
}


void show_snake(SnakeNode *head)
{
	move(head->coords.y, head->coords.x);
	printw("O");
	head = head->next;

	while (head != NULL) {
		move(head->coords.y, head->coords.x);
		printw("o");
		head = head->next;
	}

	refresh();
}

void clear_snake(SnakeNode *tail)
{
	move(tail->coords.y, tail->coords.x);
	printw(" ");
	refresh();
}

int main(void)
{
	init();

	char key;
	int dir;

	Snake *snake = create_snake();
	add_snake_node(snake, create_snake_node(snake->tail));
	add_snake_node(snake, create_snake_node(snake->tail));
	Coords *apple = create_apple(snake);

	show_apple(apple);
	show_snake(snake->head);

	while (!game_over(snake)) {
		key = getch();
		clear_snake(snake->tail);
		switch (key) {
			case 'h':
				if (dir == RIGHT) { continue; }
				move_snake(snake, LEFT);
				dir = LEFT;
				break;
			case 'l':
				if (dir == LEFT) { continue; }
				move_snake(snake, RIGHT);
				dir = RIGHT;
				break;
			case 'k':
				if (dir == DOWN) { continue; }
				move_snake(snake, UP);
				dir = UP;
				break;
			case 'j':
				if (dir == UP) { continue; }
				move_snake(snake, DOWN);
				dir = DOWN;
				break;
			default:
				move_snake(snake, dir);
				break;
		}

		if (is_ate_apple(snake->head, apple)) {
			add_snake_node(snake, create_snake_node(snake->tail));
			apple = create_apple(snake);
			show_apple(apple);
			delay -= 100;
		}

		show_snake(snake->head);
		usleep(delay);
	}

	free(apple);
	refresh();
	endwin();

	return 0;
}
