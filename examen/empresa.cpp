#include <iostream>
#include <fstream> // Para manejar archivos

using namespace std;

int main() {
    // Crear un objeto ofstream para escribir en el archivo
    ofstream archivoSalida("empresa.txt");

    // Verificar si el archivo se abrió correctamente
    if (archivoSalida.is_open()) {
        // Escribir los datos en el archivo
        archivoSalida << "id\tproducto\tcant\tprecio\tsucursal" << endl;
        archivoSalida << "1\tLaptop\t5\t1200.00\tNorte" << endl;
        archivoSalida << "2\tMouse\t15\t25.00\tCentro" << endl;
        archivoSalida << "3\tTeclado\t8\t45.00\tSur" << endl;
        archivoSalida << "4\tMonitor\t3\t250.00\tEste" << endl;
        archivoSalida << "5\tLaptop\t2\t1200.00\tCentro" << endl;
        archivoSalida << "6\tImpresora\t4\t180.00\tNorte" << endl;
        archivoSalida << "7\tMouse\t20\t25.00\tSur" << endl;
        archivoSalida << "8\tWebcam\t6\t60.00\tEste" << endl;
        archivoSalida << "9\tTeclado\t10\t45.00\tNorte" << endl;
        archivoSalida << "10\tMonitor\t7\t250.00\tCentro" << endl;
        archivoSalida << "11\tLaptop\t3\t1200.00\tSur" << endl;
        archivoSalida << "12\tImpresora\t2\t180.00\tEste" << endl;
        archivoSalida << "13\tMouse\t12\t25.00\tNorte" << endl;
        archivoSalida << "14\tWebcam\t5\t60.00\tCentro" << endl;
        archivoSalida << "15\tTeclado\t6\t45.00\tEste" << endl;
        archivoSalida << "16\tMonitor\t4\t250.00\tSur" << endl;
        archivoSalida << "17\tLaptop\t1\t1200.00\tEste" << endl;
        archivoSalida << "18\tImpresora\t3\t180.00\tCentro" << endl;
        archivoSalida << "19\tMouse\t8\t25.00\tEste" << endl;
        archivoSalida << "20\tWebcam\t7\t60.00\tSur" << endl;
        
        // Cerrar el archivo
        archivoSalida.close();
        
        cout << "Archivo 'empresa.txt' creado con éxito." << endl;
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }

    return 0;
}
