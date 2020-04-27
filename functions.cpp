#include <iostream>
#include <iomanip>
#include "functions.h"
using namespace std;

Life::Life() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			board[i][j] = 0;
			board2[i][j] = 0;
		}
	}

	for (int i = 24; i < 25; i++) {
		for (int j = 20; j < 30; j++) {
			board[i][j] = 1;
		}
	}
}

void Life::display() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (board[i][j] == 0) {
				cout << "  ";
			}
			else {
				cout << "1 ";
			}
		}
		cout << endl;
	}
}

void Life::Rules() {
	//Set a seperate 2d array to store the values
	for (int i = 1; i < size-1; i++) {
		for (int j = 1; j < size-1; j++) {
			int area = board[i - 1][j - 1] + board[i - 1][j] + board[i - 1][j + 1] + board[i + 1][j - 1] + board[i + 1][j] + board[i + 1][j + 1] + board[i][j - 1] + board[i][j + 1];
			if (area < 2 && board[i][j] == 1) {
				board2[i][j] = 0; //Any live cell with fewer than two live neighbours dies, as if by underpopulation.
			}
			else if (area == 2 || area == 3 && board[i][j] == 1) {
				board2[i][j] = 1; //Any live cell with two or three live neighbours lives on to the next generation.
			}
			else if (area > 3 && board[i][j] == 1) {
				board2[i][j] = 0; //Any live cell with more than three live neighbours dies, as if by overpopulation.
			}
			else if (area == 3 && board[i][j] == 0) {
				board2[i][j] = 1; //Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
			}
			else {
				continue;
			}
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			board[i][j] = board2[i][j];
		}
	}
}