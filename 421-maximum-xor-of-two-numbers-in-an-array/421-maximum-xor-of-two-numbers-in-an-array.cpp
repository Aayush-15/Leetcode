struct TrieNode {
    TrieNode *child[2] = {};
    int go = 0; // Number of elements goes through this node
    void increase(int number) {
        TrieNode *cur = this;
        for (int i = 31; i >= 0; --i) {
            int bit = (number >> i) & 1;
            if (cur->child[bit] == nullptr) cur->child[bit] = new TrieNode();
            cur = cur->child[bit];
            cur->go += 1;
        }
    }
    int findMax(int number) {
        TrieNode *cur = this;
        int ans = 0;
        for (int i = 31; i >= 0; --i) {
            int bit = (number >> i) & 1;
            if (cur->child[1 - bit] != nullptr && cur->child[1 - bit]->go > 0) {
                cur = cur->child[1 - bit];
                ans |= (1 << i);
            } else cur = cur->child[bit];
        }
        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int> &nums) {
        TrieNode *trieNode = new TrieNode();
        for (int x : nums) trieNode->increase(x);
        
        int ans = 0;
       
        for (int x : nums) ans = max(ans, trieNode->findMax(x));
        return ans;
    }
};