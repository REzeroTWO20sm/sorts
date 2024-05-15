#include <iostream>
#include <vector>

//g++ insert.cpp -o insert --std=c++14

using namespace std;

template<typename T>
void insert_s(vector<T>& arr){
    for(int i=1;i < arr.size();i++){
        int j = i-1;
        T buf = arr[i];
        while(j>=0 && arr[j] > buf){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = buf;
    }
}

template<typename T>
void print(const vector<T> arr){
    for(auto g : arr){
        cout << g << " , ";
    }cout << endl;
}

int main(){
    vector<int> vec{12,1,45,2,1,78};
    print(vec);
    insert_s(vec);
    print(vec);
}