#pragma once

class Life {
	int size = 50;
	int board[50][50];
	int board2[50][50];
public:
	Life();

	void display();
	void Rules();
};