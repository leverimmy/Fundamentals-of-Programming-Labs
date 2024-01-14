#include <bits/stdc++.h>

const int N = 5;

int a[N][N], b[N][N], dir;
char opt[1];

int random(int l, int r) { // 随机出 [l, r] 中的一个整数
    return rand() * rand() % (r - l + 1) + l;
}

void print() { // 输出整个 4*4 矩阵的函数
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++)
            printf("%3d ", a[i][j]);
        puts("");
    }
}

int main() {
    srand(time(0));
    for (int i = 1; i < 4; i++)
        for (int j = 1; j <= 4; j++)
            a[i][j] = random(0, 20);
    print();

    while (scanf("%s %d", opt, &dir) != EOF) {
        if (opt[0] == 'C') { // C 表示 Compress
            switch (dir) {
                case 0: // 向上
                    for (int j = 1; j <= 4; j++) { // 枚举列
                        int sum = 0;
                        for (int i = 1; i <= 4; i++) { // 枚举行，求和
                            sum += a[i][j];
                            a[i][j] = 0; // 其余单元改为 0
                        }
                        a[1][j] = sum;
                    }
                    break;
                case 1: // 向左
                    for (int i = 1; i <= 4; i++) { // 枚举行
                        int sum = 0;
                        for (int j = 1; j <= 4; j++) { // 枚举列，求和
                            sum += a[i][j];
                            a[i][j] = 0; // 其余单元改为 0
                        }
                        a[i][1] = sum;
                    }
                    break;
                case 2: // 向下
                    for (int j = 1; j <= 4; j++) { // 枚举列
                        int sum = 0;
                        for (int i = 1; i <= 4; i++) { // 枚举行，求和
                            sum += a[i][j];
                            a[i][j] = 0; // 其余单元改为 0
                        }
                        a[4][j] = sum;
                    }
                    break;
                case 3: // 向右
                    for (int i = 1; i <= 4; i++) { // 枚举行
                        int sum = 0;
                        for (int j = 1; j <= 4; j++) { // 枚举列，求和
                            sum += a[i][j];
                            a[i][j] = 0; // 其余单元改为 0
                        }
                        a[i][4] = sum;
                    }
                    break;
                default:
                    continue;
            }
        } else if (opt[0] == 'R') { // R 表示 Rotate
            for (int i = 1; i <= 4; i++)
                for (int j = 1; j <= 4; j++)
                    b[i][j] = a[5 - j][i]; // 向右旋转 90 度，复制到 b 数组中
            for (int i = 1; i <= 4; i++)
                for (int j = 1; j <= 4; j++)
                    a[i][j] = b[i][j]; // 再重新移动回 a 数组
        } else {
            continue;
        }
        print();
    }

    return 0;
}