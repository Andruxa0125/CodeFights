bool areFollowingPatterns(std::vector<std::string> strings, std::vector<std::string> patterns) 
{
    unordered_map<string, int> myMap;
    for(int i = 0; i < strings.size(); i++)
    {
        if(myMap.find(strings[i]) != myMap.end())
        {
            if(patterns[i] != patterns[myMap[strings[i]]])
                return false;
        }
        myMap[strings[i]] = i;
    }
    
    myMap.clear();
    for(int j = 0; j < patterns.size(); j++)
    {
         if(myMap.find(patterns[j]) != myMap.end())
        {
            if(strings[j] != strings[myMap[patterns[j]]])
                return false;
        }
        myMap[patterns[j]] = j;
    }
    return true;
}
