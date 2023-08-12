using namespace std;
#include <iostream>
#include <unordered_map>
#include <array>
#include <math.h>
#include <numeric>
#include <functional>

// 自定义哈希函数，将 array 映射为哈希值
struct ArrayHash {
    size_t operator()(const array<int, 4>& arr) const {
        return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) {
            return (acc << 1) ^ num;
        });
    }
};

int main() {
    // 使用自定义哈希函数创建哈希表
    unordered_map<array<int, 4>, string, ArrayHash> customHashMap;

    // 添加键值对到哈希表
    array<int, 4> key1 = {4, 2, 3, 4};
    array<int, 4> key2 = {1, 8, 3, 4};
    customHashMap[key1] = "Value 1";
    customHashMap[key1] = "Value 3";

    // 查询并输出哈希表中的值
    cout << "Value at key 1: " << customHashMap[key1] << endl;
    cout << "Value at key 2: " << customHashMap[key2] << endl;
    system("pause");
}




