#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

class Persona { // creamos la clase
    private: //atributos de la clase 
        string nombre;
        int edad;
    public: // metodo de la clase 
        Persona(string, int);// constructor 
        void mostrarPersona();
};

Persona::Persona(string _nombre, int _edad){ //constructor 
    nombre = _nombre;
    edad = _edad;
}

class Empleado : public Persona { //creamos otra clase(hija) con herencia de clase padre(Persona)
    private: // atributos de la clase Empleado 
        string puesto;
        int nEmpleado;
    public: //metodo de la clase empleado
    Empleado(string, int, string, int); // hereda los atributos de la clase padre por eso dos string y dos int (nombre, edad, puesto, nEmpleado)
    void mostrarEmpleado();
};

// constructor de la clase hija (hereda los atributos de la clase padre)
Empleado::Empleado(string _nombre, int _edad, string _puesto, int _nEmpleado) : Persona(_nombre, _edad){ 
    puesto = _puesto;
    nEmpleado = _nEmpleado;
}

void Persona::mostrarPersona() {
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
}
    
void Empleado::mostrarEmpleado() {
    mostrarPersona();
    cout << "Puesto: " << puesto << endl;
    cout << "Numero de empleado: " << nEmpleado << endl;
}

int main(){
    Empleado p1("Gerardo",26,"ing. en comp.",10); //creamos un objeto
    
    p1.mostrarEmpleado(); //accedemos a los datos del obj
    
    return 0;
}
