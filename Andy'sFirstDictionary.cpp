#include <string>
#include <iostream>
#include <set>
#include <sstream>

std::set<std::string> dict;

int main() {
	std::string s, buf;
	while (std::cin >> s) {
		for (int i = 0; i != s.length(); i++)
			if (isalpha(s[i]))
				s[i] = tolower(s[i]);
			else
				s[i] = ' ';
		std::stringstream ss(s);
		while (ss >> buf)
			dict.insert(buf);
	}
	for (std::set<std::string>::iterator it = dict.begin(); it != dict.end(); ++it)
		std::cout << *it << std::endl;
	return 0;

}