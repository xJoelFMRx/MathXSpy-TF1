#pragma once
#include "Estructuras.h"
#include "Graficos.h"
#include "Utilidades.h"
#include "Ranking.h"
#include "Tutores.h"
#include "Preguntas.h"

// LOGICA PRINCIPAL
// MUNDO 1
void mundo1_escenario1(Jugador& jugador) {
    jugador.invisible = false;
    jugador.pregunta_respondida = false;
    jugador.x = 6;
    jugador.y = 26;

    EstadoJuego estado = { 0, 30, 30, false, 0, 0 };
    // X - Y - DX - DY
    Enemigo enemigos[3] = { {4, 13, 1, 0}, {22, 13, 1, 0}, {48, 3, 0, 1} };
    // X - Y - TUTOR_ACTIVO
    Tutor tutor = { 14, 25, false };

    char tec = '0';

    while (!jugador.pregunta_respondida && jugador.vidas > 0) {
        system("cls");
        jugador.invisible = false;
        jugador.x = 6;
        jugador.y = 26;
        color(1);
        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < 60; j++) {
                color(m1_esc1[i][j]);
                cursor(j, i);
                cout << " ";
            }
        }
        color(1);

        imp_mundo_actual(1, 1);

        while (!((jugador.x <= 54 && jugador.x >= 51) &&
            (jugador.y >= 2 && jugador.y <= 6)) &&
            jugador.vidas > 0) {
            color(3);
            Console::ForegroundColor = ConsoleColor::Black;

            jugador.borrar();

            // Borrado enemigos
            for (int i = 0; i < 3; i++) {
                enemigos[i].borrar();
            }

            // Borrado tutor
            tutor.borrar();

            color(1);
            // Borrado de la tabla de información
            estado.borrar();
            color(3);

            if (_kbhit()) {
                tec = _getch();
                if (tec == 72)
                    jugador.y--; // Arriba
                if (tec == 75)
                    jugador.x--; // Izquierda
                if (tec == 77)
                    jugador.x++; // Derecha
                if (tec == 80)
                    jugador.y++; // Abajo
                if ((tec == 'A' || tec == 'a') && !estado.contador_activo) {
                    jugador.invisible = true;
                    estado.iniciarContador();
                }
            }

            // Contador cooldown - invisible
            if (estado.contador_activo) {
                estado.actualizarContador();
                if (estado.segundos_pantalla == 25) {
                    jugador.invisible = false;
                }
            }

            // Acercamiento tutor - indicaciones
            if (jugador.x >= tutor.x - 3 && jugador.x <= tutor.x + 3 &&
                jugador.y == tutor.y) {
                tutor.activo = true;
                jugador.x = 6;
                jugador.y = 26;
                color(1);
                tutor_mostrar(1, 1);
                color(1);
                tutor.activo = false;
                break;
            }

            // Limites enemigos
            if (enemigos[0].x <= 3 || enemigos[0].x >= 14)
                enemigos[0].dx *= -1;
            if (enemigos[1].x <= 21 || enemigos[1].x >= 30)
                enemigos[1].dx *= -1;
            if (enemigos[2].y <= 2 || enemigos[2].y >= 13)
                enemigos[2].dy *= -1;

            // Movimiento de enemigos
            for (int i = 0; i < 3; i++) {
                enemigos[i].mover();
            }

            // Límites del personaje principal
            if (jugador.x > 60 - 6)
                jugador.x = 60 - 6; // Derecha
            if (jugador.x < 3)
                jugador.x = 3; // Izquierda
            if (jugador.y > 30 - 5)
                jugador.y = 30 - 5; // Abajo
            if (jugador.y < 2)
                jugador.y = 2; // Arriba

            // Colisiones con barreras
            // Barrera 1
            if ((jugador.y >= 4 && jugador.y <= 27) && (jugador.x == 15)) {
                jugador.x--;
            }
            if ((jugador.x >= 15 && jugador.x <= 20) && (jugador.y == 4)) {
                jugador.y--;
            }
            if ((jugador.y >= 4 && jugador.y <= 27) && (jugador.x == 20)) {
                jugador.x++;
            }

            // Barrera 2
            if ((jugador.y >= 2 && jugador.y <= 23) && (jugador.x == 32)) {
                jugador.x--;
            }
            if ((jugador.x >= 33 && jugador.x <= 46) && (jugador.y == 23)) {
                jugador.y++;
            }
            if ((jugador.y >= 20 && jugador.y <= 23) && (jugador.x == 46)) {
                jugador.x++;
            }
            if ((jugador.x >= 38 && jugador.x <= 46) && (jugador.y == 20)) {
                jugador.y--;
            }
            if ((jugador.y >= 12 && jugador.y <= 19) && (jugador.x == 37)) {
                jugador.x++;
            }
            if ((jugador.x >= 38 && jugador.x <= 46) && (jugador.y == 11)) {
                jugador.y++;
            }
            if ((jugador.y >= 2 && jugador.y <= 11) && (jugador.x == 46)) {
                jugador.x++;
            }

            // Barrera 3
            if ((jugador.x >= 45 && jugador.x <= 56) && (jugador.y == 17)) {
                jugador.y++;
            }
            if ((jugador.y >= 14 && jugador.y <= 17) && (jugador.x == 45)) {
                jugador.x--;
            }
            if ((jugador.x >= 45 && jugador.x <= 56) && (jugador.y == 14)) {
                jugador.y--;
            }

            // Barrera tutor
            if ((jugador.y >= 23 && jugador.y <= 27) && (jugador.x == 11)) {
                jugador.x--;
            }
            if ((jugador.x >= 12 && jugador.x <= 16) && (jugador.y == 23)) {
                jugador.y--;
            }

            // Colisiones con enemigos
            for (int i = 0; i < 3; i++) {
                if ((jugador.x <= enemigos[i].x + 2 && jugador.x >= enemigos[i].x - 2) &&
                    (jugador.y <= enemigos[i].y + 2 &&
                        jugador.y >= enemigos[i].y - 2) &&
                    !jugador.invisible) {
                    jugador.x = 9;
                    jugador.y = 26;
                    jugador.vidas--;
                }
            }

            // Dibujar información del juego
            color(1);
            Console::ForegroundColor = ConsoleColor::Cyan;
            estado.dibujar(jugador);
            color(3);
            Console::ForegroundColor = ConsoleColor::Black;

            // Dibujar personajes y enemigos
            jugador.dibujar();
            for (int i = 0; i < 3; i++) {
                enemigos[i].dibujar();
            }
            tutor.dibujar();
            _sleep(60);
        }

        // Preguntas y respuestas
        color(1);
        int numero_intentos = 1;
        while (!jugador.pregunta_respondida && numero_intentos <= 2 && jugador.vidas > 0 && ((jugador.x <= 54 && jugador.x >= 51) && (jugador.y >= 2 && jugador.y <= 6))) {
            system("cls");
            Console::ForegroundColor = ConsoleColor::Cyan;
            int pregunta_respuesta = pregunta(1, 1);
            int res = 0;
            cursor(10, 36);
            cout << "Ingrese la respuesta: ";
            cin >> res;
            if (res == pregunta_respuesta) {
                jugador.pregunta_respondida = true;
                cursor(20, 38);
                cout << "PUERTA DESBLOQUEADA";
                _sleep(500);
                animacion_puerta(6, 36, 19);
                jugador.puntos += calcular_puntaje_pregunta(numero_intentos);
                _sleep(1000);
                break; // FIN DEL ESCENARIO
            }
            else {
                numero_intentos++;
            }
        }
    }
}

