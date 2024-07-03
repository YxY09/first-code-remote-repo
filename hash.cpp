#include<iostream>
using namespace std;

int binpow(int a, int b, int p) {
    int res = 1;
    while(b > 0) {
        if(b & 1)
            res = ((res * a) % p);
        a = (a * a) % p;
        b >>= 1;
    }
    return res;
}

int main() {
    int a, b, p;
    cin >> a >> b >> p;
    cout <<a<<"^"<<b<<" mod "<<p<<"=" << binpow(a, b, p); // 输出结果
    return 0;
}

