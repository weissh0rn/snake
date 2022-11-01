#ifndef MAIN_H
#define MAIN_H

enum {
	LEFT,
	UP,
	RIGHT,
	DOWN
};

typedef struct {
	int x;
	int y;
} Coords;

enum { WIDTH = 40, HEIGHT = 15 };
/* const unsigned int WIDTH  = 30; */
/* const unsigned int HEIGHT = 30; */

#endif
