#include <bits/stdc++.h> 
using namespace std; 
#define INF 0x3f3f3f3f

int V,graph[100][100],dist[100][100];

void printSolution(){  
    cout<<"The following matrix shows the shortest distances between every pair of vertices \n";  
    for (int i = 0; i < V; i++){  
        for (int j = 0; j < V; j++){  
            if (dist[i][j] == INF) cout<<"INF\t";  
            else cout<<dist[i][j]<<"\t";  
        }  
        cout<<endl;  
    }  
}  
  
void floydWarshall(){  
    int i, j, k;  
    for (i = 0; i < V; i++)  
        for (j = 0; j < V; j++)  
            dist[i][j] = graph[i][j];  // isi dist senilai graph. dist[i][j] brrt menampung jarak dari vertex-i ke vertex-j
           
    for (k = 0; k < V; k++){  
        for (i = 0; i < V; i++){  
            for (j = 0; j < V; j++){  
                if (dist[i][k] + dist[k][j] < dist[i][j]) dist[i][j] = dist[i][k] + dist[k][j];  // update dist[i][j]
            }  
        }  
    }  
    printSolution();  // print semua jarak dari tiap vertex ke vertex lainnya
}  

int main(){  
    /* Let us create the following weighted graph  
            10  
    (0)------->(3)  
     |         /|\  
   5 |          |  
     |          | 1  
    \|/         |  
    (1)------->(2)  
            3     */
    V=4;								// banyak vertex
    for(int i=0;i<V;i++){				// pakai adjacency matrix, semua di set INF, kecuali yang menunjuk ke dirinya sndr bernilai 0
    	for(int j=0;j<V;j++){
    		if(i==j) graph[i][j]=0;
    		else graph[i][j]=INF;
		}
	}
	graph[0][1]=5;						// input weight. graph[i][j]=weight brrt weight utk vertex-i ke vertex-j
	graph[0][3]=10;
	graph[1][2]=3;
	graph[2][3]=1;
    floydWarshall();					// hitung shortest path
    return 0;  
}  
