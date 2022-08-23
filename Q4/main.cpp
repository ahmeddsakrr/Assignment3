#include <iostream>
#include <vector>
using namespace std;

template<typename T>
int partition(vector<T> arr,int l,int h){
    int p=arr[l];
    int i=l;
    int j=h;
    while(i<j){
        do {
            i++;
        } while (arr[i]<=p);
        do {
            j--;
        } while (arr[j] > p);
        if (i<j)
            swap(arr[i],arr[j]);
    }
    swap(arr[l],arr[j]);
    return j;
}

template<typename T>
void quickSort(vector<T> arr,int l,int h){
    if (l<h){
        int pivot= partition(arr,l,h);
        quickSort(arr,l,pivot);
        quickSort(arr,pivot+1,h);
    }
}
