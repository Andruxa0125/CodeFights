bool containsDuplicates(std::vector<int> a) 
{
    unordered_map<int, int> myMap;
    for(auto& el:a)
    {
        myMap[el]++;
        if(myMap[el] > 1)
            return true;
    }
    return false;

}
