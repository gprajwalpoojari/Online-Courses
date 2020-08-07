 #include <iostream>
 
 using namespace std;
 
 int main() { 
     cout << "Enter the amount in cents :";
     int value {};
     cin >> value;
     
     int dollar {}, quarter {}, dime {}, nickel {}, penny {};
     dollar = value / 100;
     value %= 100;
     
     quarter = value / 25;
     value %= 25;
     
     dime = value / 10;
     value %= 10;
     
     nickel = value / 5;
     value %= 5;
     
     penny = value;
     
     cout << "\n\n\nYou can provide the change as follows:" << endl;
     cout << "dollars : " << dollar << endl;
     cout <<  "quarters : " << quarter << endl;
     cout << "dimes : " << dime << endl;
     cout << "nickels : " << nickel<< endl;
     cout << "pennies : " << penny << endl;
     return 0;
 }