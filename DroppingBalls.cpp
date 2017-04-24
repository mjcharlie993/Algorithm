// C
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
const int maxd = 20;
int s[1 << maxd];

int main() {
	int D, I;
	while (scanf("%d%d", &D, &I) == 2) {
		memset(s, 0, sizeof(s));
		int k = 0, n = (1 << D) - 1;
		for (int i = 0; i != I; i++) {
			k = 1;
			for (;;) {
				s[k] = !s[k];
				k = s[k] ? k * 2 : k * 2 + 1;
				if (k > n)
					break;
			}
		}
		printf("%d\n", k / 2);
	}
	return 0;
}

// C++
#include <iostream>
const int maxn = 20;
int s[1 << maxn];
int main() {
	int D, I;
	while (std::cin >> D >> I) {
		memset(s, 0, sizeof(s));
		int k, n = (1 << D) - 1;
		for (int i = 0; i != I; i++) {
			k = 1;
			for (;;) {
				s[k] = !s[k];
				k = s[k] ? k * 2 : k * 2 + 1;
				if (k > n)
					break;
			}
		}
		std::cout << k / 2 << std::endl;
	}
	return 0;
}