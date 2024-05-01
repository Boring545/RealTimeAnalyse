#pragma once
#include <stdexcept>
namespace my_algorithm {
    //最大公因数
    template<class T>
    T gcd(T a, T b) {
        if (a <= 0 || b <= 0) {
            throw std::invalid_argument("Arguments must be positive numbers.");
        }
        if (a == 1 || b == 1) return 1;
        while (b != 0) {
            T temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    //扩展欧几里得算法
    template<class T>
    T extended_gcd(T a, T b, int& x, int& y) {
        if (b == 0) {
            x = 1;
            y = 0;
            return a;
        }
        int x1, y1;
        T gcd_val = extended_gcd(b, a % b, x1, y1);
        x = y1;
        y = x1 - (a / b) * y1;
        return gcd_val;
    }
    //最小公倍数
    template<class T>
    unsigned long long lcm(T a, T b) {
        if (a <= 0 || b <= 0) {
            throw std::invalid_argument("Arguments must be positive numbers.");
        }
        return (a * b) / gcd(a, b);
    }
}

