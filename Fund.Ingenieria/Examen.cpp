#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <sstream>
#include <limits>
#include <algorithm>
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

struct Prestamo {
    string fechaAprobacion;
    string fechaConsignacion;
    vector<string> fechasPago;
};

struct Cuenta {
    string numeroCuenta;
    string descripcion;
    bool esCorriente;
    bool tieneChequera;
    vector<TarjetaDebito> tarjetasDebito;
    vector<TarjetaCredito> tarjetasCredito;
    vector<Prestamo> prestamos;
    int mesesSinMovimiento;
    bool activa;
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
    bool activo;
};

vector<Cliente> clientes;

bool validarCodigo(const string& codigo) {
    return codigo.length() >= 6;
}

bool validarNombresApellidos(const string& texto) {
    istringstream stream(texto);
    string palabra;
    int contador = 0;
    while (stream >> palabra) {
        contador++;
    }
    return contador >= 2;
}

void limpiarPantalla() {
    system("clear || cls");
}

// Funcion generica para validar entradas
int obtenerOpcion(const string& mensaje, const vector<int>& opcionesValidas) {
    int opcion;
    while (true) {
        cout << mensaje;
        cin >> opcion;
        if (cin.fail() || find(opcionesValidas.begin(), opcionesValidas.end(), opcion) == opcionesValidas.end()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida. Intente de nuevo.\n";
        } else {
            break;
        }
    }
    return opcion;
}

string obtenerEntradaValida(const string& mensaje, bool (*validador)(const string&)) {
    string entrada;
    while (true) {
        cout << mensaje;
        cin >> entrada;
        if (validador(entrada)) {
            break;
        } else {
            cout << "Entrada invalida. Intente de nuevo.\n";
        }
    }
    return entrada;
}

void agregarPrestamos(Cuenta& cuenta) {
    int numPrestamos;
    cout << "\nIngrese la cantidad de prestamos para esta cuenta (maximo 3): ";
    cin >> numPrestamos;
    numPrestamos = min(numPrestamos, 3); // Limitar a un maximo de 3 prestamos

    for (int i = 0; i < numPrestamos; i++) {
        Prestamo prestamo;
        cout << "\nIngrese la fecha de aprobacion del prestamo: ";
        cin >> prestamo.fechaAprobacion;
        cout << "Ingrese la fecha de consignacion del dinero: ";
        cin >> prestamo.fechaConsignacion;

        int numFechasPago;
        cout << "Ingrese la cantidad de fechas de pago: ";
        cin >> numFechasPago;
        for (int j = 0; j < numFechasPago; j++) {
            string fechaPago;
            cout << "Ingrese la fecha de pago " << (j + 1) << ": ";
            cin >> fechaPago;
            prestamo.fechasPago.push_back(fechaPago);
        }

        cuenta.prestamos.push_back(prestamo);
    }
}

void ingresarDatosCliente() {
    Cliente nuevoCliente;

    nuevoCliente.codigo = obtenerEntradaValida("Ingrese el codigo del cliente (minimo 6 digitos): ", validarCodigo);
    
    cout << "Ingrese cedula o pasaporte: "; cin >> nuevoCliente.identificacion;

    do {
        cout << "Ingrese nombres (debe incluir al menos dos palabras): "; cin.ignore(); getline(cin, nuevoCliente.nombres);
    } while (!validarNombresApellidos(nuevoCliente.nombres));

    do {
        cout << "Ingrese apellidos (debe incluir al menos dos palabras): "; getline(cin, nuevoCliente.apellidos);
    } while (!validarNombresApellidos(nuevoCliente.apellidos));

    cout << "Ingrese direccion: "; getline(cin, nuevoCliente.direccion);
    cout << "Ingrese email: "; cin >> nuevoCliente.email;
    cout << "Ingrese telefono: "; cin >> nuevoCliente.telefono;

    int numCuentas;
    cout << "Ingrese la cantidad de cuentas del cliente: "; cin >> numCuentas;
    for (int i = 0; i < numCuentas; i++) {
        Cuenta cuenta;
        cout << "\nIngrese numero de cuenta: "; cin >> cuenta.numeroCuenta;

        int opcionDescripcion = obtenerOpcion(
            "Seleccione la descripcion de la cuenta:\n1. Cuenta para comprar casas\n2. Cuenta para comprar vehiculos\n3. Pagar estudios\n4. Emprender un negocio\nIngrese su opcion: ", 
            {1, 2, 3, 4}
        );

        switch (opcionDescripcion) {
            case 1:
                cuenta.descripcion = "Cuenta para comprar casas";
                break;
            case 2:
                cuenta.descripcion = "Cuenta para comprar vehiculos";
                break;
            case 3:
                cuenta.descripcion = "Pagar estudios";
                break;
            case 4:
                cuenta.descripcion = "Emprender un negocio";
                break;
        }

        cuenta.esCorriente = obtenerOpcion("Es cuenta corriente o de ahorros? (1: Corriente, 0: Ahorros): ", {0, 1});

        if (cuenta.esCorriente) {
            cuenta.tieneChequera = obtenerOpcion("Tiene chequera? (1: Si, 0: No): ", {0, 1});
        } else {
            cuenta.tieneChequera = false; // Cuentas de ahorros no tienen chequera
        }

        cuenta.mesesSinMovimiento = 0;
        cuenta.activa = true;

        agregarPrestamos(cuenta);
        nuevoCliente.cuentas.push_back(cuenta);
    }

    nuevoCliente.activo = true;
    clientes.push_back(nuevoCliente);
    limpiarPantalla();
    cout << "Cliente ingresado correctamente!\n";
}

void verificarInactividad() {
    for (auto& cliente : clientes) {
        bool tieneCuentasActivas = false;
        for (auto& cuenta : cliente.cuentas) {
            if (cuenta.mesesSinMovimiento >= 6) {
                cuenta.activa = false;
            }
            if (cuenta.activa) {
                tieneCuentasActivas = true;
            }
        }
        if (!tieneCuentasActivas) {
            cliente.activo = false;
        }
    }
}

void mostrarMenu() {
    limpiarPantalla();
    cout << "\nMenu:" << endl;
    cout << "1. Ingresar datos de cliente" << endl;
    cout << "2. Verificar inactividad" << endl;
    cout << "3. Salir" << endl;
    cout << "Ingrese su opcion: ";
}

int main() {
    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        switch (opcion) {
            case 1:
                ingresarDatosCliente();
                break;
            case 2:
                verificarInactividad();
                cout << "Inactividad verificada y actualizada correctamente.\n";
                break;
            case 3:
                limpiarPantalla();
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                limpiarPantalla();
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 3);
    return 0;
}