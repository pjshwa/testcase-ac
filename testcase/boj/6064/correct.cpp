#include <bits/stdc++.h>
using namespace std;

long long gcdExtended(long long a, long long b, long long& x, long long& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long g = gcdExtended(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

long long modInverse(long long value, long long mod) {
    long long x, y;
    gcdExtended(value, mod, x, y);
    x %= mod;
    if (x < 0) x += mod;
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        long long M, N, x, y;
        cin >> M >> N >> x >> y;

        long long targetX = x % M;
        long long targetY = y % N;
        long long g = gcd(M, N);
        long long diff = targetY - targetX;

        if (diff % g != 0) {
            cout << "-1\n";
            continue;
        }

        long long reducedM = M / g;
        long long reducedN = N / g;
        long long t = (diff / g) % reducedN;
        if (t < 0) t += reducedN;
        t = (t * modInverse(reducedM % reducedN, reducedN)) % reducedN;

        long long answer = targetX + M * t;
        if (answer == 0) {
            answer = lcm(M, N);
        }
        cout << answer << '\n';
    }

    return 0;
}
