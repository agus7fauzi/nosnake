// Nosnake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <Windows.h>
#include <time.h>

using namespace std;

void gotoxy(int x, int y)
{
    COORD coordinates; // coordinate is declared as COORD
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

int main()
{
    int i;
    int playerX, playerY, enemyX, enemyY, seedX, seedY, playerScore, enemyScore = 0;
    char ch;

    srand(time(NULL));

    for (i = 0; i < 79; i++)
    {
        gotoxy(i, 0); cout << "#";
        gotoxy(i, 40); cout << "#";

        if (i < 40)
        {
            gotoxy(0, i); cout << "#";
            gotoxy(79, i); cout << "#";
        }
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
