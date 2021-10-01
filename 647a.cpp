//Based on the work of keshavk https://leetcode.com/problems/palindromic-substrings/discuss/105688/Very-Simple-Java-Solution-with-Detail-Explanation

class Solution {
public: 
    
    int countFromCenter(std::string& inputStr, int startInd, int endInd)
    {
        int addNum = 0;
        if(inputStr.size() == 0)
        {
            return addNum;
        }        
        while( startInd >= 0 && endInd < inputStr.size() 
              && inputStr[startInd] == inputStr[endInd])
        {
            addNum++;
            startInd--;
            endInd++;
        }
        return addNum;
    }
    int countSubstrings(string s) {
        int finalCount = 1;
        if(s.size() == 0)
        {
            return 0;
        }
        for(int i = 0; i < s.size() - 1; i++)
        {
            finalCount += countFromCenter(s, i, i);
            finalCount += countFromCenter(s, i, i + 1);
        }
        return finalCount;
    }
};
