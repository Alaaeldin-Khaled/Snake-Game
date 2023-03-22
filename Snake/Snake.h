#pragma once
#include <Windows.h>
#include <functional>
#include <thread>
#include <vector>
using namespace std;

#define WIDTH 50
#define HEIGHT 25

class Snake
{
private:
	COORD pos;					//Position of the snake
	int len;					//Length of the snake
	int vel;					//Velocity of the snake
	char direction;				//Direction of the snake
	vector<COORD> body;			//The body of the snake

	Snake(COORD pos, int vel);	//Constructor

public:

	// Using Singleton Pattern to make one instance only from the Snake class.

	static Snake& getInstance();

	//Snake(COORD pos, int vel);	//Old constructor

	void change_dir(char dir);		//Changes the direction of the snake

	void move_snake();              //Moves the snake

	COORD get_pos();				//Returns the position of the snake

	bool eaten(COORD food_pos);		//Returns the status whether the food is eaten or not

	void grow();					//Increases the snake size

	void setTimeout(int milli);		//Decreases the speed of the snake using threading

	bool collided();				//Returns the status whether the snake collided or not

	vector<COORD> get_body();		//Returns the body of the snake
};

