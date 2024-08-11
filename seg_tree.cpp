#include <iostream>
#include <vector>
#include <set>
using namespace std;

class SegmentTree {
private:
    vector<set<char>> tree;
    string data;
    int n;

    void build(int node, int start, int end) {
        if (start == end) {
            // 叶子节点，只包含一个字符
            tree[node].insert(data[start]);
        } else {
            int mid = (start + end) / 2;
            int left_child = 2 * node + 1;
            int right_child = 2 * node + 2;
            build(left_child, start, mid);
            build(right_child, mid + 1, end);
            tree[node].insert(tree[left_child].begin(), tree[left_child].end());
            tree[node].insert(tree[right_child].begin(), tree[right_child].end());
        }
    }

    set<char> query(int node, int start, int end, int L, int R) {
        if (R < start || end < L) {
            // 查询区间和当前节点区间不重叠
            return {};
        }
        if (L <= start && end <= R) {
            // 当前节点区间完全在查询区间内
            return tree[node];
        }
        int mid = (start + end) / 2;
        set<char> left_result = query(2 * node + 1, start, mid, L, R);
        set<char> right_result = query(2 * node + 2, mid + 1, end, L, R);
        left_result.insert(right_result.begin(), right_result.end());
        return left_result;
    }

public:
    SegmentTree(const string& s) : data(s) {
        n = s.length();
        tree.resize(4 * n);
        build(0, 0, n - 1);
    }

    int query(int L, int R) {
        set<char> result = query(0, 0, n - 1, L, R);
        return result.size();
    }
};

int main() {
    string input = "hello, world!";
    SegmentTree st(input);
    cout << "Number of unique characters in 'hello, world!': " << st.query(0, input.size() - 1) << endl;
    cout << "Number of unique characters in 'world': " << st.query(7, 11) << endl;
	system("pause");
    return 0;
}
