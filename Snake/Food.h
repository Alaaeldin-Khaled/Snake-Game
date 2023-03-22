#pragma once
#include <cstdlib>
#include <Windows.h>
#define WIDTH 50
#define HEIGHT 25

class Food {
private:
	COORD pos;
public:
	
	void gen_food();		//Generates food randomly on the board
	COORD get_pos();		//Returns the position of the food on the board
	
};

