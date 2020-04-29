#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v){ //adjacency list utk undirected
    adj[u].push_back(v); 
    adj[v].push_back(u); //klo directed maka hilangkan line ini
}

void BFS(vector<int> adj[], int V){ 
    bool *visited = new bool[V]; 						// utk ngecek sudah pernah dilewati atau blm
    for(int i = 0; i < V; i++) visited[i] = false; 		// semua di set false (blm prnh dilewati)
    vector<int> ::iterator it; 		// iterator. Cara kerja nya mirip saat pakai variabel int i di loop, tetapi iterator memakai pointer
    queue<int> queue; 				// deklarasi queue
    visited[0] = true; 				// visited[source]=true		disini aku anggap vertex 0 sebagai source
    queue.push(0); 					// push source ke queue
    while(!queue.empty()){
        int s = queue.front(); 
        cout << s << " "; 			// cetak deh
        queue.pop(); 
        for (it = adj[s].begin(); it != adj[s].end(); ++it){ 
            if (!visited[*it]){ 		// klo blm visited maka visited dan push ke queue
                visited[*it] = true; 
                queue.push(*it); 
            } 
        } 
    } 
} 

void DFSUtil(int u, vector<int> adj[], vector<bool> &visited){ 
    visited[u] = true; 
    cout << u << " "; 
    for (int i=0; i<adj[u].size(); i++) 
        if (visited[adj[u][i]] == false) 
            DFSUtil(adj[u][i], adj, visited); 	// ya udh rekursif :v
} 

void DFS(vector<int> adj[], int V){ 
    vector<bool> visited(V, false); 		// deklarasi vector visited sebesar V dengan semua nilainya false
    for (int u=0; u<V; u++) 
        if (visited[u] == false) 
            DFSUtil(u, adj, visited); 		// panggil DFS rekursif
} 

void DFS_iteratif(vector<int> adj[], int V){ 			//cara kerjanya sama kyk BFS, hanya saja memakai stack
    bool *visited = new bool[V]; 
    for(int i = 0; i < V; i++) visited[i] = false; 
    vector<int> ::iterator it; 
    stack<int> stack; 
    visited[0] = true; 
    stack.push(0); 
    while(!stack.empty()){
        int s = stack.top(); 
        cout << s << " "; 
        stack.pop(); 
        for (it = adj[s].begin(); it != adj[s].end(); ++it){ 
            if (!visited[*it]){ 
                visited[*it] = true; 
                stack.push(*it); 
            } 
        } 
    } 
} 

int main(){ 
    int V = 9;				// input banyak vertex
    vector<int> adj[V];		// aku pakai adjacency list
    addEdge(adj, 0, 1); 	// input graph nya. Format addEdge(adj, source, destination)
    addEdge(adj, 0, 7); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 1, 7); 
    addEdge(adj, 2, 3); 
    addEdge(adj, 2, 8); 
    addEdge(adj, 2, 5); 
    addEdge(adj, 3, 4); 
    addEdge(adj, 3, 5); 
    addEdge(adj, 4, 5); 
    addEdge(adj, 5, 6); 
    addEdge(adj, 6, 7); 
    addEdge(adj, 6, 8); 
    addEdge(adj, 7, 8);
    cout<<"BFS Queue:\n";
    BFS(adj, V);
    cout<<"\n\nDFS Stack:\n";
    DFS_iteratif(adj, V);
    cout<<"\n\nDFS Recursive:\n";	// sebisa mungkin hindari rekursif krn makan bnyk memory
	DFS(adj, V); 
    return 0; 
} 
