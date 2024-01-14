#include <bits/stdc++.h>

std::string print(int x) {
    std::stack<bool> stk;
    std::string res;
    for (int i = 0; i <= 31; i++)
        stk.push(x >> i & 1);
    while (!stk.empty()) {
        res.push_back(stk.top() + '0');
        stk.pop();
    }
    return res;
}

int main() {
    int mul = 1;
    for (int n = 1; n <= 100; n++) {
        mul *= n;
        printf("*%3d, mul = %11d, bin = %s\n", n, mul, print(mul).c_str());
    }
    return 0;
}