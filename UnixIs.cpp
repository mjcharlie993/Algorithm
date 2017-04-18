#include <iostream>
#include <string>
#include <algorithm>

const int maxcols = 60;
const int maxn = 100 + 5;
std::string filenames[maxn];

void print(const string& s, int len, char extra) {
    std::cout << s;
    for (int i = 0; i != len - s.length(); i++) 
        std::cout << extra;
}

int main() {
    int n;
    while (std::cin >> n) {
        int M = 0;
        for (int i = 0; i != n; i++) {
            std::cin >> filenames[i];
            M = max(M, (int)filenames[i].length());
        }
        int cols = (maxcol - M) / (M + 2) + 1, rows = (n - 1) / cols + 1;
        print("", 60, '-');
        std::cout << '\n';
        sort(filenames, filenames + n);
        for (int r = 0; r != rows; r++) {
            for (int c = 0; c != cols; c++) {
                int idx = c * rows + r;
                if (idx < n)
                    print(filenames[idx], c == cols - 1 ? M : M + 2, ' ');
            }
            std::cout << '\n';
        }
    }
    return 0;
}