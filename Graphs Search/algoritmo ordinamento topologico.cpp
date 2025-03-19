#include <algorithm>
#include <deque>
#include <fstream>
#include <iostream>
#include <set>
#include <stack>
#include <vector>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

stack<int> st;

//DFS che inserisce a fine ricorsione il nodo nello stack
void DFSRec(int nodo1, vector<vector<int> >& adj, vector<bool>& visited) {
  visited[nodo1] = true;

  for (auto nodo2 : adj[nodo1]) {
    if (visited[nodo2] == false) {
      DFSRec(nodo2, adj, visited);
    }
  }
  st.push(nodo1);
}

int main() {
  int n, m;
  in >> n >> m;

  set<int> node_root;
  vector<vector<int> > adj(n);
  vector<bool> visited(n, false);

  //inizializzazione del set dei nodi di partenza
  for (int i = 0; i < n; ++i) {
    node_root.insert(i);
  }

  //inserire nodi nella matrice di adiacenza e eliminare quelli che hanno archi entranti
  for (int i = 0; i < m; ++i) {
    int nodo1, nodo2;
    in >> nodo1 >> nodo2;
    adj[nodo1].push_back(nodo2);
    node_root.erase(nodo2);
  }

  //invia tutti i nodi che hanno solo archi uscenti a fare la DFS
  for (set<int>::iterator nodeInizio = node_root.begin();
    nodeInizio != node_root.end(); ++nodeInizio) {
    DFSRec(*nodeInizio, adj, visited);
  }

  //stampa stack
  while (!st.empty()) {
    int nodo = st.top();
    st.pop();
    out << nodo << " ";
  }
  return 0;
}