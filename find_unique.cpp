Find unique coding ninjas
        array has 2m +
    1 element find the element which occur once

    int
    findUnique(int *arr, int size)
{

    // how to count which no occur how maany times
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;
}