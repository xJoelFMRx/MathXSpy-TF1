#pragma once
#include "Utilidades.h"

// LOGICA PARA EL RANKING
int calcular_puntaje_pregunta(int num_intento) {
    int pts = 0;
    if (num_intento == 1) {
        pts = 3;
    }
    else if (num_intento == 2) {
        pts = 2;
    }
    else if (num_intento == 3) {
        pts = 1;
    }

    return pts;
}

void ordenar(string** ranking, int numJugadores) {
    for (int i = 0; i < numJugadores - 1; ++i) {
        for (int j = 0; j < numJugadores - i - 1; ++j) {
            if (stoi(ranking[j][1]) < stoi(ranking[j + 1][1])) {
                // Intercambiar los jugadores
                string tempNombre = ranking[j][0];
                string tempPts = ranking[j][1];
                ranking[j][0] = ranking[j + 1][0];
                ranking[j][1] = ranking[j + 1][1];
                ranking[j + 1][0] = tempNombre;
                ranking[j + 1][1] = tempPts;
            }
        }
    }
}

void agregar_ranking(int& numJugadores, string**& ranking, string nombre, int pts) {
    // Crear un nuevo array con tamaño incrementado
    string** nuevoRanking = new string * [numJugadores + 1];
    for (int i = 0; i < numJugadores + 1; ++i) {
        nuevoRanking[i] = new string[2];
    }

    // Copiar el contenido del ranking actual al nuevo ranking
    for (int i = 0; i < numJugadores; ++i) {
        nuevoRanking[i][0] = ranking[i][0];
        nuevoRanking[i][1] = ranking[i][1];
    }

    // Agregar el nuevo jugador al final
    nuevoRanking[numJugadores][0] = nombre;
    nuevoRanking[numJugadores][1] = to_string(pts);

    // Liberar la memoria del ranking anterior
    for (int i = 0; i < numJugadores; ++i) {
        delete[] ranking[i];
    }
    delete[] ranking;

    // Asignar el nuevo ranking y aumentar el número de jugadores
    ranking = nuevoRanking;
    numJugadores++;
}

void puntaje_ranking(string** ranking, int numJugadores, int x, int y) {
    system("cls");
    int mostrar = numJugadores > 5 ? 5 : numJugadores;

    ordenar(ranking, numJugadores);
    cursor(x, y);
    cout << R"(
   888888ba                    dP       oo                   
   88    `8b                   88                            
  a88aaaa8P' .d8888b. 88d888b. 88  .dP  dP 88d888b. .d8888b. 
   88   `8b. 88'  `88 88'  `88 88888"   88 88'  `88 88'  `88 
   88     88 88.  .88 88    88 88  `8b. 88 88    88 88.  .88 
   dP     dP `88888P8 dP    dP dP   `YP dP dP    dP `8888P88 
                                                         .88 
                                                     d8888P  
)";
    y += 11;
    for (int i = 0; i < mostrar; i++) {
        cursor(x + 10, y + i * 2);
        cout << i + 1 << ". " << ranking[i][0] << ": " << ranking[i][1] << " pts." << endl;
    }
}