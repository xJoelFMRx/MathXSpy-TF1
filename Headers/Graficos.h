#pragma once
#include "Utilidades.h"
#include "Matrices.h"

// ELEMENTOS GRAFICOS
void imp_logo(int x, int y) {
    color(1);
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 80; j++) {
            color(logo[i][j] /* Matrices.h */);
            cursor(x + j, y + i);
            cout << " ";
        }
    }
    color(1);
}

void imp_bolas(int n, int x, int y) {
    color(1);
    int bol[6][6] = { {1, 1, n, n, 1, 1}, {1, n, n, n, n, 1}, {n, n, n, n, n, n},
                     {n, n, n, n, n, n}, {1, n, n, n, n, 1}, {1, 1, n, n, 1, 1} };
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            color(bol[i][j]);
            cursor(x + j, y + i);
            cout << " ";
        }
    }
    color(1);
}

void imp_moneda_entero(int cantidad, int x, int y) {
    color(1);
    int n = 10;
    int bol[6][6] = { {1, 1, n, n, 1, 1}, {1, n, n, n, n, 1}, {n, n, n, n, n, n},
                     {n, n, n, n, n, n}, {1, n, n, n, n, 1}, {1, 1, n, n, 1, 1} };
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            color(bol[i][j]);
            cursor(x + j, y + i);
            cout << " ";
        }
    }
    cursor(x + 2, y + 2);
    cout << cantidad;
    color(1);
}

void imp_moneda_decimal(int cantidad, int x, int y) {
    color(1);
    int n = 16;
    int bol[6][6] = { {1, 1, n, n, 1, 1}, {1, n, n, n, n, 1}, {n, n, n, n, n, n},
                     {n, n, n, n, n, n}, {1, n, n, n, n, 1}, {1, 1, n, n, 1, 1} };
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            color(bol[i][j]);
            cursor(x + i, y + j);
            cout << " ";
        }
    }

    cursor(x + 2, y + 2);
    cout << cantidad;

    color(1);
}

void imp_caja(int n, int x, int y) {
    color(1);
    int caj[6][6] = { {n, 1, 1, 1, 1, n}, {n, n, n, n, n, n}, {n, 1, 1, 1, 1, n},
                     {n, n, n, n, n, n}, {n, n, n, n, n, n}, {n, n, n, n, n, n} };
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            color(caj[i][j]);
            cursor(x + j, y + i);
            cout << " ";
        }
    }
    color(1);
}

