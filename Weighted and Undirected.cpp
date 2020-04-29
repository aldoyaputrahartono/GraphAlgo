#include <bits/stdc++.h> 
using namespace std;

void addEdge(vector<pair<int,int> > adj[], int u, int v, int wt){ //adjacency list utk undirected
    adj[u].push_back(make_pair(v, wt)); 
    adj[v].push_back(make_pair(u, wt)); //klo directed maka hilangkan line ini
} 

void printGraph(vector<pair<int,int> > adj[], int V){ 
    vector<pair<int,int> > :: iterator it;	// iterator. Cara kerja nya mirip saat pakai variabel int i di loop, tetapi iterator memakai pointer
    int dst, weight; 
    for (int src = 0; src < V; src++){ 
        cout << "Node " << src << " makes an edge with \n"; 
        for (it = adj[src].begin(); it!=adj[src].end(); it++){ 
            dst = it->first; 			// krn tadi pair<destination, weight> maka destination jd first dan weight jd second
            weight = it->second; 
            cout << "\tNode " << dst << " with edge weight =" << weight << "\n"; 
        } 
        cout << "\n"; 
    } 
} 

int main(){ 
    int V = 5; 				// banyak vertex
    vector<pair<int, int> > adj[V]; 	// adjacency list dmn isi pairnya <destination, weight>
    addEdge(adj, 0, 1, 10); 		// input graphnya. Format addEdge(adj, source, destination, weight)
    addEdge(adj, 0, 4, 20); 
    addEdge(adj, 1, 2, 30); 
    addEdge(adj, 1, 3, 40); 
    addEdge(adj, 1, 4, 50); 
    addEdge(adj, 2, 3, 60); 
    addEdge(adj, 3, 4, 70); 
    printGraph(adj, V); 		// print graphnya
    // klo graphnya sdh weighted maka BFS DFS jd gk seberapa berguna krn lbh berfokus ke weightnya
    // ntar problem yang muncul biasanya MST sama shortest path
    return 0; 
}
