#include <iostream>
using namespace std;
const long long MOD = 1000000007;
inline long long powermod(int x, int y, long long mod){
    long long ans = 1;
    while(y) {
        if(y & 1) {
            ans *= x;
            ans %= mod;
        }
        x *= x;
        x %= mod;
        y >>= 1;
    }
    return ans;
}
long long puzzle(int n, int m){
    long long b1, b2;
    if(n <= 1 || m <= 1)return 0;
    if((n * m) % 6 != 0)return 0;
    if(n > m) swap(n,m);
    if(n == 2) {
        if(m % 3 != 0)return 0;
        return powermod(2, m / 3, MOD);
    } else if(n == 3) {
        if(m % 2 != 0)return 0;
        return powermod(2, m / 2, MOD);
    } else if(n == 4 && m == 6) { // 4 * 6
        b1 = puzzle(2, m);  // 分为两半
        b2 = puzzle(2, 3);   // 4*6异形数量
        return (b1 * b1 + b2) % MOD;
    } else if(n == 4) { // 4 * 3 * 2 * k, k = m / 6 或　4 * 3 * 2 * k + 4 * 3, k = m / 6
        b1 = powermod(puzzle(4, 6), m / 6, MOD);
        if(m % 6 == 0) return b1;
        else if(m % 6 == 3) {
            b2 = puzzle(3, 4);
            return b1 * b2 * (m / 6 + 1) % MOD;
        } else return 0;
    } else if(n == 5 && m == 6) {
        long long b1, b2;
        b1 = puzzle(3, m);
        b2 = puzzle(2, m);
        return b1 * b2 * 2 % MOD;   // 64
    } else if(n == 5) {
        if(m % 6 != 0)return 0;
        return powermod(puzzle(5, 6), m / 6, MOD);
    } else if(n == 6 && m == 6) {
        b1 = puzzle(3, m);  
        b2 = puzzle(2, 3);  
        return (b1 * b2 * 2 + b2 * puzzle(2, 6) * 4 + 2) % MOD;
    } else if(n == 6 && m == 7) {
        b1 = puzzle(2, 6) * puzzle(5, 6);
        b2 = puzzle(3, 6) * puzzle(4, 6);
        return (b1 + b2) % MOD;
    } else if(n == 6) return 0;
    else if(n == 7) return powermod(puzzle(6, 7), m / 6, MOD);
	return 0;
}
int main(){
    int n, m;
    long long ans;
    cin >> n >> m;
    ans = puzzle(n, m);
    cout << ans << endl;
    return 0;
}
