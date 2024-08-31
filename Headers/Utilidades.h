#pragma once
#include "iostream"
#include "string"
#include "conio.h"

using namespace std;
using namespace System;

void iniciar() {
    Console::SetWindowSize(80, 40);
    srand(time(nullptr));
}

void cursor(int x, int y) {
    Console::CursorVisible = false;
    Console::SetCursorPosition(x, y);
}

int aleatorio(int min, int max) { return rand() % (max - min + 1) + min; }

void color(int n) {
    switch (n) {
    case 1:
        Console::BackgroundColor = ConsoleColor::Black;
        break;
    case 2:
        Console::BackgroundColor = ConsoleColor::Blue;
        break;
    case 3:
        Console::BackgroundColor = ConsoleColor::Cyan;
        break;
    case 4:
        Console::BackgroundColor = ConsoleColor::DarkBlue;
        break;
    case 5:
        Console::BackgroundColor = ConsoleColor::DarkCyan;
        break;
    case 6:
        Console::BackgroundColor = ConsoleColor::DarkGray;
        break;
    case 7:
        Console::BackgroundColor = ConsoleColor::DarkGreen;
        break;
    case 8:
        Console::BackgroundColor = ConsoleColor::DarkMagenta;
        break;
    case 9:
        Console::BackgroundColor = ConsoleColor::DarkRed;
        break;
    case 10:
        Console::BackgroundColor = ConsoleColor::DarkYellow;
        break;
    case 11:
        Console::BackgroundColor = ConsoleColor::Gray;
        break;
    case 12:
        Console::BackgroundColor = ConsoleColor::Green;
        break;
    case 13:
        Console::BackgroundColor = ConsoleColor::Magenta;
        break;
    case 14:
        Console::BackgroundColor = ConsoleColor::Red;
        break;
    case 15:
        Console::BackgroundColor = ConsoleColor::White;
        break;
    case 16:
        Console::BackgroundColor = ConsoleColor::Yellow;
        break;
    }
}

void color_text(int n) {
    switch (n) {
    case 1:
        Console::ForegroundColor = ConsoleColor::Black;
        break;
    case 2:
        Console::ForegroundColor = ConsoleColor::Blue;
        break;
    case 3:
        Console::ForegroundColor = ConsoleColor::Cyan;
        break;
    case 4:
        Console::ForegroundColor = ConsoleColor::DarkBlue;
        break;
    case 5:
        Console::ForegroundColor = ConsoleColor::DarkCyan;
        break;
    case 6:
        Console::ForegroundColor = ConsoleColor::DarkGray;
        break;
    case 7:
        Console::ForegroundColor = ConsoleColor::DarkGreen;
        break;
    case 8:
        Console::ForegroundColor = ConsoleColor::DarkMagenta;
        break;
    case 9:
        Console::ForegroundColor = ConsoleColor::DarkRed;
        break;
    case 10:
        Console::ForegroundColor = ConsoleColor::DarkYellow;
        break;
    case 11:
        Console::ForegroundColor = ConsoleColor::Gray;
        break;
    case 12:
        Console::ForegroundColor = ConsoleColor::Green;
        break;
    case 13:
        Console::ForegroundColor = ConsoleColor::Magenta;
        break;
    case 14:
        Console::ForegroundColor = ConsoleColor::Red;
        break;
    case 15:
        Console::ForegroundColor = ConsoleColor::White;
        break;
    case 16:
        Console::ForegroundColor = ConsoleColor::Yellow;
        break;
    }
}