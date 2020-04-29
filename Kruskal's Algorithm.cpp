#include <bits/stdc++.h> 
using namespace std;

bool cmp(pair<int,pair<int,int> > a, pair<int,pair<int,int> > b){
    return (a<b);	// klo a<b maka sama aja kyk sort biasa (sort(edges.begin(), edges.end()))
    // klo a>b bakal sort dari besar ke kecil. Berguna klo diminta Maximum Spanning Tree
}

void addEdge(vector<pair<int,pair<int,int> > > &edges, int u, int v, int wt){ 
    edges.push_back(make_pair(wt, make_pair(u,v)));	// push adjacency edge sesuai format
} 

int find(int parent[], int u){ 
    if (u != parent[u]) parent[u] = find(parent, parent[u]); 
    return parent[u]; 
}

int kruskalMST(vector<pair<int,pair<int,int> > > &edges, int V){ 
    int mst_wt = 0;
//    sort(edges.begin(), edges.end()); 		// STL sort. Formatnya sort(begin(),end()). Sort dari kecil ke besar
    sort(edges.begin(), edges.end(),cmp); 		// STL sort. Formatnya sort(begin(),end(),bool_function)
    
    int *parent = new int[V+1];				// membuat array parent utk nampung parent suatu node
    for (int i = 0; i <= V; i++) parent[i] = i; 	// set awal semua parent dari node adalah dirinya sendiri
    
    vector<pair<int, pair<int,int> > > :: iterator it; 	// iterator. Cara kerja nya mirip saat pakai variabel int i di loop, tetapi iterator memakai pointer
    for (it=edges.begin(); it!=edges.end(); it++){ 
        int u = it->second.first; 			// u = source
        int v = it->second.second; 			// v = destination
        int set_u = find(parent, u);			// cari parent u
        int set_v = find(parent, v);			// cari parent v
        if (set_u != set_v){				// jika parent nya berbeda (tdk membentuk loops)
            cout << u << " - " << v << endl; 
            mst_wt += it->first; 			// update nilai MST
            parent[set_u]=parent[set_v];		// update parent
        } 
    } 
    return mst_wt; 
} 

int main(){ 
    int V=9;					// banyak vertex
    vector<pair<int, pair<int, int> > > edges; 	// aku pakai adjacency edge. Formatnya pair<weight, pair<source, destination > >
    addEdge(edges, 0, 1, 4); 			// input graph. Formatnya addEdge(edges, source, destination, weight)
    addEdge(edges, 0, 7, 8); 
    addEdge(edges, 1, 2, 8); 
    addEdge(edges, 1, 7, 11); 
    addEdge(edges, 2, 3, 7); 
    addEdge(edges, 2, 8, 2); 
    addEdge(edges, 2, 5, 4); 
    addEdge(edges, 3, 4, 9); 
    addEdge(edges, 3, 5, 14); 
    addEdge(edges, 4, 5, 10); 
    addEdge(edges, 5, 6, 2); 
    addEdge(edges, 6, 7, 1); 
    addEdge(edges, 6, 8, 6); 
    addEdge(edges, 7, 8, 7); 
    int mst_wt = kruskalMST(edges, V); 		// hitung MST
    cout<<mst_wt<<endl;
    return 0; 
}