void mundo1_escenario2(Jugador& jugador) {
    jugador.pregunta_respondida = false;
    jugador.invisible = false;
    jugador.x = 3;
    jugador.y = 2;

    // dificultad - seg_cooldown - seg_pantalla - cont_activo - t_inicio -
    // t_actual
    EstadoJuego estado = { 1, 30, 30, false, 0, 0 };
    // X - Y - DX - DY
    Enemigo enemigos[3] = { {4, 13, 1, 0}, {22, 13, 1, 0}, {48, 3, 0, 1} };
    // X - Y - TUTOR_ACTIVO
    Tutor tutor = { 11, 2, false };

    char tec = '0';

    while (!jugador.pregunta_respondida && jugador.vidas > 0) {
        system("cls");
        jugador.invisible = false;
        jugador.x = 3;
        jugador.y = 2;
        color(1);
        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < 60; j++) {
                color(m1_esc2[i][j]);
                cursor(j, i);
                cout << " ";
            }
        }
        color(1);

        imp_mundo_actual(1, 2);

        while (!((jugador.x <= 34 && jugador.x >= 31) &&
            (jugador.y >= 2 && jugador.y <= 4)) &&
            jugador.vidas > 0) {
            color(11);
            Console::ForegroundColor = ConsoleColor::Black;

            jugador.borrar();

            // Borrado enemigos
            for (int i = 0; i < 3; i++) {
                enemigos[i].borrar();
            }

            // Borrado tutor
            tutor.borrar();

            color(1);
            // Borrado de la tabla de información
            estado.borrar();
            color(11);

            if (_kbhit()) {
                tec = _getch();
                if (tec == 72)
                    jugador.y--; // Arriba
                if (tec == 75)
                    jugador.x--; // Izquierda
                if (tec == 77)
                    jugador.x++; // Derecha
                if (tec == 80)
                    jugador.y++; // Abajo
                if ((tec == 'A' || tec == 'a') && !estado.contador_activo) {
                    jugador.invisible = true;
                    estado.iniciarContador();
                }
            }

            // Contador cooldown - invisible
            if (estado.contador_activo) {
                estado.actualizarContador();
                if (estado.segundos_pantalla == 25) {
                    jugador.invisible = false;
                }
            }

            // Acercamiento tutor - indicaciones
            if (jugador.x >= tutor.x - 3 && jugador.x <= tutor.x + 3 &&
                jugador.y == tutor.y) {
                tutor.activo = true;
                jugador.x = 6;
                jugador.y = 26;
                color(1);
                color_text(3);
                tutor_mostrar(1, 2);
                color_text(3);
                color(1);
                tutor.activo = false;
                break;
            }

            // Limites enemigos
            if (enemigos[0].x <= 3 || enemigos[0].x >= 11)
                enemigos[0].dx *= -1;
            if (enemigos[1].x <= 20 || enemigos[1].x >= 26)
                enemigos[1].dx *= -1;
            if (enemigos[2].y <= 2 || enemigos[2].y >= 9)
                enemigos[2].dy *= -1;

            // Movimiento de enemigos
            for (int i = 0; i < 3; i++) {
                enemigos[i].mover();
            }

            // Límites del personaje principal
            if (jugador.x > 60 - 6)
                jugador.x = 60 - 6; // Derecha
            if (jugador.x < 3)
                jugador.x = 3; // Izquierda
            if (jugador.y > 30 - 5)
                jugador.y = 30 - 5; // Abajo
            if (jugador.y < 2)
                jugador.y = 2; // Arriba

            // Colisiones con barreras
            // Barrera 1
            if ((jugador.y >= 2 && jugador.y <= 23) && (jugador.x == 12)) {
                jugador.x--;
            }
            if ((jugador.x >= 13 && jugador.x <= 44) && (jugador.y == 23)) {
                jugador.y++;
            }
            if ((jugador.x >= 20 && jugador.x <= 44) && (jugador.y == 19)) {
                jugador.y--;
            }
            if ((jugador.y >= 2 && jugador.y <= 18) && (jugador.x == 19)) {
                jugador.x++;
            }
            if ((jugador.y >= 19 && jugador.y <= 23) && (jugador.x == 44)) {
                jugador.x++;
            }

            if ((jugador.x >= 20 && jugador.x <= 45) && (jugador.y == 7)) {
                jugador.y++;
            }
            if ((jugador.x >= 20 && jugador.x <= 45) && (jugador.y == 3)) {
                jugador.y--;
            }
            if ((jugador.y >= 3 && jugador.y <= 7) && (jugador.x == 45)) {
                jugador.x++;
            }

            // Barrera 2
            if ((jugador.x >= 27 && jugador.x <= 56) && (jugador.y == 15)) {
                jugador.y++;
            }
            if ((jugador.x >= 27 && jugador.x <= 56) && (jugador.y == 10)) {
                jugador.y--;
            }
            if ((jugador.y >= 10 && jugador.y <= 16) && (jugador.x == 27)) {
                jugador.x--;
            }

            // Barrera tutor
            if (jugador.y >= tutor.y - 2 && jugador.y <= tutor.y + 2 &&
                jugador.x == tutor.x - 2) {
                jugador.x--;
            }
            if (jugador.y >= tutor.y - 2 && jugador.y <= tutor.y + 2 &&
                jugador.x == tutor.x + 2) {
                jugador.x++;
            }
            if (jugador.x >= tutor.x - 2 && jugador.x <= tutor.x + 2 &&
                jugador.y == tutor.y - 2) {
                jugador.y--;
            }
            if (jugador.x >= tutor.x - 2 && jugador.x <= tutor.x + 2 &&
                jugador.y == tutor.y + 2) {
                jugador.y++;
            }

            // Colisiones con enemigos
            for (int i = 0; i < 3; i++) {
                if ((jugador.x <= enemigos[i].x + 2 && jugador.x >= enemigos[i].x - 2) &&
                    (jugador.y <= enemigos[i].y + 2 &&
                        jugador.y >= enemigos[i].y - 2) &&
                    !jugador.invisible) {
                    jugador.x = 3;
                    jugador.y = 2;
                    jugador.vidas--;
                }
            }

            // Dibujar información del juego
            color(1);
            Console::ForegroundColor = ConsoleColor::Cyan;
            estado.dibujar(jugador);
            color(11);
            Console::ForegroundColor = ConsoleColor::Black;

            // Dibujar personajes y enemigos
            jugador.dibujar();
            for (int i = 0; i < 3; i++) {
                enemigos[i].dibujar();
            }
            tutor.dibujar();
            _sleep(60);
        }

        // Preguntas y respuestas
        color(1);
        int numero_intentos = 1;
        while (!jugador.pregunta_respondida && numero_intentos <= 2 &&
            jugador.vidas > 0 &&
            ((jugador.x <= 34 && jugador.x >= 31) &&
                (jugador.y >= 2 && jugador.y <= 4))) {
            system("cls");
            Console::ForegroundColor = ConsoleColor::Cyan;
            int pregunta_respuesta = pregunta(1, 2);
            int res = 0;
            cursor(10, 35);
            cout << "Ingrese la respuesta: ";
            cin >> res;
            if (res == pregunta_respuesta) {
                jugador.pregunta_respondida = true;
                cursor(20, 37);
                cout << "PUERTA DESBLOQUEADA";
                _sleep(500);
                animacion_puerta(8, 36, 19);
                jugador.puntos += calcular_puntaje_pregunta(numero_intentos);
                _sleep(1000);
                break; // FIN DEL ESCENARIO
            }
            else {
                numero_intentos++;
            }
        }
    }
}

