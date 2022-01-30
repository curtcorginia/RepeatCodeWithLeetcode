#include <vector>
#include <unordered_map>

class RandomizedSet {
public:
    std::unordered_map<int,int> u1;
    std::vector<int> myVec;
    
    
    RandomizedSet() {
        std::unordered_map<int,int> u2;
        std::vector<int> v2;
        u1 = u2;
        myVec = v2;
    }
    
    void testPrintVector(std::vector<int>& inputVec)
    {
        std::cout << "Vector: ";
        for(int i = 0; i < inputVec.size(); i++)
        {
            std::cout << " " << inputVec[i];
        }
    }
    bool insert(int val) {
        if(u1.find(val) == u1.end())
        {
            myVec.push_back(val);
            u1[val] = myVec.size() - 1;
            //std::cout << "\nAdded to unordered map. it now has key " << val << " with value " << u1[val]; 
            //std::cout << "\nJust inserted " << val << "print vector";
            //testPrintVector(myVec);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(u1.find(val) != u1.end()) {
            int endValueTemp = myVec[myVec.size() - 1];
            int indexToDelete = u1[val];
            myVec[myVec.size() - 1] = u1[val];
            myVec[indexToDelete] = endValueTemp;
            u1[endValueTemp] = u1[val]; //critical line - update map
            myVec.pop_back();
            //std::cout << "\nAfter removal of " << val;
            //testPrintVector(myVec);
            u1.erase(val);
            return true;
        } else {
            return false;
        }
    
    }
    
    int getRandom() {        
        int randIndex = rand() % myVec.size();
        return myVec[randIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
