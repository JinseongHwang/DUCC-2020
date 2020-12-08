
// DUCC 2020 2ÇÐ³â - 3

#include <bits/stdc++.h>
using namespace std;

string next_char(string str) {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'z') {
			str[i] = 'a';
		}
		else if (str[i] == 'Z') {
			str[i] = 'A';
		}
		else if ('a' <= str[i] && str[i] <= 'z') {
			str[i] = str[i] + 1;
		}
		else if ('A' <= str[i] && str[i] <= 'Z') {
			str[i] = str[i] + 1;
		}
	}
	return str;
}

string circular_shift(string str) {
	string tmp;
	tmp += str.back();
	for (int i = 0; i < str.length() - 1; i++) {
		tmp += str[i];
	}
	return tmp;
}

string toggle_case(string str) {
	for (int i = 0; i < str.length(); i++) {
		if ('a' <= str[i] && str[i] <= 'z') {
			str[i] -= ('a' - 'A');
		}
		else if ('A' <= str[i] && str[i] <= 'Z') {
			str[i] += ('a' - 'A');
		}
	}
	return str;
}

string convert_string(string str) {
	str = circular_shift(str);
	str = toggle_case(str);
	str = next_char(str);
	return str;
}

int main() {

	//freopen("./sampleData9/2.inp", "r", stdin);
	//freopen("./sampleData9/my.out", "w", stdout);
	freopen("string.inp", "r", stdin);
	freopen("string.out", "w", stdout);

	//ios_base::sync_with_stdio(false); cin.tie(NULL);

	int T; scanf("%d", &T);
	string buffer_flush;
	getline(cin, buffer_flush);
	while (T--) {
		string inp;
		getline(cin, inp);

		string curr; curr.clear();
		int start_index = 0;
		bool needChange = true;
		for (int i = 0; i <= inp.length(); i++) {
			if (('A' <= inp[i] && inp[i] <= 'Z') || ('a' <= inp[i] && inp[i] <= 'z')) {
				if (needChange) {
					start_index = i;
					needChange = false;
				}
				curr += inp[i];
			}
			else {
				if (!curr.empty()) {
					string converted = convert_string(curr);
					inp.replace(start_index, curr.length(), converted);
					needChange = true;
					curr.clear();
				}
			}
		}

		cout << inp << "\n";
	}


	return 0;
}