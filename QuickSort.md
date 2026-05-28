# Homework2
41043209 陳冠宏
2026/05/28

---
## Quick Sort 程式碼  
Quick Sort 使用 median-of-three（三數中位數法）選擇 pivot。此方法會從資料中的 left、middle、right 三個位置取出元素，並選擇三者中的中間值作為 pivot。相較於固定選擇第一個或最後一個元素作為 pivot，median-of-three 可以降低因資料排列特殊而造成分割不均的情況。
```cpp
#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;
void insertionSort(vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int medianOfThree(vector<int>& arr, int left, int right) {
    int mid = (left + right) / 2;
    if (arr[left] > arr[mid]) {
        swap(arr[left], arr[mid]);
    }
    if (arr[left] > arr[right]) {
        swap(arr[left], arr[right]);
    }
    if (arr[mid] > arr[right]) {
        swap(arr[mid], arr[right]);
    }
    swap(arr[mid], arr[right - 1]);
    return arr[right - 1];
}
void quickSort(vector<int>& arr, int left, int right) {
    const int CUTOFF = 10;
    if (left + CUTOFF <= right) {
        int pivot = medianOfThree(arr, left, right);
        int i = left;
        int j = right - 1;
        while (true) {
            while (arr[++i] < pivot) {}
            while (arr[--j] > pivot) {}
            if (i < j) {
                swap(arr[i], arr[j]);
            } else {
                break;
            }
        }
        swap(arr[i], arr[right - 1]);
        quickSort(arr, left, i - 1);
        quickSort(arr, i + 1, right);
    } else {
        insertionSort(arr, left, right);
    }
}
void quickSort(vector<int>& arr) {
    if (!arr.empty()) {
        quickSort(arr, 0, arr.size() - 1);
    }
}
vector<int> generateQuickWorstCase(int n) {
    vector<int> arr;
    for (int i = 1; i <= n; i++) {
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
    cout << "Quick Sort Worst-case Runtime" << endl;
    cout << "Repeat: " << repeat << " times" << endl;
    cout << endl;
    cout << "n\tTime(ms)" << endl;
    for (int n : sizes) {
        auto start = high_resolution_clock::now();
        for (int r = 0; r < repeat; r++) {
            vector<int> data = generateQuickWorstCase(n);
            quickSort(data);
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
---
```
## 執行結果
<img width="231" height="177" alt="QuickSortOutput" src="https://github.com/user-attachments/assets/663d98c2-649f-439a-95c6-2d1f10622ead" />

```
