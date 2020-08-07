#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;

static const long long int prime = 1000000007;
static const long long int multiplier = 263;

class RabinKarp {
 private:
   string pattern;
   string text;
   size_t hash_pattern;
   vector<size_t> occurences;
   vector<long long int> hash_text;

   size_t hash_function (string &s, long long int begin, long long int length) {
     size_t hash = 0;
     for (long long int i = begin + length - 1; i >= begin ; i--) {
       hash = (hash * multiplier + s[i]) % prime;
     }
     return hash;
   }

   void calculate_hashes() {
     hash_pattern = hash_function(pattern, 0, pattern.size());
     long long int y {1};
     for (long long int i = 0; i < pattern.size(); i++)
       y = (y * multiplier) % prime;
     hash_text.resize(text.size() - pattern.size() + 1);
     hash_text[text.size() - pattern.size()] = hash_function(text, text.size() - pattern.size(), pattern.size());
     for (long long int i = text.size() - pattern.size() - 1; i >= 0; i--) {
       hash_text[i] = (multiplier * hash_text[i + 1] + text[i] - y * text[i + pattern.size()]) % prime;
       if (hash_text[i] < 0)
         hash_text[i] = (hash_text[i] + prime) % prime;
     }
   }

 public:
   RabinKarp() : occurences{} {}

   void ReadData() {
     std::cin >> pattern >> text;
   }

   void get_occurences() {
     calculate_hashes();
     if (text.size() >= pattern.size()) {
       for (size_t i = 0; i < hash_text.size(); i++) {
         if (hash_text[i] != hash_pattern)
           continue;
         else {
           if (text.substr(i, pattern.size()) == pattern)
             occurences.push_back(i);
         }
       }
     }
   }
   void print_occurences() {
     for (auto i : occurences)
       std::cout << i << " ";
   std::cout << "\n";
   }

   void search() {
     ReadData();
     get_occurences();
     print_occurences();
   }
};


int main() {
    std::ios_base::sync_with_stdio(false);
    RabinKarp hash;
    hash.search();
    return 0;
}
