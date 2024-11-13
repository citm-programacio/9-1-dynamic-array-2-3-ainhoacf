// DynamicArray.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
using namespace std;
class Candy {
public:
	string name;
	int num;
	Candy(string name, int num) : name(name), num(num) {}
};

class CandyShop {
private:
	Candy** candies; // Array de punteros a objetos Candy
	int candyCount;
	// Función para encontrar el índice de un caramelo en el array
	int findCandyIndex(const string& name) {
		for (int i = 0; i < candyCount; ++i) {
			if (candies[i]->name == name) {
				return i;
			}
		}
		return -1;
	}
	// Función para redimensionar el array cuando añadimos o eliminamos caramelos
	void resizeArray(int newSize) {
		Candy** newArray = new Candy * [newSize];
		for (int i = 0; i < candyCount && i < newSize; ++i) {
			newArray[i] = candies[i];
		}
		delete[] candies; // Liberamos el array original
		candies = newArray;
	}
public:
	CandyShop() : candies(nullptr), candyCount(0) {}
	~CandyShop() {
		for (int i = 0; i < candyCount; ++i) {
			delete candies[i];
		}
		delete[] candies;
	}
	void buyCandies(const string& name, int amount) {
		int index = findCandyIndex(name);
		if (index == -1) { // Si no existe el caramelo, lo añadimos
			resizeArray(candyCount + 1);
			candies[candyCount++] = new Candy(name, amount);
		}
		else { // Si existe, incrementamos la cantidad
			candies[index]->num += amount;
		}
	}
	void sellCandies(const string& name, int amount) {
		int index = findCandyIndex(name);
		if (index == -1) {
			cout << "El caramelo no existe en la tienda.\n";
			return;
		}
		if (candies[index]->num > amount) {
			// Reducimos la cantidad si es mayor que la vendida
			candies[index]->num -= amount;
		}
		else {
			// Si la cantidad vendida es igual o mayor, eliminamos el caramelo
			delete candies[index];
			for (int i = index; i < candyCount - 1; ++i) {
				candies[i] = candies[i + 1];
			}
			resizeArray(--candyCount);
		}
	}
	void showInventory() const {
		if (candyCount == 0) {
			cout << "La tienda está vacía.\n";
			return;
		}
		cout << "Inventario de la tienda:\n";
		for (int i = 0; i < candyCount; ++i) {
			cout << "- " << candies[i]->name << ": " << candies[i]->num << " unidades\n";
		}
	}
};
int main() {
	CandyShop shop;
	shop.buyCandies("Chocolates", 10);
	shop.buyCandies("Caramelos", 5);
	shop.showInventory();
	shop.sellCandies("Chocolates", 3);
	shop.showInventory();
	shop.sellCandies("Caramelos", 5);
	shop.showInventory();
	return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
