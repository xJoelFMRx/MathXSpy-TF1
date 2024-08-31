#pragma once
#include "Estructuras.h"
#include "Utilidades.h"
#include "Juego.h"

void instrucciones() {
    system("cls");
    cout << R"(
   ************************************************************************
   * ___       ___      _     ___      ______     ___      _     ____     *
   * `MMb     dMM'     dM.    `MM\     `M`MM'     `M'     dM.    `MM'     *
   *  MMM.   ,PMM     ,MMb     MMM\     M MM       M     ,MMb     MM      *
   *  M`Mb   d'MM     d'YM.    M\MM\    M MM       M     d'YM.    MM      *
   *  M YM. ,P MM    ,P `Mb    M \MM\   M MM       M    ,P `Mb    MM      *
   *  M `Mb d' MM    d'  YM.   M  \MM\  M MM       M    d'  YM.   MM      *
   *  M  YM.P  MM   ,P   `Mb   M   \MM\ M MM       M   ,P   `Mb   MM      *
   *  M  `Mb'  MM   d'    YM.  M    \MM\M MM       M   d'    YM.  MM      *
   *  M   YP   MM  ,MMMMMMMMb  M     \MMM YM       M  ,MMMMMMMMb  MM      *
   *  M   `'   MM  d'      YM. M      \MM  8b     d8  d'      YM. MM    / *
   * _M_      _MM_dM_     _dMM_M_      \M   YMMMMM9 _dM_     _dMM_MMMMMMM *
   ************************************************************************

   SELECCIONA TU MUNDO INICIAL:
   - Al comenzar el juego, puedes elegir entre el Mundo 1 
     (Ecuaciones con una incognita) o el Mundo 2 (E. suma y resta).

   - Cada mundo cuenta con 3 escenarios que se divide en 
     dificultades: Principiante, Intermedio, Avanzado.

   TUTOR AL INICIO:
   - Al inicio de cada escenario, un tutor te explicara el tema 
     correspondiente segun la dificultad.

   VIDAS:
   - Comienzas el juego con 3 vidas.

   OBJETIVO DEL JUEGO:
   - Tu mision es moverte por los diferentes escenarios sin chocar 
     con los guardias. Si chocas con uno, perderas una vida y regresaras 
     al inicio del escenario. Ademas, tienes que llegar al final de cada
     escenario. Llegar al final del escenario 3 de cualquiera de los dos
     mundos significa que ganaste (YOU WIN)

)";
    cursor(60, 37);
    cout << "1 / 3";
    cursor(51, 38);
    cout << "Presione para continuar...";

    system("pause>0");
    system("cls");
    cout << R"(
   ************************************************************************
   * ___       ___      _     ___      ______     ___      _     ____     *
   * `MMb     dMM'     dM.    `MM\     `M`MM'     `M'     dM.    `MM'     *
   *  MMM.   ,PMM     ,MMb     MMM\     M MM       M     ,MMb     MM      *
   *  M`Mb   d'MM     d'YM.    M\MM\    M MM       M     d'YM.    MM      *
   *  M YM. ,P MM    ,P `Mb    M \MM\   M MM       M    ,P `Mb    MM      *
   *  M `Mb d' MM    d'  YM.   M  \MM\  M MM       M    d'  YM.   MM      *
   *  M  YM.P  MM   ,P   `Mb   M   \MM\ M MM       M   ,P   `Mb   MM      *
   *  M  `Mb'  MM   d'    YM.  M    \MM\M MM       M   d'    YM.  MM      *
   *  M   YP   MM  ,MMMMMMMMb  M     \MMM YM       M  ,MMMMMMMMb  MM      *
   *  M   `'   MM  d'      YM. M      \MM  8b     d8  d'      YM. MM    / *
   * _M_      _MM_dM_     _dMM_M_      \M   YMMMMM9 _dM_     _dMM_MMMMMMM *
   ************************************************************************

   PREGUNTAS AL FINAL DEL ESCENARIO:
   - Al final de cada escenario, deberas responder una pregunta para 
     desbloquear la puerta:

     - En los dos primeros escenarios, tienes 2 intentos para responder 
       correctamente.
     - En el ultimo escenario, tienes 3 intentos.
     - Si respondes correctamente en el primer intento, obtendras 3 puntos; 
       cada intento adicional reducira la puntuacion en 1 punto.
     - Si fallas ambos intentos en los dos primeros escenarios, volveras al 
       inicio del escenario.
     - Si fallas los tres intentos en el ultimo escenario, el juego terminara 
       automaticamente (GAME OVER).

   SUPERPODER:
   - Tienes un superpoder que te permite volverte invisible durante 5 segundos. 
     Despues de usarlo, tendras que esperar 30 segundos para utilizarlo 
     nuevamente. (FUNCIONALIDAD ADICIONAL)
)";
    cursor(60, 37);
    cout << "2 / 3";
    cursor(51, 38);
    cout << "Presione para continuar...";

    system("pause>0");
    system("cls");
    cout << R"(
   ************************************************************************
   * ___       ___      _     ___      ______     ___      _     ____     *
   * `MMb     dMM'     dM.    `MM\     `M`MM'     `M'     dM.    `MM'     *
   *  MMM.   ,PMM     ,MMb     MMM\     M MM       M     ,MMb     MM      *
   *  M`Mb   d'MM     d'YM.    M\MM\    M MM       M     d'YM.    MM      *
   *  M YM. ,P MM    ,P `Mb    M \MM\   M MM       M    ,P `Mb    MM      *
   *  M `Mb d' MM    d'  YM.   M  \MM\  M MM       M    d'  YM.   MM      *
   *  M  YM.P  MM   ,P   `Mb   M   \MM\ M MM       M   ,P   `Mb   MM      *
   *  M  `Mb'  MM   d'    YM.  M    \MM\M MM       M   d'    YM.  MM      *
   *  M   YP   MM  ,MMMMMMMMb  M     \MMM YM       M  ,MMMMMMMMb  MM      *
   *  M   `'   MM  d'      YM. M      \MM  8b     d8  d'      YM. MM    / *
   * _M_      _MM_dM_     _dMM_M_      \M   YMMMMM9 _dM_     _dMM_MMMMMMM *
   ************************************************************************
)";

    Tutor tutor_prueba;
    tutor_prueba.x = 38;
    tutor_prueba.y = 18;

    Enemigo enemigo_prueba;
    enemigo_prueba.x = 48;
    enemigo_prueba.y = 18;

    Jugador jugador_prueba;
    jugador_prueba.x = 13;
    jugador_prueba.y = 18;
    jugador_prueba.invisible = false;

    cursor(38, 16);
    cout << "TUTOR";
    tutor_prueba.dibujar();

    color_text(3);
    cursor(48, 16);
    cout << "ENEMIGO";
    color(15);
    enemigo_prueba.dibujar();
    color(1);
    color_text(3);

    cursor(10, 16);
    cout << "PERSONAJE";
    jugador_prueba.dibujar();
    color_text(3);

    cursor(23, 16);
    cout << "P. INVISIBLE";
    jugador_prueba.x = 28;
    jugador_prueba.y = 18;
    jugador_prueba.invisible = true;
    jugador_prueba.dibujar();
    color_text(3);

    cursor(0, 23);
    cout << R"(
   RANKING:
   - Obtengas o no puntos, ganes o pierdas, apareceras en la lista (RANKING). 
     Se mostrarán los 5 primeros puestos en orden descendente.
)";

    cursor(60, 37);
    cout << "3 / 3";
    cursor(51, 38);
    cout << "Presione para continuar...";

    system("pause>0");
}

void introduccion() {
    system("cls");
    cursor(0, 2);
    color_text(2);
    cout << R"(
      ******************************************************************
      *                                                                *
      *  ooo        ooooo       .o.       ooooooooooooo ooooo   ooooo  *
      *  `88.       .888'      .888.      8'   888   `8 `888'   `888'  *
      *   888b     d'888      .8"888.          888       888     888   *
      *   8 Y88. .P  888     .8' `888.         888       888ooooo888   *
      *   8  `888'   888    .88ooo8888.        888       888     888   *
      *   8    Y     888   .8'     `888.       888       888     888   *
      *  o8o        o888o o88o     o8888o     o888o     o888o   o888o  *
      *                                                                *
      ******************************************************************
)";

    _sleep(300);
    system("cls");
    cursor(0, 13);
    color_text(3);
    cout << R"(
      ******************************************************************
      *                                                                *
      *  ooo        ooooo       .o.       ooooooooooooo ooooo   ooooo  *
      *  `88.       .888'      .888.      8'   888   `8 `888'   `888'  *
      *   888b     d'888      .8"888.          888       888     888   *
      *   8 Y88. .P  888     .8' `888.         888       888ooooo888   *
      *   8  `888'   888    .88ooo8888.        888       888     888   *
      *   8    Y     888   .8'     `888.       888       888     888   *
      *  o8o        o888o o88o     o8888o     o888o     o888o   o888o  *
      *                                                                *
      ******************************************************************
)";
    _sleep(300);
    system("cls");
    cursor(0, 24);
    color_text(4);
    cout << R"(
      ******************************************************************
      *                                                                *
      *  ooo        ooooo       .o.       ooooooooooooo ooooo   ooooo  *
      *  `88.       .888'      .888.      8'   888   `8 `888'   `888'  *
      *   888b     d'888      .8"888.          888       888     888   *
      *   8 Y88. .P  888     .8' `888.         888       888ooooo888   *
      *   8  `888'   888    .88ooo8888.        888       888     888   *
      *   8    Y     888   .8'     `888.       888       888     888   *
      *  o8o        o888o o88o     o8888o     o888o     o888o   o888o  *
      *                                                                *
      ******************************************************************
)";

    _sleep(300);
    system("cls");
    cursor(0, 24);
    color_text(4);
    cout << R"(
                             ********************
                             *                  *
                             *  ooooooo  ooooo  *
                             *   `8888    d8'   *
                             *     Y888..8P     *
                             *      `8888'      *
                             *     .8PY888.     *
                             *    d8'  `888b    *
                             *  o888o  o88888o  *
                             *                  *
                             ********************
)";
    _sleep(300);
    system("cls");
    cursor(0, 13);
    color_text(3);
    cout << R"(
                             ********************
                             *                  *
                             *  ooooooo  ooooo  *
                             *   `8888    d8'   *
                             *     Y888..8P     *
                             *      `8888'      *
                             *     .8PY888.     *
                             *    d8'  `888b    *
                             *  o888o  o88888o  *
                             *                  *
                             ********************
)";
    _sleep(300);
    system("cls");
    cursor(0, 2);
    color_text(2);
    cout << R"(
                             ********************
                             *                  *
                             *  ooooooo  ooooo  *
                             *   `8888    d8'   *
                             *     Y888..8P     *
                             *      `8888'      *
                             *     .8PY888.     *
                             *    d8'  `888b    *
                             *  o888o  o88888o  *
                             *                  *
                             ********************
)";

    _sleep(300);
    system("cls");
    cursor(0, 2);
    color_text(2);
    cout << R"(
                ********************************************
                *                                          *
                *   .oooooo..o ooooooooo.   oooooo   oooo  *
                *  d8P'    `Y8 `888   `Y88.  `888.   .8'   *
                *  Y88bo.       888   .d88'   `888. .8'    *
                *   `"Y8888o.   888ooo88P'     `888.8'     *
                *       `"Y88b  888             `888'      *
                *  oo     .d8P  888              888       *
                *  8""88888P'  o888o            o888o      *
                *                                          *
                ********************************************
)";

    _sleep(300);
    system("cls");
    cursor(0, 13);
    color_text(3);
    cout << R"(
                ********************************************
                *                                          *
                *   .oooooo..o ooooooooo.   oooooo   oooo  *
                *  d8P'    `Y8 `888   `Y88.  `888.   .8'   *
                *  Y88bo.       888   .d88'   `888. .8'    *
                *   `"Y8888o.   888ooo88P'     `888.8'     *
                *       `"Y88b  888             `888'      *
                *  oo     .d8P  888              888       *
                *  8""88888P'  o888o            o888o      *
                *                                          *
                ********************************************
)";
    _sleep(300);
    system("cls");
    cursor(0, 24);
    color_text(4);
    cout << R"(
                ********************************************
                *                                          *
                *   .oooooo..o ooooooooo.   oooooo   oooo  *
                *  d8P'    `Y8 `888   `Y88.  `888.   .8'   *
                *  Y88bo.       888   .d88'   `888. .8'    *
                *   `"Y8888o.   888ooo88P'     `888.8'     *
                *       `"Y88b  888             `888'      *
                *  oo     .d8P  888              888       *
                *  8""88888P'  o888o            o888o      *
                *                                          *
                ********************************************
)";

    _sleep(300);
    system("cls");
    cursor(0, 4);
    color_text(3);
    cout << R"(
        ****************************************************************
        * ___       ___      _   __________ ____    ____               *
        * `MMb     dMM'     dM.  MMMMMMMMMM `MM'    `MM'               *
        *  MMM.   ,PMM     ,MMb  /   MM   \  MM      MM                *
        *  M`Mb   d'MM     d'YM.     MM      MM      MM                *
        *  M YM. ,P MM    ,P `Mb     MM      MM      MM                *
        *  M `Mb d' MM    d'  YM.    MM      MMMMMMMMMM                *
        *  M  YM.P  MM   ,P   `Mb    MM      MM      MM                *
        *  M  `Mb'  MM   d'    YM.   MM      MM      MM                *
        *  M   YP   MM  ,MMMMMMMMb   MM      MM      MM                *
        *  M   `'   MM  d'      YM.  MM      MM      MM                *
        * _M_      _MM_dM_     _dMM__MM_    _MM_    _MM_               *
        *                                                              *
        *                                                              *
        *                                                              *
        *                                                              *
        *                                                              *
        *                         ____      ___ ________  ____     ___ *
        *                         `MM(      )M' `MMMMMMMb.`MM(     )M' *
        *                          `MM.     d'   MM    `Mb `MM.    d'  *
        *                           `MM.   d'    MM     MM  `MM.  d'   *
        *                            `MM. d'     MM     MM   `MM d'    *
        *                             `MMd       MM    .M9    `MM'     *
        *                              dMM.      MMMMMMM9'     MM      *
        *                             d'`MM.     MM            MM      *
        *                            d'  `MM.    MM            MM      *
        *                           d'    `MM.   MM            MM      *
        *                         _M(_    _)MM_ _MM_          _MM_     *
        ****************************************************************
)";
    _sleep(1000);
}

