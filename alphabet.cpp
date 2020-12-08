
// DUCC 2020 2ÇÐ³â - 1

#include <bits/stdc++.h>
using namespace std;

string a, b;

__inline int alpha_index(char c) {
	return c - 'a';
}

int main() {

	//freopen("./sampleData7/2.inp", "r", stdin);
	//freopen("./sampleData7/my.out", "w", stdout);
	freopen("alphabet.inp", "r", stdin);
	freopen("alphabet.out", "w", stdout);

	int T; scanf("%d", &T);
	while (T--) {
		
		cin >> a >> b;

		bool aUsed[26] = { 0, };
		bool bChecked[26] = { 0, };
		for (char ca : a) {
			aUsed[alpha_index(ca)] = true;
		}

		int result = 0;
		for (char cb : b) {
			if (aUsed[alpha_index(cb)] && !bChecked[alpha_index(cb)]) {
				bChecked[alpha_index(cb)] = true;
				result++;
			}
		}

		cout << result << "\n";
	}
	

	return 0;
}