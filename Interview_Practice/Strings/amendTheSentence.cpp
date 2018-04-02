std::string amendTheSentence(std::string s)
{
    string result = "";
    if(s.size() == 0)
        return s;
    
    if(isupper(s[0]))
        result += tolower(s[0]);
    else
        result += s[0];
    
    int i = 1;
    while (i < s.size())
    {
        if(isupper(s[i]))
        {
            result += " ";
            result += tolower(s[i++]);
        }
        else
            result += s[i++];
    }
    return result;
}
