#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> generateParenthesis(int n);
void dfs(vector<string> &yield, string str, int n, int left, int right);

int main() {
	int n;
	cin >> n;
	vector<string> answer = generateParenthesis(n);
	for (auto &str : answer)
		cout << str << endl;
	return 0;
}

vector<string> generateParenthesis(int n) {
	vector<string> ret;
	string str;
	dfs(ret, str, n, 0, 0);
	return ret;
}

void dfs(vector<string> &yield, string str, int n, int left, int right) {
	if (left == n and right == n) {
		yield.emplace_back(str);
		return;
	}
	if (left < n)
		dfs(yield, str + "(", n, left + 1, right);
	if (right < left)
		dfs(yield, str + ")", n, left, right + 1);
}