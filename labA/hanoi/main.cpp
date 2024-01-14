#include <iostream>
using namespace std;
int step = 1;

void move(int, char, char, char);

int main() {
    int n;
    cout << "盘数 n = ";
    cin >> n;
    cout << "在 3 根柱子上移 " << n << " 只盘的步骤为：" << endl;
    move(n, 'A', 'B', 'C');
    return 0;
}

void move(int n, char A, char B, char C) {
    if (n == 1) {
        cout << "[" << step << "] move 1# from " << A << " to " << C << endl;
        step++;
    } else {
        move(n - 1, A, C, B);
        cout << "[" << step << "] move " << n << "# from " << A << " to " << C << endl;
        step++;
        move(n - 1, B, A, C);
    }
}
