bool isCryptSolution(std::vector<std::string> crypt, std::vector<std::vector<char>> solution) 
{
    unordered_map<char, char> myMap;
    for(auto& v : solution)
    {
        myMap[v[0]] = v[1];
    }
    
    for(auto& str : crypt)
    {
        for(int i = 0; i < str.size(); i++)
        {
            str[i] = myMap[str[i]];
        }
        if(str.size() > 1 && str[0] == '0')
            return false;
    }
    return stol(crypt[0]) + stol(crypt[1]) == stol(crypt[2]);

}
