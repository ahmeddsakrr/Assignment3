#include <iostream>
#include <vector>
#include "List.h"
#include <cmath>
using namespace std;

template<typename T>
void radixSort(vector<T> &arr){
    int m,p;
    int index=0;
    int temp=0;
    int count=0;
    int max=INT16_MAX;
    for(auto elem:arr)
        if (elem>max)
            max=elem;
    vector<List> list(10);
    for (int i = 0; i < max; ++i) {
        m= pow(10,i+1);
        p=pow(10,i);
        for (int j = 0; j < arr.size(); ++j) {
            temp=arr[j]%m;
            index=temp/p;
            list[index].push_back(arr[j]); // this function was added to List class
        }
        count=0;
        for (int j = 0; j < 10; ++j) {
            while (!list[j].empty()){
                arr[count++]=list[j].get(0); // this function was added to list class
                list[j].erase(0);

            }
        }
    }

}

int main(){
    vector<int> vector{1098,978,48,7,56,5,4333,3483,2,1};
    for (int i : vector) {
        cout<<i<<" ";
    }
    cout<<endl;
    radixSort(vector);
    for (int i : vector) {
        cout<<i<<" ";
    }
    return 0;

}