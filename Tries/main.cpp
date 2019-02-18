#include <iostream>
#include <string>
#include <cassert>

using namespace std;

class Trie {
	struct Node {
		bool end;
		Node *map[26];
		/* assume that all inputs are consists of lowercase letters */
		explicit Node() {
			end = false;
			for (Node *&ptr : map)
				ptr = nullptr;
		}
	};
	Node *forest[26];
public:

	/** Initialize your data structure here. */
	explicit Trie() {
		for (Node *&root : forest)
			root = nullptr;
	}

	/** Inserts a word into the trie. */
	void insert(const string& word) {
		Node **ptr = forest, **pre = ptr;
		for (char ch : word) {
			int idx = ch - 'a';
			if (ptr[idx] == nullptr)
				ptr[idx] = new Node();

			pre = ptr;
			ptr = ptr[idx]->map;
		}
		pre[word.back() - 'a']->end = true;
	}

	/** Returns if the word is in the trie. */
	bool search(const string& word) {
		Node **ptr = forest, **pre = ptr;
		for (char ch : word) {
			int idx = ch - 'a';
			if (ptr[idx] == nullptr)
				return false;
			pre = ptr;
			ptr = ptr[idx]->map;
		}
		return pre[word.back() - 'a']->end;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(const string& prefix) {
		Node **ptr = forest;
		for (char ch : prefix) {
			int idx = ch - 'a';
			if (ptr[idx] == nullptr)
				return false;
			ptr = ptr[idx]->map;
		}
		return true;
	}
};

int main() {
	Trie trie = Trie();
	trie.insert("apple");
	assert(trie.search("apple"));
	assert(not trie.search("app"));
	assert(trie.startsWith("app"));
	trie.insert("app");
	assert(trie.search("app"));
	cout << "accepted" << endl;
	return 0;
}