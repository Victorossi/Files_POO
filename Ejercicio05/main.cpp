#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    std :: vector <std::string> idioms;

    idioms.push_back("pan comido");
    idioms.push_back("mas vale tarde que nunca");
    idioms.push_back("mas vale prevenir que curar");
    idioms.push_back("agarrar el toro por los cuernos");
    idioms.push_back("hacerse el sueco");

    std::sort(idioms.begin(), idioms.end());

    std::cout << "Expresiones idiomaticas ordenasas alfabeticamente: \n";
    for (const auto& idiom: idioms)
    {
        std:: cout << idiom << std:: endl;
    }
    return 0;
}
