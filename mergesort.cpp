#include<iostream>
using namespace std;
void merge(int arr[], int l, int m, int r) {
    int i = l;
    int j = m + 1;  
    int k = l;
    int temp[5];  
    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i <= m) {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= r) {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for (int x = l; x <= r; x++) {
        arr[x] = temp[x];
    }
}
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m); // Corrected index
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int myarr[5];
    cout << "Enter 5 numbers: ";
    for (int i = 0; i < 5; i++) {
        cin >> myarr[i];
    }

    mergeSort(myarr, 0, 4); // Corrected index for 5 elements

    cout << "Sorted array: ";
    for (int i = 0; i < 5; i++) {
        cout << myarr[i] << " ";
    }
}