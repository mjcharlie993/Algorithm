#include <cstdio>
#include <cstring>
const int maxn = 100000 + 5;
int last, curr, next[maxn];
char s[maxn];

int main() {
    while (scanf("%s", s + 1) == 1) {
        int n = strlen(s + 1); // 输入保存在s[1], s[2] ... 中
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
        printf("/n");
    }
    return 0;
}