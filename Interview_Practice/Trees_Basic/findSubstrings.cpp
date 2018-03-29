struct Node
{
    char ch;
    Node* child[52];
    bool makesWord;
    Node(char c) : Node()
    {
        ch = c;
    }
    Node()
    {
        makesWord = false;
        for(auto& p : child)
            p = NULL;
    }
};

void insert(Node* trie, string& str)
{
    for(int i = 0; i < str.size(); i++)
    {
        char c = str[i];
        int index = computeIndex(c);
        if(!trie->child[index])
            trie->child[index] = new Node(c);
        
        trie = trie->child[index];
    }
    trie->makesWord = true;
}

std::vector<std::string> findSubstrings(std::vector<std::string> words, std::vector<std::string> parts) 
{
    vector<string> res;
    Node* trie = new Node();
    
    for(auto& str : parts)
    {
        insert(trie, str);
    }
    
    for(auto& word : words)
    {
        pair<int, int> p = findWord(trie, word);
        if(p.second == -1)
            res.push_back(word);
        else
            res.push_back(helper(word, p.first, p.second));
    }
    return res;
}

string helper(string& str, int start, int stop)
{
    string res = "";
    
    for(int i = 0; i < str.size(); i++)
    {
        if(i == start)
            res += '[';
        res += str[i];
        if(i == stop)
            res += ']';
    }
    return res;
}

int computeIndex(char c)
{
    int index = 0;
    if(isupper(c))
    {
        index = c - 65 + 26;
    }
    else if(islower(c))
        index = c - 97;
    return index;
}

pair<int, int> findWord(Node* t, string& word)
{
    pair<int, int> p(0,-1); 
    for(int i = 0; i < word.size(); i++)
    {
        Node* trie = t;
        char curLet = word[i];
        int index = computeIndex(curLet);
        int j = i;
        while(trie->child[index] && j < word.size())
        {
            if(trie->child[index]->makesWord) // something makes word
            {
                 if(j - i > p.second - p.first)
                {
                    p.second = j;
                    p.first = i;
                }
            }
            trie = trie->child[index];
            j++;
            index = computeIndex(word[j]);
        }
    }
    return p;
}
