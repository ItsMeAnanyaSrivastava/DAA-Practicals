#include <iostream>
using namespace std;
void insertionSort(int arr[]){
    int j=0;
    int key;
    for(int i=1;i<5;i++){
        j=i-1;
        key=arr[i];
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}
int main() {
    cout<<"This is insertion Sort"<<endl;
    int myarr[5];
    cout<<"Enter 5 elements in the array"<<endl;
    for(int i=0;i<5;i++){
        cin>>myarr[i];
    }
    insertionSort(myarr);
    for(int i=0;i<5;i++){
        cout<<myarr[i]<<" ";
    }
    return 0;
}