#include<bits/stdc++.h> 
using namespace std; 
# define INF 0x3f3f3f3f 
  
typedef pair<int, int> iPair; 
  
void addEdge(vector <pair<int, int> > adj[], int u, int v, int wt){ //adjacency list utk undirected
    adj[u].push_back(make_pair(v, wt)); 
    adj[v].push_back(make_pair(u, wt)); //klo directed maka hilangkan line ini
} 
   
void shortestPath(vector<pair<int,int> > adj[], int V, int src){ 
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq; // deklarasi priority queue urut dari kecil ke besar (hafalan aja)
    // default priority queue dari besar ke kecil
    vector<pair<int,int> > :: iterator x;	// iterator. Cara kerja nya mirip saat pakai variabel int i di loop, tetapi iterator memakai pointer
    vector<int> dist(V, INF); 				// dist utk menampung jarak sementara suatu vertex dari source. Set awal infinite. INF ada di line 3
    dist[src] = 0;
    pq.push(make_pair(dist[src], src)); 	// isi di dlm pq adalah pair<dist, source>
	 
    while (!pq.empty()){
        int u = pq.top().second; 			// u utk menampung source
        pq.pop(); 
        for (x=adj[u].begin();x!=adj[u].end();++x){ 
            int v = x->first; 				// v utk menampung destination
            int weight = x->second; 
            if (dist[v] > dist[u] + weight){ // jika jarak ke-v lbh besar daripada (jarak awal + weight)
                dist[v] = dist[u] + weight; 
                pq.push(make_pair(dist[v], v)); 
            } 
        } 
    } 
  
    printf("Vertex	Distance from Vertex %d\n",src); 
    for (int i = 0; i < V; ++i) printf("%d\t%d\n", i, dist[i]); 
} 
  
int main(){ 
    int V = 9; 					// banyak vertex
    vector<iPair > adj[V]; 		// pakai adjacency list. iPair disini pair<int, int> untuk pair<destination, weight>
    addEdge(adj, 0, 1, 4); 		// input graph. Formatnya addEdge(adj, source, destination, weight)
    addEdge(adj, 0, 7, 8); 
    addEdge(adj, 1, 2, 8); 
    addEdge(adj, 1, 7, 11); 
    addEdge(adj, 2, 3, 7); 
    addEdge(adj, 2, 8, 2); 
    addEdge(adj, 2, 5, 4); 
    addEdge(adj, 3, 4, 9); 
    addEdge(adj, 3, 5, 14); 
    addEdge(adj, 4, 5, 10); 
    addEdge(adj, 5, 6, 2); 
    addEdge(adj, 6, 7, 1); 
    addEdge(adj, 6, 8, 6); 
    addEdge(adj, 7, 8, 7); 
    shortestPath(adj, V, 0); 	// hitung shortest path
    return 0; 
} 
