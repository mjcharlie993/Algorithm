#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <algorithm>

std::map<std::string, int> cnt;
std::vector<std::string> words;

std::string repr(const std::string &s) {
	std::string ans = s;
	for (int i = 0; i != ans.length(); i++)
		ans[i] = tolower(ans[i]);
	std::sort(ans.begin(), ans.end());
	return ans;
}

int main() {
	int n = 0;
	std::string s;
	while (std::cin >> s) {
		if (s[0] == '#')
			break;
		words.push_back(s);
		std::string r = repr(s);
		if (!cnt.count(r)) cnt[r] = 0;
		cnt[r]++;
	}
	std::vector<std::string> ans;
	for (int i = 0; i != words.size(); i++) {
		if (cnt[repr(words[i])] == 1)
			ans.push_back(words[i]);
		std::sort(ans.begin(), ans.end());
		for (int i = 0; i != ans.size(); i++)
			std::cout << ans[i] << std::endl;
		return 0;
	}
}
