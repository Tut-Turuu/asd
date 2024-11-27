#include <hash_fun.h>
#include <iostream>
#include <functional>

size_t hash(const char * s) {
    size_t res = 0;
    size_t tmp = 0;
    int i = 0;
    while (s[i] != '\0') {
        for (int j = 0; j < 3; ++j) {
            tmp += s[i];
            tmp = tmp << 8;
        }
        tmp += s[i];
        // for (int j = 0; j < 8; ++j) {
        //     res += tmp;
        //     tmp = tmp << 1;
        // }
        res += tmp;
        tmp = 0;
        ++i;
    }
    res += 234;
    res *= 23453062436265764;
    return res;
}


int main() {
    

    char s[100];
    while (1) {
        std::cin.getline(s, 100);
        std::cout << hash(s) << '\n';
    }

    
    
}