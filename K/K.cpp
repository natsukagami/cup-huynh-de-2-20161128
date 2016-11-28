#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 6;
int n, sumAnd[N][2], sumOr[N][2], sumXor[N][2], a[N], p1, p2, p3;
string s[] =  {"KHoNg", "Ko"};
int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	sumAnd[0][0] = sumAnd[n + 1][1] = (~0);
	for (int i = 1; i <= n; ++ i) {
		sumAnd[i][0] = sumAnd[i - 1][0] & a[i];
		 sumOr[i][0] =  sumOr[i - 1][0] | a[i];
		sumXor[i][0] = sumXor[i - 1][0] ^ a[i];
	}
	for (int i = n; i >= 1; -- i) {
		sumAnd[i][1] = sumAnd[i + 1][1] & a[i];
		 sumOr[i][1] =  sumOr[i + 1][1] | a[i];
		sumXor[i][1] = sumXor[i + 1][1] ^ a[i];
	}
	p1 = p2 = p3 = 0;
	for (int i = 1; i <= n; ++ i) {
		if (a[i] == (sumAnd[i - 1][0] & sumAnd[i + 1][1])) p1 = 1;
		if (a[i] == ( sumOr[i - 1][0] |  sumOr[i + 1][1])) p2 = 1;
		if (a[i] == (sumXor[i - 1][0] ^ sumXor[i + 1][1])) p3 = 1;
	}
	cout << s[p1] << ' ' << s[p2] << ' ' << s[p3] << '\n';
}