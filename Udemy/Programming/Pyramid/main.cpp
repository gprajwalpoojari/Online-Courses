#include <iostream>
#include <string>

using namespace std;
 
 int main() {
     cout << "Enter a string of your choice : ";
     string user_entry {};
     cin >> user_entry;
     cout << endl << endl;
     
     size_t len = user_entry.length();
     for ( unsigned row = 0; row < len; row++) {
         for (unsigned space = 0; space < len - row - 1; space++) { //for entering spaces in each line
             cout << " ";
         }
         for (unsigned index = 0;index < row + 1; index++) {//printing characters from index 0 to len - 1
             cout << user_entry.at(index);
             if (index == row) { //printing characters from len - 1 to 0
                 for (int reverse_index = index - 1; reverse_index >= 0; reverse_index--) {
                     cout << user_entry.at(reverse_index);
                 }
             }
         }
         cout << endl;
     }
     return 0;
 }