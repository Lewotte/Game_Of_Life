#include <iostream>
#include <windows.h>
#include "functions.cpp"

int main() {
	Life board;
	int iterations = 100;
	
	board.display();
	system("PAUSE");
	for (int z = 0; z < iterations; z++) {
		system("CLS");
		board.Rules();
		board.display();
		//Sleep(200);
	}
}