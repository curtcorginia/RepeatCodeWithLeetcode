class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int leftIndex = 0;
        int runningSum = 0;
        int finalAnswer = numeric_limits<int>::max();
        
        for(int i = 0; i < nums.size(); i++)
        {
            runningSum += nums[i];
            while(runningSum >= target)
            {
                finalAnswer = min(finalAnswer, i + 1 - leftIndex);
                runningSum -= nums[leftIndex];
                leftIndex++;
            }
        }
        if(finalAnswer == numeric_limits<int>::max())
        {
            return 0;
        }
        return finalAnswer;
    }
};
