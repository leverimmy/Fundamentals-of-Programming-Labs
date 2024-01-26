## 上机实验四

### 代码实现

```cpp
#include <iostream>

bool isLeapYear(int y) {

    if (y % 4 == 0) {
        if (y % 100 == 0) {
            if (y % 400 == 0) {
                return true;
            } else {
                return false;
            }
        } else {
            return true;
        }
    } else {
        return false;
    }
}

int main() {

    int year;
    std::cin >> year;
    std::cout << (isLeapYear(year) ? "Yes" : "No");

    return 0;
}
```

### 测试数据与截图

#### 测试数据 1：2023

![2023-1](./2023-1.png)

![2023-2](./2023-2.png)

#### 测试数据 2：2024

![2024-1](./2024-1.png)

![2024-2](./2024-2.png)

![2024-3](./2024-3.png)

#### 测试数据 3：2000

![2000-1](./2000-1.png)

![2000-2](./2000-2.png)

![2000-3](./2000-3.png)

![2000-4](./2000-4.png)

#### 测试数据 4：1900

![1900-1](./1900-1.png)

![1900-2](./1900-2.png)

![1900-3](./1900-3.png)

![1900-4](./1900-4.png)

### 选做任务：实现更多的闰年判断方法

将原始代码中的 `isLeapYear()` 的实现替换如下：

#### 方法 1

```cpp
bool isLeapYear() {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return true;
    else
        return false;
}
```

#### 方法 2

```cpp
bool isLeapYear() {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
```
