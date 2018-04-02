int fillingBlocks(int n) 
{
    // f(n)=f(n-1)+5f(n-2)+f(n-3)-f(n-4)
    int array[23] = {0};
    array[0] = 0;
    array[1] = 1;
    array[2] = 1;
    array[3] = 5;
    if(n <= 2 )
        return array[n + 1];
    for(int i = 4; i <= n + 1; i++)
    {
        array[i] = array[i - 1] + 5 * array[i - 2] + array[i - 3] - array[i - 4];  
    }
    return array[n + 1];
}
