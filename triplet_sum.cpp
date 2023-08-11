coding ninjas triplet sum

    find all the distinct triplet that sum to private
#include <bits/stdc++.h>

    vector<vector<int>>
    findTriplets(vector<int> arr, int n, int K)
{

    // Set to keep the track of visited triplets.
    map<vector<int>, bool> visited;
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 2; i++)
    {

        int s = i + 1;
        int e = n - 1;
        while (s < e)
        {
            int sum = arr[i] + arr[s] + arr[e];
            if (sum == K)
            {
                vector<int> triplet;
                triplet.push_back(arr[i]);
                triplet.push_back(arr[s]);
                triplet.push_back(arr[e]);

                if (visited[triplet] == false)
                {
                    ans.push_back(triplet);
                    visited[triplet] = true;
                }
                s++;
                e--;
            }
            else if (sum > K)
            {
                e--;
            }
            else
            {
                s++;
            }
        }
    }

    return ans;
}