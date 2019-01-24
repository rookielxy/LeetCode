#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

string simplifyPath(const string &path);
vector<string> divideBySlash(const string &path);

int main() {
	string path;
	cin >> path;
	cout << simplifyPath(path) << endl;
	return 0;
}

string simplifyPath(const string &path) {
	vector<string> dir = divideBySlash(path);
	vector<string> pwd;
	for (string &ele : dir) {
		if (ele == ".")
			continue;
		else if (ele == "..") {
			if (not pwd.empty())
				pwd.pop_back();
		} else {
			pwd.push_back(ele);
		}
	}
	string ret;
	if (pwd.empty())
		return "/";
	for (string &ele : pwd)
		ret += '/' + ele;
	return ret;
}

vector<string> divideBySlash(const string &path) {
	vector<string> ele;
	if (path.empty())
		return ele;
	size_t pos = 0, len = 0;
	while (pos + len < path.size()) {
		if (path[pos + len] == '/') {
			if (len != 0) {
				ele.emplace_back(path.substr(pos, len));
				pos += len;
				len = 0;
			} else {
				++pos;
			}
		} else {
			++len;
		}
	}
	if (len != 0)
		ele.emplace_back(path.substr(pos, len));
	return ele;
}
