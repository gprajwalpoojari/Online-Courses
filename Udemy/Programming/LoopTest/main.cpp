 #include <iostream>
#include<vector>

using namespace std;
 
 int main() {
     char selection;
     vector <int> vec {};
     do {
         cout << "P - Print numbers" << endl;
         cout << "A - Add a number" << endl;
         cout << "M - Display mean of the numbers" << endl;
         cout << "S - Display the smallest number" << endl;
         cout << "L - Display the largest number" << endl;
         cout << "Q - Quit" << endl;
         
         cout << "Enter your choice : " << endl;
         cin >> selection;
         
         if (selection == 'p' || selection == 'P') {
             if (vec.size() == 0) {
                 cout << "[] - this list is empty." << endl;
             }
             else {
                 cout << "[ ";
                 for (auto val : vec) {
                     cout << val << " "; 
                 }
                 cout << "]" << endl;
             }
         }
         else if (selection == 'a' || selection == 'A') {
             int data {};
             cout << "Enter the number you wish to add :";
             cin >> data;
             vec.push_back(data);
             cout << "\n" << data << " added." << endl;
         }
         else if (selection == 'm' || selection == 'M') {
             if (vec.size() == 0) {
                 cout << "Unable to calculate the mean - no data" << endl;
             }
             else {
                 double total {};
                 for (auto val : vec) {
                     total += val;
                 }
                 cout << "Mean : " << total / vec.size() << endl;
             }
         }
         else if (selection == 's' || selection == 'S') {
             if (vec.size() == 0) {
                 cout << "List empty" << endl;
             }
             else {
             int small {vec.at(0)};
             for (auto val : vec) {
                 if (val < small) {
                     small = val;
                 }
             }
             cout << "Smallest number : " << small << endl;
             }
         }
         else if (selection == 'l' || selection == 'L') {
             if (vec.size() == 0) {
                 cout << "List empty" << endl;
             }
             else {
             int large {vec.at(0)};
             for (auto val : vec) {
                 if (val > large) {
                     large = val ;
                 }
             }
             cout << "Largest number : " << large << endl;             
             }
         }
         else if (selection == 'q' || selection == 'Q') {
             break;
         }
         else {
             cout << "Unknown selection, please try again" << endl;
         }
     } while (1);
     cout << "Goodbye!" << endl;
     return 0;
 }