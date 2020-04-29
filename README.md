# Graph Algorithm

Graph pada dasarnya dibagi 2:
1. Berdasarkan beratnya : Weighted dan Unweighted
2. Berdasarkan arahnya  : Directed dan Undirected

Untuk implementasi BFS dan DFS pada graph Unweighted (baik itu Directed ataupun Undirected) dapat dilihat di https://github.com/aldoyaputrahartono/GraphAlgo/blob/master/Unweighted%20and%20Undirected.cpp

BFS menghasilkan shortest path, sedangkan DFS menghasilkan jarak terjauh dari suatu vertex.

Untuk graph Weighted (baik itu Directed ataupun Undirected) dapat dilihat di https://github.com/aldoyaputrahartono/GraphAlgo/blob/master/Weighted%20and%20Undirected.cpp

BFS dan DFS sedikit tidak berguna disini karena lebih berfokus pada weight tiap vertex.
Implementasinya lebih banyak pada Minimum Spanning Tree (MST) dan Shortest Path.

Algoritma Minimum Spanning Tree:
1. Kruskal's Algorithm  : https://github.com/aldoyaputrahartono/GraphAlgo/blob/master/Kruskal's%20Algorithm.cpp

   Fokus Kruskal adalah memilih edge berdasarkan urutan weight dari terkecil ke terbesar hingga semua edge terhubung.
2. Prim's Algorthm      : https://github.com/aldoyaputrahartono/GraphAlgo/blob/master/Prim's%20Algorithm.cpp

   Fokus Prim adalah melakukan BFS dari source sambil memilih edge dengan weight terkecil yang terhubung dengan source.

Algoritma Shortest Path:
1. Dijkstra's Algorithm     : https://github.com/aldoyaputrahartono/GraphAlgo/blob/master/Dijkstra%E2%80%99s%20Algorithm.cpp

   Dijkstra hanya bisa digunakan jika weight bernilai non-negative.
2. Bellman-Ford Algorithm   : https://github.com/aldoyaputrahartono/GraphAlgo/blob/master/Bellman-Ford%20Algorithm.cpp

   Bellman-Ford bisa digunakan meskipun weight bernilai negative.
3. Floyd Warshall Algorithm : https://github.com/aldoyaputrahartono/GraphAlgo/blob/master/Floyd%20Warshall%20Algorithm.cpp

   Floyd Warshall akan mencetak jarak semua pasangan vertex.
