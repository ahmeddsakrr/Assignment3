#include <iostream>
#include <vector>
using namespace std;

template<typename T>
void merge(vector<T> &arr,int start,int m,int end){
    int i,j,k;
    int n1=m-start+1; // first subarray
    int n2=end-m; // second subarray
    vector<T> left(n1);
    vector<T> right(n2);
    for (i = 0; i < n1; ++i) {
        left[i]=arr[start+i];
    }
    for(j=0;j<n2;j++){
        right[j]=arr[m+1+j];
    }
    i=j=0;
    k=start;
    while (i<n1 && j<n2){
        if (left[i] <= right[j])
            arr[k]=left[i++];
        else
            arr[k]=right[j++];
        k++;
    }
    while(i<n1)
        arr[k++]=left[i++];
    while (j<n2)
        arr[k++]=right[j++];

}

template<typename T>
void mergeSort(vector<T> arr, int start,int end){
    if (start<end){
        int m=start+(end-1)/2;
        mergeSort(arr,start,m);
        mergeSort(arr,m+1,end);
        merge(arr,start,m,end);
    }
}
