#include <iostream>
#include <string>
using namespace std;

class Persona
{
public:
    Persona(string nombre): nombre(nombre) {}

    string getNombre() const
    {
        return nombre;
    }
private:
    string nombre;
};

class Poste
{
public:
    Poste(double altura, double diametro) : altura(altura), diametro(diametro) {}

    double getAltura() const
    {
        return altura;
    }
    double getDiametro() const
    {
        return diametro;
    }

private:
double altura;
double diametro;
};

template<typename T>
void imprimirDescripcion(const T& objeto);

template<>
void imprimirDescripcion(const Persona& persona)
{
    cout << "Persona con nombre " << persona.getNombre() << endl;
}

template<>
void imprimirDescripcion(const Poste& poste)
{
    cout << "Poste con altura de " << poste.getAltura() << " metros y " << poste.getDiametro() << "cm de diametro." << endl;
}


int main()
{
    Persona persona1("Victoria");
    Persona persona2("Constanza");
    Poste poste1(8.0, 15.0);
    Poste poste2(10.0, 20.0);

    imprimirDescripcion(persona1);
    imprimirDescripcion(persona2);
    imprimirDescripcion(poste1);
    imprimirDescripcion(poste2);
    return 0;
}
