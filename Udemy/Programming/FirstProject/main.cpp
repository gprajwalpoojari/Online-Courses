 #include <iostream>
 
 using namespace std;
 
 int main() {
     const double small_room_price {25};
     const double large_room_price {35};
     const int expiry {30};
     const double tax_value {0.06};
     
     cout << "Hello, Welcome to Frank's carpet cleaning service"<<endl;
     cout << "How many small rooms would you like cleaned?";
     int small_rooms {0};
     cin >> small_rooms ;
     
     cout <<"How many large rooms would you like cleaned?";
     int large_rooms {0};
     cin >> large_rooms;
     cout << endl;
     double small_room_cost, large_room_cost, total_cost, tax, total_estimate;
     small_room_cost = small_room_price * small_rooms;
     large_room_cost = large_room_price * large_rooms;
     total_cost = small_room_cost + large_room_cost;
     tax = total_cost * tax_value;
     total_estimate = total_cost +tax;
     cout << "\nEstimate for carpet cleaning service" << endl;
     cout << "Number of small rooms : " << small_rooms << endl;
     cout << "Number of large rooms : " << large_rooms << endl;
     cout << "Price per small room : $" << small_room_price <<endl;
     cout << "Price per large room : $" << large_room_price <<endl;
     cout << "Cost : $" << total_cost << endl;
     cout << "Tax : $" << tax << endl;
     cout << "========================================"<< endl;
     cout << "Total Estimate : $" << total_estimate << endl;
     cout << "This estimate is valid for " << expiry << " days." << endl;
 }