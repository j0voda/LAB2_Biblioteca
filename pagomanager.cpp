#include "pagomanager.h"
#include <string.h>  // strlen ()
#include <ctype.h>   // isdigit()
#include <iostream>
#include <stdlib.h>

using namespace std;

PagoManager::PagoManager(){}

void PagoManager::listarPagosPorUsuario(){
    vector<Pago> pagos = _pagoArchivo.leerPorIdUsuario(_usuarioManager.clienteActivo().getId());
    for (const auto &pago : pagos) {
        mostrarPago(pago);
    }
}

void PagoManager::mostrarPago(const Pago &pago) {
    system("cls");
    cout << "-----------------------------" << endl;
    cout << "ID: " << pago.getIdPago() << endl;
    cout << "Nro Membresia: " << pago.getIdMembresia()<< endl;
    cout << "Monto: " << pago.getMonto()<< endl;
    cout << "Nro Tarjeta:  " << pago.getMetodoPago()<< endl;
    cout << "Fecha: " << pago.getFecha().toString() << endl;
	cout<<endl;
    cout << "-----------------------------" << endl;
    cin.ignore();
}

bool PagoManager::registrarPago(int idMembresia, float montoMembresia){
    float monto = 0;
    string metodoPago;
    string metodoPagoClave;
    Fecha fechaActual = Fecha::obtenerFechaActual();
    int idNuevo = _pagoArchivo.getCantidadRegistros() + 1;

    system("cls");
    cout << "-----------------------------" << endl;
	cout << "GENERAR PAGO" << endl;
	cout << "-----------------------------" << endl;

    bool valid = false;
    int digits = 0;
    do
    {
        cout << "Ingrese los 16 digitos de su tarjeta: ";
        getline(cin, metodoPago);
        cout<<endl;
        // Valido que el numero ingresado tenga 16 digitos
        if (!validarNumeroTarjeta(metodoPago))
        {
            cin.clear();
            cin.ignore();
            cout << "- Numero no valido - " << endl;
        }
        else
        {
            //El numero ingresado esta ok
            valid = true;
        }
    } while (!valid);

    bool valid2= false;
    int digits2 = 0;
    do
    {
        cout<<endl;
        cout << "Ingrese los 3 digitos del codigo de seguridad: ";
        getline(cin, metodoPagoClave);
        // Valido que el numero ingresado tenga 16 digitos
        if (!validarClaveTarjeta(metodoPagoClave))
        {
            cin.clear();
            cout << "- Ingrese un numero valido: " << endl;
        }
        else
        {
            //El numero ingresado esta ok
            valid2 = true;
        }
    } while (!valid2);

    Usuario logueado = _usuarioManager.clienteActivo();
    Pago nuevoPago(idNuevo, logueado.getId(), idMembresia, montoMembresia, fechaActual, metodoPago, metodoPagoClave);
    if (_pagoArchivo.guardar(nuevoPago)) {
        cout << endl;
        cout << "Pago agregado con exito." << endl;
        cin.ignore();
        return true;
    } else {
        cout << endl;
        cout << "Error al agregar el pago." << endl;
        cin.ignore();
        return false;
    }
}

bool PagoManager::validarNumeroTarjeta(const string &numeroTarjeta) {
    cout << numeroTarjeta << endl;
    cin.ignore();
    // 16 digitos
    int len = strlen(numeroTarjeta.c_str());
    cout << len << endl;
    if (len > 16 || len < 16)
        return false;

    // number to validate
    int number[16];
    for(int i = 0; i < len; i++) {
        if(!isdigit(numeroTarjeta[i]))
          return false;
        number[i] = numeroTarjeta[i] - '0';
    }
    return true;
}

bool PagoManager::validarClaveTarjeta(const string &claveTarjeta) {
    // 16 digitos
    int len = strlen(claveTarjeta.c_str());
    if (len > 3 || len < 3)
        return false;

    // number to validate
    int number[3];
    for(int i = 0; i < len; i++) {
        if(!isdigit(claveTarjeta[i]))
          return false;
        number[i] = claveTarjeta[i] - '0';
    }
    return true;
}
