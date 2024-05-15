#include <iostream>
#include <vector>

using namespace std;

//g++ select.cpp -o select --std=c++14

template<typename T>
void selection_s(vector<T>& arr){
    for(int i=0;i<arr.size()-1;i++){
        int min = i;
        for(int j = i+1;j<arr.size();j++){
            if(arr[min] > arr[j]){
                min = j;
            }
        }
        swap(arr[i],arr[min]);
    }
}

template<typename T>
void print(const vector<T> arr){
    for(auto g : arr){
        cout << g << " , ";
    }cout << endl;
}

int main(){
    vector<int> vec{12,1,14,35,9};
    print(vec);
    selection_s(vec);
    print(vec);
}