#include <iostream>
#include <cstdlib>
#include <ctime>
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
    return min + rand() % (max - min +1);
}

};
int main ()
{
    RandomNumberGenerator rng;

    cout << "Generando 10 numeros aleatorios en el intervalo [2,20]:\n";
    for (int i=0; i<10; i++)
    {
        int randomNumber = rng.generateRandomNumber(2,20);
        cout << randomNumber << " ";
    }
    cout << std :: endl;
    return 0;
}