void creditos() {
    system("cls");
    cursor(0, 2);
    cout << R"(
*******************************************************************************
*    ____   ________   __________ ________  ______________   ____      ____   *
*   6MMMMb/ `MMMMMMMb. `MMMMMMMMM `MMMMMMMb.`MM'MMMMMMMMMM  6MMMMb    6MMMMb\ *
*  8P    YM  MM    `Mb  MM      \  MM    `Mb MM /   MM   \ 8P    Y8  6M'    ` *
* 6M      Y  MM     MM  MM         MM     MM MM     MM    6M      Mb MM       *
* MM         MM     MM  MM    ,    MM     MM MM     MM    MM      MM YM.      *
* MM         MM    .M9  MMMMMMM    MM     MM MM     MM    MM      MM  YMMMMb  *
* MM         MMMMMMM9'  MM    `    MM     MM MM     MM    MM      MM      `Mb *
* MM         MM  \M\    MM         MM     MM MM     MM    MM      MM       MM *
* YM      6  MM   \M\   MM         MM     MM MM     MM    YM      M9       MM *
*  8b    d9  MM    \M\  MM      /  MM    .M9 MM     MM     8b    d8  L    ,M9 *
*   YMMMM9  _MM_    \M\_MMMMMMMMM _MMMMMMM9'_MM_   _MM_     YMMMM9   MYMMMM9  *
*******************************************************************************
)";

    cursor(10, 17);
    cout << "- MORA RIVERA, JOEL FERNANDO";
    cursor(10, 19);
    cout << "- RAMOS CERDAN, ELIAS DANIEL";
    cursor(10, 21);
    cout << "- VILLARREAL BAZAN, ANGEL MARTIN";

    cursor(6, 36);
    cout << "© 2024 MATHXPY. Todos los derechos reservados.";

    cursor(68, 36);
    cout << "--->";

    system("pause>0");
}

