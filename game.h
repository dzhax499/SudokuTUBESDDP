// Nama Program : game.h
// Deskripsi    : game file yang mendeklarasikan fungsi dan prosedur 
//                untuk mendukung logika game Sudoku, pengelolaan waktu, 
//                pencatatan riwayat pemain, dan kontrol permainan.
// Pembuat      : Dzakir Tsabit Asy Syafiq / 241511071
//                Muhammad Raihan Abubakar / 241511084
#ifndef GAME_H
#define GAME_H
#include <stdlib.h>
#include <string.h>

#define SIZE 9  // Ukuran papan Sudoku 9x9

// Deklarasi fungsi dari berbagai modul
// Modul logika game atau utilitas
void printBoard(int board[SIZE][SIZE]);
int isValidMove(int board[SIZE][SIZE], int row, int col, int num);
int attemptMove(int board[SIZE][SIZE], int solution[SIZE][SIZE], int row, int col, int num);
int isBoardComplete(int board[SIZE][SIZE]);

// Modul Timer & Logging
void displayAndLogTime(const char *filename, double elapsedTime, const char *status);

// Modul History
void displayPlayerHistory(const char *filename);

// Modul Game
void startGame();
int setDifficulty(int board[SIZE][SIZE], int difficulty);
void copySolutionBoard(int board[SIZE][SIZE]);
void RemovedCell(int board[SIZE][SIZE], int removedCells);

#endif
