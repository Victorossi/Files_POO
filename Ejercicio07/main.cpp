#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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
    Producto producto1("Camisetas", 30000, 50);
    Producto producto2("Pantalones", 28000, 40);
    Producto producto3("Zapatillas", 140000, 20);

        std:: vector<Producto> productos;
        productos.push_back(producto1);
        productos.push_back(producto2);
        productos.push_back(producto3);

        std:: sort(productos.begin(), productos.end(), [](const Producto& a, const Producto b)
        {
            return a.getPrecio() < b.getPrecio();
        });

        std::cout << "Productos ordenados de menor a mayor en terminos de precio: \n";
                for(const auto& producto: productos)
        {
            producto.mostrarInformacion();
        }

    return 0;
}

