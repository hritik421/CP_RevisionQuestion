// Given an integer array nums that may contain duplicates, return all possible subsets(the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

class Solution {
public:
    void solve(vector<vector<int>>& res, vector<int>& nums, vector<int>& curr, bool inc, int pos){
        if(pos == nums.size()) {
            res.push_back(curr);
            return;
        }

        // not pick
        solve(res,nums,curr,false,pos+1);
        // pick only when previous is not same in case of exclusion
        if(inc || pos == 0 || (nums[pos]!=nums[pos-1])){
            curr.push_back(nums[pos]);
            solve(res,nums,curr,true,pos+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> curr;
        solve(res, nums, curr, false, 0);
        return res;
    }
};
