#include <iostream>
#include <string>

inline double f(char c) {
	switch (c) {
	case 'C': return 12.01;
	case 'H': return 1.008;
	case 'O': return 16.00;
	case 'N': return 14.01;
	default: std::cout << "Error!" << std::endl;
		exit(0);
	}
}
inline bool g(char c) {
	if (c >= '0' && c <= '9')
		return true;
	else
		return false;
}
int main() {
//	std::string s = "C6H5OH";
	std::string s;
	std::cin >> s;
	double sum = 0;
	int n = 0;
	int size = s.size();
	for (int i = 0; i != size; i++) {
		if (g(s[i])) {
			n = s[i] - '0';
			sum += f(s[i - 1]) * (n - 1);
		}
		else {
			sum += f(s[i]);
		}
	}
	std::cout << sum << std::endl;
	return 0;
}