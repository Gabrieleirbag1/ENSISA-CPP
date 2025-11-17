#include <iostream>
#include <vector>
#include <map>

using namespace std;

void countFrequencyBruteForce(const vector<int> &numbers)
{
    map<int, int> frequencyMap;
    for (int i = 0; i < numbers.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < numbers.size(); j++)
        {
            if (numbers[j] == numbers[i])
            {
                count++;
            }
        }
        frequencyMap[numbers[i]] = count;
    }

    for (auto &p : frequencyMap)
    {
        cout << p.first << " : " << p.second << endl;
    }
}

map<int, int> countFrequencyOptimal(const vector<int> &numbers)
{
}

int main(int argc, char const *argv[])
{
    vector<int> numbers = {1, 2, 3, 2, 4, 1, 5, 5, 6};

    cout << "Frequency (Brute Foce):" << endl;
    countFrequencyBruteForce(numbers);

    // cout << "\nFrequency (Optimal):" << endl;
    // map<int, int> frequencyMapOptimal = countFrequencyOptimal(numbers);
    // for (const auto& entry : frequencyMapOptimal) {
    //     cout << entry.first << ": " << entry.second << " times" << endl;
    // }
    return 0;
}
