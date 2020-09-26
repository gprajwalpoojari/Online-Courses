#include <iostream>
#include <cstdio>
#include <cassert>
#include <vector>
#include <queue>
#include <limits>
#include <utility>

using namespace std;

// External vector of size 2 - for forward and backward search.
// Internal 2-dimensional vector is vector of adjacency lists for each node.
typedef vector<vector<vector<int>>> Adj;

// Distances can grow out of int type
typedef long long Len;

// Vector of two priority queues - for forward and backward searches.
// Each priority queue stores the closest unprocessed node in its head.
typedef vector<priority_queue<pair<Len, int>,vector<pair<Len,int>>,greater<pair<Len,int>>>> Queue;

const Len INFINITY = numeric_limits<Len>::max() / 4;

class Bidijkstra {
    // Number of nodes
    int n_;
    // Graph adj_[0] and cost_[0] correspond to the initial graph,
    // adj_[1] and cost_[1] correspond to the reversed graph.
    // Graphs are stored as vectors of adjacency lists corresponding
    // to nodes.
    // Adjacency list itself is stored in adj_, and the corresponding
    // edge costs are stored in cost_.
    Adj adj_;
    Adj cost_;
    // distance_[0] stores distances for the forward search,
    // and distance_[1] stores distances for the backward search.
    vector<vector<Len>> distance_;
    // Stores all the nodes visited either by forward or backward search.
    vector<int> workset_;
    // Stores a flag for each node which is True iff the node was visited
    // either by forward or backward search.
    vector<bool> visited_;

public:
    Bidijkstra(int n, Adj adj, Adj cost)
        : n_(n), adj_(adj), cost_(cost), distance_(2, vector<Len>(n, INFINITY)), visited_(n)
    { workset_.reserve(n); }

    // Initialize the data structures before new query,
    // clear the changes made by the previous query.
    void clear() {
        for (int i = 0; i < workset_.size(); ++i) {
            int v = workset_[i];
            distance_[0][v] = distance_[1][v] = INFINITY;
            visited_[v] = false;
        }
        workset_.clear();
    }

    // Processes visit of either forward or backward search 
    // (determined by value of side), to node v trying to
    // relax the current distance by dist.
    void visit(Queue& q, int side, int v, Len dist) {
        // Implement this method yourself
	if (dist == 0) {
	    distance_[side][v] = 0;
	    q[side].push(std::make_pair(distance_[side][v], v));
	}
	else {
	    int u = q[side].top().second;
	    if (distance_[side][v] > distance_[side][u] + dist) {
		distance_[side][v] = distance_[side][u] + dist;
         	q[side].push(std::make_pair(distance_[side][v], v));
	    }
	}
    }

    // Returns the distance from s to t in the graph.
    Len query(int s, int t) {
        clear();
	if (s == t) {
	    return 0;
	}
        Queue q(2);
        visit(q, 0, s, 0);
        visit(q, 1, t, 0);
        // Implement the rest of the algorithm yourself
	while (!q[0].empty() || !q[1].empty()) {
            if (!q[0].empty()) {
		int u = q[0].top().second;
		if (!visited_[u]) {
		    for (int vert = 0; vert < adj_[0][u].size(); vert++) {
			int vertex = adj_[0][u][vert];
	                if (!visited_[vertex]) {
                            visit(q, 0, adj_[0][u][vert], cost_[0][u][vert]);
		        }
		     }
		    visited_[u] = 1;
		    workset_.push_back(u);
		}
		else {
		    if (distance_[1][u] != INFINITY) {
			Len length_ = INFINITY;
		        for (int i = 0; i < workset_.size(); i++) {
			    if (distance_[0][i] + distance_[1][i] < length_) {
			        length_ = distance_[0][i] + distance_[1][i];
			    }
			}
			return length_;
		    }
		}
		q[0].pop();
	    }
	    if (!q[1].empty()) {
	        int u = q[1].top().second;
		if (!visited_[u]) {
		    for (int vert = 0; vert < adj_[1][u].size(); vert++) {
	                if (!visited_[adj_[1][u][vert]]) {
                            visit(q, 1, adj_[1][u][vert], cost_[1][u][vert]);
		        }
		    }
		    visited_[u] = 1;
		    workset_.push_back(u);
		}
		else {
		    if (distance_[0][u] != INFINITY) {
		        Len length_ = INFINITY;
			for (int i = 0; i < workset_.size(); i++) {
			    if (distance_[0][i] + distance_[1][i] < length_) {
			        length_ = distance_[0][i] + distance_[1][i];
			    }
			}
			return length_;
		    }
		}
		q[1].pop();
	    }
        }
        return -1;
    }
};

int main() {
    int n, m;
    std::cin >> n >> m;
//    scanf("%d%d", &n, &m);
    Adj adj(2, vector<vector<int>>(n));
    Adj cost(2, vector<vector<int>>(n));
    for (int i=0; i<m; ++i) {
        int u, v, c;
        std::cin >> u >> v >> c;
//        scanf("%d%d%d", &u, &v, &c);
        adj[0][u-1].push_back(v-1);
        cost[0][u-1].push_back(c);
        adj[1][v-1].push_back(u-1);
        cost[1][v-1].push_back(c);
    }

    Bidijkstra bidij(n, adj, cost);

    int t;
    std::cin >> t;
//    scanf("%d", &t);
    for (int i=0; i<t; ++i) {
        int u, v;
        std::cin >> u >> v;
//        scanf("%d%d", &u, &v);
        std::cout << bidij.query(u - 1, v - 1) << std::endl;
//        printf("%ld\n", bidij.query(u-1, v-1));
    }
}
