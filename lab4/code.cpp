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