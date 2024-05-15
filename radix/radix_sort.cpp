#include <iostream>
#include <vector>
#include <algorithm>

int findMax(std::vector<int>& arr) {
    int maxVal = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

void radixSortLSD(std::vector<int>& arr) {
    int maxVal = findMax(arr);
    
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        int n = arr.size();
        std::vector<int> output(n);
        std::vector<int> count(10, 0);
        
        for (int i = 0; i < n; i++) {     //0, 
            count[(arr[i] / exp) % 10]++; //170, 45, 75, 90, 802, 24, 2, 66
        }
        for (int num : count) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
        
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        for (int num : count) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
        
        for (int i = n - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }
        
        for (int i = 0; i < n; i++) {
            arr[i] = output[i];
        }
    }
}

void radixSortMSD(std::vector<int>& arr, int exp, int low, int high) {
    if (low >= high || exp <= 0) {
        return;
    }
    
    std::vector<std::vector<int>> buckets(10);
    
    for (int i = low; i <= high; i++) {
        int digit = (arr[i] / exp) % 10;
        buckets[digit].push_back(arr[i]);
    }
    
    for (int i = 0; i < 10; i++) {
        radixSortMSD(buckets[i], exp / 10, 0, buckets[i].size() - 1);
    }
    
    int index = low;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

void radixSortMSD(std::vector<int>& arr) {
    int maxVal = findMax(arr);
    radixSortMSD(arr, maxVal, 0, arr.size() - 1);
}

int main(){
    std::vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    std::cout << "Original Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    //radixSortLSD(arr);
    radixSortMSD(arr);

    std::cout << "Sorted Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

}