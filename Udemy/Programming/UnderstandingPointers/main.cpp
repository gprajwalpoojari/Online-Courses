 #include <iostream>
 
 using namespace std;
 
 int *apply_all(const int *array1, int size1, const int *array2, int size2);
 void print(const int *const array, int size);
 int main() {
     int array1 [] {1, 2, 3, 4, 5};
     int array2 [] {10, 20, 30};
     
     cout << "Array 1 : ";
     print(array1, 5);
     
     cout << "Array 2 : ";
     print(array2, 3);
     
     int *results = apply_all(array1, 5, array2, 3);
     cout << "Result : ";
     print(results,15);
     
     delete [] results;
     return 0;
 }
 
 int *apply_all(const int *const array1, int size1, const int *const array2, int size2) {
     int size = size1 * size2;
     int k {0};
     int *result = new int[size];
     for (int i = 0; i < size2; i++) {
         for (int j = 0; j < size1; j++) {
              *(result + k)= array2[i] * array1[j];
              k++;
         }
     }
     return result;
 } 
 void print(const int *const array, int size) {
     cout << "[ ";
     for (int i = 0; i < size; i++) {
         cout << array[i] << " ";
     }
     cout << "]" <<endl;
 }
 