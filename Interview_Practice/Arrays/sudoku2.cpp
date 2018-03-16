bool sudoku2(std::vector<std::vector<char>> grid) 
{
    int size = 9;
    bool temp = checkRows(grid) && checkColumns(grid);

    if(!temp)
        return false;
    for(int i = 0; i < size; i+=3)
    {
        for(int j = 0; j < size; j+=3)
        {
            if(!checkSquare(grid, j, i))
                return false;
        }
    }
    return true;

}

bool checkSquare(vector<vector<char>> grid, int row, int column)
{
    unordered_set<char> mySet;
    for(int j = column; j < column + 3; j++)
    {
        for(int i = row; i < row + 3; i++)
        {
            if(grid[i][j] != '.')
            {
                if(mySet.find(grid[i][j]) != mySet.end())
                    return false;
                mySet.insert(grid[i][j]);
            }
        }
    }
    return true;
}
bool checkRows(vector<vector<char>> grid)
{
     int size = 9;
    for(int j = 0; j < size; j++)
    {
        unordered_set<char> mySet;
        for(int i = 0; i < size; i++)
        {
            if(grid[i][j] != '.')
            {
                if(mySet.find(grid[i][j]) != mySet.end())
                    return false;
                mySet.insert(grid[i][j]);
            }
        }
    }
    return true;
}

bool checkColumns(vector<vector<char>> grid)
{
     int size = 9;
    for(int j = 0; j < size; j++)
    {
        unordered_set<char> mySet;
        for(int i = 0; i < size; i++)
        {
            if(grid[j][i] != '.')
            {
                if(mySet.find(grid[j][i]) != mySet.end())
                    return false;
                mySet.insert(grid[j][i]);
            }
        }
    }
    return true;
}