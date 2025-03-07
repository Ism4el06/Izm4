#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Venta {
    string producto;
    int cantidad;
    double precio;
    string sucursal;
};

void calcularTotales(const vector<Venta> &ventas, string productos[], int totalArticulos[], double recaudacionSucursales[], string sucursales[], int &cantidadSur, int &cantidadTecladoNorte) {
    for (const auto &venta : ventas) {
        for (int i = 0; i < 6; i++) {
            if (venta.producto == productos[i]) {
                totalArticulos[i] += venta.cantidad;
            }
        }
        for (int i = 0; i < 4; i++) {
            if (venta.sucursal == sucursales[i]) {
                recaudacionSucursales[i] += venta.cantidad * venta.precio;
            }
        }
        if (venta.sucursal == "Sur") {
            cantidadSur += venta.cantidad;
        }
        if (venta.producto == "Teclado" && venta.sucursal == "Norte") {
            cantidadTecladoNorte += venta.cantidad;
        }
    }
}

double recaudacionTotal(double recaudacionSucursales[]) {
    double total = 0;
    for (int i = 0; i < 4; i++) {
        total += recaudacionSucursales[i];
    }
    return total;
}

string sucursalMayorRecaudacion(double recaudacionSucursales[], string sucursales[]) {
    int mejorIndex = 0;
    for (int i = 1; i < 4; i++) {
        if (recaudacionSucursales[i] > recaudacionSucursales[mejorIndex]) {
            mejorIndex = i;
        }
    }
    return sucursales[mejorIndex];
}

int main() {
    vector<Venta> ventas;
    ifstream archivoEntrada("empresa.txt");
    if (!archivoEntrada) {
        cout << "No se pudo abrir el archivo empresa.txt" << endl;
        return 1;
    }
    
    string id, producto, sucursal;
    int cantidad;
    double precio;
    
    string encabezado;
    getline(archivoEntrada, encabezado); // Omitir la primera línea de encabezado
    
    while (archivoEntrada >> id >> producto >> cantidad >> precio >> sucursal) {
        ventas.push_back({producto, cantidad, precio, sucursal});
    }
    archivoEntrada.close();
    
    string productos[] = {"Laptop", "Mouse", "Teclado", "Monitor", "Impresora", "Webcam"};
    int totalArticulos[6] = {0};
    string sucursales[] = {"Norte", "Centro", "Sur", "Este"};
    double recaudacionSucursales[4] = {0};
    int cantidadSur = 0;
    int cantidadTecladoNorte = 0;
    
    calcularTotales(ventas, productos, totalArticulos, recaudacionSucursales, sucursales, cantidadSur, cantidadTecladoNorte);
    double totalEmpresa = recaudacionTotal(recaudacionSucursales);
    string mejorSucursal = sucursalMayorRecaudacion(recaudacionSucursales, sucursales);
    
    ofstream archivoSalida("consolidado.txt");
    if (!archivoSalida) {
        cout << "No se pudo crear el archivo consolidado.txt" << endl;
        return 1;
    }
    
    archivoSalida << "Producto  Cantidad Total\n";
    for (int i = 0; i < 6; i++) {
        archivoSalida << productos[i] << " " << totalArticulos[i] << "\n";
    }
    archivoSalida << "\nCantidad de articulos en la sucursal Sur: " << cantidadSur << "\n";
    archivoSalida << "Cantidad de teclados en la sucursal Norte: " << cantidadTecladoNorte << "\n\n";
    
    archivoSalida << "Sucursal  Recaudacion Total\n";
    for (int i = 0; i < 4; i++) {
        archivoSalida << sucursales[i] << " $" << recaudacionSucursales[i] << "\n";
    }
    
    archivoSalida << "\nRecaudacion total de la empresa: $" << totalEmpresa << "\n";
    archivoSalida << "Sucursal con mayor recaudacion: " << mejorSucursal << "\n";
    
    archivoSalida.close();
    cout << "Datos guardados en consolidado.txt" << endl;
    
    return 0;
}
