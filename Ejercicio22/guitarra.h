#ifndef GUITARRA_H
#define GUITARRA_H

#include "instrumento.h"

class Guitarra : public Instrumento
{
public:
    Guitarra(const std::string& marca = "Paul Reed Smith", int cuerdas = 6)
        : Instrumento(marca), cuerdas(cuerdas) {}

    void sonar() const override {
        std::cout << "Guitarra suena..." << std::endl;
        std::cout <<"-------------"<<std::endl;
    }

    void setCuerdas(int cuerdas)
    {
        this->cuerdas = cuerdas;
    }

    int getCuerdas() const
    {
        return cuerdas;
    }

private:
    int cuerdas;
};

#endif // GUITARRA_H
