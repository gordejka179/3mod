#include <stdio.h>
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;



int main() {
	int n, m, q0;
	cin >> n;
	cin >> m;
	cin >> q0;
	vector<int> used(n, 0);
	vector<vector<int>> input(n, vector<int>(m, 0));
	vector<vector<string>> output(n, vector<string>(m, "0"));
	vector<int> g2(n, 0);
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
	cout << "digraph {" << endl;
	cout << "rankdir = LR" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << i << " -> " << input[i][j] << " [label = \"" << (char)(j + 97) << "(" << output[i][j] << ")\"]" << endl;
		}
	}
	cout << "}" << endl;
}