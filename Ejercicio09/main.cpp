#include <iostream>
using namespace std;

template <class T>
void imprimir(T *v, int cantidad, bool mayor_a_menor)
{
    for(int i = 1; i<cantidad; i++)
    {
        T key = v[i];
        int j = i-1;
       if(mayor_a_menor)
       {
           while (j >= 0 && v[j] < key)
           {
               v[j+1] = v[j];
               j--;
           }
       }
       else
       {
           while(j >= 0 && v[j] > key)
           {
               v[j+1] = v[j];
               j--;
           }
       }
       v[j+1] = key;
    }

    if (mayor_a_menor)
    {
        cout << "Valores ordenados de mayor a menor:\n";
        for (int i = 0; i< cantidad; i++)
        {
            cout << v[i] << " ";
        }
        std:: cout << std::endl;
    }
    else
    {
        std:: cout << "Valores ordenanos de menor a mayor:\n";
        for(int i=0; i< cantidad; i++)
        {
            cout << v[i] << " ";
        }
        std:: cout << std:: endl;
    }
}

int main()
{
    int arr_int[]= {5,2,9,1,7};
    float arr_float[]= {3.5,1.2,4.8,2.1,6.7};

    //array enteros mayor a menor
    imprimir(arr_int, sizeof(arr_int) / sizeof(arr_int[0]), true);

    //array enteros menor a mayor
    imprimir(arr_float, sizeof(arr_float) / sizeof(arr_float[0]), false);

    return 0;
}
