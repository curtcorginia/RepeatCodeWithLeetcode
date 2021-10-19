class Solution {
public:
    vector<string> fizzBuzz(int n) 
    {
        std::vector<string> finalVec;
        for(int i = 1; i <= n; i++)
        {
            if(i%3 == 0 && i % 5 == 0) 
            {
                finalVec.push_back("FizzBuzz");
            }
            else if(i%3 == 0)
            {
                finalVec.push_back("Fizz");
            }
            else if(i % 5 == 0)
            {
                finalVec.push_back("Buzz");
            }
            else 
            {
                finalVec.push_back(std::to_string(i));
            }
        }
        return finalVec;
    }
};
