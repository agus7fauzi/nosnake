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
    int i = 0;
    int playerX, playerY, enemyX, enemyY, seedX, seedY, playerScore = 0, enemyScore = 0;
    char ch = 'x';

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

    playerX = rand() % 40 + 20;
    playerY = rand() % 20 + 10;
    gotoxy(playerX, playerY); cout << '\2';

    enemyX = rand() % 40 + 20;
    enemyY = rand() % 20 + 10;
    gotoxy(enemyX, enemyY); cout << '\1';

    seedX = rand() % 74 + 3;
    seedY = rand() % 35 + 2;
    gotoxy(seedX, seedY); cout << '@';

    int direction = 0;

    int delay = 0, limit = 5000;

    while (true)
    {
        delay++;

        if (delay > limit)
        {
            gotoxy(0, 0); cout << " You : " << playerScore << " Enemy : " << enemyScore << " ";
            delay = 0;
            switch(direction)
            {
            case 72: playerY--; break;
            case 75: playerX--; break;
            case 80: playerY++; break;
            case 77: playerX++; break;
            }

            if (direction)
            {
                if (seedX == enemyX)
                {
                    if (seedY > enemyY) enemyY++;
                    else if (seedY < enemyY) enemyY--;
                }
                if (seedX > enemyX) enemyX++; else if (seedX < enemyX) enemyX--;
            }

            gotoxy(enemyX, enemyY); cout << '\1';
            gotoxy(playerX, playerY); cout << '\2';

            if (enemyX == seedX && enemyY == seedY)
            {
                seedX = rand() % 74 + 3;
                seedY = rand() % 35 + 2;
                gotoxy(seedX, seedY); cout << '@';
                enemyScore += 100;
                limit -= 100;

            }
            if (playerX == seedX && playerY == seedY)
            {
                seedX = rand() % 74 + 3;
                seedY = rand() % 35 + 2;
                gotoxy(seedX, seedY); cout << '@';
                playerScore += 100;
                limit -= 100;
            }
        }

        if (playerX > 78 || playerX < 1 || playerY>39 || playerY < 1)
        {
            gotoxy(40, 20); cout << "GAME OVER ! ";
            if (playerScore > enemyScore)
                cout << "You Win "; else if (playerScore < enemyScore) cout << "You Lose"; else cout << "Draw!";

            break;
        }


        if (_kbhit())
        {
            //penekanan tombol
            ch = _getch();

            if (ch == 32)
            {
                gotoxy(playerX, playerY); cout << ' ';
                switch (direction)
                {
                case 72: playerY -= 5; break;
                case 75: playerX -= 5; break;
                case 80: playerY += 5; break;
                case 77: playerX += 5; break;
                }

            }

            if (ch < 0)
            {
                ch = _getch();
                if (ch == 72 || ch == 80 || ch == 75 || ch == 77)
                {
                    if (ch % 2 && !(direction % 2))direction = ch;
                    if (!(ch % 2) && direction % 2)direction = ch;

                }
            }
        }
    }
    // return EXIT_SUCCESS;
}
