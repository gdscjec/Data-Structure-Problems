class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        if (nums.size() < 4)
            return {};

        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 3; increment(nums, i))
        {
            for (int j = i + 1; j < nums.size() - 2; increment(nums, j))
            {
                int l = j + 1, r = nums.size() - 1;
                long sum = 0;

                // two pointer
                while (l < r)
                {
                    sum = (long)nums[i] + nums[j] + nums[l] + nums[r];

                    // if a solution is found, add it and change both pointers
                    if (sum == target)
                    {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        increment(nums, l);
                        decrement(nums, r);
                    }
                    // if sum is lesser, move left pointer to right by 1
                    else if (sum < target)
                        increment(nums, l);
                    // else if sum is greater, move right pointer to left by 1
                    else
                        decrement(nums, r);
                }
            }
        }

        return ans;
    }

    // increment() & decrement() are helper functions to avoid duplicates
    // basically, they do i++ or i-- but until a different number is found

    void increment(vector<int> &nums, int &n)
    {
        do
            n++;
        while (n < nums.size() && nums[n] == nums[n - 1]);
    }

    void decrement(vector<int> &nums, int &n)
    {
        do
            n--;
        while (n >= 0 && nums[n] == nums[n + 1]);
    }
};