void mundo1_escenario3(Jugador& jugador) {
    jugador.invisible = false;
    jugador.pregunta_respondida = false;
    jugador.x = 3;
    jugador.y = 2;

    // dificultad - seg_cooldown - seg_pantalla - cont_activo - t_inicio -
    // t_actual
    EstadoJuego estado = { 2, 30, 30, false, 0, 0 };
    // X - Y - DX - DY
    Enemigo enemigos[2] = { {10, 5, 0, 1}, {29, 11, 0, 1} };
    // X - Y - TUTOR_ACTIVO
    Tutor tutor = { 3, 25, false };

    char tec = '0';

    while (!jugador.pregunta_respondida && jugador.vidas > 0) {
        system("cls");
        jugador.invisible = false;
        jugador.x = 28;
        jugador.y = 25;
        color(1);
        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < 60; j++) {
                color(m1_esc3[i][j]);
                cursor(j, i);
                cout << " ";
            }
        }
        color(1);

        imp_mundo_actual(1, 3);

        while (!((jugador.x >= 3 && jugador.x <= 7) &&
            (jugador.y >= 13 && jugador.y <= 18)) &&
            jugador.vidas > 0) {
            color(12);
            Console::ForegroundColor = ConsoleColor::Black;

            jugador.borrar();

            // Borrado enemigos
            for (int i = 0; i < 2; i++) {
                enemigos[i].borrar();
            }

            // Borrado tutor
            tutor.borrar();

            color(1);
            // Borrado de la tabla de información
            estado.borrar();
            color(12);

            if (_kbhit()) {
                tec = _getch();
                if (tec == 72)
                    jugador.y--; // Arriba
                if (tec == 75)
                    jugador.x--; // Izquierda
                if (tec == 77)
                    jugador.x++; // Derecha
                if (tec == 80)
                    jugador.y++; // Abajo
                if ((tec == 'A' || tec == 'a') && !estado.contador_activo) {
                    jugador.invisible = true;
                    estado.iniciarContador();
                }
            }

            // Contador cooldown - invisible
            if (estado.contador_activo) {
                estado.actualizarContador();
                if (estado.segundos_pantalla == 25) {
                    jugador.invisible = false;
                }
            }

            // Acercamiento tutor - indicaciones
            if (jugador.x >= tutor.x - 3 && jugador.x <= tutor.x + 3 &&
                jugador.y == tutor.y) {
                tutor.activo = true;
                jugador.x = 28;
                jugador.y = 25;
                color(1);
                color_text(3);
                tutor_mostrar(1, 3);
                color_text(3);
                color(1);
                tutor.activo = false;
                break;
            }

            // Limites enemigos
            if (enemigos[0].y <= 2 || enemigos[0].y >= 14)
                enemigos[0].dy *= -1;
            if (enemigos[1].y <= 10 || enemigos[1].y >= 20)
                enemigos[1].dy *= -1;

            // Movimiento de enemigos
            for (int i = 0; i < 2; i++) {
                enemigos[i].mover();
            }

            // Límites del personaje principal
            if (jugador.x > 60 - 6)
                jugador.x = 60 - 6; // Derecha
            if (jugador.x < 3)
                jugador.x = 3; // Izquierda
            if (jugador.y > 30 - 5)
                jugador.y = 30 - 5; // Abajo
            if (jugador.y < 2)
                jugador.y = 2; // Arriba

            // Colisiones con barreras
            // Barrera 1
            if ((jugador.y >= 6 && jugador.y <= 16) && (jugador.x == 11)) {
                jugador.x--;
            }
            if ((jugador.x >= 3 && jugador.x <= 25) && (jugador.y == 19)) {
                jugador.y++;
            }
            if ((jugador.x >= 3 && jugador.x <= 12) && (jugador.y == 17)) {
                jugador.y--;
            }
            if ((jugador.y >= 10 && jugador.y <= 19) && (jugador.x == 25)) {
                jugador.x++;
            }
            if ((jugador.x >= 26 && jugador.x <= 44) && (jugador.y == 9)) {
                jugador.y++;
            }
            if ((jugador.x >= 11 && jugador.x <= 44) && (jugador.y == 6)) {
                jugador.y--;
            }
            if ((jugador.y >= 6 && jugador.y <= 9) && (jugador.x == 44)) {
                jugador.x++;
            }


            // Barrera 2
            if ((jugador.x >= 35 && jugador.x <= 56) && (jugador.y == 18)) {
                jugador.y++;
            }
            if ((jugador.x >= 35 && jugador.x <= 56) && (jugador.y == 12)) {
                jugador.y--;
            }
            if ((jugador.y >= 12 && jugador.y <= 18) && (jugador.x == 35)) {
                jugador.x--;
            }

            // Barrera 3
            if ((jugador.x >= 10 && jugador.x <= 47) && (jugador.y == 24)) {
                jugador.y++;
            }
            if ((jugador.x >= 10 && jugador.x <= 47) && (jugador.y == 21)) {
                jugador.y--;
            }
            if ((jugador.y >= 21 && jugador.y <= 24) && (jugador.x == 10)) {
                jugador.x--;
            }
            if ((jugador.y >= 21 && jugador.y <= 24) && (jugador.x == 47)) {
                jugador.x++;
            }

            // Barrera tutor
            if (jugador.y >= tutor.y - 2 && jugador.y <= tutor.y + 2 &&
                jugador.x == tutor.x - 2) {
                jugador.x--;
            }
            if (jugador.y >= tutor.y - 2 && jugador.y <= tutor.y + 2 &&
                jugador.x == tutor.x + 2) {
                jugador.x++;
            }
            if (jugador.x >= tutor.x - 2 && jugador.x <= tutor.x + 2 &&
                jugador.y == tutor.y - 2) {
                jugador.y--;
            }
            if (jugador.x >= tutor.x - 2 && jugador.x <= tutor.x + 2 &&
                jugador.y == tutor.y + 2) {
                jugador.y++;
            }

            // Colisiones con enemigos
            for (int i = 0; i < 2; i++) {
                if ((jugador.x <= enemigos[i].x + 2 && jugador.x >= enemigos[i].x - 2) &&
                    (jugador.y <= enemigos[i].y + 2 &&
                        jugador.y >= enemigos[i].y - 2) &&
                    !jugador.invisible) {
                    jugador.x = 28;
                    jugador.y = 25;
                    jugador.vidas--;
                }
            }

            // Dibujar información del juego
            color(1);
            Console::ForegroundColor = ConsoleColor::Cyan;
            estado.dibujar(jugador);
            color(12);
            Console::ForegroundColor = ConsoleColor::Black;

            // Dibujar personajes y enemigos
            jugador.dibujar();
            for (int i = 0; i < 2; i++) {
                enemigos[i].dibujar();
            }
            tutor.dibujar();
            _sleep(60);
        }

        // Preguntas y respuestas
        color(1);
        int numero_intentos = 1;
        while (!jugador.pregunta_respondida && numero_intentos <= 3 && jugador.vidas > 0 && ((jugador.x >= 3 && jugador.x <= 7) && (jugador.y >= 13 && jugador.y <= 18))) {
            system("cls");
            Console::ForegroundColor = ConsoleColor::Cyan;
            int pregunta_respuesta = pregunta(1, 3);
            int res = 0;
            cursor(10, 36);
            cout << "Ingrese la respuesta: ";
            cin >> res;
            if (res == pregunta_respuesta) {
                jugador.pregunta_respondida = true;
                cursor(20, 38);
                cout << "PUERTA DESBLOQUEADA";
                _sleep(500);
                animacion_puerta(2, 36, 19);
                jugador.puntos += calcular_puntaje_pregunta(numero_intentos);
                _sleep(1000);
                break; // FIN DEL ESCENARIO
            }
            else {
                numero_intentos++;
            }
        }
        if (numero_intentos == 4) {
            jugador.vidas = 0;
            break;
        }
    }
}

