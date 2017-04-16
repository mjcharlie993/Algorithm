#include <iostream>
#include <vector>
#include <string>
inline int f(std::string s, int n) {
	int res = s[n] - '0';
	return res;
}

int main() {
	std::vector<int> vec(10, 0);
	std::string str;
	std::cin >> str;
	int size = str.size();
	while (size--) {
		int n = f(str, size);
		vec[n]++;
	}
	for (int i = 0; i != 10; i++)
		std::cout << i << " appear time is: " << vec[i] << std::endl;
}
void firstTry() {
	std::vector<int> vec(10, 0);
	int num;
	std::cin >> num;
	while (num) {
		int c = num % 10;
		vec[c]++;
		num /= 10;
	}
	for (int i = 0; i != 10; i++)
		std::cout << i << " appear time is: " << vec[i] << std::endl;
}