#include <iostream>
#include <string>
using namespace std;

int main() {
    int* array = nullptr; //Array vacio
    int tamany = 0;
    int num;

    while (1) {
        cout << "Entra un numero: ";
        cin >> num; //Analizo el numero que escribe el usuario

        int* newArray = new int[tamany + 1]; //Creo un nuevo array con un espacio más

        int i = 0;
       
        while (i < tamany && array[i] < num) {//
            newArray[i] = array[i];
            i++;
        }
        newArray[i] = num;

        for (int j = i; j < tamany; j++) {
            newArray[j + 1] = array[j];
        }
        delete[] array; //Elimino el antiguo

        array = newArray;
        tamany++;

        cout << "[";
        for (int k = 0; k < tamany; k++) {
            cout << array[k];
            if (k < tamany - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    delete[] array;
    return 0;
}

