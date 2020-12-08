
// DUCC 2020 2�г� - 5
// union-find �����ϰ�, 20/100 ���� �ҽ��ڵ��Դϴ�

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

const int MAX = 1e4 + 5;
int n, arr[MAX], parent[MAX];
bool visited[MAX];
bool first = false;

int getParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	a < b ? parent[b] = a : parent[a] = b;
}

bool hasSameParent(int a, int b) {
	return parent[a] == parent[b];
}

void dfs(int curr) {
	int nxt = arr[curr];
	if (!first && !hasSameParent(curr, nxt)) {
		unionParent(curr, nxt);
	}
	if (!visited[nxt]) {
		visited[nxt] = true;
		dfs(nxt);
	}
	return;
}

int number_of_cycle() {
	int cnt_cycle = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			dfs(i);
			cnt_cycle++;
		}
	}
	return cnt_cycle;
}

int main() {

	//freopen("./sampleData11/2.inp", "r", stdin);
	//freopen("./sampleData11/my.out", "w", stdout);
	//freopen("permcycle.inp", "r", stdin);
	//freopen("permcycle.out", "w", stdout);

	// ��ǥ���� �ؾߵɰŰ�����
	// ���� input���� ���ص� �ɰͰ��� ������
	
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);

		// �ܵ� ���� ��ȯ���൵ ����Ŭ ���� �ٲ��� �ʴ´�.
		unordered_set<int> single_node_index;

		for (int i = 1; i <= n; i++) {
			scanf("%d", arr + i);
			if (i == arr[i]) {
				single_node_index.insert(i);
			}
			parent[i] = i;
		}

		int default_cycle = number_of_cycle();
		int result = 0;

		first = true;
		
		for (int i = 1; i <= n; i++) {
			if (single_node_index.find(i) != single_node_index.end()) {
				continue;
			}
			for (int j = i + 1; j <= n; j++) {
				if (single_node_index.find(j) != single_node_index.end()) {
					continue;
				}
				if (hasSameParent(i, j)) {
					continue;
				}
				memset(visited, false, sizeof(bool) * (n + 1));
				swap(arr[i], arr[j]);
				int curr_cycle = number_of_cycle();
				if (default_cycle + 1 == curr_cycle) {
					result++;
				}
				swap(arr[i], arr[j]);
			}
		}
		
		printf("%d\n", result);

		memset(arr, 0, sizeof(arr));
		memset(visited, false, sizeof(visited));
	}

	return 0;
}