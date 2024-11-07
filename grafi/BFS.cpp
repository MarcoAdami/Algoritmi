#include<iostream>
#include<vector> //#include <bits/stdc++.h> // use in terminal std=c++11
#include <fstream>
#include <deque>
using namespace std;
 
int main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt", ios::out);
    
    int n, m; // n = numero di nodi, m = numero di archi
    cin>>n>>m;

    vector<vector<int> > adj(n);
    int nodo1, nodo2;
    for(int i=0; i<n; ++i){
        cin>>nodo1>>nodo2;
        adj[nodo1].push_back(nodo2);
        //adj[nodo2].push_back(nodo1); //se il grafo non è orientato
    }

    int nodoInizio=0;
    deque<int> nodes;
    vector<bool> visited(n, 0);

    nodes.push_back(nodoInizio);
    visited[nodoInizio]=true;
    
    while(!nodes.empty()){
        int temp1 = nodes.front();
        nodes.pop_front();
        
        
        for(int i=0; i<adj[temp1].size(); ++i){
            int temp2 = adj[temp1][i];
            
            // se il nodo adiacente non stato visitato entra nella queue
            if(visited[temp2]==false){
                visited[temp2]=true;
                nodes.push_back(temp2);
            }
        }
    }
    return 0;
}