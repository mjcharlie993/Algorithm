#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstdio>

const int maxn = 10000;
int main() {
	int n, q, x, a[maxn], kase = 0;
	while (scanf("%d%d", &n, &q) == 2 && n) {
		printf("CASE# %d:\n", ++kase);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		std::sort(a, a + n);
		while (q--) {
			scanf("%d", &x);
			int p = std::lower_bound(a, a + n, x) - a;
			if (a[p] == x)
				printf("%d found at %d\n", x, p + 1);
			else
				printf("%d not found\n", x);
		}
	}
	return 0;
}