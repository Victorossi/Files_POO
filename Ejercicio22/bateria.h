#ifndef BATERIA_H
#define BATERIA_H

#include "instrumento.h"

class Bateria : public Instrumento
{
public:
    Bateria(const std::string& marca = "Mapex Drums", int tambores = 5)
        : Instrumento(marca), tambores(tambores) {}

    void sonar() const override
    {
        std::cout << "Bateria suena..." << std::endl;
        std::cout <<"-------------"<<std::endl;

    }

    void setTambores(int tambores)
    {
        this->tambores = tambores;
    }

    int getTambores() const
    {
        return tambores;
    }

private:
    int tambores;
};

#endif // BATERIA_H
