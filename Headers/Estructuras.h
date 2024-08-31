#pragma once
#include "Utilidades.h"

// STRUCTS
struct Jugador {
    string nombre;
    int vidas;
    int puntos;
    int x, y; // posición del jugador
    int dx, dy;
    bool invisible;
    bool pregunta_respondida;

    void dibujar() {
        if (invisible) {
            color_text(14);
            cursor(x, y);
            cout << " *";
            cursor(x, y + 1);
            cout << (char)205 << (char)186 << (char)205;
            cursor(x, y + 2);
            cout << "/ \\";
            color_text(1);
        }
        else {
            color_text(4);
            cursor(x, y);
            cout << " " << (char)220;
            cursor(x, y + 1);
            cout << (char)205 << (char)186 << (char)205;
            cursor(x, y + 2);
            cout << "/ \\";
            color_text(1);
        }
    }

    void mover() {
        x += dx;
        y += dy;
    }

    void borrar() {
        cursor(x, y);
        cout << "  ";
        cursor(x, y + 1);
        cout << "   ";
        cursor(x, y + 2);
        cout << "   ";
    }
};

struct Enemigo {
    int x, y;   // posición del enemigo
    int dx, dy; // movimiento del enemigo

    void dibujar() {
        color_text(1);
        cursor(x, y);
        cout << " -";
        cursor(x, y + 1);
        cout << "/÷\\";
        cursor(x, y + 2);
        cout << "<->";
        color_text(1);
    }

    void mover() {
        x += dx;
        y += dy;
    }

    void borrar() {
        cursor(x, y);
        cout << "  ";
        cursor(x, y + 1);
        cout << "   ";
        cursor(x, y + 2);
        cout << "   ";
    }
};

struct Tutor {
    int x, y; // posición del tutor
    bool activo;

    void dibujar() {
        color_text(8);
        cursor(x, y);
        cout << " ?";
        cursor(x, y + 1);
        cout << "-" << (char)206 << "-";
        cursor(x, y + 2);
        cout << "|" << (char)202 << "|";
        color_text(1);
    }

    void borrar() {
        cursor(x, y);
        cout << "  ";
        cursor(x, y + 1);
        cout << "   ";
        cursor(x, y + 2);
        cout << "   ";
    }
};

struct EstadoJuego {
    int dificultad;
    int segundos_cooldown;
    int segundos_pantalla;
    bool contador_activo;
    time_t tiempo_inicio;
    time_t tiempo_actual;

    void dibujar(Jugador& jugador) {
        color_text(3);
        cursor(62, 5);
        cout << "VIDAS: " << jugador.vidas;
        cursor(62, 7);
        cout << "PTOS: " << jugador.puntos;
        cursor(62, 9);
        cout << "DIFICULTAD: ";
        cursor(62, 10);
        if (dificultad == 0)
            cout << "PRINCIPIANTE";
        else if (dificultad == 1)
            cout << "INTERMEDIO";
        else if (dificultad == 2)
            cout << "AVANZADO";
        else if (dificultad == 3)
            cout << "MAXIMO";
        cursor(62, 12);
        cout << "COOLDOWN: " << segundos_pantalla;
        cursor(62, 14);
        cout << "MISION: LLEGA";
        cursor(62, 15);
        cout << "A LA PUERTA";

        color_text(1);
    }

    void borrar() {
        cursor(70, 5);
        cout << " ";
        cursor(70, 7);
        cout << "  ";
        cursor(64, 10);
        cout << "          ";
        cursor(64, 12);
        cout << "             ";
    }

    void iniciarContador() {
        contador_activo = true;
        tiempo_inicio = time(nullptr);
    }

    void actualizarContador() {
        if (contador_activo) {
            tiempo_actual = time(nullptr);
            int transcurrido = difftime(tiempo_actual, tiempo_inicio);
            int faltante = segundos_cooldown - transcurrido;
            if (transcurrido >= segundos_cooldown) {
                contador_activo = false; // Desactivar el contador
                segundos_cooldown = 30;
                segundos_pantalla = segundos_cooldown;
            }
            else {
                segundos_pantalla = faltante;
            }
        }
    }
};