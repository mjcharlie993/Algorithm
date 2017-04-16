#include <iostream>
#include <string>

int main() {
	int t;
	std::cin >> t;
	char x[50][1000];
	while (t--) {
		int m, n;
		std::cin >> m >> n;
		for (int i = 0; i != m; i++)
			for (int j = 0; i != n; j++)
				std::cin >> x[i][j];
		int dis = 0;
		char temp;
		std::string s(1000, 0);
		int p = 0;
		for (int j = 0; j != n; j++) {
			int a = 0, t = 0, c = 0, g = 0, max = 0;
			for (int i = 0; i != m; i++) {
				if (x[i][j] == 'A')
					a++;
				if (x[i][j] == 'T')
					t++;
				if (x[i][j] == 'C')
					c++;
				if (x[i][j] == 'G')
					g++;
			}
			max = a;
			temp = 'A';
			if (max < t) {
				max = t;
				temp = 'T';
			}
			if (max < c) {
				max = c;
				temp = 'C';
			}
			if (max < g) {
				max = g;
				temp = 'G';
			}
			s[p++] = temp;
			if (temp == 'A') dis = dis + t + c + g;
			if (temp == 'T') dis = dis + a + c + g;
			if (temp == 'C') dis = dis + a + t + g;
			if (temp == 'G') dis = dis + a + t + c;
		}
		for (int i = 0; i != n; i++)
			std::cout << s[i];
		std::cout << std::endl  << dis << std::endl;
	}
	return 0;
}