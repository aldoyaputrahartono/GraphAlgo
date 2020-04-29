#include <bits/stdc++.h> 
using namespace std;
# define INF 0x3f3f3f3f 

typedef pair<int, int> iPair; 
  
void addEdge(vector <pair<int, int> > adj[], int u, int v, int wt){ //adjacency list utk directed
    adj[u].push_back(make_pair(v, wt)); 
} 
  
void BellmanFord(vector<pair<int,int> > adj[], int V, int src){ 
    vector<pair<int,int> > :: iterator x;		// iterator. Cara kerja nya mirip saat pakai variabel int i di loop, tetapi iterator memakai pointer
    vector<int> dist(V, INF);  				// dist utk menampung jarak sementara suatu vertex dari source. Set awal infinite. INF ada di line 3
    dist[src] = 0; 
  
    for (int i = 0; i < V; i++) { 
    	for(x=adj[i].begin();x!=adj[i].end();++x){ 
            int v = x->first; 				// v utk menampung destination
            int weight = x->second; 
            // jika jarak dari source ke vertex-i tdk infinite dan jarak ke vertex-v lbh besar drpd (jarak awal + weight)
            if (dist[i] != INF && dist[i] + weight < dist[v]) dist[v] = dist[i] + weight;
	}
    } 
  
    // looping lagi seperti diatas utk mengecek apakah ada negative weight cycle yaitu cycle yang weight nya negatif semua
    for (int i = 0; i < V; i++) { 
    	for(x=adj[i].begin();x!=adj[i].end();++x){ 
            int v = x->first; 
            int weight = x->second; 
            if (dist[i] != INF && dist[i] + weight < dist[v]){
            	printf("Graph contains negative weight cycle"); 
            	return; // klo ketemu lngsng return 
	    }
	}
    } 
  
    printf("Vertex	Distance from Vertex %d\n",src); 
    for (int i = 0; i < V; ++i) printf("%d\t%d\n", i, dist[i]); 
    return; 
} 
  
int main(){ 
    // Algoritmanya mirip dengan Dijkstra's, hanya saja weight disini dpt bernilai negatif
    int V = 5;			// banyak vertex
    vector<iPair > adj[V]; 	// pakai adjacency list. iPair disini pair<int, int> untuk pair<destination, weight>
    addEdge(adj, 0, 1, -1); 	// input graph. Formatnya addEdge(adj, source, destination, weight)
    addEdge(adj, 0, 2, 4); 
    addEdge(adj, 1, 2, 3); 
    addEdge(adj, 1, 3, 2); 
    addEdge(adj, 1, 4, 2); 
    addEdge(adj, 3, 2, 5); 
    addEdge(adj, 3, 1, 1); 
    addEdge(adj, 4, 3, -3); 
    BellmanFord(adj, V, 0); 	// hitung shortest path
    return 0; 
} 
