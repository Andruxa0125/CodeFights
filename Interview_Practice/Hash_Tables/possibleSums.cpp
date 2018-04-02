int possibleSums(std::vector<int> coins, std::vector<int> quantity) 
{
    unordered_set<int> set;
    set.insert(0);
    for(int i = 0; i < coins.size(); i++) // different coins
    {
        unordered_set<int> setNow = set; // temporary set
        for(auto& sum : setNow) // for every element that we have in a set
        {
            for(int j = 1; j <= quantity[i]; j++) // repeat the # of times we have this coin
            {
                set.insert(sum + j * coins[i]);
            }
        }
    }
    return set.size() - 1;
}
