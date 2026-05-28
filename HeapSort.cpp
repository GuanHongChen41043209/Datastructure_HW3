#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>
using namespace std;
using namespace chrono;
template <class T>
void Permute(vector<T>& a, int n) {
    for (int i = n; i >= 2; i--) {
        int j = rand() % i + 1;
        swap(a[j], a[i]);
    }
}
vector<int> generateRandomPermutation(int n) {
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = i;
    }
    Permute(a, n);
    return a;
}
void heapify(vector<int>& a, int n, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left <= n && a[left] > a[largest]) {
        largest = left;
    }
    if (right <= n && a[right] > a[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}
void heapSort(vector<int>& a, int n) {
    for (int i = n / 2; i >= 1; i--) {
        heapify(a, n, i);
    }
    for (int i = n; i >= 2; i--) {
        swap(a[1], a[i]);
        heapify(a, i - 1, 1);
    }
}
bool isSorted(const vector<int>& a, int n) {
    for (int i = 2; i <= n; i++) {
        if (a[i - 1] > a[i]) {
            return false;
        }
    }
    return true;
}
int main() {
    srand(time(NULL));
    vector<int> sizes = {500, 1000, 2000, 3000, 4000, 5000};
    int permutationCount = 100;
    cout << "Heap Sort Worst-case Runtime" << endl;
    cout << endl;
    cout << "n\tMax Time(ms)" << endl;
    for (int n : sizes) {
        double maxTime = 0.0;
        for (int p = 0; p < permutationCount; p++) {
            vector<int> data = generateRandomPermutation(n);
            auto start = high_resolution_clock::now();
            heapSort(data, n);
            auto end = high_resolution_clock::now();
            if (!isSorted(data, n)) {
                cout << "Sorting error!" << endl;
                return 1;
            }
            duration<double, milli> elapsed = end - start;
            double time = elapsed.count();
            if (time > maxTime) {
                maxTime = time;
            }
        }
        cout << n << "\t" << maxTime << endl;
    }
    return 0;
}