// MUNDO 2
void mundo2_escenario1(Jugador& jugador) {
    jugador.invisible = false;
    jugador.pregunta_respondida = false;
    jugador.x = 3;
    jugador.y = 2;

    // dificultad - seg_cooldown - seg_pantalla - cont_activo - t_inicio - t_actual
    EstadoJuego estado = { 0, 30, 30, false, 0, 0 };
    // X - Y - DX - DY
    Enemigo enemigos[2] = { {4, 15, 1, 0}, {45, 15, 1, 0} };
    // X - Y - TUTOR_ACTIVO
    Tutor tutor = { 13, 2, false };

    char tec = '0';

    while (!jugador.pregunta_respondida && jugador.vidas > 0) {
        system("cls");
        jugador.invisible = false;
        jugador.x = 3;
        jugador.y = 2;
        color(1);
        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < 60; j++) {
                color(m2_esc1[i][j]);
                cursor(j, i);
                cout << " ";
            }
        }
        color(1);

        imp_mundo_actual(2, 1);

        while (!((jugador.x >= 52 && jugador.x <= 56) && (jugador.y >= 2 && jugador.y <= 10)) && jugador.vidas > 0) {
            color(12);
            Console::ForegroundColor = ConsoleColor::Black;

            jugador.borrar();

            // Borrado enemigos
            for (int i = 0; i < 2; i++) {
                enemigos[i].borrar();
            }

            // Borrado tutor
            tutor.borrar();

            color(1);
            // Borrado de la tabla de información
            estado.borrar();
            color(12);

            if (_kbhit()) {
                tec = _getch();
                if (tec == 72)
                    jugador.y--; // Arriba
                if (tec == 75)
                    jugador.x--; // Izquierda
                if (tec == 77)
                    jugador.x++; // Derecha
                if (tec == 80)
                    jugador.y++; // Abajo
                if ((tec == 'A' || tec == 'a') && !estado.contador_activo) {
                    jugador.invisible = true;
                    estado.iniciarContador();
                }
            }

            // Contador cooldown - invisible
            if (estado.contador_activo) {
                estado.actualizarContador();
                if (estado.segundos_pantalla == 25) {
                    jugador.invisible = false;
                }
            }

            // Acercamiento tutor - indicaciones
            if (jugador.x >= tutor.x - 3 && jugador.x <= tutor.x + 3 &&
                jugador.y == tutor.y) {
                tutor.activo = true;
                jugador.x = 6;
                jugador.y = 26;
                color(1);
                color_text(3);
                tutor_mostrar(2, 1);
                color_text(3);
                color(1);
                tutor.activo = false;
                break;
            }

            // Limites enemigos
            if (enemigos[0].x <= 3 || enemigos[0].x >= 13)
                enemigos[0].dx *= -1;
            if (enemigos[1].x <= 44 || enemigos[1].x >= 54)
                enemigos[1].dx *= -1;

            // Movimiento de enemigos
            for (int i = 0; i < 2; i++) {
                enemigos[i].mover();
            }

            // Límites del personaje principal
            if (jugador.x > 60 - 6)
                jugador.x = 60 - 6; // Derecha
            if (jugador.x < 3)
                jugador.x = 3; // Izquierda
            if (jugador.y > 30 - 5)
                jugador.y = 30 - 5; // Abajo
            if (jugador.y < 2)
                jugador.y = 2; // Arriba

            // Colisiones con barreras
            // Barrera 1
            if ((jugador.y >= 2 && jugador.y <= 23) && (jugador.x == 14)) {
                jugador.x--;
            }
            if ((jugador.x >= 14 && jugador.x <= 43) && (jugador.y == 23)) {
                jugador.y++;
            }
            if ((jugador.y >= 2 && jugador.y <= 23) && (jugador.x == 43)) {
                jugador.x++;
            }

            // Barrera tutor
            if (jugador.y >= tutor.y - 2 && jugador.y <= tutor.y + 2 && jugador.x == tutor.x - 2) {
                jugador.x--;
            }
            if (jugador.y >= tutor.y - 2 && jugador.y <= tutor.y + 2 && jugador.x == tutor.x + 2) {
                jugador.x++;
            }
            if (jugador.x >= tutor.x - 2 && jugador.x <= tutor.x + 2 && jugador.y == tutor.y - 2) {
                jugador.y--;
            }
            if (jugador.x >= tutor.x - 2 && jugador.x <= tutor.x + 2 && jugador.y == tutor.y + 2) {
                jugador.y++;
            }

            // Colisiones con enemigos
            for (int i = 0; i < 2; i++) {
                if ((jugador.x <= enemigos[i].x + 2 && jugador.x >= enemigos[i].x - 2) &&
                    (jugador.y <= enemigos[i].y + 2 && jugador.y >= enemigos[i].y - 2) &&
                    !jugador.invisible) {
                    jugador.x = 3;
                    jugador.y = 2;
                    jugador.vidas--;
                }
            }

            // Dibujar información del juego
            color(1);
            Console::ForegroundColor = ConsoleColor::Cyan;
            estado.dibujar(jugador);
            color(12);
            Console::ForegroundColor = ConsoleColor::Black;

            // Dibujar personajes y enemigos
            jugador.dibujar();
            for (int i = 0; i < 2; i++) {
                enemigos[i].dibujar();
            }
            tutor.dibujar();
            _sleep(60);
        }

        // Preguntas y respuestas
        color(1);
        int numero_intentos = 1;
        while (!jugador.pregunta_respondida && numero_intentos <= 2 && jugador.vidas > 0 &&
            ((jugador.x >= 52 && jugador.x <= 56) && (jugador.y >= 2 && jugador.y <= 10))) {
            system("cls");
            Console::ForegroundColor = ConsoleColor::Cyan;
            int pregunta_respuesta = pregunta(2, 1);
            int res = 0;
            cursor(10, 38);
            cout << "Ingrese la respuesta: ";
            cin >> res;
            if (res == pregunta_respuesta) {
                jugador.pregunta_respondida = true;
                cursor(20, 39);
                cout << "PUERTA DESBLOQUEADA";
                _sleep(500);
                animacion_puerta(6, 36, 19);
                jugador.puntos += calcular_puntaje_pregunta(numero_intentos);
                _sleep(1000);
                break; // FIN DEL ESCENARIO
            }
            else {
                numero_intentos++;
            }
        }
    }
}

