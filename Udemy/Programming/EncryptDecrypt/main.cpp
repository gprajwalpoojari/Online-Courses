 #include <iostream>
#include <string>

using namespace std; 
 int main() {
      string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
      string key {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};
      cout << "Enter your secret message : ";
      string message {}, encrypt {}, decrypt {};
      getline(cin, message);
      
      cout << "\n\nEncrypting message.........." <<endl << endl;
      for (char c : message) {
          size_t index {alphabet.find(c)}; 
          if (index != string::npos) {
              encrypt += key.at(index);
          }
          else {
              encrypt += c;
          }
      }
      cout << encrypt << endl << endl;
      
      cout << "Decrypting message.............." << endl << endl;
      for (char c : encrypt) {
          size_t index {key.find(c)}; 
          if (index != string::npos) {
              decrypt += alphabet.at(index);
          }
          else {
              decrypt += c;
          }
      }
      cout << decrypt << endl << endl;
     return 0;
 }