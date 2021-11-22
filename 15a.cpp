class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> finalVec;
        if(nums.size() < 3)
        {
            return finalVec;
        }
        for(int i = 0; i < nums.size() - 2; i++)
        {
            if(i == 0 || i > 0 && nums[i] != nums[i - 1])
            {
                int left = i + 1;
                int right = nums.size() - 1;
                int complement = -1 * nums[i];
                while(left < right)
                {
                    int thisSum = nums[left] + nums[right];
                    if(thisSum == complement)
                    {
                        vector<int> thisVec;
                        thisVec.push_back(-complement);
                        thisVec.push_back(nums[left]);
                        thisVec.push_back(nums[right]);
                        finalVec.push_back(thisVec);
                        left++;
                        right--;
                        while(left< right && nums[left] == nums[left - 1])
                        {
                            left++;
                        }
                        while(left < right && nums[right] == nums[right + 1])
                        {
                            right--;
                        }
                    }
                    if(thisSum < complement)
                    {
                        left++;
                    }
                    if(thisSum > complement)
                    {
                        right--;
                    }
                }
                
            }
        }
        return finalVec;
    }
    
};
