
codestudio duplicate in an __ARRAY

        array has element from 1 to N -
    1 find the element which occur twice

    int
    findDuplicate(vector<int> &arr)
{
    // Write your code here
    int ans = 0;
    // xoring from 1 to n-1
    for (int i = 1; i < arr.size(); i++)
    {
        ans = ans ^ i;
    }

    // xoring all array element
    for (int i = 0; i < arr.size(); i++)
    {
        ans = ans ^ arr[i];
    }

    return ans;
}
