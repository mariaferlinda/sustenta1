
#include <iterator>
#include <iostream>
#include <string>
#include <sstream>
#include "Lista.h"
using namespace std;

void prepararArticulosPorDefecto();
void menu();
void cliente();
void coordinador();
Lista* articulos;

Lista* articulosCarrito;
int main()
{
	prepararArticulosPorDefecto();
	menu();
	return 0;
}

void prepararArticulosPorDefecto() {
	articulos = new Lista();
	//Agregar articulos por defecto
	Articulo* balon = new Articulo("Balon", 10, 1, 80000, 1);
	Articulo* raqueta = new Articulo("Raqueta", 30, 3, 90000, 1);
	Articulo* pc = new Articulo("PC", 20, 2, 100000, 2);
	Articulo* tablet = new Articulo("Tablet", 40, 4, 60000, 2);
	articulos->agregar(balon);
	articulos->agregar(pc);
	articulos->agregar(raqueta);
	articulos->agregar(tablet);

}





void menu() {
	int opc;
	do {
		cout << "\t.:MENU:.\n";
		cout << "Seleccione su rol:.\n";
		cout << "1. coordinador.\n";
		cout << "2. cliente\n";
		cout << "3. salir \n";
		cout << " opcion:  \n";
		cin >> opc;

		switch (opc)
		{
		case 1:
			coordinador();
			break;

		case 2:
			cliente();
			break;
		}

	} while (opc != 3);

}



void cliente() {
	int opc, opcPagar;
	int art, cant;
	articulosCarrito = new Lista();
	do {
		cout << "seleccione que desea hacer.\n";
		cout << "1. comprar articulo.\n";
		cout << "2. pagar articulos.\n";
		cout << "3. salir.\n";
		cin >> opc;
		switch (opc) {
		case 1:
			articulos->imprimir(0);
			cout << "ingrese el Id del articulo a comprar: ";
			cin >> art;
			Articulo* existente;
			existente = articulos->obtener(art);
			if (existente->id > 0)
			{
				cout << "ingrese la cantidad a comprar: ";
				cin >> cant;
				existente->cantidad = cant;
				if (articulosCarrito->existe(existente->id))
				{
					articulosCarrito->actualizar(existente);
				}
				else {
					articulosCarrito->agregar(existente);
				}
				cout << "Carrito de compras actualizado. \n";
			}
			else {
				cout << "No existe un articulo con Id : " << to_string(art) << std::endl;
			}
			break;
		case 2:
			if (!articulosCarrito->esVacia())
			{
				articulosCarrito->imprimirTotal();

				cout << "Desea pagar o cancelar la compra\n";
				cout << "1. Pagar.\n";
				cout << "2. Cancelar.\n";
				cin >> opcPagar;

				switch (opcPagar)
				{
				case 1:
					cout << "Pago exitoso \n";
					break;
				case 2:
					cout << "Compra cancelada \n";
					break;

				default: break;
				}
				articulosCarrito = new Lista();
			}
			else {
				cout << "No tiene articulos en el carrito de compras " << std::endl;
			}
			break;
		}

	} while (opc != 3);

}


void coordinador() {
	int numero;
	int x, n, atributo;
	int id, precio, cantidad, tipo;
	string nombre;

	do {
		cout << "seleccione que desea hacer.\n";
		cout << "1. agregar articulo.\n";
		cout << "2. modificar articulo.\n";
		cout << "3. eliminar articulo.\n";
		cout << "4. salir \n";
		cin >> numero;

		switch (numero)
		{
		case 1:
			cout << "de qué seccion desea agregar un articulo\n";
			cout << "1. deportes.\n";
			cout << "2. tecnologico.\n";
			cin >> tipo;

			cout << "ingrese el id del articulo: \n";
			cin >> id;
			cout << "ingrese el nombre del articulo: \n";
			cin >> nombre;
			cout << "ingrese el precio del articulo: \n";
			cin >> precio;
			cout << "ingrese la cantidad del articulo: \n";
			cin >> cantidad;
			Articulo* nuevo;
			nuevo = new Articulo(nombre, cantidad, id, precio, tipo);
			if (articulos->agregar(nuevo)) {
				cout << "Articulo insertado satisfactoriamente: \n";
			}
			break;

		case 2:
			cout << "de qué sección desea modificar un articulo\n";
			cout << "1. deportes.\n";
			cout << "2. tecnologico.\n";
			cin >> x;
			articulos->imprimir(x);
			cout << "ingrese el id del articulo a modificar: ";
			cin >> n;
			Articulo* existente;
			existente = articulos->obtener(n);
			if (existente->id > 0)
			{
				do {
					cout << "Ingrese el atributo a modificar\n";
					cout << "1. Nombre.\n";
					cout << "2. Precio.\n";
					cout << "3. Cantidad.\n";
					cout << "4. Tipo.\n";
					cout << "5. Salir\n";
					cin >> atributo;

					switch (atributo)
					{
					case 1:
						cout << "ingrese el nuevo nombre del articulo: \n";
						cin >> nombre;
						existente->nombre = nombre;
						break;
					case 2:
						cout << "ingrese el nuevo precio del articulo: \n";
						cin >> precio;
						existente->precio = precio;
						break;
					case 3:
						cout << "ingrese el nuevo cantidad del articulo: \n";
						cin >> cantidad;
						existente->cantidad = cantidad;
						break;
					case 4:
						cout << "ingrese el nuevo tipo del articulo: 1 -> Deportivo; 2 -> Tecnologico \n";
						cin >> tipo;
						existente->tipo = tipo;
						break;
					default: break;
					}
					if (atributo < 5)
					{
						if (articulos->actualizar(existente)) {
							cout << "Articulo actualizado satisfactoriamente: \n";
						}
					}

				} while (atributo != 5);
			}
			else {
				cout << "No existe un articulo con Id : " << to_string(n) << std::endl;
			}
			break;
		case 3:
			cout << "de qu� seccion desea eliminar un articulo\n";
			cout << "1. deportes.\n";
			cout << "2. tecnologico.\n";
			cin >> x;
			articulos->imprimir(x);

			cout << "ingrese el id del articulo a eliminar: ";
			cin >> n;
			if (articulos->eliminar(n)) {
				cout << "Articulo eliminado satisfactoriamente: \n";
			}
			break;

		default:
			break;
		}
	} while (numero != 4);

}