void imp_game_over() {
    system("cls");
    Console::ForegroundColor = ConsoleColor::Cyan;
    cursor(0, 1);
    cout << R"(
              ++------------------------------------------------++
              ++------------------------------------------------++
              ||   sSSSSs   .S_SSSs     .S_SsS_S.     sSSs      ||
              ||  d%%%%SP  .SS~SSSSS   .SS~S*S~SS.   d%%SP      ||
              || d%S'      S%S   SSSS  S%S `Y' S%S  d%S'        ||
              || S%S       S%S    S%S  S%S     S%S  S%S         ||
              || S&S       S%S SSSS%S  S%S     S%S  S&S         ||
              || S&S       S&S  SSS%S  S&S     S&S  S&S_Ss      ||
              || S&S       S&S    S&S  S&S     S&S  S&S~SP      ||
              || S&S sSSs  S&S    S&S  S&S     S&S  S&S         ||
              || S*b `S%%  S*S    S&S  S*S     S*S  S*b         ||
              || S*S   S%  S*S    S*S  S*S     S*S  S*S.        ||
              ||  SS_sSSS  S*S    S*S  S*S     S*S   SSSbs      ||
              ||   Y~YSSY  SSS    S*S  SSS     S*S    YSSP      ||
              ||                  SP           SP               ||
              ||                  Y            Y                ||
              ||                                                ||
              ||   sSSs_sSSs     .S    S.     sSSs   .S_sSSs    ||
              ||  d%%SP~YS%%b   .SS    SS.   d%%SP  .SS~YS%%b   ||
              || d%S'     `S%b  S%S    S%S  d%S'    S%S   `S%b  ||
              || S%S       S%S  S%S    S%S  S%S     S%S    S%S  ||
              || S&S       S&S  S&S    S%S  S&S     S%S    d*S  ||
              || S&S       S&S  S&S    S&S  S&S_Ss  S&S   .S*S  ||
              || S&S       S&S  S&S    S&S  S&S~SP  S&S_sdSSS   ||
              || S&S       S&S  S&S    S&S  S&S     S&S~YSY%b   ||
              || S*b       d*S  S*b    S*S  S*b     S*S   `S%b  ||
              || S*S.     .S*S  S*S.   S*S  S*S.    S*S    S%S  ||
              ||  SSSbs_sdSSS    SSSbs_S*S   SSSbs  S*S    S&S  ||
              ||   YSSP~YSSY      YSSP~SSS    YSSP  S*S    SSS  ||
              ||                                    SP          ||
              ||                                    Y           ||
              ||                                                ||
              ++------------------------------------------------++
              ++------------------------------------------------++
)";
    _sleep(1500);
}

void imp_you_win() {
    system("cls");
    Console::ForegroundColor = ConsoleColor::Cyan;
    cursor(0, 1);
    cout << R"(
                   >>========================================<<
                   ||                                        ||
                   ||                                        ||
                   ||  ____     ___                          ||
                   ||  `MM(     )M'                          ||
                   ||   `MM.    d'                           ||
                   ||    `MM.  d' _____  ___   ___           ||
                   ||     `MM d' 6MMMMMb `MM    MM           ||
                   ||      `MM' 6M'   `Mb MM    MM           ||
                   ||       MM  MM     MM MM    MM           ||
                   ||       MM  MM     MM MM    MM           ||
                   ||       MM  MM     MM MM    MM           ||
                   ||       MM  YM.   ,M9 YM.   MM           ||
                   ||      _MM_  YMMMMM9   YMMM9MM_          ||
                   ||                                        ||
                   ||                                        ||
                   ||                                        ||
                   ||                                        ||
                   ||                                        ||
                   ||  ____              ___                 ||
                   ||  `Mb(      db      )d' 68b             ||
                   ||   YM.     ,PM.     ,P  Y89             ||
                   ||   `Mb     d'Mb     d'  ___ ___  __     ||
                   ||    YM.   ,P YM.   ,P   `MM `MM 6MMb    ||
                   ||    `Mb   d' `Mb   d'    MM  MMM9 `Mb   ||
                   ||     YM. ,P   YM. ,P     MM  MM'   MM   ||
                   ||     `Mb d'   `Mb d'     MM  MM    MM   ||
                   ||      YM,P     YM,P      MM  MM    MM   ||
                   ||      `MM'     `MM'      MM  MM    MM   ||
                   ||       YP       YP      _MM__MM_  _MM_  ||
                   ||                                        ||
                   ||                                        ||
                   >>========================================<<
)";
    _sleep(1500);
}

