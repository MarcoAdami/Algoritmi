#include <deque>
#include <fstream>
#include <iostream>
#include <stack>
#include <vector>  //#include <bits/stdc++.h> // use in terminal std=c++11
using namespace std;

void DFSRec(int nodo1, vector<vector<int> >& adj, vector<bool>& visited) {
  visited[nodo1] = true;

  cout << nodo1 << " ";

  for (int i = 0; i < adj[nodo1].size(); ++i) {
    int nodo2 = adj[nodo1][i];
    if (visited[nodo2] == false) {
      DFSRec(nodo2, adj, visited);
    }
  }
}

void DFSRec_Kosaraju(int nodo1, vector<vector<int> >& adj,
                     vector<bool>& visited, stack<int>& st) {
  visited[nodo1] = true;

  for (int i = 0; i < adj[nodo1].size(); ++i) {
    int nodo2 = adj[nodo1][i];
    if (visited[nodo2] == false) {
      DFSRec_Kosaraju(nodo2, adj, visited, st);
    }
  }

  st.push(nodo1);
}

void Kosaraju(int n, int m) {
  vector<vector<int> > adj(n);
  vector<bool> visited(n, false);
  stack<int> st;

  int nodo1, nodo2;
  for (int i = 0; i < m; ++i) {
    cin >> nodo1 >> nodo2;
    adj[nodo1].push_back(nodo2);
    // adj[nodo2].push_back(nodo1); //se il grafo non è orientato
  }
  for (int i = 0; i < n;
       ++i) {  // for loop nel caso in cui un grafo non abbia nodi collegati
    if (visited[i] == false) {
      DFSRec_Kosaraju(0, adj, visited, st);
    }
  }

  // while (!st.empty()) {
  //   cout << st.top();
  //   st.pop();
  // }
  // cout << "a" << endl;
  // calcolo trasposta
  vector<vector<int> > adj2(n);

  for (int i = 0; i < n; ++i) {
    int nodo1 = i;
    for (int j = 0; j < adj[nodo1].size(); ++j) {
      int nodo2 = adj[nodo1][j];
      adj2[nodo2].push_back(nodo1);
    }
  }

  // clacola componenti connessi con DFS su trasposta partendo dallo stack
  visited.clear();
  visited.assign(n, 0);

  while (!st.empty()) {
    int nodo = st.top();
    st.pop();

    if (visited[nodo] == false) {
      cout << endl;
      DFSRec(nodo, adj2, visited);
    }
  }
}

int main() {
  // ifstream cin("input.txt");
  // ofstream cout("output.txt");

  int n, m;  // n = numero di nodi, m = numero di archi
  cin >> n >> m;

  Kosaraju(n, m);

  return 0;
}