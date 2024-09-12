#include <iostream>




void f(int x) {
    for (int i = 1; i <= x; ++i) {
        int j = i;
        while (j % 3 == 0) {
            j /= 3;
        }
        while (j % 5 == 0) {
            j /= 5;
        }        
        while (j % 7 == 0) {
            j /= 7;
        }
        if (j == 1) std::cout << i << ' ';
    }
    std::cout << '\n';
}


int main() {
    f(19000);
}