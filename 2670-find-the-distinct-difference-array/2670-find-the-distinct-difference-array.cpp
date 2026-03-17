class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        const int n = nums.size();
        std::vector<int> ans(n);

        std::unordered_map<int, int> tracker {};
        int tracker_size {};
        for (int num : nums)
        {
            tracker[num] += 1;
            if (tracker[num] == 1) tracker_size++;
        }

        std::unordered_map<int, int> considered {};
        int considered_size {};
        for (int i {}; i < n; i++)
        {
            int num = nums[i];
            considered[num] += 1;
            if (considered[num] == 1) considered_size++;

            tracker[num] -= 1;
            if (tracker[num] == 0) tracker_size--;
            ans[i] = considered_size - tracker_size;
        }

        return ans;
    }
};