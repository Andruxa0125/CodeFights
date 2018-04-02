std::vector<std::vector<std::string>> groupingDishes(std::vector<std::vector<std::string>> dishes) 
{
    map<string, vector<string>> myMap;
    for(auto& v : dishes)
    {
        string dish = v[0];
        for(int i = 1; i < v.size(); i++)
        {
            myMap[v[i]].push_back(dish);
        }
    }
    vector<vector<string>> result;
    
    for(auto& pair : myMap)
    {
        if(pair.second.size() < 2)
            continue;
        sort(pair.second.begin(), pair.second.end());
        vector<string> temp;
        temp.push_back(pair.first);
        for(auto& el : pair.second)
            temp.push_back(el);
        result.push_back(temp);
    }
    return result;

}
    