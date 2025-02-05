#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <time.h>

using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    //size of each half
    int leftHalf = mid - left + 1;
    int rightHalf = right - mid;

    //temp arrays
    vector<int> leftArr(leftHalf);
    vector<int> rightArr(rightHalf);

    //fill temp arrays
    for (int i = 0; i < leftHalf; i++) {
        leftArr[i] = arr[left + i];
    }

    for (int j = 0; j < rightHalf; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    //merge temp arrays
    while(i < leftHalf && j < rightHalf) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    //leftover left half
    while (i < leftHalf) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    //leftover right half
    while (j < rightHalf) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    int size;
    vector<int> arr;

    cout << "Enter the size of your array: ";
    cin >> size;
    cout << "You inputted: " << size << endl;

    srand(time(0));

    for(int i = 0; i < size; i++) {
        arr.push_back(rand() % 100);
    }

    cout << "Initial Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;


    //start the clock
    clock_t start = clock();  

    mergeSort(arr, 0, size - 1);

    //end the clock
    clock_t end = clock();

    cout << "Sorted Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    cout << fixed << setprecision(8);

    double elapsedTime = double(end - start) / CLOCKS_PER_SEC;

    cout << "Time elapsed: " << elapsedTime << " seconds" << endl;

    return 0;
}

