#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
vector<int> generateInsertionWorstCase(int n) {
    vector<int> arr;
    for (int i = n; i >= 1; i--) {
        arr.push_back(i);
    }
    return arr;
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
    int repeat = 1000;
    cout << "Insertion Sort Worst-case Runtime" << endl;
    cout << "n\tTime(ms)" << endl;
    for (int n : sizes) {
        auto start = high_resolution_clock::now();
        for (int r = 0; r < repeat; r++) {
            vector<int> data = generateInsertionWorstCase(n);
            insertionSort(data);
            if (!isSorted(data)) {
                cout << "Sorting error!" << endl;
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