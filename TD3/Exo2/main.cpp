#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSumBruteForce(const vector<int> &nums, int target)
{
    for (int i = 0; i < nums.size(); i++)
    {
        int number = nums[i];
        if (number > target)
            continue;
        for (int j = 0; j < nums.size(); j++)
        {
            int sum = number + nums[j];
            if (sum == target)
            {
                return vector<int>{i, j};
            }
        }
    }
    return vector<int>{-1, -1};
}

vector<int> twoSumOptimal(const vector<int> &nums, int target)
{
    unordered_map<int, int> numbers;
    for (int i = 0; i < nums.size(); i++)
    {
        int number = nums[i];
        int complement = target - number;
        if (numbers.find(complement) != numbers.end()) {
            return vector<int>{numbers[complement], i};
        }
        numbers[number] = i;
    }
    return vector<int>{-1, -1};
}

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> indicesBruteForce = twoSumBruteForce(nums, target);
    cout << "Brute-Force-Solution: ["
         << indicesBruteForce[0]
         << ", "
         << indicesBruteForce[1]
         << "]"
         << endl;

    vector<int> indicesOptimal = twoSumOptimal(nums, target);
    cout << "Optimal - Solution: ["
         << indicesOptimal[0]
         << ", "
         << indicesOptimal[1]
         << "]"
         << endl;

    return 0;
}