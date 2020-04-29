#include<bits/stdc++.h> 
using namespace std; 
# define INF 0x3f3f3f3f 

typedef pair<int, int> iPair; 
  
void addEdge(vector <pair<int, int> > adj[], int u, int v, int wt){ //adjacency list utk undirected
    adj[u].push_back(make_pair(v, wt)); 
    adj[v].push_back(make_pair(u, wt)); //klo directed maka hilangkan line ini
} 
  
void primMST(vector<pair<int,int> > adj[], int V) { 
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq; // deklarasi priority queue urut dari kecil ke besar (hafalan aja)
    // default priority queue dari besar ke kecil
    vector<pair<int,int> > :: iterator x;	// iterator. Cara kerja nya mirip saat pakai variabel int i di loop, tetapi iterator memakai pointer
    int src = 0, mst_wt = 0; 
    vector<int> key(V, INF); 				// key utk menampung jarak sementara suatu vertex dari source. Set awal infinite. INF ada di line 3
    vector<int> parent(V, -1); 				// parent utk menampung vertex ke-i dihubungkan dengan siapa. Set awal semua -1
    vector<bool> inMST(V, false); 			// inMST utk ngecek sdh dilewati atau blm
    key[src] = 0; 
    pq.push(make_pair(key[src], src)); 		// isi di dlm pq adalah pair<key, source>
    while (!pq.empty()){ 
        int u = pq.top().second; 			// u menampung source
        pq.pop(); 
        inMST[u] = true;
        for (x=adj[u].begin();x!=adj[u].end();++x){ 
            int v = x->first; 				// v menampung destination
            int weight = x->second; 
            if (inMST[v] == false && key[v] > weight){ // jika blm dilewati dan jarak ke-v melebihi weight
                key[v] = weight; 
                pq.push(make_pair(key[v], v)); 
                parent[v] = u; 
            } 
        } 
    } 
    for (int i = 1; i < V; ++i){
    	printf("%d - %d\n", parent[i], i); 
    	mst_wt+=key[i];						// update MST
	}
    cout<<mst_wt<<endl;
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
    primMST(adj, V); 			// hitung MST
    return 0; 
} 
