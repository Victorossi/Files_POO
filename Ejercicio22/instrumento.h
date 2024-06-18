#ifndef INSTRUMENTO_H
#define INSTRUMENTO_H

#include <iostream>
#include <string>

class Instrumento
{
public:
    Instrumento(const std::string& marca = "Yamaha") : marca(marca) {}
    virtual ~Instrumento() {}

    virtual void sonar() const = 0;
    virtual void verlo() const
    {
        std::cout << "Marca: " << marca << std::endl;
    }

protected:
    std::string marca;
};
#endif // INSTRUMENTO_H
