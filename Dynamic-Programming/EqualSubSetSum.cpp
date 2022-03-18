class Solution
{
public:
    bool SubsetSum(vector<int> &nums, int currIndex, int targetSum, unordered_map<string, int> &mpp)
    {

        if (targetSum == 0)
            return true;

        if (currIndex >= nums.size())
            return false;
        string currKey = to_string(currIndex) + '-' + to_string(targetSum);
        if (mpp.find(currKey) != mpp.end())
            return mpp[currKey];
        bool consider = false;
        if (nums[currIndex] <= targetSum)
            consider = SubsetSum(nums, currIndex + 1, targetSum - nums[currIndex], mpp);
        if (consider == true)
            return true;

        bool notConsider = SubsetSum(nums, currIndex + 1, targetSum, mpp);
        mpp[currKey] = consider || notConsider;

        return mpp[currKey];
    }

    bool canPartition(vector<int> &nums)
    {

        unordered_map<string, int> mpp;
        int sum = 0;
        for (auto b : nums)
            sum += b;

        if (sum % 2 != 0)
            return false;

        else
            return SubsetSum(nums, 0, sum / 2, mpp);
    }
};