void mundo2_escenario2(Jugador& jugador) {
    jugador.invisible = false;
    jugador.pregunta_respondida = false;
    jugador.x = 3;
    jugador.y = 2;

    // dificultad - seg_cooldown - seg_pantalla - cont_activo - t_inicio -
    // t_actual
    EstadoJuego estado = { 1, 30, 30, false, 0, 0 };
    // X - Y - DX - DY
    Enemigo enemigos[2] = { {44, 3, 0, 1}, {14, 15, 0, 1} };
    // X - Y - TUTOR_ACTIVO
    Tutor tutor = { 54, 2, false };

    char tec = '0';

    while (!jugador.pregunta_respondida && jugador.vidas > 0) {
        system("cls");
        jugador.invisible = false;
        jugador.x = 3;
        jugador.y = 2;
        color(1);
        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < 60; j++) {
                color(m2_esc2[i][j]);
                cursor(j, i);
                cout << " ";
            }
        }
        color(1);

        imp_mundo_actual(2, 2);

        while (!((jugador.x >= 37 && jugador.x <= 53) &&
            (jugador.y >= 24 && jugador.y <= 27)) &&
            jugador.vidas > 0) {
            color(3);
            Console::ForegroundColor = ConsoleColor::Black;

            jugador.borrar();

            // Borrado enemigos
            for (int i = 0; i < 2; i++) {
                enemigos[i].borrar();
            }

            // Borrado tutor
            tutor.borrar();

            color(1);
            // Borrado de la tabla de información
            estado.borrar();
            color(3);

            if (_kbhit()) {
                tec = _getch();
                if (tec == 72)
                    jugador.y--; // Arriba
                if (tec == 75)
                    jugador.x--; // Izquierda
                if (tec == 77)
                    jugador.x++; // Derecha
                if (tec == 80)
                    jugador.y++; // Abajo
                if ((tec == 'A' || tec == 'a') && !estado.contador_activo) {
                    jugador.invisible = true;
                    estado.iniciarContador();
                }
            }

            // Contador cooldown - invisible
            if (estado.contador_activo) {
                estado.actualizarContador();
                if (estado.segundos_pantalla == 25) {
                    jugador.invisible = false;
                }
            }

            // Acercamiento tutor - indicaciones
            if (jugador.x >= tutor.x - 3 && jugador.x <= tutor.x + 3 &&
                jugador.y == tutor.y) {
                tutor.activo = true;
                jugador.x = 6;
                jugador.y = 26;
                color(1);
                color_text(3);
                tutor_mostrar(2, 2);
                color_text(3);
                color(1);
                tutor.activo = false;
                break;
            }

            // Limites enemigos
            if (enemigos[0].y <= 2 || enemigos[0].y >= 15)
                enemigos[0].dy *= -1;
            if (enemigos[1].y <= 14 || enemigos[1].y >= 25)
                enemigos[1].dy *= -1;

            // Movimiento de enemigos
            for (int i = 0; i < 2; i++) {
                enemigos[i].mover();
            }

            // Límites del personaje principal
            if (jugador.x > 60 - 6)
                jugador.x = 60 - 6; // Derecha
            if (jugador.x < 3)
                jugador.x = 3; // Izquierda
            if (jugador.y > 30 - 5)
                jugador.y = 30 - 5; // Abajo
            if (jugador.y < 2)
                jugador.y = 2; // Arriba

            // Colisiones con barreras
            // Barrera 1
            if ((jugador.y >= 6 && jugador.y <= 13) && (jugador.x == 43)) {
                jugador.x++;
            }
            if ((jugador.x >= 3 && jugador.x <= 43) && (jugador.y == 13)) {
                jugador.y++;
            }
            if ((jugador.x >= 3 && jugador.x <= 43) && (jugador.y == 6)) {
                jugador.y--;
            }

            // Barrera 2
            if ((jugador.x >= 15 && jugador.x <= 56) && (jugador.y == 23)) {
                jugador.y++;
            }
            if ((jugador.x >= 15 && jugador.x <= 56) && (jugador.y == 16)) {
                jugador.y--;
            }
            if ((jugador.y >= 16 && jugador.y <= 23) && (jugador.x == 15)) {
                jugador.x--;
            }


            // Barrera tutor
            if (jugador.y >= tutor.y - 2 && jugador.y <= tutor.y + 2 &&
                jugador.x == tutor.x - 2) {
                jugador.x--;
            }
            if (jugador.y >= tutor.y - 2 && jugador.y <= tutor.y + 2 &&
                jugador.x == tutor.x + 2) {
                jugador.x++;
            }
            if (jugador.x >= tutor.x - 2 && jugador.x <= tutor.x + 2 &&
                jugador.y == tutor.y - 2) {
                jugador.y--;
            }
            if (jugador.x >= tutor.x - 2 && jugador.x <= tutor.x + 2 &&
                jugador.y == tutor.y + 2) {
                jugador.y++;
            }

            // Colisiones con enemigos
            for (int i = 0; i < 2; i++) {
                if ((jugador.x <= enemigos[i].x + 2 && jugador.x >= enemigos[i].x - 2) &&
                    (jugador.y <= enemigos[i].y + 2 &&
                        jugador.y >= enemigos[i].y - 2) &&
                    !jugador.invisible) {
                    jugador.x = 3;
                    jugador.y = 2;
                    jugador.vidas--;
                }
            }

            // Dibujar información del juego
            color(1);
            Console::ForegroundColor = ConsoleColor::Cyan;
            estado.dibujar(jugador);
            color(3);
            Console::ForegroundColor = ConsoleColor::Black;

            // Dibujar personajes y enemigos
            jugador.dibujar();
            for (int i = 0; i < 2; i++) {
                enemigos[i].dibujar();
            }
            tutor.dibujar();
            _sleep(60);
        }

        // Preguntas y respuestas
        color(1);
        int numero_intentos = 1;
        while (!jugador.pregunta_respondida && numero_intentos <= 2 && jugador.vidas > 0 && ((jugador.x >= 37 && jugador.x <= 53) && (jugador.y >= 24 && jugador.y <= 27))) {
            system("cls");
            Console::ForegroundColor = ConsoleColor::Cyan;
            int pregunta_respuesta = pregunta(2, 2);
            int res = 0;
            int cent = 0;
            cursor(10, 29);
            cout << "Ingrese los soles: ";
            cin >> res;
            cursor(10, 30);
            cout << "Ingrese los centimos: ";
            cin >> cent;

            if (res == pregunta_respuesta && cent == 40) {
                jugador.pregunta_respondida = true;
                cursor(20, 32);
                cout << "PUERTA DESBLOQUEADA";
                _sleep(500);
                animacion_puerta(8, 36, 19);
                jugador.puntos += calcular_puntaje_pregunta(numero_intentos);
                _sleep(1000);
                break; // FIN DEL ESCENARIO
            }
            else {
                numero_intentos++;
            }
        }
    }
}

