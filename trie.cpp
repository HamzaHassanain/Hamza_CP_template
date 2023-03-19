#include <bits/stdc++.h>
#include <iomanip>
#include <chrono>
using namespace std;
// collapse
struct TrieNode
{
	bool isEndOfWord;
	vector<TrieNode *> children;
	TrieNode(bool isEndOfWord = false) : isEndOfWord{isEndOfWord}
	{
		children = vector<TrieNode *>(26, nullptr);
	}
};
class Trie
{

public:
	TrieNode *head;
	Trie()
	{
		this->head = new TrieNode();
	}

	void insert(string &word)
	{
		auto node = this->head;
		for (int i = 0; i < word.size(); i++)
		{
			int curr = word[i] - 'a';
			if (node->children[curr] == NULL)
			{
				node->children[curr] = new TrieNode();
			}
			node = node->children[curr];
		}

		node->isEndOfWord = true;
	}

	bool search(string &word, TrieNode *node, int idx)
	{
		if (not node)
			return false;
		if (idx > word.size())
			return false;
		if (idx == word.size())
			return node->isEndOfWord;
		if (word[idx] != '.')
			return search(word, node->children[word[idx] - 'a'], idx + 1);

		for (int i = 0; i < 26; i++)
		{
			if (search(word, node->children[i], idx + 1))
				return true;
		}

		return false;
	}
	bool search(string word)
	{
		return this->search(word, head, 0);
	}
	bool startsWith(string &prefix)
	{
		TrieNode *node = head;
		int curr = 0;

		for (int i = 0; i < prefix.size(); i++)
		{
			curr = prefix[i] - 'a';
			if (node->children[curr] == NULL)
			{
				return false;
			}
			node = node->children[curr];
		}

		return true;
	}
};

int main()
{
}
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
