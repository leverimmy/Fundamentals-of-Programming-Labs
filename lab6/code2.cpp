#include <bits/stdc++.h>

const int N = 5;

int a[N][N], b[N][N], c[1 << N], dir, ratio;
char opt[1];

int random(int l, int r) { // 随机出 [l, r] 中的一个整数
    return rand() * rand() % (r - l + 1) + l;
}

int random2() { // 随机出一个 20 以内的 2 的自然数次幂
    return 1 << random(0, 4);
}

void print() { // 输出整个 4*4 矩阵的函数
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++)
            printf("%3d ", a[i][j]);
        puts("");
    }
}

void bubble() {
    for (int j = 1; j <= 4; j++) { // 枚举列
        for (int i = 3; i >= 1; i--) { // 枚举行
            for (int k = i; k <= 3; ++k) { // 从上到下，替换 0
                if (a[k + 1][j] == 0) // 如果下一位为 0
                    std::swap(a[k][j], a[k + 1][j]); // 交换，类似于“冒泡”操作
            }
        }
    }
}

void calc() {
    for (int j = 1; j <= 4; j++) {
        for (int i = 1; i <= 3; ) {
            if (a[i][j] == a[i + 1][j]) {
                a[i + 1][j] *= 2;
                a[i][j] = 0;
                i += 2;
            } else
                i++;
        }
    }
}

void modify() { // 随机往一个有数字 0 的位置，将内容修改为 2 或 4
    int cnt = 0;
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            cnt += a[i][j] == 0; // 先计算有多少个 0
    int rank = random(1, cnt); // 随机，修改第 rank 个 0
    cnt = 0;
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            cnt += a[i][j] == 0;
            if (cnt == rank) { // 如果当前是第 rank 个 0
                a[i][j] = random(0, 1) ? 2 : 4; // 修改为 2 或 4
                return;
            }
        }
    }
}

int main() {
    srand(time(0));
    scanf("%d", &ratio);

    for (int i = 1; i <= 16 * ratio / 100.0; i++) // 一部分为 2 的自然数次幂，其余为 0
        c[i] = random2();
    std::random_shuffle(c + 1, c + 17); // 打乱
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            a[i][j] = c[(i - 1) * 4 + j]; // 把长度为 16 的 c 数组整理成 4*4 的矩阵

    print();

    while (scanf("%s", opt) != EOF) {
        if (opt[0] == 'C') { // C 表示 Compress
            scanf("%d", &dir);
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
            scanf("%d", &dir);
            for (int i = 1; i <= 4; i++)
                for (int j = 1; j <= 4; j++)
                    b[i][j] = a[5 - j][i]; // 向右旋转 90 度，复制到 b 数组中
            for (int i = 1; i <= 4; i++)
                for (int j = 1; j <= 4; j++)
                    a[i][j] = b[i][j]; // 再重新移动回 a 数组
        } else if (opt[0] == 'M') { // M 表示 Melt
            bubble();
            calc();
            bubble();
            modify();
        } else if (opt[0] == 'Q') { // Q 表示 Quit
            break;
        }
        print();
    }
    return 0;
}
