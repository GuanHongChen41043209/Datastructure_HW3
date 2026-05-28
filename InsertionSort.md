# Homework2
41043209 陳冠宏
2026/05/28

---
## Insertion Sort 程式碼  
在 Insertion Sort 中，最壞情況會發生在輸入資料為完全反向排序時。因為每次插入新的元素時，該元素都必須與前方所有已排序的元素進行比較
```cpp
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
---
```
## 執行結果
<img width="266" height="161" alt="InsertionSortOutput" src="https://github.com/user-attachments/assets/ff74c2f0-28f8-4c8a-abff-cd184050b9fc" />

```
