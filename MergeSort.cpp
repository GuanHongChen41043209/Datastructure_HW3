#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;
vector<int> generateMergeWorstCase(vector<int> arr) {
    int n = arr.size();
    if (n <= 1) {
        return arr;
    }
    vector<int> left;
    vector<int> right;
    for (int i = 0; i < n; i += 2) {
        left.push_back(arr[i]);
    }
    for (int i = 1; i < n; i += 2) {
        right.push_back(arr[i]);
    }
    left = generateMergeWorstCase(left);
    right = generateMergeWorstCase(right);
    vector<int> result;
    for (int x : left) {
        result.push_back(x);
    }
    for (int x : right) {
        result.push_back(x);
    }
    return result;
}
vector<int> createMergeWorstCase(int n) {
    vector<int> sorted;
    for (int i = 1; i <= n; i++) {
        sorted.push_back(i);
    }
    return generateMergeWorstCase(sorted);
}
void merge(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= right) {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for (int p = left; p <= right; p++) {
        arr[p] = temp[p];
    }
}
void iterativeMergeSort(vector<int>& arr) {
    int n = arr.size();
    vector<int> temp(n);
    for (int size = 1; size < n; size *= 2) {
        for (int left = 0; left < n - size; left += 2 * size) {
            int mid = left + size - 1;
            int right = min(left + 2 * size - 1, n - 1);

            merge(arr, temp, left, mid, right);
        }
    }
}
void recursiveMergeSort(vector<int>& arr, vector<int>& temp, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = (left + right) / 2;
    recursiveMergeSort(arr, temp, left, mid);
    recursiveMergeSort(arr, temp, mid + 1, right);
    merge(arr, temp, left, mid, right);
}
void recursiveMergeSort(vector<int>& arr) {
    int n = arr.size();
    vector<int> temp(n);
    recursiveMergeSort(arr, temp, 0, n - 1);
}
bool isSorted(const vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i - 1] > arr[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<int> sizes = {500, 1000, 2000, 3000, 4000, 5000};
    int repeat = 100;
    cout << "Merge Sort Worst-case Runtime" << endl;
    cout << endl;
    cout << "Iterative Merge Sort" << endl;
    cout << "n\tTime(ms)" << endl;
    for (int n : sizes) {
        auto start = high_resolution_clock::now();
        for (int r = 0; r < repeat; r++) {
            vector<int> data = createMergeWorstCase(n);
            iterativeMergeSort(data);
            if (!isSorted(data)) {
                cout << "Iterative Merge Sort error!" << endl;
                return 1;
            }
        }
        auto end = high_resolution_clock::now();
        duration<double, milli> totalTime = end - start;
        double averageTime = totalTime.count() / repeat;
        cout << n << "\t" << averageTime << endl;
    }
    cout << endl;
    cout << "Recursive Merge Sort" << endl;
    cout << "n\tTime(ms)" << endl;
    for (int n : sizes) {
        auto start = high_resolution_clock::now();
        for (int r = 0; r < repeat; r++) {
            vector<int> data = createMergeWorstCase(n);
            recursiveMergeSort(data);
            if (!isSorted(data)) {
                cout << "Recursive Merge Sort error!" << endl;
                return 1;
            }
        }
        auto end = high_resolution_clock::now();
        duration<double, milli> totalTime = end - start;
        double averageTime = totalTime.count() / repeat;
        cout << n << "\t" << averageTime << endl;
    }
    return 0;
}