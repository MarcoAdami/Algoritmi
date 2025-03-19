#include <deque>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

void BFS(vector<vector<int> >& adj, vector<bool> visited) {
  int nodoInizio = 0;
  deque<int> nodes;

  nodes.push_back(nodoInizio);
  visited[nodoInizio] = true;

  while (!nodes.empty()) {
    int temp1 = nodes.front();
    nodes.pop_front();

    for (int i = 0; i < adj[temp1].size(); ++i) {
      int temp2 = adj[temp1][i];

      // se il nodo adiacente non stato visitato entra nella queue
      if (visited[temp2] == false) {
        visited[temp2] = true;
        nodes.push_back(temp2);
      }
    }
  }
}

int main() {
  ifstream cin("input.txt");
  ofstream cout("output.txt", ios::out);

  int n, m;  // n = numero di nodi, m = numero di archi
  cin >> n >> m;

  vector<vector<int> > adj(n);
  vector<bool> visited(n, 0);

  int nodo1, nodo2;
  for (int i = 0; i < m; ++i) {
    cin >> nodo1 >> nodo2;
    adj[nodo1].push_back(nodo2);
    adj[nodo2].push_back(nodo1);
  }

  BFS(adj, visited);

  return 0;
}