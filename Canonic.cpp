#include <stdio.h>
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

void dfs(int to, vector<int>& used, vector<vector<int>>& input, vector<int>& g, int& count, int m) {
	if (used[to] == 0) {
		used[to] = 1;
		g[count] = to;
		count++;
		for (int i = 0; i < m; i++) {
			dfs(input[to][i], used, input, g, count, m);
		}
	}
}

int main() {
	int n, m, q0;
	cin >> n;
	cin >> m;
	cin >> q0;
	vector<int> used(n, 0);
	vector<vector<int>> input(n, vector<int>(m, 0));
	vector<vector<string>> output(n, vector<string>(m, "0"));
	vector<int> g(n, 0);
	vector<int> inverse_g(n, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> input[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> output[i][j];
		}
	}

	int count = 0;
	dfs(q0, used, input, g, count, m);
	for (int line = 0; line < n; line++) {
		inverse_g[g[line]] = line;
	}
	cout << n << endl;
	cout << m << endl;
	cout << inverse_g[q0] << endl;
	for (int line = 0; line < n; line++) {
		for (int i = 0; i < m; i++) {
			//cout << line << " " << i << " " << index << " " << input[line][i] << " " << g2[index] << endl;
			cout << inverse_g[input[g[line]][i]] << " ";
		}
		cout << "\n";
	}
	for (int line : g) {
		for (int i = 0; i < m; i++) {
			cout << output[line][i] << " ";
		}
		cout << "\n";
	}
}