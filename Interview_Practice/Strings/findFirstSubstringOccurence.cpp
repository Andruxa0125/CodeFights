
int findFirstSubstringOccurrence(std::string s, std::string x) 
{
    int q = 13;
    int alpSize = 256;
    int winHash = 0;
    int patHash = 0;
    int highestPower = 1;
    int M = x.size();
    for(int i = 0; i < M - 1; i++)
    {
        highestPower = (highestPower * alpSize) % q;
    }
    
    for(int i = 0; i < x.size(); i++)
    {
        winHash = (alpSize * winHash + s[i]) % q;
        patHash = (alpSize * patHash + x[i]) % q;;
    }

    for(int j = M; j <= s.size(); j++)
    {
        if(winHash == patHash)
        {
            int start = j - M;
            int k = 0;
            for(; k < x.size(); k++, start++)
            {
                if(x[k] != s[start])
                    break;
            }
            if(k == M)
                return j - M;
        }
        if(j == s.size())
            return -1;
        
        winHash = (alpSize*(winHash - highestPower* s[j - M]) + s[j]) % q;
        if(winHash < 0)
            winHash += q;
    }
}