void mundo2_escenario3(Jugador& jugador) {
    jugador.invisible = false;
    jugador.pregunta_respondida = false;
    jugador.x = 45;
    jugador.y = 2;

    // dificultad - seg_cooldown - seg_pantalla - cont_activo - t_inicio -
    // t_actual
    EstadoJuego estado = { 2, 30, 30, false, 0, 0 };
    // X - Y - DX - DY
    Enemigo enemigos[2] = { {12, 13, 0, 1}, {44, 15, 1, 0} };
    // X - Y - TUTOR_ACTIVO
    Tutor tutor = { 54, 2, false };

    char tec = '0';

    while (!jugador.pregunta_respondida && jugador.vidas > 0) {
        system("cls");
        jugador.invisible = false;
        jugador.x = 45;
        jugador.y = 2;
        color(1);
        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < 60; j++) {
                color(m2_esc3[i][j]);
                cursor(j, i);
                cout << " ";
            }
        }
        color(1);

        imp_mundo_actual(2, 3);

        while (!((jugador.x >= 2 && jugador.x <= 8) &&
            (jugador.y >= 2 && jugador.y <= 7)) &&
            jugador.vidas > 0) {
            color(11);
            Console::ForegroundColor = ConsoleColor::Black;

            jugador.borrar();

            // Borrado enemigos
            for (int i = 0; i < 2; i++) {
                enemigos[i].borrar();
            }

            // Borrado tutor
            tutor.borrar();

            color(1);
            // Borrado de la tabla de información
            estado.borrar();
            color(11);

            if (_kbhit()) {
                tec = _getch();
                if (tec == 72)
                    jugador.y--; // Arriba
                if (tec == 75)
                    jugador.x--; // Izquierda
                if (tec == 77)
                    jugador.x++; // Derecha
                if (tec == 80)
                    jugador.y++; // Abajo
                if ((tec == 'A' || tec == 'a') && !estado.contador_activo) {
                    jugador.invisible = true;
                    estado.iniciarContador();
                }
            }

            // Contador cooldown - invisible
            if (estado.contador_activo) {
                estado.actualizarContador();
                if (estado.segundos_pantalla == 25) {
                    jugador.invisible = false;
                }
            }

            // Acercamiento tutor - indicaciones
            if (jugador.x >= tutor.x - 3 && jugador.x <= tutor.x + 3 &&
                jugador.y == tutor.y) {
                tutor.activo = true;
                jugador.x = 6;
                jugador.y = 26;
                color(1);
                color_text(3);
                tutor_mostrar(2, 3);
                color_text(3);
                color(1);
                tutor.activo = false;
                break;
            }

            // Limites enemigos
            if (enemigos[0].y <= 12 || enemigos[0].y >= 25)
                enemigos[0].dy *= -1;
            if (enemigos[1].x <= 43 || enemigos[1].x >= 54)
                enemigos[1].dx *= -1;

            // Movimiento de enemigos
            for (int i = 0; i < 2; i++) {
                enemigos[i].mover();
            }

            // Límites del personaje principal
            if (jugador.x > 60 - 6)
                jugador.x = 60 - 6; // Derecha
            if (jugador.x < 3)
                jugador.x = 3; // Izquierda
            if (jugador.y > 30 - 5)
                jugador.y = 30 - 5; // Abajo
            if (jugador.y < 2)
                jugador.y = 2; // Arriba

            // Colisiones con barreras
            // Barrera 1
            if ((jugador.y >= 6 && jugador.y <= 11) && (jugador.x == 12)) {
                jugador.x++;
            }
            if ((jugador.x >= 3 && jugador.x <= 21) && (jugador.y == 11)) {
                jugador.y++;
            }
            if ((jugador.x >= 3 && jugador.x <= 21) && (jugador.y == 6)) {
                jugador.y--;
            }

            // Barrera 2
            if ((jugador.x >= 13 && jugador.x <= 42) && (jugador.y == 22)) {
                jugador.y++;
            }
            if ((jugador.x >= 13 && jugador.x <= 31) && (jugador.y == 15)) {
                jugador.y--;
            }
            if ((jugador.y >= 15 && jugador.y <= 22) && (jugador.x == 13)) {
                jugador.x--;
            }
            if ((jugador.y >= 2 && jugador.y <= 16) && (jugador.x == 30)) {
                jugador.x--;
            }
            if ((jugador.y >= 2 && jugador.y <= 22) && (jugador.x == 42)) {
                jugador.x++;
            }

            // Barrera tutor
            if (jugador.y >= tutor.y - 2 && jugador.y <= tutor.y + 2 &&
                jugador.x == tutor.x - 2) {
                jugador.x--;
            }
            if (jugador.y >= tutor.y - 2 && jugador.y <= tutor.y + 2 &&
                jugador.x == tutor.x + 2) {
                jugador.x++;
            }
            if (jugador.x >= tutor.x - 2 && jugador.x <= tutor.x + 2 &&
                jugador.y == tutor.y - 2) {
                jugador.y--;
            }
            if (jugador.x >= tutor.x - 2 && jugador.x <= tutor.x + 2 &&
                jugador.y == tutor.y + 2) {
                jugador.y++;
            }

            // Colisiones con enemigos
            for (int i = 0; i < 2; i++) {
                if ((jugador.x <= enemigos[i].x + 2 && jugador.x >= enemigos[i].x - 2) &&
                    (jugador.y <= enemigos[i].y + 2 &&
                        jugador.y >= enemigos[i].y - 2) &&
                    !jugador.invisible) {
                    jugador.x = 45;
                    jugador.y = 2;
                    jugador.vidas--;
                }
            }

            // Dibujar información del juego
            color(1);
            Console::ForegroundColor = ConsoleColor::Cyan;
            estado.dibujar(jugador);
            color(11);
            Console::ForegroundColor = ConsoleColor::Black;

            // Dibujar personajes y enemigos
            jugador.dibujar();
            for (int i = 0; i < 2; i++) {
                enemigos[i].dibujar();
            }
            tutor.dibujar();
            _sleep(60);
        }

        // Preguntas y respuestas
        color(1);
        int numero_intentos = 1;
        while (!jugador.pregunta_respondida && numero_intentos <= 3 && jugador.vidas > 0 && ((jugador.x >= 2 && jugador.x <= 8) && (jugador.y >= 2 && jugador.y <= 7))) {
            system("cls");
            Console::ForegroundColor = ConsoleColor::Cyan;
            int pregunta_respuesta = pregunta(2, 3);
            int res = 0;
            int cent = 0;
            cursor(10, 36);
            cout << "Ingrese los soles: ";
            cin >> res;
            cursor(10, 37);
            cout << "Ingrese los centimos: ";
            cin >> cent;
            if (res == pregunta_respuesta && cent == 60) {
                jugador.pregunta_respondida = true;
                cursor(20, 39);
                cout << "PUERTA DESBLOQUEADA";
                _sleep(500);
                animacion_puerta(12, 36, 19);
                jugador.puntos += calcular_puntaje_pregunta(numero_intentos);
                _sleep(1000);
                break; // FIN DEL ESCENARIO
            }
            else {
                numero_intentos++;
            }
        }
        if (numero_intentos == 4) {
            jugador.vidas = 0;
            break;
        }
    }
}

