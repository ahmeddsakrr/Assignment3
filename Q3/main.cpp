#include <iostream>
#include <vector>
using namespace std;

template<typename T>
void insertionSort(vector<T> &arr){
    for (int i = 1; i <arr.size() ; ++i) {
        int key=arr[i];
        int j=i-1;
        while(j>-1 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
