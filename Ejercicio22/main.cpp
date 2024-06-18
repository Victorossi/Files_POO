#include <iostream>
#include <vector>
#include "guitarra.h"
#include "bateria.h"
#include "teclado.h"

int main()
{
    std::vector<Instrumento*> instrumentos;

    instrumentos.push_back(new Guitarra());
    instrumentos.push_back(new Bateria());
    instrumentos.push_back(new Teclado());
    instrumentos.push_back(new Guitarra("Fender", 12));
    instrumentos.push_back(new Teclado("Casio", 76, 110));

    for (const auto& instrumento : instrumentos)
    {
        instrumento->verlo();
        instrumento->sonar();
    }

    for (auto& instrumento : instrumentos)
    {
        delete instrumento;
    }

    return 0;
}
