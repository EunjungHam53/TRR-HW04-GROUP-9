#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <queue>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
#include <set>

// source code nay de tinh khoa d cho bai RSA(2 ham bai 4 da dc include trong file nay).
using namespace std;

long long phi(long long n) {
	long long res = n;
	for(int i = 2; i * i <= n; i++) {
		if(n % i == 0) {
			while(n % i == 0) n/= i;
			res -= res / i;
		}
	}
	if(n != 1) res -= res / n;
	return res;
}

long long sqr(long long n) {
	return n * n;
}

long long RevModulo(long long a, long long b, long long c) {
	if(b == 0) {
        return 1;
    } else {
        if(b % 2 == 0) {
            return (sqr(RevModulo(a, b / 2, c))) % c;
        } else {
            return (a * (sqr(RevModulo(a, b / 2, c)) % c)) % c;
        }
    }    
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	long long a, b;
	cin >> a >> b;
	cout << RevModulo(a, phi(phi(b)) - 1, phi(b));
	
	return 0;
}
