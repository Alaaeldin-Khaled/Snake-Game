#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <ctime>
#include "Snake.h"
#include "Food.h"
using namespace std;

#define WIDTH 50
#define HEIGHT 25

Snake& snake = Snake::getInstance();
Food food;

void board() {
	COORD snake_pos = snake.get_pos();
	COORD food_pos = food.get_pos();

	vector<COORD> body = snake.get_body();

	for (int i = 0; i < HEIGHT; ++i) {
		cout << "\t\t\t\t#";

		for (int j = 0; j < WIDTH - 2; ++j) {

			if (i == 0 || i == HEIGHT - 1) cout << "#";
			else if (i == snake_pos.Y && j+1 == snake_pos.X) cout << '0';
			
			else if (i == food_pos.Y && j+1 == food_pos.X) {
				cout << '@';
			}
			else {
				bool isBodyPart = false;
				
				for (int k = 0; k < body.size() - 1; ++k) {
					if (i == body[k].Y && j + 1 == body[k].X) {
						cout << 'o';
						isBodyPart = true;
						break;
					}
				}
				if (!isBodyPart) cout << ' ';
			}
				
		}
		cout << "#\n";
	}
}

int score;

int main() {

		score = 0;
		srand(time(NULL));

		food.gen_food();
		bool game_over = false;

		while (!game_over) {
			cout << "SCORE: " << score << endl;
			board();

			if (_kbhit()) {
				switch (_getch()) {
				case 'w':
					snake.change_dir('u');
					break;
				case 'a':
					snake.change_dir('l');
					break;
				case 's':
					snake.change_dir('d');
					break;
				case 'd':
					snake.change_dir('r');
					break;

				}
			}

			if (snake.collided())
				game_over = true;

			if (snake.eaten(food.get_pos())) {

				food.gen_food();
				snake.grow();
				score += 10;
			}

			if (food.get_pos().X < 1 || food.get_pos().X > WIDTH || food.get_pos().Y < 1 || food.get_pos().Y > HEIGHT)
				food.gen_food();

			snake.setTimeout(60);


			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
		}

	cout << "\n\nSCORE: " << score << endl;

		

}

