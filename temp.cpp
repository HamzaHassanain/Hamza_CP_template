#include <bits/stdc++.h>
using namespace std;
#define minHeap(type) priority_queue<type, vector<type>, greater<type>>
typedef pair<int, int> heapNode;
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

        if (!node->children[word[idx] - 'a'])
            return false;

        return search(word, node->children[word[idx] - 'a'], idx + 1);
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

class Solution
{
public:
    Trie trie;
    vector<vector<char>> b;
    set<string> result;
    set<pair<int, int>> vis;
    void dfs(int i, int j, string pref)
    {
        if (vis.find({i, j}) != vis.end())
            return;
        if (trie.search(pref))
            result.insert(pref);
        vis.insert({i, j});
        if (trie.startsWith(pref))
        {
            pref.push_back(b[i][j]);
            dfs(i + 1, j, pref);
            dfs(i, j + 1, pref);
            dfs(i - 1, j, pref);
            dfs(i, j - 1, pref);
        }
    }
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        b = board;
        for (auto word : words)
        {
            trie.insert(word);
        }
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[i].size(); j++)
            {
                string pref = " ";
                pref[0] = board[i][j];
                if (trie.search(pref))
                    result.insert(pref);

                vis.insert({i, j});
                dfs(i + 1, j, pref);
                dfs(i, j + 1, pref);
                dfs(i - 1, j, pref);
                dfs(i, j - 1, pref);

                vis.clear();
            }
        }
        vector<string> res;
        for (auto str : result)
            res.push_back(str);
        return res;
    }
};

int main()
{

    Solution sol;
    vector<vector<int>> input = {{1, 2, 9}, {2, 3, 6}, {2, 4, 5}, {1, 4, 7}};
    // cout << sol.minScore(4, input) << endl;
}