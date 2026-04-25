class TrieNode {
public:
    TrieNode* children[26];
    bool word;

    TrieNode() {
        for(int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        word = false;
    }
};

class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(char w: word) {
            int i = w - 'a';
            if(curr->children[i] == nullptr) {
                curr->children[i] = new TrieNode();
            }
            curr = curr->children[i];
        }
        curr->word = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }

private:
    bool dfs(string word, int j, TrieNode* root) {
        TrieNode* curr = root;

        for(int i = j; i < word.size(); i++) {
            char c = word[i];
            if(c == '.') {
                for(TrieNode* child: curr->children) {
                    if(child != nullptr && dfs(word, i + 1, child)) {
                        return true;
                    }
                }
                return false;
            } else {
                if(curr->children[c - 'a'] == nullptr) return false;
                curr = curr->children[c - 'a'];
            }
        }
        return curr->word;
    }
};
