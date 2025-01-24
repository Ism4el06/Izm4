#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

struct TarjetaDebito {
    string numeroTarjeta;
    string nombreTitular;
    string codigoSeguridad;
    bool esPrincipal;
};

struct TarjetaCredito : public TarjetaDebito {
    int mesExpiracion;
    int anioExpiracion;
};

struct Cuenta {
    string numeroCuenta;
    string descripcion;
    bool esCorriente;
    bool tieneChequera;
    vector<TarjetaDebito> tarjetasDebito;
    vector<TarjetaCredito> tarjetasCredito;
};

struct Prestamo {
    string fechaAprobacion;
    string fechaConsignacion;
    vector<string> fechasPago;
};

struct Cliente {
    string codigo;
    string identificacion;
    string nombres;
    string apellidos;
    string direccion;
    string email;
    string telefono;
    vector<Cuenta> cuentas;
    vector<Prestamo> prestamos;
    bool activo;
};

vector<Cliente> clientes;

void ingresarDatosCliente() {
    Cliente nuevoCliente;
    cout << "Ingrese el codigo del cliente: "; cin >> nuevoCliente.codigo;
    cout << "Ingrese cedula o pasaporte: "; cin >> nuevoCliente.identificacion;
    cout << "Ingrese nombres: "; cin.ignore(); getline(cin, nuevoCliente.nombres);
    cout << "Ingrese apellidos: "; getline(cin, nuevoCliente.apellidos);
    cout << "Ingrese direccion: "; getline(cin, nuevoCliente.direccion);
    cout << "Ingrese email: "; cin >> nuevoCliente.email;
    cout << "Ingrese telefono: "; cin >> nuevoCliente.telefono;
    
    int numCuentas;
    cout << "Ingrese la cantidad de cuentas del cliente: "; cin >> numCuentas;
    for (int i = 0; i < numCuentas; i++) {
        Cuenta cuenta;
        cout << "Ingrese numero de cuenta: "; cin >> cuenta.numeroCuenta;
        cout << "Ingrese descripcion de la cuenta: "; cin.ignore(); getline(cin, cuenta.descripcion);
        cout << "Es cuenta corriente? (1: Si, 0: No): "; cin >> cuenta.esCorriente;
        if (cuenta.esCorriente) {
            cout << "Tiene chequera? (1: Si, 0: No): "; cin >> cuenta.tieneChequera;
        }
        nuevoCliente.cuentas.push_back(cuenta);
    }
    
    clientes.push_back(nuevoCliente);
    system("clear || cls");
    cout << "Cliente ingresado correctamente!\n";
}

void mostrarClientes() {
    for (const auto &cliente : clientes) {
        cout << "Codigo: " << cliente.codigo << ", Nombres: " << cliente.nombres << " " << cliente.apellidos << endl;
    }
}

int main() {
    int opcion;
    do {
        cout << "\nMenu:" << endl;
        cout << "1. Ingresar datos de cliente" << endl;
        cout << "2. Salir" << endl;
        cout << "Ingrese su opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                ingresarDatosCliente();
                mostrarClientes();
                break;
            case 2:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 2);
    return 0;
}
