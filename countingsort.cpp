// Counting Sort
#include <iostream>
using namespace std;
void countingSort(int input_array[],int s,int r){
    int output_array[s];
    int count_array[r];
    for (int i=0;i<r;i++){
        count_array[i]=0;
    }
    for (int i=0;i<s;i++){
        ++count_array[input_array[i]];
    }
    for (int i=1;i<r;i++){
        count_array[i]=count_array[i]+count_array[i-1];
    }
    for (int i=0;i<s;i++){
        output_array[--count_array[input_array[i]]]=input_array[i];
    }
    for (int i=0;i<s;i++){
        input_array[i]=output_array[i];
    }
}
int main() {
    int size;
    int range=10;
    cout<<"Enter the size : ";
    cin>>size;
    int myarr[size];
    cout<<"Enter elements ";
    for (int i=0;i<size;i++){
        cin>>myarr[i];
    }
    countingSort(myarr,size,10);
    for (int i=0;i<size;i++){
        cout<<myarr[i];
    }
    return 0;
}