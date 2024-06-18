#ifndef ELECTRICO_H
#define ELECTRICO_H

#include <iostream>

class Electrico
{
public:
    Electrico(int voltaje = 220) : voltaje(voltaje) {}
    virtual ~Electrico()
    {
        std::cout << "Desenchufado" << std::endl;
    }

    void setVoltaje(int voltaje)
    {
        this->voltaje = voltaje;
    }

    int getVoltaje() const
    {
        return voltaje;
    }

private:
    int voltaje;
};

#endif // ELECTRICO_H
