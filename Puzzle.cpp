#include <vector>
#include <string>
#include <iostream>

void main() {
	char a[5][5] = { 'T', 'R', 'G', 'S', 'J',
		'X', 'D', 'O', 'K', 'I',
		'M',' ', 'V', 'L','N',
		'W','P','A','B','E',
		'U','Q','H','C','F' };
	for (int i = 0; i != 5; i++) {
		for (int j = 0; j != 5; j++) {
			std::cout << a[i][j];
		}
		std::cout << std::endl;
	}

	int x = 0, y = 0;
	for (int i = 0; i != 5; i++) {
		for (int j = 0; j != 5; j++) {
			if (a[i][j] == ' ') {
				x = i;
				y = j;
				break;
			}
		}
	}
	std::string s;
	std::cin >> s;
	int size = s.size();
	char c = 0;
	for (int i = 0; i != size; i++) {
		c = s[i];
		switch (c) {
		case 'A': {
			std::swap(a[x][y], a[x - 1][y]);
			x = x - 1;
			y = y;
			break;
		}
		case 'B': {
			std::swap(a[x][y], a[x + 1][y]);
			x = x + 1;
			y = y;
			break;
		}
		case 'L': {
			std::swap(a[x][y], a[x][y - 1]);
			x = x;
			y = y - 1;
			break;
		}
		case 'R': {
			std::swap(a[x][y], a[x][y + 1]);
			x = x;
			y = y + 1;
			break;
		}
		case '0': {
			break;
		}
		default:
			std::cout << "This puzzle has no final configuration." << std::endl;
			break;
		}
	}
	for (int i = 0; i != 5; i++) {
		for (int j = 0; j != 5; j++) {
			std::cout << a[i][j];
		}
		std::cout << std::endl;
	}
}