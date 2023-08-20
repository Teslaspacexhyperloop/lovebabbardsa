// GFG
Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.

vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K)
{
    queue<long long int> q;

    for (long long int i = 0; i < K - 1; i++)
    {
        if (A[i] < 0)
        {
            q.push(A[i]);
        }
    }

    vector<long long> ans;
    int ind = 0;
    for (long long int i = K - 1; i < N; i++)
    {
        if (A[i] < 0)
        {
            q.push(A[i]);
        }

        if (q.empty())
        {
            ans.push_back(0);
        }
        else
        {
            ans.push_back(q.front());
        }

        if (A[ind] < 0)
        {
            q.pop();
        }
        ind++;
    }

    return ans;
}