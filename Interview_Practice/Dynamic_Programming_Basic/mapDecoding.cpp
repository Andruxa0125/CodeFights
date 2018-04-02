int mapDecoding(std::string mes) 
{
    const int NUM = (1000000000 + 7);
    int size = mes.size();
    vector<int> res(size + 2, 0);
    res[size] = 1; 
    res[size + 1] = 1;
    
    for(int i = size - 1; i >= 0; i--)
    {
        int first = 0;
        int second = 0;
        if(mes[i] != '0')
        {
            first = res[i + 1];
            res[i] += res[i + 1];
        }
        
        if(i <= (size - 2))
        {
            string temp = mes.substr(i,2);
            if(mes[i] != '0' && stoi(temp) <= 26 && stoi(temp) >= 1)
                //second = res[i + 2];
                res[i] = (res[i] + res[i + 2]) % NUM;
        }
    }
    
    return res[0];
}
