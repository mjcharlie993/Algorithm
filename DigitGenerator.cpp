#include <iostream>
#include <string>
const int maxn = 2006;
int ans[maxn];

int main() {
	int T = 0;
	memset(ans, 0, sizeof(ans));
	for (int m = 1; m != maxn; m++) {
		int x = m, y = m;
		while (x > 0) {
			y += x % 10;
			x /= 10;
		}
		if (ans[y] == 0 || m < ans[y])
			ans[y] = m;
	}
	//for (auto c : ans)
	//	std::cout << c << std::endl;
	std::cin >> T;

	std::cout << ans[T];
	return 0;
}