#include <iostream>
#include <vector>

//g++ buble.cpp -o buble --std=c++14

using namespace std;

template<typename T>
void buble(std::vector<T>& arr){
for(int i = 0; i < arr.size() - 1; i++){
   for(int j = 0; j < arr.size() - 1 - i;j++){
       if(arr[j] > arr[j + 1]){
           std::swap(arr[j], arr[j+1]);
           }   
        }
    }
}

template<typename T>
void print(const vector<T> arr){
    for(auto g : arr){
        cout << g << " , ";
    }cout << endl;
}

int main(){
    vector<int> vec{12,1,34,55,1};
    print(vec);
    buble(vec);
    print(vec);
}