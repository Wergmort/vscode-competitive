#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;

using ll = long long;
using ull = unsigned long long;
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;
#define yes cout << "yes" << endl;
#define no cout << "no" << endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
//cout << fixed << setprecision(10);
void double_out_format(int precision) {
    cout << fixed << setprecision(precision);
}
template <typename T, typename S>
auto add(T a, S b) -> decltype(a + b) {
	return a + b;
}

typedef pair<int, int> grid;

grid rotate(int x, int y, int n) {
	return {y, n - 1 - x};
}

bool visited[200001];
vector<int> G[200001];

bool flag = true;
int dfs_count = 0; // 深さ優先探索のカウント

void dfs(int pos,int n) { // pos は現在位置
  visited[pos] = true; // 訪問済み
  dfs_count++; // カウントを増やす	
   for (int i = 0; i < G[pos].size(); i++) {
	   int nex = G[pos][i];
	   if (visited[nex] == false) dfs(nex, n);
	   else if (dfs_count != n) { 
		   //cout << pos << endl;
		//    cout << nex << endl;
		   return;
	   } 
  }
  return ;
}

int main() {

}	