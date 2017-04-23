#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
const int maxn = 100000 + 5;
int last, curr, next[maxn];
char s[maxn];
// next[i] 表示 s[i] 右边的字符编号（s中的下标）
int main() {
	while (scanf("%s", s + 1) == 1) {
		int n = strlen(s + 1);
		last = curr = 0;
		next[0] = 0;

		for (int i = 1; i <= n; i++) {
			char ch = s[i];
			if (ch == '[')
				curr = 0;
			else if (ch == ']')
				curr = last;
			else {
				next[i] = next[curr];
				next[curr] = i;
				if (curr == last)
					last = i;
				curr = i;
			}
		}
		for (int i = next[0]; i != 0; i = next[i])
			printf("%c", s[i]);
		printf("\n");
	}
	return 0;
}