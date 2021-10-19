class Solution {
public:
    vector<string> fizzBuzz(int n) 
    {
        std::vector<string> finalVec;
        for(int i = 1; i <= n; i++)
        {
            std::string pushThis = "";
            if(i%3 == 0)
            {
                pushThis += "Fizz";
            }
            if(i % 5 == 0)
            {
                pushThis += "Buzz";
            }
            if(i % 3 != 0 && i % 5 != 0)
            {
                pushThis += std::to_string(i);
            }
            finalVec.push_back(pushThis);
        }
        return finalVec;
    }
};
