#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

// Función para limpiar la terminal
void limpiar_terminal() {
    #ifdef _WIN32
        system("cls");  // Comando para Windows
    #else
        system("clear");  // Comando para Linux/macOS
    #endif
}

class Cliente {
public:
    string nombre;
    string email;
    string telefono;
    string documentoIdentidad;

    Cliente(string n, string e, string t, string d)
        : nombre(n), email(e), telefono(t), documentoIdentidad(d) {}

    void registrarCliente() {
        cout << "Cliente registrado: " << nombre << endl;
    }
    void actualizarDatos(string nuevoEmail, string nuevoTelefono) {
        email = nuevoEmail;
        telefono = nuevoTelefono;
        cout << "Datos actualizados para: " << nombre << endl;
    }
    void consultarReserva();
};

class Habitacion {
public:
    int numeroHabitacion;
    string tipoHabitacion;
    string estado;
    double precioNoche;

    Habitacion(int num, string tipo, string est, double precio)
        : numeroHabitacion(num), tipoHabitacion(tipo), estado(est), precioNoche(precio) {}

    bool verDisponibilidad() {
        return estado == "Disponible";
    }
    void actualizarEstado(string nuevoEstado) {
        estado = nuevoEstado;
    }
};

class Pago {
public:
    int idPago;
    double monto;
    string metodoPago;
    string fechaPago;

    Pago(int id, double m, string metodo, string fecha)
        : idPago(id), monto(m), metodoPago(metodo), fechaPago(fecha) {}

    bool verificarPago() {
        cout << "Pago verificado por: " << monto << " via " << metodoPago << endl;
        return true;
    }
    void emitirFactura() {
        cout << "Factura emitida por: " << monto << endl;
    }
};

class Reserva {
public:
    int idReserva;
    string fechaInicio;
    string fechaFin;
    string estadoReserva;
    Cliente* cliente;
    Habitacion* habitacion;

    Reserva(int id, string inicio, string fin, Cliente* c, Habitacion* h)
        : idReserva(id), fechaInicio(inicio), fechaFin(fin), estadoReserva("Pendiente"), cliente(c), habitacion(h) {}

    void crearReserva() {
        if (habitacion->verDisponibilidad()) {
            habitacion->actualizarEstado("Reservada");
            estadoReserva = "Confirmada";
            cout << "Reserva creada para cliente: " << cliente->nombre << endl;
        } else {
            cout << "No hay disponibilidad para la habitaci\xA2n seleccionada." << endl;
        }
    }
    void cancelarReserva() {
        estadoReserva = "Cancelada";
        habitacion->actualizarEstado("Disponible");
        cout << "Reserva cancelada." << endl;
    }
    void consultarEstado() {
        cout << "Estado de la reserva: " << estadoReserva << endl;
    }
    void modificarReserva(string nuevaFechaInicio, string nuevaFechaFin) {
        fechaInicio = nuevaFechaInicio;
        fechaFin = nuevaFechaFin;
        cout << "Reserva modificada." << endl;
    }
};

class Sistema {
public:
    void mostrarDisponibilidad() {
        cout << "Mostrando disponibilidad de habitaciones..." << endl;
    }
    void mostrarConfirmacion() {
        cout << "Reserva confirmada con exito." << endl;
    }
    void mostrarError(string mensaje) {
        cout << "Error: " << mensaje << endl;
    }
};

// Función para ejecutar el flujo principal del programa
void ejecutar_programa() {
    Cliente cliente("Juan Perez", "juan@email.com", "123456789", "ABC123");
    Habitacion habitacion(101, "Doble", "Disponible", 100.0);
    Reserva reserva(1, "2025-05-01", "2025-05-10", &cliente, &habitacion);

    Sistema sistema;
    sistema.mostrarDisponibilidad();
    reserva.crearReserva();
    reserva.consultarEstado();

    Pago pago(1, 1000.0, "Tarjeta", "2025-04-25");
    pago.verificarPago();
    pago.emitirFactura();

    reserva.cancelarReserva();
    reserva.consultarEstado();

    sistema.mostrarConfirmacion();
}

int main() {
    char opcion;

    do {
        limpiar_terminal();  // Limpia la terminal antes de ejecutar el programa

        ejecutar_programa();

        cout << "\nDesea continuar? (s/n): ";
        cin >> opcion;
        
    } while (opcion == 's' || opcion == 'S');

    limpiar_terminal();  // Limpia la terminal después de la ejecución si el usuario elige no continuar

    return 0;
}