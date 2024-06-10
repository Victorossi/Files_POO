#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unordered_map>
using namespace std;

class RandomNumberGenerator
{
public:
    RandomNumberGenerator()
    {
        srand(time(nullptr));
    }

    int generateRandomNumber(int min, int max)
    {
        return min + rand()%(max-min +1);
    }
};

class Statistics
{
public:
    int CalculateMode(const std::vector<int>& numbers)
    {
        std::unordered_map<int,int> frequencyMap;

        for (int num : numbers)
        {
            frequencyMap[num]++;
        }

        int mode=0;
        int maxFrequency = 0;
        for (const auto& pair : frequencyMap)
        {
            if (pair.second > maxFrequency)
            {
                maxFrequency = pair.second;
                mode = pair.first;
            }
        }
        return mode;
    }
};

int main()
{
    RandomNumberGenerator rng;
    std:: vector <int> numbers;

    for (int i = 0; i < 30; i++)
    {
        numbers.push_back(rng.generateRandomNumber(1,15));
    }

    cout << "Numeros generados:\n";
    for (int num:numbers)
    {
        std::cout << num << " ";
    }
    std:: cout << std:: endl;

    Statistics stats;
    int mode= stats.CalculateMode(numbers);
    std:: cout << "La moda de los numeros generados es: " << mode << std::endl;

    return 0;
}

