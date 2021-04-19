// *** 实现 Trie ***

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 1.注意要有构造函数
// 2.每个Trie中都有一个children子节点序列,可以做如下想象
/*



                |(a)----
                |(b)
    --- |(a)--- |(c)             
        |(b)    ...
        |(c)    |(z)
        |(d)
        |(e)---
        ...
        |(z)
*/
class Trie
{
private:
    vector<Trie *> children;
    bool isEnd;
    Trie *searchPrefix(string word)
    {
        Trie *node = this;
        for (char ch : word)
        {
            ch -= 'a';
            if (node->children[ch] == nullptr)
            {
                return nullptr;
            }
            node = node->children[ch];
        }
        return node;
    }

public:
    /** Initialize your data structure here. */
    Trie() : children(26), isEnd(false)
    {
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Trie *node = this;
        for (char ch : word)
        {
            ch -= 'a';
            if (node->children[ch] == nullptr)
            {
                node->children[ch] = new Trie();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Trie *node = this->searchPrefix(word);
        return node != nullptr && node->isEnd == true;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        return this->searchPrefix(prefix) != nullptr;
    }
};

void print(const vector<int> &mv)
{
    for (size_t i = 0; i != mv.size(); i++)
    {
        cout << mv[i] << " | ";
    }
    cout << endl;
}
void Test1()
{
}
int main()
{
    Test1();
    return 0;
}