void imp_mundo_actual(int mundo, int escenario) {
    if (mundo == 1) {
        if (escenario == 1) {
            cursor(0, 30);
            cout << R"(
        /============================================================\
        ||    __  ___                __          ___            ___ ||
        ||   /  |/  /_  ______  ____/ /___      <  /           <  / ||
        ||  / /|_/ / / / / __ \/ __  / __ \     / / ______     / /  ||
        || / /  / / /_/ / / / / /_/ / /_/ /    / / /_____/    / /   ||
        ||/_/  /_/\__,_/_/ /_/\__,_/\____/    /_/            /_/    ||
        \============================================================/
)";
        }
        else if (escenario == 2) {
            cursor(0, 30);
            cout << R"(
        /============================================================\
        ||    __  ___                __          ___            ___ ||
        ||   /  |/  /_  ______  ____/ /___      <  /           |__ \||
        ||  / /|_/ / / / / __ \/ __  / __ \     / / ______     __/ /||
        || / /  / / /_/ / / / / /_/ / /_/ /    / / /_____/    / __/ ||
        ||/_/  /_/\__,_/_/ /_/\__,_/\____/    /_/            /____/ ||
        \============================================================/
)";
        }
        else if (escenario == 3) {
            cursor(0, 30);
            cout << R"(
        /==============================================================\
        ||    __  ___                __          ___            _____ ||
        ||   /  |/  /_  ______  ____/ /___      <  /           |__  / ||
        ||  / /|_/ / / / / __ \/ __  / __ \     / / ______      /_ <  ||
        || / /  / / /_/ / / / / /_/ / /_/ /    / / /_____/    ___/ /  ||
        ||/_/  /_/\__,_/_/ /_/\__,_/\____/    /_/            /____/   ||
        \==============================================================/
)";
        }
    }
    else if (mundo == 2) {
        if (escenario == 1) {
            cursor(0, 30);
            cout << R"(
        /================================================================\
        ||    __  ___                __          ___                 ___||
        ||   /  |/  /_  ______  ____/ /___      |__ \               <  /||
        ||  / /|_/ / / / / __ \/ __  / __ \     __/ /    ______     / / ||
        || / /  / / /_/ / / / / /_/ / /_/ /    / __/    /_____/    / /  ||
        ||/_/  /_/\__,_/_/ /_/\__,_/\____/    /____/              /_/   ||
        \================================================================/
)";
        }
        else if (escenario == 2) {
            cursor(0, 30);
            cout << R"(
       /==================================================================\
       ||    __  ___                __          ___                 ___  ||
       ||   /  |/  /_  ______  ____/ /___      |__ \               |__ \ ||
       ||  / /|_/ / / / / __ \/ __  / __ \     __/ /    ______     __/ / ||
       || / /  / / /_/ / / / / /_/ / /_/ /    / __/    /_____/    / __/  ||
       ||/_/  /_/\__,_/_/ /_/\__,_/\____/    /____/              /____/  ||
       \==================================================================/
)";
        }
        else if (escenario == 3) {
            cursor(0, 30);
            cout << R"(
      /==================================================================\
      ||    __  ___                __          ___                 _____||
      ||   /  |/  /_  ______  ____/ /___      |__ \               |__  /||
      ||  / /|_/ / / / / __ \/ __  / __ \     __/ /    ______      /_ < ||
      || / /  / / /_/ / / / / /_/ / /_/ /    / __/    /_____/    ___/ / ||
      ||/_/  /_/\__,_/_/ /_/\__,_/\____/    /____/              /____/  ||
      \==================================================================/
)";
        }
    }
}

// ANIMACION PUERTA ABIERTA - CERRADA
void anim_puerta_cerrada(int n, int x, int y) {
    color(1);
    int puerta[10][10] = {
        {5, 5, 5, 5, 5, 5, 5, 5, 5, 5}, {5, n, n, n, n, n, n, n, n, 5},
        {5, n, n, n, n, n, n, n, n, 5}, {5, n, n, n, n, n, n, n, n, 5},
        {5, n, n, n, n, n, n, n, n, 5}, {5, n, n, n, n, n, n, n, 16, 5},
        {5, n, n, n, n, n, n, n, n, 5}, {5, n, n, n, n, n, n, n, n, 5},
        {5, n, n, n, n, n, n, n, n, 5}, {5, n, n, n, n, n, n, n, n, 5} };
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            color(puerta[i][j]);
            cursor(x + j, y + i);
            cout << " ";
        }
    }
    color(1);
}

void anim_puerta_abierta(int n, int x, int y) {
    color(1);
    int puerta[10][10] = {
        {5, 5, 5, 5, 5, 5, 5, 5, 5, 5}, {5, n, 1, 1, 1, 1, 1, 1, 1, 5},
        {5, n, 1, 1, 1, 1, 1, 1, 1, 5}, {5, n, 1, 1, 1, 1, 1, 1, 1, 5},
        {5, n, 1, 1, 1, 1, 1, 1, 1, 5}, {5, n, 1, 1, 1, 1, 1, 1, 1, 5},
        {5, n, 1, 1, 1, 1, 1, 1, 1, 5}, {5, n, 1, 1, 1, 1, 1, 1, 1, 5},
        {5, n, 1, 1, 1, 1, 1, 1, 1, 5}, {5, n, 1, 1, 1, 1, 1, 1, 1, 5} };
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            color(puerta[i][j]);
            cursor(x + j, y + i);
            cout << " ";
        }
    }
    color(1);
}

void animacion_puerta(int color, int x, int y) {
    system("cls");
    anim_puerta_cerrada(color, x, y);
    _sleep(1000);
    anim_puerta_abierta(color, x, y);
    _sleep(1000);
}