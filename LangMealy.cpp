#include <stdio.h>
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <set>
using namespace std;

void dfs(int from, int t0, set<int> loop, vector<vector<int>>& input, vector<vector<string>>& output, int count, int m, string s, set<string>& all) {
	if (from != -1 && output[from][t0] != "-") {
		count += 1;
		s += output[from][t0];
		if (all.find(s) == all.end()) {
			cout << s << endl;
		}
		all.insert(s);
	}
	if (from != -1 && output[from][t0] == "-") {
		loop.insert(from);
	}
	if (from != -1 && output[from][t0] != "-") {
		loop.clear();
	}
	//cout << from << " " << t0 << " " << s << " " << " " << endl;
	if (count < m) {
		if (!(from != - 1 && output[from][t0] == "-" && loop.find(input[from][t0]) != loop.end())) {
			for (int i = 0; i < 2; i++) {
				if (from != -1) {
					dfs(input[from][t0], i, loop, input, output, count, m, s, all);
				}
				else {
					dfs(t0, i, loop, input, output, count, m, s, all);
				}
			}
		}
	}
}

int main() {
	int n, m, q0;
	cin >> n;
	vector<int> used(n, 0);
	vector<vector<int>> input(n, vector<int>(2, 0));
	vector<vector<string>> output(n, vector<string>(2, "0"));
	vector<int> g(n, 0);
	vector<int> inverse_g(n, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> input[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> output[i][j];
		}
	}
	cin >> q0;
	cin >> m;
	set<string> all;
	set<int> loop;
	dfs(-1, q0, loop, input, output, 0, m, "", all);
}