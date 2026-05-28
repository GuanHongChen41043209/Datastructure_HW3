由圖中可以觀察到，當資料筆數 (n) 增加時，各排序方法的執行時間皆有不同程度的上升。

其中 Insertion Sort 的成長幅度最明顯，尤其在 (n = 3000) 之後執行時間快速增加，顯示其在 worst-case 情況下具有明顯的 (O(n^2)) 成長趨勢。

Quick Sort 在最壞情況下可能退化為 (O(n^2))，因此實際表現仍會受到 pivot 選擇方式與輸入資料排列影響。本實驗中 Quick Sort 使用 median-of-three 方法選擇 pivot，因此有效降低了分割不平均的情況

Iterative Merge Sort 與 Recursive Merge Sort 的時間成長趨勢相對穩定，整體符合 (O(n \log n)) 的特性。從圖中可看出，Recursive Merge Sort 的執行時間大多高於 Iterative Merge Sort，可能是因為遞迴呼叫會產生額外的函式呼叫成本，因此在相同資料量下，遞迴版本的花費時間較多。

Heap Sort 的執行時間也相對較低，且隨著資料筆數增加呈現緩慢上升的趨勢，符合 (O(n \log n)) 的時間複雜度。由於 Heap Sort 的 worst-case data 較難直接產生，因此本實驗使用多組 random permutation 進行測試，並取其中最大的執行時間作為近似 worst-case time。
<img width="4194" height="2465" alt="Compare" src="https://github.com/user-attachments/assets/c1dd0225-fd6b-408f-b8d4-aad7174908b4" />
