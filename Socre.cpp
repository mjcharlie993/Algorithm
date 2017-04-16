#include <iostream>
#include <string>

int main() {
	std::string msg = { "OOXXOXXOOO" };
	int sum = 0, value = 1;
	int size = msg.size();
	for (int i = 0; i != size; i++) {
		if (msg[i] == 'O')
			sum += value++;
		if (msg[i] == 'X') {
			value = 1;
		}
	}
	std::cout << sum << std::endl;
	return sum;
}