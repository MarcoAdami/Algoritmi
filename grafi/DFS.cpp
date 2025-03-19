#include <deque>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

void DFSRec(int nodo1, vector<vector<int> >& adj, vector<bool>& visited) {
  visited[nodo1] = true;

  for (int i = 0; i < adj[nodo1].size(); ++i) {
    int nodo2 = adj[nodo1][i];
    if (visited[nodo2] == false) {
      DFSRec(nodo2, adj, visited);
    }
  }
}

void DFS(int n, int m) {
  vector<vector<int> > adj(n);
  vector<bool> visited(n, false);

  int nodo1, nodo2;
  for (int i = 0; i < m; ++i) {
    cin >> nodo1 >> nodo2;
    adj[nodo1].push_back(nodo2);
    // adj[nodo2].push_back(nodo1); //se il grafo non è orientato
  }

  DFSRec(0, adj, visited);
}

int main() {
  ifstream cin("input.txt");
  ofstream cout("output.txt", ios::out);

  int n, m;  // n = numero di nodi, m = numero di archi
  cin >> n >> m;

  DFS(n, m);

  return 0;
}