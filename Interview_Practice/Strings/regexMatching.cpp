bool regexMatching(string pattern, string test) 
{
    if(pattern.size() == 0 || (pattern.size() == 1 && (pattern[0] == '^' 
                              || pattern[0] == '$')))
       return true;
                               
                               
    if(test.size() < pattern.size() - 1)
        return false;
    
    if(pattern[0] == '^')
    {
        int i = 0;
        for(i = 1; i < pattern.size(); i++)
        {
            if(pattern[i] != test[i - 1])
                break;
        }
        if(i != pattern.size())
            return false;
        return true;
    }
    else if(pattern[pattern.size() - 1] == '$')
    {
        int i = pattern.size() - 2;
        for(int j = test.size() - 1; i >= 0; i--, j--)
        {
            cout << "the char is " << pattern[i] << endl;
            cout << "the char is " << test[j] << endl;
            if(pattern[i] != test[j])
                break;
        }
        cout << "I is " << i;
        if(i != -1)
            return false;
        return true;
    }
    else
    {
        if (test.find(pattern) != std::string::npos)
            return true;
        else
            return false;
    }

}
