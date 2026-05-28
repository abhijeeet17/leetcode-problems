class Solution {
public:

    struct TrieNode {
        int child[26];
        int bestIndex;
        int bestLength;

        TrieNode() {
            memset(child, -1, sizeof(child));
            bestIndex = -1;
            bestLength = INT_MAX;
        }
    };

    vector<TrieNode> trie;

    void updateNode(int node, int len, int idx) {
        if(len < trie[node].bestLength) {
            trie[node].bestLength = len;
            trie[node].bestIndex = idx;
        }
    }

    void insert(string &word, int idx) {
        int node = 0;

        updateNode(node, word.size(), idx);

        for(int i = word.size() - 1; i >= 0; i--) {
            int c = word[i] - 'a';

            if(trie[node].child[c] == -1) {
                trie[node].child[c] = trie.size();
                trie.push_back(TrieNode());
            }

            node = trie[node].child[c];

            updateNode(node, word.size(), idx);
        }
    }

    int query(string &word) {
        int node = 0;

        for(int i = word.size() - 1; i >= 0; i--) {
            int c = word[i] - 'a';

            if(trie[node].child[c] == -1)
                break;

            node = trie[node].child[c];
        }

        return trie[node].bestIndex;
    }

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {

        trie.push_back(TrieNode());

        for(int i = 0; i < wordsContainer.size(); i++) {
            insert(wordsContainer[i], i);
        }

        vector<int> ans;

        for(auto &q : wordsQuery) {
            ans.push_back(query(q));
        }

        return ans;
    }
};