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

//Queue q(2);

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
        : n_(n), adj_(adj), cost_(cost), distance_(2, vector<Len>(n, INFINITY)), visited_(n, false)
    { workset_.reserve(n);}

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
	if (q[side].empty()) {
	    distance_[side][v] = dist;
	    q[side].push(std::make_pair(distance_[side][v], v));
	}
	else {
	    int u = q[side].top().second;
	    if (distance_[side][v] > distance_[side][u] + dist) {
		distance_[side][v] = distance_[side][u] + dist;
	       	q[side].push(std::make_pair(distance_[side][v], v));
	    }
	}
	if (!visited_[v]) {
            visited_[v] = true;
	    workset_.push_back(v);
	}
    }

    // Returns the distance from s to t in the graph.
    Len query(int s, int t) {
        clear();
	Queue q(2);
	vector<vector<bool>> processed(2,vector<bool>(n_, false));
        visit(q, 0, s, 0);
        visit(q, 1, t, 0);
        // Implement the rest of the algorithm yourself
	int side = 0;
	while (!q[0].empty() || !q[1].empty()) {
            if (!q[side].empty()) {
		int u = q[side].top().second;
		if (!processed[side][u]) {
		    for (int vert = 0; vert < adj_[side][u].size(); vert++) {
			int vertex = adj_[side][u][vert];
	                if (!processed[side][vertex]) {
                            visit(q, side, vertex, cost_[side][u][vert]);
		        }
		     }
		    processed[side][u] = true;
		}
		q[side].pop();
	        if (processed[side][u] && processed[(side + 1) % 2][u]) {
	            Len length_ = INFINITY;
		    for (int i = 0; i < workset_.size(); i++) {
			length_ = std::min(distance_[side][workset_[i]] + distance_[(side + 1) % 2][workset_[i]], length_);
		    }
		    return length_;
	        }
	    }
            side = (side + 1) % 2;
        }
        return -1;
    }
};

int main() {
    int n, m;
    std::cin >> n >> m;
    Adj adj(2, vector<vector<int>>(n));
    Adj cost(2, vector<vector<int>>(n));
    for (int i=0; i<m; ++i) {
        int u, v, c;
        std::cin >> u >> v >> c;
        adj[0][u-1].push_back(v-1);
        cost[0][u-1].push_back(c);
        adj[1][v-1].push_back(u-1);
        cost[1][v-1].push_back(c);
    }

    Bidijkstra bidij(n, adj, cost);

    int t;
    std::cin >> t;
    for (int i=0; i<t; ++i) {
        int u, v;
        std::cin >> u >> v;
        u--;
	v--;
        std::cout << bidij.query(u, v) << std::endl;
    }
}
