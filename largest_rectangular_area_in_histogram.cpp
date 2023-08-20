
Leetcode 84;

class Solution
{
public:
    // find prev smaller element
    void prevsmaller(vector<int> &heights, vector<int> &prev, int n)
    {
        stack<int> s;
        for (int i = 0; i < n; i++)
        {
            int curr = heights[i];
            while (!s.empty() && heights[s.top()] >= curr)
            {
                s.pop();
            }
            if (s.empty())
            {
                prev[i] = -1;
            }
            else
            {
                prev[i] = s.top();
            }
            s.push(i);
        }
    }

    // find next smaller element
    void nextsmaller(vector<int> &heights, vector<int> &next, int n)
    {
        stack<int> s;
        for (int i = n - 1; i >= 0; i--)
        {
            int curr = heights[i];
            while (!s.empty() && heights[s.top()] >= curr)
            {
                s.pop();
            }
            if (s.empty())
            {
                next[i] = n;
            }
            else
            {
                next[i] = s.top();
            }
            s.push(i);
        }
    }
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> next(n);
        vector<int> prev(n);

        nextsmaller(heights, next, n);
        prevsmaller(heights, prev, n);

        int maxi = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int base = next[i] - prev[i] - 1;
            int area = heights[i] * base;
            if (area > maxi)
            {
                maxi = area;
            }
        }
        return maxi;
    }
};