char firstNotRepeatingCharacter(std::string s) 
{
    unordered_map<char, int> myMap;
    int array[26] = {0};
    
    for(int i = 0; i < s.size(); i++)
    {
        myMap[s[i]]++;
        int index = s[i] - 'a';
        array[index] = i;
    }
    
    int answer = numeric_limits<int>::max();
    for(auto it = myMap.begin(); it != myMap.end(); ++it )
    {
        if(it->second == 1)
        {
            answer = min(answer, array[it->first - 'a']);
        }
    }
    if(answer == numeric_limits<int>::max())
        return '_';
    return s[answer];

}
