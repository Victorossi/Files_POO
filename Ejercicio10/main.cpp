#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Jugador
{
private:
    int velocidad;
    int fuerza;
    string nombre;
public:
    //constructor
    Jugador(): velocidad(0), fuerza(0), nombre("Sin nombre") {}
    //constructor parametros
    Jugador(int velocidad, int fuerza, const std:: string&nombre)
        :velocidad(velocidad), fuerza(fuerza), nombre(nombre) {}
    //destructor
    ~Jugador() {}

    //metodos setter
    void setVelocidad(int velocidad) {this->velocidad = velocidad;}
    void setFuerza(int fuerza) {this->fuerza=fuerza;}
    void setNombre(const std:: string& nombre) {this->nombre=nombre;}
    //metodos getter
    int getVelocidad() const {return velocidad;}
    int getFuerza() const {return fuerza;}
    std::string getNombre() const {return nombre;}
};

int main()
{
    std:: vector<Jugador> jugadores;
    //insertar 10 jugadores distintos en el vector
    for(int i=0; i<10; i++)
    {
        Jugador jugador(i+1, (i+1) * 10, "Jugador" + std::to_string(i+1));
        jugadores.push_back(jugador);
    }
    //publicar los datos de cada jugador con std::cout
    for(const auto& jugador : jugadores)
    {
        cout << "Nombre: " << jugador.getNombre() << ", Velocidad: " << jugador.getVelocidad()
             << ", Fuerza: " << jugador.getFuerza() << std :: endl;
    }

    return 0;
}
