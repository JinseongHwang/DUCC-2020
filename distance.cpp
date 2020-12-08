
// DUCC 2020 2ÇÐ³â - 2

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAX = 1005;
const int INF = 0x7fffffff;
pii arr[MAX];

int main() {

	//freopen("./sampleData8/2.inp", "r", stdin);
	//freopen("./sampleData8/my.out", "w", stdout);
	freopen("distance.inp", "r", stdin);
	freopen("distance.out", "w", stdout);

	int T; scanf("%d", &T);
	while (T--) {
		int N; scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			int val; scanf("%d", &val);
			arr[i] = { val, i };
		}

		sort(arr, arr + N);

		int mx = arr[N - 1].first;
		int mn = arr[0].first;

		if (mx == mn) {
			printf("0\n");
			continue;
		}

		vector<pii> maxList, minList;

		for (int i = N - 1; i >= 0; i--) {
			if (arr[i].first == mx) {
				maxList.push_back(arr[i]);
			}
			else break;
		}

		for (int i = 0; i < N; i++) {
			if (arr[i].first == mn) {
				minList.push_back(arr[i]);
			}
			else break;
		}

		int result = INF;
		for (pii mxElem : maxList) {
			for (pii mnElem : minList) {
				int diff = abs(mxElem.second - mnElem.second);
				if (result > diff) result = diff;
			}
		}
		printf("%d\n", result);

		memset(arr, 0, sizeof(arr));
	}

	return 0;
}