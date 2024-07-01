#include <stdio.h>
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
using namespace std;

void dfs(int to, vector<int>& used, vector<vector<int>>& input, vector<vector<string>>& output, 
map<pair<int, string>, set<pair<int, string>>>& g, int m, int n,vector<string> &all_insign, vector<string> &all_outsign, 
vector<set<pair<int, string>>>& comp,  map<pair<pair<int, string>, pair<int, string>>, vector<string>>& sign_edge){
    used[to] = 1;
    for (int i = 0; i < m; i++){
        int aim = input[to][i];
        string outsign = output[to][i];
        pair<int, string> p = make_pair(aim, outsign);
            for (auto it1 = comp[to].begin(); it1 != comp[to].end(); ++it1){
                g[*it1].insert(p);
                pair<pair<int, string>, pair<int, string>> tmp_pair2 = make_pair(*it1, p);
                //cout << it1->first << " " << it1->second << " " << it->first << " " << it->second << " " << all_insign[i] << endl;
                auto it3 = sign_edge.find(tmp_pair2);
                if (it3 != sign_edge.end()) {
                    //cout << it3->first.first.first<< " " << it3->first.first.second<< " " << it3->first.second.first << " " << it3->first.second.second << endl;
                    it3->second.push_back(all_insign[i]);
                }
                else{
                    vector<string> tmp;
                    tmp.push_back(all_insign[i]);
                    pair<pair<pair<int, string>, pair<int, string>>, vector<string>> tmp_pair = make_pair(tmp_pair2, tmp);
                    sign_edge.insert(tmp_pair);

                }

        }
        if (used[input[to][i]] == 0){
            dfs(input[to][i], used, input, output, g, m, n, all_insign, all_outsign, comp, sign_edge);
        }
    }
}

int main() {
	int k, m, n;
	cin >> m;
    vector<string> all_insign(m);
	for (int j = 0; j < m; j++) {
	    cin >> all_insign[j];
    }
    cin >> k;
    vector<string> all_outsign(k);
    for (int j = 0; j < k; j++) {
	    cin >> all_outsign[j];
    }
    cin >> n;
	vector<vector<int>> input(n, vector<int>(m, 0));
	vector<vector<string>> output(n, vector<string>(m, "0"));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> input[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
            int num;
            cin >> num;
            output[i][j] = all_outsign[num];
		}
	}
    map<pair<int, string>, set<pair<int, string>>> g;
    vector<set<pair<int, string>>> comp(n);
    for (int i = 0; i < n; i++){
        for (int x = 0; x < n; x++){
            for (int y = 0; y < m; y++){
                if (input[x][y] == i){
                    string outsign = output[x][y];
                    pair<int, string> p = make_pair(i, outsign);
                    comp[i].insert(p);
                    set<pair<int, string>> v;
                    pair<pair<int, string>, set<pair<int, string>>> p2 = make_pair(p, v);
                    g.insert(p2);  
                }
            }
        }
    }
    vector<int> used(n, 0);
    map<pair<pair<int, string>, pair<int, string>>, vector<string>> sign_edge;
	dfs(0, used, input, output, g, m, n, all_insign, all_outsign, comp, sign_edge);
    int count = 0;
    cout << "digraph {" << endl;
    cout << "rankdir = LR" << endl;
    map<pair<int, string>, int> newg;
    for (auto p : g) {
        pair<pair<int, string>, int> p2 = make_pair(p.first, count);
        newg.insert(p2);
        cout << count << " " << "[label = \"(" << p.first.first << "," << p.first.second << ")\"]" << endl;
        count++;
    }
    for (auto p:g){
        int from, to;
        from = newg.find(p.first)->second;
        for (auto tmpp: p.second){
            to = newg.find(tmpp)->second; 
            pair<pair<int, string>, pair<int, string>> tmpp2 = make_pair(p.first, tmpp);
            for (string sign:sign_edge.find(tmpp2)->second){
                 cout << from << " -> " << to << " [label = \"" << sign << "\"]" << endl;         
            }
        }
    }
    cout << "}" << endl;
}