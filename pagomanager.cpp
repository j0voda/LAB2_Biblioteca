#include "pagomanager.h"

PagoManager::PagoManager(){}

void PagoManager::listarPagosPorUsuario(){
    vector<Pago> pagos = _pagoArchivo.leerPorIdUsuario(_usuarioManager.clienteActivo().getId());
    for (const auto &pago : pagos) {
        mostrarPago(pago);
    }
}

void PagoManager::mostrarPago(const Pago &pago) {
    cout << "-----------------------------" << endl;
	cout<<endl;
    cout << "ID: " << pago.getIdPago() << endl;
    cout << "Nro Membresia: " << pago.getIdMembresia()<< endl;
    cout << "Monto: " << pago.getMonto()<< endl;
    cout << "Nro Tarjeta:  " << pago.getMetodoPago()<< endl;
    cout << "Fecha: " << pago.getFecha().toString() << endl;
	cout<<endl;
    cout << "-----------------------------" << endl;
}

bool PagoManager::registrarPago(int idMembresia, float montoMembresia){
    float monto = 0;
    int metodoPago, metodoPagoClave = 0;
    Fecha fechaActual = Fecha::obtenerFechaActual();
    int idNuevo = _pagoArchivo.getCantidadRegistros() + 1;

    system("cls");
    cout << "-----------------------------" << endl;
	cout << "GENERAR PAGO" << endl;
	cout << "-----------------------------" << endl;

    cout << "Ingrese los 16 digitos de su tarjeta: ";
    cin >> metodoPago;
    cout<<endl;

    // Valido que el numero ingresado tenga 16 digitos
    int digits = 0;
    if (metodoPago <= 0) digits = 1;
    while (metodoPago) {
        metodoPago /= 10;
        digits++;
    }
    while(digits != 16){
        cout << "-- Ingrese un numero valido: ";
        cin >> metodoPago;
        cout<<endl;
    }

	cout<<endl;
    cout << "Ingrese los 3 digitos del codigo de seguridad: ";
    cin >> metodoPagoClave;
    cin.ignore();

    // Valido que el numero ingresado tenga 3 digitos
    int digits2 = 0;
    if (metodoPagoClave <= 0) digits2 = 1;
    while (metodoPagoClave) {
        metodoPagoClave /= 10;
        digits2++;
    }
    while (metodoPagoClave != 3) {
		cout << "-- Ingrese un numero valido: ";
		cin >> metodoPagoClave;
		cin.ignore();
	}

    Pago nuevoPago(idNuevo, _usuarioManager.clienteActivo().getId(), idMembresia, montoMembresia, fechaActual, metodoPago, metodoPagoClave);

    if (_pagoArchivo.guardar(nuevoPago)) {
        cout << endl;
        cout << "Pago agregado con exito." << endl;
        return true;
    } else {
        cout << endl;
        cout << "Error al agregar el pago." << endl;
        return false;
    }
}
