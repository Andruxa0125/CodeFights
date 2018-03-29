std::string findProfession(int level, int pos) 
{
    if(level == 1)
        return "Engineer";
    if(pos % 2 == 1)
    {
        return findProfession(level - 1, (pos + 1) / 2);
    }
    else
    {
        string temp = findProfession(level - 1, pos / 2);
        if(temp == "Engineer")
            return "Doctor";
        else
            return "Engineer";
    }
}
