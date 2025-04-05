#include "graph/uf.cpp"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Minispan {
    public:
        int N, M;
        int A[100009], B[100009], C[100009];
        UnionFind UF;
        vector<pair<int, int>> EdgeList;
        
        void init() {
            // 入力を受け取る
            cin >> N >> M;
            for (int i = 1; i <= M; i++) cin >> A[i] >> B[i] >> C[i];
            // 辺を長さの小さい順にソートする
            for (int i = 1; i <= M; i++) EdgeList.push_back(make_pair(C[i], i));
            sort(EdgeList.begin(), EdgeList.end());
        }
                
        int solve() {
            // 最小全域木を求める
            int Answer = 0; UF.init(N);
            for (int i = 0; i < EdgeList.size(); i++) {
                int idx = EdgeList[i].second;
                if (UF.same(A[idx], B[idx]) == false) {
                    UF.unite(A[idx], B[idx]);
                    Answer += C[idx];
                }
            }
            return Answer;
        }
};