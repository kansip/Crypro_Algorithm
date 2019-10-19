//Вы не слишком добры...
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <clocale>

#define int long long

using namespace std;

vector<char> fix_code(vector<char>& arr, int n = -1) {
	int ans_wr = 0;
	if (n == -1)
		n = arr.size();
	for (int i = 1; i < n + 1; i *= 2) {
		bool ans = 0;
		for (int j = i; j < n + 1; j += 2 * i) {
			for (int k = j; k < j + i; k++) {
				ans xor_eq (arr[k - 1] == '1' ? true : false);
			}
		}
		if (ans)
			ans_wr += i;
	}
	//cout << ans_wr;
	if (ans_wr)
		arr[ans_wr - 1] = (arr[ans_wr - 1] == '1' ? '0' : '1');
	vector<char> ret;
	int notPrint = 1;
	int it2 = 0;
	for (int i = 0; i < n; i++) {
		if (i + 1 == notPrint)
			notPrint *= 2;
		else
			ret.push_back(arr[i]);
	}
	return ret;
}

signed main() {
	int n = 0, k, bas = 15;
	setlocale(LC_ALL, "ru");
	string s2;
	getline(cin, s2);
	vector<char> ans_bit;
	vector<char> arr(10000);
	int it = 0;
	for (auto el : s2) {
		if (el == '0' || el == '1')
			arr[it++] = el;
	}
	for (int i = 0; i < it; i += 15) {
		vector<char> send;
		for (int j = i; j < i + 15; j++)
			send.push_back(arr[j]);
		vector<char> ans = fix_code(send, 15);
		for (auto el : ans) {
			ans_bit.push_back(el);
			cout << el;
		}
		cout << ' ';
	}
	cout << endl;
	for (int i = 0; i < ans_bit.size(); i += 8) {
		int symb_ans = 0;
		for (int j = i; j < i + 8 && j < ans_bit.size(); j++) {
			if (ans_bit[j] == '1') {
				symb_ans += (pow(2, abs(-1*(j - i - 7))));
			}
		}
		cout << (char)(symb_ans);
	}
}
