std::string minSubstringWithAllChars(std::string s, std::string t)
{
    if(t.size() == 0) return "";
    set<char> mySet;
    unordered_map<char, int> myMap;
    int start = 0;
    int size = t.size();
    pair<int, int> res(0, s.size() - 1);
    
    for(auto& ch : t)
    {
        mySet.insert(ch);
    }
    
    for(int i = 0; i < s.size(); i++)
    {
        if(mySet.find(s[i]) != mySet.end())
        {
            myMap[s[i]]++;
        }
        
        while(myMap.size() == size)
        {
            // cout << "got all the letters" << endl;
            // cout << "start is " << start << ";  end is " << i << endl << endl;
            if(i - start < res.second - res.first)
            {
                res.first = start;
                res.second = i;
            }
            
            if(myMap.find(s[start]) != myMap.end())
            {
                myMap[s[start]] --;
                if(myMap[s[start]] == 0)
                {
                    myMap.erase(s[start]);
                }
            }
            start++;
        }
        
    }
    string result = "";
    for(int i = res.first; i <= res.second; i++)
    {
        result += s[i];
    }
    return result;
}
 