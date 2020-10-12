#include <iostream>
#include <cstdio>
#include <cassert>
#include <vector>
#include <queue>
#include <limits>
#include <utility>
#include <cmath>

using namespace std;

// See the explanations of these typedefs and constants in the starter for friend_suggestion
typedef vector<vector<vector<int>>> Adj;
typedef long long Len;
typedef vector<priority_queue<pair<Len, int>, vector<pair<Len,int>>, greater<pair<Len,int>>>> Queue;

const Len INFINITE = numeric_limits<Len>::max() / 4;

class AStar {
    // See the descriptions of these fields in the starter for friend_suggestion
    int n_;
    Adj adj_;
    Adj cost_;
    vector<vector<Len>> distance_;
    vector<int> workset_;
    vector<bool> visited_;
    // Coordinates of the nodes
    std::vector<std::pair<Len,Len>> xy_;

public:
    AStar(int n, Adj adj, Adj cost, std::vector<std::pair<Len,Len>> xy)
        : n_(n), adj_(adj), cost_(cost), distance_(2, vector<Len>(n_, INFINITE)), visited_(n), xy_(xy)
    { workset_.reserve(n); }

    // See the description of this method in the starter for friend_suggestion
    void clear() {
        for (int i = 0; i < workset_.size(); ++i) {
            int v = workset_[i];
            distance_[0][v] = distance_[1][v] = INFINITE;
            visited_[v] = false;
        }
        workset_.clear();
    }

    Len euclidian(int u, int v) {
        return (sqrt(pow(xy_[u].first - xy_[v].first, 2) + pow(xy_[u].second - xy_[v].second, 2)));
    }

    Len norm_distance(int v, int s, int t, int side) {
	if (side == 0) {
	    return 0.5 * (euclidian(s, t) + euclidian(s, v) - euclidian(v, t));
	}
	else
	    return 0.5 * (euclidian(s, t) - euclidian(s, v) + euclidian(v, t));
    }

    // See the description of this method in the starter for friend_suggestion
    void visit(Queue& q, int side, int v, Len dist, int s, int t) {
        // Implement this method yourself
	if (q[side].empty()) {
	    distance_[side][v] = dist;
	    q[side].push(std::make_pair(distance_[side][v], v));
	}
	else {
	    int u = q[side].top().second;
	    if (distance_[side][v] > distance_[side][u] + dist) {
	        distance_[side][v] = distance_[side][u] + dist;
		q[side].push(std::make_pair(distance_[side][v] - norm_distance(v, s, t, side), v));
	    }
	}
	if (!visited_[v]) {
	    visited_[v] = true;
	    workset_.push_back(v);
	}
    }

    // Returns the distance from s to t in the graph
    Len query(int s, int t) {
        clear();
        Queue q(2);
        visit(q, 0, s, 0, s, t);
        visit(q, 1, t, 0, s, t);
        // Implement the rest of the algorithm yourself
	int side {0};
	vector<vector<bool>> processed(2, vector<bool>(n_, false));
	while (!q[side].empty() || !q[(side + 1) % 2].empty()) {
	    if (!q[side].empty()) {
		int u = q[side].top().second;
		if (!processed[side][u]) {
   		    for (int i = 0; i < adj_[side][u].size(); i++) {
			int vertex = adj_[side][u][i];
		        if (!processed[side][vertex]) {
			    visit(q, side, vertex, cost_[side][u][i], s, t);
			}
		    }
		    processed[side][u] = true;
		}
		q[side].pop();
		if (processed[side][u] && processed[(side + 1) % 2][u]) {
		    Len length = INFINITE;
		    for (auto i : workset_) {
			Len shortest = distance_[side][i] + distance_[(side + 1) % 2][i];
			length = min(shortest, length);
		    }
		    return length;
		}
	    }
	    side = (side + 1) % 2;
	}
        return -1;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    std::vector<std::pair<Len,Len>> xy(n);
    for (int i=0;i<n;++i){
        int a, b;
	cin >> a >> b;
        xy[i] = make_pair(a,b);
    }
    Adj adj(2, vector<vector<int>>(n));
    Adj cost(2, vector<vector<int>>(n));
    for (int i=0; i<m; ++i) {
        int u, v, c;
	cin >> u >> v >> c;
        adj[0][u-1].push_back(v-1);
        cost[0][u-1].push_back(c);
        adj[1][v-1].push_back(u-1);
        cost[1][v-1].push_back(c);
    }

    AStar astar(n, adj, cost, xy);

    int t;
    cin >> t;
    for (int i=0; i<t; ++i) {
        int u, v;
	cin >> u >> v;
	cout << astar.query(u - 1, v - 1) << endl;
    }
}