// LOGICA PRINCIPAL
// Función para mostrar el menú y permitir la selección
void mostrar_mundo(int position, int xm, int ym, string menu_text[], int menu_items) {
    for (int i = 0; i < menu_items; ++i) {
        cursor(xm, ym + i);
        if (i == position) {
            cout << ">>> " << menu_text[i] << " <<<";
        }
        else {
            cout << "    " << menu_text[i] << "    ";
        }
    }
}

int selector_mundo(int xm, int ym, string menu_text[], int menu_items) {
    int position = 0;
    int key;

    mostrar_mundo(position, xm, ym, menu_text, menu_items);

    while (true) {
        key = _getch();
        if (key == 0 || key == 224) {
            key = _getch();
            switch (key) {
            case 72: // Flecha arriba
                position = (position == 0) ? menu_items - 1 : position - 1;
                break;
            case 80: // Flecha abajo
                position = (position == menu_items - 1) ? 0 : position + 1;
                break;
            }
            mostrar_mundo(position, xm, ym, menu_text, menu_items);
        }
        else if (key == 13) { // Enter
            return position;
        }
    }
}

void jugar(string**& ranking, int numJugadores, Jugador& jugador) {

    // Ingresar nombre - Verificar si se ingresó texto
    do {
        cursor(26, 19);
        cout << "Ingrese su nombre: ";
        getline(cin, jugador.nombre);
    } while (jugador.nombre.empty());

    // Opciones del menú de selección de mundo
    const int menu_items = 2;
    string menu_text[menu_items] = {
        "Mundo 1: Ecuaciones con una incognita",
        "Mundo 2: Ecuaciones de suma y resta"
    };

    // Posición del menú
    int xm = 18;
    int ym = 21;

    // Seleccionar mundo
    int opc = selector_mundo(xm, ym, menu_text, menu_items);

    // Ejecutar el mundo seleccionado
    if (opc == 0) { // MUNDO 1
        mundo1_escenario1(jugador);
        mundo1_escenario2(jugador);
        mundo1_escenario3(jugador);
    }
    else if (opc == 1) { // MUNDO 2
        mundo2_escenario1(jugador);
        mundo2_escenario2(jugador);
        mundo2_escenario3(jugador);
    }

    if (jugador.vidas > 0) {
        imp_you_win();
    }

    if (jugador.vidas < 1) {
        imp_game_over();
    }
}