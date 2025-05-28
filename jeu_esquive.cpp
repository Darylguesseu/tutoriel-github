#include <iostream>
#include <conio.h> // _kbhit, _getch
#include <windows.h> // Sleep, system
#include <ctime>
using namespace std;

const int width = 20;
const int height = 10;
int playerPos = width / 2;
int obstacleX = rand() % width;
int obstacleY = 0;
bool gameOver = false;

void draw() {
    system("cls");
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (y == obstacleY && x == obstacleX)
                cout << "#";
            else if (y == height - 1 && x == playerPos)
                cout << "P";
            else
                cout << " ";
        }
        cout << endl;
    }
}

void input() {
    if (_kbhit()) {
        char key = _getch();
        if (key == 'a' && playerPos > 0)
            playerPos--;
        else if (key == 'd' && playerPos < width - 1)
            playerPos++;
    }
}

void logic() {
    obstacleY++;
    if (obstacleY == height - 1) {
        if (obstacleX == playerPos) {
            gameOver = true;
        } else {
            obstacleX = rand() % width;
            obstacleY = 0;
        }
    }
}

int main() {
    srand(time(0));
    while (!gameOver) {
        draw();
        input();
        logic();
        Sleep(100); // ralentir le jeu
    }

    cout << "\n💥 Game Over! Tu as été touché.\n";
    return 0;
}
