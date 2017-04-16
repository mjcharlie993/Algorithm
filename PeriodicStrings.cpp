#include <iostream>
#include <string>

void main() {
	std::string s;
	std::cin >> s;
	int size = s.size();
	for (int i = 1; i != size + 1; i++) {
		if (size % i == 0) {
			bool ac = true;
			for (int j = i; j != size; j++)
				if (s[j] != s[j % i]) {
					ac = false;
					break;
				}
			if (ac) {
				std::cout << i << std::endl;
				break;
			}
		}
	}
}