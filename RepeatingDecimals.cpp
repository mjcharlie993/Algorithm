#include <iostream>
#include <vector>

void main() {
	int sh[3003], yu[3003], mark[3003];
	int m, n, t;
	while (std::cin >> m >> n) {
		int count = 0;
		memset(sh, 0, sizeof(sh));
		memset(mark, 0, sizeof(mark));
		sh[count++] = m / n;
		m %= n;
		while (m && !mark[m]) {
			mark[m] = count;
			yu[count] = m;
			sh[count++] = (10 * m) / n;
			m = 10 * m % n;
		}
		std::cout << sh[0] << '.';
		for (int i = 1; i < count && i <= 50; i++) {
			if (m && yu[i] == m)
				std::cout << '(';
			std::cout << sh[i];
		}
		if (!m) std::cout << "(0";
		if (count > 50)	std::cout << "...";
		std::cout << ')' << std::endl;
		int ans = count - mark[m];
		if (n == 0) ans = 1;
		std::cout << "循环节长度为: " << ans << std::endl;
	}
}
