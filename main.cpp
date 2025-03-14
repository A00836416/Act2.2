/**
 * Programa que genera y ordena sufijos de un texto
 * Ordena alfabéticamente todos los sufijos e imprime sus posiciones originales
 * Autor: Harold Andres Lancheros Alvarez - A00836416
 * Fecha: 09/03/2025
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * Función principal que procesa la entrada, genera sufijos y los ordena
 * @return 0 si el programa termina correctamente
 */
int main()
{
    // Variable para almacenar el texto de entrada
    string textoEntrada;
    getline(cin, textoEntrada);

    // Crear vector de pares (sufijo, posición original)
    vector<pair<string, int> > vectorSufijos;
    for (int i = 0; i < textoEntrada.length(); i++)
    {
        vectorSufijos.push_back(make_pair(textoEntrada.substr(i), i + 1));
    }

    // Ordenar los sufijos alfabéticamente usando algoritmo bubble sort
    for (int i = 0; i < vectorSufijos.size() - 1; i++)
    {
        for (int j = 0; j < vectorSufijos.size() - i - 1; j++)
        {
            if (vectorSufijos[j].first > vectorSufijos[j + 1].first)
            {
                pair<string, int> pairAuxiliar = vectorSufijos[j];
                vectorSufijos[j] = vectorSufijos[j + 1];
                vectorSufijos[j + 1] = pairAuxiliar;
            }
        }
    }

    // Mostrar las posiciones originales de los sufijos ya ordenados
    for (const auto &sufijo : vectorSufijos)
    {
        cout << sufijo.second << endl;
    }

    return 0;
}