std::vector<std::vector<int>> rotateImage(std::vector<std::vector<int>> a) 
{
    int size = a.size();
    int k = 0;
    while(size - 2*k > 1)
    {
        int offset = 0;
        while(k + offset < size - 1 - k)
        {
            int temp =  a[k][k + offset]; //left top element
            a[k][k + offset] = a[size - 1 - k - offset][k]; //left bot element;
            a[size - 1 - k - offset][k] = a[size - 1 - k][size - 1 - k - offset]; //right bot el.
            a[size - 1 - k][size - 1 - k - offset] = a[k + offset][size - 1 - k]; //right top corner
            a[k + offset][size - 1 - k] = temp;
            offset++;
        }
        k++;
    }
    return a;
}
