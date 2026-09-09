#include <iostream>

struct fenwick {
    int* tree;
    size_t tree_size;

    fenwick(size_t new_size = 0) {
        tree_size = new_size + 1;
        tree = new int[tree_size];

        for (int i = 0; i < tree_size; ++i) {
            tree[i] = 0;
        }
    }

    void add(int pos, int val) {
        for (pos; pos < tree_size; pos += pos & -pos) {
            tree[pos] += val;
        }
    }

    int get(int pos) {
        int ans = 0;
        for (pos; pos > 0; pos -= pos & -pos) {
            ans += tree[pos];
        }

        return ans;
    }
};

int main() {

    fenwick a(5);
    for (int i = 0; i < 5; ++i) {
        a.add(i + 1, i + 1);
    }

    for (int i = 0; i < 5; ++i) {
        std::cout << a.get(i + 1) << '\n';
    }

    return 0;
}