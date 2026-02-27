#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
void printVec(std::vector<int>& nums) {
    for (const auto& num : nums) {
        std::cout << num << " ";
    }
    std::cout << "\n\n";
}

// helper function  for the expected neighbor
int checkNeighbor(int val) {
    if (val % 2 == 0) {
        return val + 1;
    } else {
        return val - 1;
    }
}


int swapPair(std::vector<int>& nums) {
    int count = 0;
    std::unordered_map<int, int> table; // create a hash map of value at index and index
    for (std::size_t i = 0; i < nums.size(); ++i) {
        table[nums[i]] = i;             // populate the table
    }
    
    for (std::size_t i = 0; i < nums.size(); i = i + 2) { // iterate every left partner in seats
        int neighborValue = checkNeighbor(nums[i]);       // check what expected/desired neighbor's value is
        int nextVal = nums[i + 1];                        // check what the actual neighbor's value is
        if (nextVal != neighborValue) {                   // if actual is not what the expected value is
            int actualNeighborIndex = table[neighborValue];     // where the expected neighbor is
            std::swap(nums[i+1], nums[actualNeighborIndex]);    // swap the expected neighbor and the actual neighbor
            table[neighborValue] = i + 1;                       // update the value in hash map
            table[nextVal] = actualNeighborIndex;
            count++;                                            // increment answer
        }        
    }
    return count; // return the answer
}

int main() {
    std::vector<int> test = {0, 2, 1, 3};
    std::vector<int> test2 = {3,2,0,1};
    std::cout << "number of swaps: " << swapPair(test) << '\n';
    printVec(test);
    std::cout << "number of swaps: " << swapPair(test2) << '\n';
    printVec(test2);
    return 0;
}