
// DUCC 2020 2학년 - 4

#include <bits/stdc++.h>
using namespace std;

typedef long long int llt;

struct Data {
	llt S; // 가위
	llt R; // 바위
	llt P; // 보
};

int main() {

	//freopen("./sampleData10/2.inp", "r", stdin);
	//freopen("./sampleData10/my.out", "w", stdout);
	freopen("card.inp", "r", stdin);
	freopen("card.out", "w", stdout);

	int T; scanf("%d", &T);
	while (T--) {
		llt n; scanf("%lld", &n);
		
		Data A, B;
		scanf("%lld %lld %lld %lld %lld %lld",
			&A.S, &A.R, &A.P, &B.S, &B.R, &B.P);

		llt result = 0;
		// A의 가위로 B의 보를 이기는 상황
		if (A.S <= B.P) {
			result += A.S;
		}
		else {
			result += B.P;
		}
		// A의 바위로 B의 가위를 이기는 상황
		if (A.R <= B.S) {
			result += A.R;
		}
		else {
			result += B.S;
		}
		// A의 보로 B의 바위를 이기는 상황
		if (A.P <= B.R) {
			result += A.P;
		}
		else {
			result += B.R;
		}

		printf("%lld\n", result);
	}

	return 0;
}