void mostrar_menu(int opcion, int xm, int ym, string menu_text[], int menu_items) {
    for (int i = 0; i < menu_items; ++i) {
        cursor(xm, ym + i);
        if (i == opcion) {
            Console::ForegroundColor = ConsoleColor::White;
        }
        else {
            Console::ForegroundColor = ConsoleColor::Cyan;
        }
        cout << menu_text[i];
    }
}

int selector_menu(int xm, int ym, string menu_text[], int menu_items) {
    int position = 0;
    int key;

    mostrar_menu(position, xm, ym, menu_text, menu_items);

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
            mostrar_menu(position, xm, ym, menu_text, menu_items);
        }
        else if (key == 13) { // Enter
            return position;
        }
    }
}

void menu() {
    iniciar();
    introduccion();

    // INICIO VARIBLE PARA EL RANKING
    int numJugadores = 0;
    string** ranking = nullptr;

    int ym = 27;
    int xm = 30;
    const int menu_items = 5;
    string menu_text[menu_items] = {
        "     Iniciar Juego    ",
        "     Instrucciones    ",
        "Reiniciar introduccion",
        "       Creditos       ",
        "        Salir         "
    };

    //Jugador
    Jugador jugador;

    int opc;
    do {
        system("cls");
        imp_logo(0, 0);  // Imprimir el logo una sola vez
        opc = selector_menu(xm, ym, menu_text, menu_items);

        switch (opc) {
        case 0:
            system("cls");
            color(1);
            //Inicializar jugador
            // NOMBRE - VIDAS - PUNTOS - X - Y - INVISIBLE - PREGUNTA_RESPONDIDA
            jugador = { "", 3, 0, 0, 0, false, false };

            jugar(ranking, numJugadores, jugador);

            // AGREGAR RANKING
            agregar_ranking(numJugadores, ranking, jugador.nombre, jugador.puntos);
            puntaje_ranking(ranking, numJugadores, 15, 6);

            cursor(51, 38);
            cout << "Presione para continuar...";
            system("pause>0");

            //system("pause>0");
            color(1);
            break;
        case 1:
            instrucciones();
            break;
        case 2:
            introduccion();
            break;
        case 3:
            creditos();
            break;
        case 4:
            break; // Salir
        default:
            cursor(xm, ym + menu_items + 1);
            Console::ForegroundColor = ConsoleColor::Red;
            cout << "Ingrese una opcion valida.";
            _sleep(1000);
            break;
        }
    } while (opc != 4);

    for (int i = 0; i < numJugadores; ++i) {
        delete[] ranking[i];
    }
    delete[] ranking;
    ranking = nullptr;
}