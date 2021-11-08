class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        int arrCount[26];
        for(int i = 0; i < 26; i++)
        {
            arrCount[i] = 0;
        }
        if(s.size() != t.size())
        {
            return false;
        }
        for(int i = 0; i < s.size(); i++)
        {
            int thisIndex = s[i];
            thisIndex -= 'a';
            arrCount[thisIndex]++;
        }
        for(int i = 0; i < t.size(); i++)
        {
            int thisIndex = t[i];
            thisIndex -= 'a';
            arrCount[thisIndex]--;
        }
        for(int i = 0; i < 26; i++)
        {
            if(arrCount[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};
