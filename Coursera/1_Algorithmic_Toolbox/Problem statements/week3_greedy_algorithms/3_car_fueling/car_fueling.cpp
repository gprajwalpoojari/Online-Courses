#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    vector <int> path {0};
    for (int i = 0; i < stops.size(); i++){
        path.push_back(stops.at(i));
    }
    path.push_back(dist);
    int current_index {0};
    int next_index {0};
    int total_refills {0};
    while (current_index < path.size() - 1) {
        while (next_index < path.size() - 1){
            if (path.at(next_index + 1) - path.at(current_index) <= tank) {
                next_index++; 
            }
            else {
                break;
            }
        }
        if (next_index - current_index > 0) {
            current_index = next_index;
	    if (current_index != path.size() -1){
	        total_refills++;
            }
        }       
        else {
            return -1; 
        }
    }    
    return total_refills;;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
