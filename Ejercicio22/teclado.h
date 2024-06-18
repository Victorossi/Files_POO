#ifndef TECLADO_H
#define TECLADO_H

#include "instrumento.h"
#include "electrico.h"

class Teclado : public Instrumento, public Electrico
{
public:
    Teclado(const std::string& marca = "Casio", int teclas = 61, int voltaje = 220)
        : Instrumento(marca), Electrico(voltaje), teclas(teclas) {}

    void sonar() const override
    {
        std::cout << "Teclado suena..." << std::endl;
        std::cout <<"-------------"<<std::endl;
    }

    void setTeclas(int teclas)
    {
        this->teclas = teclas;
    }

    int getTeclas() const
    {
        return teclas;
    }

private:
    int teclas;
};

#endif // TECLADO_H
