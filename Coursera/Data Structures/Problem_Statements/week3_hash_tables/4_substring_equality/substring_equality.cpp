#include <iostream>
#include <vector>
using namespace std;

static const long long int prime_0 = 1000000007;
static const long long int prime_1 = 1000000009;
static const long long int multiplier = 253;
class Solver {
private:
	string s;
        vector<vector<long long int>> hash_value;
	long long int prime[2];
	vector<vector<long long int>> x;
public:
	Solver(string s) : s(s), hash_value(2, vector<long long int> (s.size() + 1, 0)), x(2,vector<long long int> (s.size() + 1, 1)) {
		prime[0] = prime_0;
		prime[1] = prime_1;
		for (long long int j = 1; j < s.size() + 1; j++) {
			for (int i = 0; i < 2; i++){
				hash_value[i][j] = (multiplier * hash_value[i][j - 1] + s[j - 1]) % prime[i];
				x[i][j] = (multiplier * x[i][j - 1]) % prime[i];
			}
		}
	}
	bool ask(int a, int b, int l) {
		long long int y[2];
		y[0] = 1;
		y[1] = 1;
		long long int hash[2][2];
		int temp = a;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				hash[i][j] = (hash_value[j][temp + l] - x[j][l] * hash_value[j][temp] % prime[j]) % prime[j];
				if (hash[i][j] < 0) {
					hash[i][j] = (hash[i][j] + prime[j]) % prime[j];
				}
			}
			temp = b;
		}
		return (hash[0][0] == hash[1][0] && hash[0][1] == hash[1][1]);
	}
};

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);

	string s;
	int q;
	cin >> s >> q;
	Solver solver(s);
	for (int i = 0; i < q; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		cout << (solver.ask(a, b, l) ? "Yes\n" : "No\n");
	}
}
