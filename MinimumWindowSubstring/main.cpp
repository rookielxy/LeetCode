#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

string minWindow(const string &s, const string &t);

int main() {
    string s, t;
    cin >> s >> t;
    cout << minWindow(s, t) << endl;
    return 0;
}


string minWindow(const string &s, const string &t) {
    if (s.empty() or t.empty())
        return "";

    int remains[256];
    bool contains[256];
    memset(remains, 0, sizeof(remains));
    memset(contains, false, sizeof(contains));
    for (const auto ch : t) {
	    ++remains[ch];
        contains[ch] = true;
    }

    bool everFind = false;
    int counter = 0;
    int start = 0, end = 0, left = 0, len = (int)s.size();
    while (start < s.size() or end < s.size()) {
    	if (counter < t.size()) {
    		if (contains[s[end]]) {
			    counter += (remains[s[end]] > 0)? 1 : 0;
			    --remains[s[end]];
    		}
    		if (end == s.size())
    			break;
		    ++end;
    	} else {
    		everFind = true;
    		if (end - start < len) {
    			left = start;
    			len = end - start;
    		}
    		if (contains[s[start]]) {
    			counter -= (remains[s[start]] < 0)? 0 : 1;
    			++remains[s[start]];
    		}
    		++start;
    	}
    }
    if (not everFind)
    	return "";
    else
    	return s.substr((unsigned)left, (unsigned)len);
}