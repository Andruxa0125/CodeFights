int countClouds(std::vector<std::vector<char>> skyMap) 
{
    if(skyMap.size() == 0 || skyMap[0].size() == 0)
        return 0;
    int res = 0;
    int size = skyMap[0].size();
    for(int j = 0; j < skyMap.size(); j++)
    {
        for(int i = 0; i < size; i++)
        {
            if(skyMap[j][i] == '1')
            {
                res++;
                destroyCloud(skyMap, j, i);
            }
        }
    }
    return res;
}

void destroyCloud(vector<vector<char>>& skyMap, int y, int x)
{
    skyMap[y][x] = 0;
    int size = skyMap[0].size();
    
    if(x >= 1 && skyMap[y][x - 1] == '1')
        destroyCloud(skyMap, y, x - 1);
    
    if(x < size - 1 && skyMap[y][x + 1] == '1')
        destroyCloud(skyMap, y, x + 1);
    
    if(y >= 1 && skyMap[y - 1][x] == '1')
        destroyCloud(skyMap, y - 1, x);
    
    if(y < skyMap.size() - 1 && skyMap[y + 1][x] == '1')
        destroyCloud(skyMap, y + 1, x);
}

