#include <iostream>
#include <stack>
#include <set>
#include <string>
#include <vector>
#include <map>
typedef std::set<int> Set;
std::map<Set, int> IDcache;
std::vector<Set> Setcache;

int ID(Set x) {
	if (IDcache.count(x))
		return IDcache[x];
	Setcache.push_back(x);
	return IDcache[x] = Setcache.size() - 1;
}

#define ALL(x) ((x.begin(), x.end());
#define INS(x) inserter(x, x.begin());

void main() {
	std::stack<int> s;
	int n;
	std::cin >> n;
	for (int i = 0; i != n; i++) {
		std::string op;
		std::cin >> op;
		if (op[0] == 'P')
			s.push(ID(Set()));
		else if (op[0] == 'D')
			s.push(s.top());
		else {
			Set x1 = Setcache[s.top()]; 
			s.pop();
			Set x2 = Setcache[s.top()];
			s.pop();
			Set x;
			if (op[0] == 'U')
				set_union(ALL(x1), ALL(x2), INS(x));
			if (op[0] == 'I')
				set_intersection(ALL(x1), ALL(x2), INS(x));
			if (op[0] == 'A') {
				x = x2;
				x.insert(ID(x1));
			}
			s.push(ID(x));
		}
		std::cout << Setcache[s.top].size() << std::endl;
	}
}
