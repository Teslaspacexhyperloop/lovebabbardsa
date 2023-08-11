codestudio pair sum

    return all the pair in the array with sum equal to s

        i.p test case n = 5 s = 4 2 - 6 2 5 2 o / p is 3

#include <bits/stdc++.h>
#include <bits/stdc++.h>
                                          vector<vector<int>>
                                          pairSum(vector<int> & arr, int s){
                                              // Write your code here.
                                              vector<vector<int>> ans;
                                              for (int i = 0; i < arr.size(); i++){
                                                  for (int j = i + 1; j < arr.size(); j++){
                                                      if (arr[i] + arr[j] == s){
                                                          vector<int> temp;
                                                          temp.push_back(min(arr[i], arr[j]));
                                                          temp.push_back(max(arr[i], arr[j]));
                                                          ans.push_back(temp);}}} sort(ans.begin(), ans.end());
                                              return ans;}

// approach 2 using binary search
#include <bits/stdc++.h>
                                          using namespace std;

    // Function to find the count of pairs
    int getPairsCount(int arr[], int n, int k){sort(arr, arr + n); int x = 0, c = 0, y, z; for (int i = 0; i < n - 1; i++){x = k - arr[i];

                                                                                                                           // Lower bound from i+1
                                                                                                                           int y = lower_bound(arr + i + 1, arr + n, x) - arr;

                                                                                                                           // Upper bound from i+1
                                                                                                                           int z = upper_bound(arr + i + 1, arr + n, x) - arr;
                                                                                                                           c = c + z - y;} return c;}

// Driver code

approach 3 using hashing

    int getPairsCount(int arr[], int n, int k){unordered_map<int, int> m; int count = 0; for (int i = 0; i < n; i++){if (m.find(k - arr[i]) != m.end()){count += m[k - arr[i]];} m[arr[i]]++;} return count;}

// Driver code
int main(){int arr[] = {1, 5, 7, -1}; int n = sizeof(arr) / sizeof(arr[0]); int sum = 6;

           // Function Call
           cout << "Count of pairs is " << getPairsCount(arr, n, sum); return 0;}
