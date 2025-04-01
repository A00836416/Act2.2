
/*
 * Programa que genera y ordena sufijos de un texto.
 * Ordena alfabéticamente todos los sufijos e imprime sus posiciones originales.
 * Copyright (C) 2024 Harold Andres Lancheros Alvarez
 * A00836416
 *
 * Este programa es software libre; puede redistribuirlo y/o
 * modificarlo bajo los términos de la Licencia Pública General Reducida GNU
 * tal como está publicada por la Free Software Foundation; ya sea
 * la versión 3 de la Licencia, o (a su elección) cualquier versión posterior.
 *
 * Este programa se distribuye con la esperanza de que sea útil,
 * pero SIN NINGUNA GARANTÍA; sin siquiera la garantía implícita de
 * COMERCIABILIDAD o IDONEIDAD PARA UN PROPÓSITO PARTICULAR. Consulte la GNU
 * Lesser General Public License para más detalles.
 *
 * Debería haber recibido una copia de la Licencia Pública General Reducida GNU
 * junto con este programa; si no es así, escriba a la Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
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
    vector<pair<string, int>> vectorSufijos;
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
