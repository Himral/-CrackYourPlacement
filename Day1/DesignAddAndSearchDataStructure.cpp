class TrieNode
{
public:
    TrieNode *links[26];
    bool flag = false;

    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, TrieNode *node)
    {
        links[ch - 'a'] = node;
    }

    TrieNode *get(char ch)
    {
        return links[ch - 'a'];
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }
};

class Trie
{
private:
public:
    TrieNode *root;
    /** Initialize your data structure here. */
    Trie()
    {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieNode *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new TrieNode());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TrieNode *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
                return false;
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word)
    {
        TrieNode *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
                return false;
            node = node->get(word[i]);
        }
        return true;
    }
};
class WordDictionary
{
public:
    Trie *T;
    WordDictionary()
    {
        T = new Trie();
    }

    void addWord(string word)
    {
        T->insert(word);
    }

    bool searchFromNode(string word, TrieNode *node)
    {
        for (int i = 0; i < word.length(); i++)
        {
            if (word[i] == '.')
            {
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    if (node->containsKey(ch))
                    {
                        if (searchFromNode(word.substr(i + 1), node->get(ch)))
                            return true;
                    }
                }
                return false;
            }
            else if (!node->containsKey(word[i]))
                return false;
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
    bool search(string word)
    {
        TrieNode *node = T->root;

        return searchFromNode(word, node);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */