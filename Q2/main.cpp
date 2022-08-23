#include <iostream>
#include <vector>
using namespace std;

template<typename T>
void selectionSort(vector<T> &arr){
    int n=arr.size();
    for (int i = 0; i < n; ++i) {
        int mn=i;
        for (int j = i+1; j <n ; ++j) {
            if (arr[j] < arr[mn])
                mn=j;
        }
        swap(arr[mn] , arr[i]);
    }
}