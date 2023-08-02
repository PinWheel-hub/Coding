using namespace std;
#include <iostream>
#include <vector>
#include <pthread.h>

// 快速排序算法
void quickSort(vector<int>& arr, int low, int high);

// 多线程排序结构体
struct ThreadData {
    vector<int>* arr;
    int low;
    int high;
};

// 快速排序线程函数
void* threadQuickSort(void* arg) {
    ThreadData* data = static_cast<ThreadData*>(arg);
    quickSort(*data->arr, data->low, data->high);
    return nullptr;
}

// 快速排序算法
void quickSort(vector<int>& arr, int low, int high) {
    if (low >= high) return;

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]); // 原地交换
        }
    }

    swap(arr[i + 1], arr[high]);

    quickSort(arr, low, i);
    quickSort(arr, i + 2, high);
}

// 多线程排序函数
void concurrentSort(vector<int>& arr, int numThreads) {
    vector<pthread_t> threads(numThreads);
    vector<ThreadData> threadData(numThreads);

    int blockSize = arr.size() / numThreads;
    int remainder = arr.size() % numThreads;
    int start = 0;

    for (int i = 0; i < numThreads; i++) {
        int blockSizeWithRemainder = blockSize + (remainder > 0 ? 1 : 0);
        threadData[i] = {&arr, start, start + blockSizeWithRemainder - 1};
        start += blockSizeWithRemainder;
        remainder--;

        pthread_create(&threads[i], nullptr, threadQuickSort, &threadData[i]);
    }

    for (int i = 0; i < numThreads; i++) {
        pthread_join(threads[i], nullptr);
    }
}

int main() {
    vector<int> arr = {9, 4, 1, 7, 3, 8, 2, 5, 6};

    // 在多线程环境下并发排序，假设有4个线程
    int numThreads = 4;
    concurrentSort(arr, numThreads);

    // 输出排序后的数组
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    quickSort(arr, 0, arr.size() - 1);

    // 输出排序后的数组
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    system("pause");
}
