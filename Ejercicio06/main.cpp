#include <iostream>
#include <string>
using namespace std;

class Producto
{
public:
    Producto(std:: string nombre, double precio, int cantidad)
    {
        this->nombre= nombre;
        this->precio= precio;
        this->cantidad = cantidad;
    }


    void setNombre(std:: string nombre)
    {
        this->nombre=nombre;
    }
    void setPrecio(double precio)
    {
        this->precio=precio;
    }
    void setCantidad(int cantidad)
    {
        this->cantidad=cantidad;
    }


    std:: string getNombre() const
    {
        return nombre;
    }
    double getPrecio() const
    {
        return precio;
    }
    int getCantidad() const
    {
        return cantidad;
    }

    void mostrarInformacion() const
    {
        cout<< "Nombre: " << nombre << endl;
        cout<< "Precio: " << precio<< endl;
        cout<< "Cantidad de stock: " << cantidad << endl;
    }

private:
    std:: string nombre;
    double precio;
    int cantidad;
};

int main()
{
    Producto producto1("Camisetas", 25000, 50);
    Producto producto2("Pantalones", 35000, 40);
    Producto producto3("Zapatillas", 140000, 20);

    std:: cout << "Informacion de los productos:\n";
    producto1.mostrarInformacion();
    producto2.mostrarInformacion();
    producto3.mostrarInformacion();
    return 0;
}

