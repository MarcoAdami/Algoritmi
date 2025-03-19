#include <deque>
#include <fstream>
#include <iostream>
#include <stack>
#include <vector>  //#include <bits/stdc++.h>
#include <cmath>
#include <climits>
using namespace std;

int tempo=1;

void tarjanUtil(int u, int disc[], int low[], stack<int>& st, bool stackMember[], vector<vector<int> >& adj) {

  // Inizializza il tempo di scoperta e di low
  disc[u] = tempo;
  low[u] = tempo;
  tempo+=1;
  st.push(u);
  stackMember[u] = true;

  // Passa attraverso tutti i vertici connessi a questo
  
  for (int i = 0; i != adj[u].size(); ++i) {
    int v = adj[u][i];  // v is current adjacent of 'u'

    // If v is not visited yet, then recur for it
    if (disc[v] == -1) {
      tarjanUtil(v, disc, low, st, stackMember, adj);
      low[u] = min(low[u], low[v]);
    }else if (stackMember[v] == true)
      low[u] = min(low[u], disc[v]);
  }

  // head node found, pop the stack and print an SCC
  int w;  // To store stack extracted vertices
  if (low[u] == disc[u]) {
    while (st.top() != u) {
      w = st.top();
      cout << w << " ";
      stackMember[w] = false;
      st.pop();
    }
    w = st.top();
    cout << w << "\n";
    stackMember[w] = false;
    st.pop();
  }
}

// The function to do DFS traversal. It uses tarjan()
void tarjan(int n, int m) {
  vector<vector<int> > adj(n);
  int disc[n];
  int low[n];
  bool stackMember[n];
  stack<int> st;

  //Inizializza la matrice di adiacenza
  for(int i=0; i<m; ++i){
    int nodo1, nodo2;
    cin>>nodo1>>nodo2;
    adj[nodo1].push_back(nodo2);
  }

  // Inizializza gli array disc, low e stackMember
  for (int i = 0; i < n; i++) {
    disc[i] = -1;
    low[i] = -1;
    stackMember[i] = false;
  }

  // Chiama la funzione ricorsiva per trovare le componenti fortemente connesse
  for (int i = 0; i < n; i++)
    if (disc[i] == -1) tarjanUtil(i, disc, low, st, stackMember, adj);
}

int main() {
  // ifstream cin("input.txt");
  // ofstream cout("output.txt");

  int n, m;  // n = numero di nodi, m = numero di archi
  cin >> n >> m;

  tarjan(n, m);

  return 0;
}