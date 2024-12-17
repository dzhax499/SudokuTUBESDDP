// Nama Program : game.c
// Deskripsi    : Program permainan Sudoku berbasis teks yang memungkinkan pengguna 
//                memilih tingkat kesulitan, mengisi angka yang hilang, serta memantau 
//                waktu bermain dan jumlah nyawa. Program juga mencatat riwayat permainan 
//                dan memberikan umpan balik kepada pemain jika mereka menang atau kalah.
// Pembuat      : Dzakir Tsabit Asy Syafiq / 241511071
//                Muhammad Raihan Abubakar / 241511084
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <string.h>
#include "game.h"

// Fungsi untuk memastikan input tingkat kesulitan valid
// Deskripsi: Fungsi ini meminta input dari pemain (1-3) untuk memilih tingkat kesulitan dan memvalidasi input.
int setDifficulty(int board[SIZE][SIZE], int difficulty) {
    int filledCells;
    switch (difficulty) {
        case 1: // Mudah
            filledCells = 80;
            break;
        case 2: // Menengah
            filledCells = 20;
            break;
        case 3: // Sulit
            filledCells = 10;
            break;
        default:
            printf("Pilihan tidak valid. pilih angka dari 1-3\n");
            break;
    }

    int removedCells = SIZE * SIZE - filledCells;
    RemovedCell(board, removedCells);
    return removedCells;
}
//memastikan tingkat kesulitan valid
int chooseDifficulty() {
    int difficulty;
    
    do {
        printf("Pilih tingkat kesulitan:\n1. Mudah\n2. Menengah\n3. Sulit\nPilih (1-3): ");
        if (scanf("%d", &difficulty) != 1) {
            printf("Input tidak valid. Silakan masukkan angka dari 1 hingga 3.\n");
            while ((getchar()) != '\n'); // Bersihkan buffer input
            difficulty = 0;
        } else if (difficulty < 1 || difficulty > 3) {
            printf("Pilihan tidak valid. Silakan pilih angka dari 1-3.\n");
        }
    } while (difficulty < 1 || difficulty > 3);
    
    return difficulty;
}

//waktu timer
void displayGameStatus(int board[SIZE][SIZE], clock_t startTime) {
    clock_t endTime = clock();
    double elapsed = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;

    // Format waktu dalam format jam:menit:detik
    int jam = (int)elapsed / 3600;
    int menit = ((int)elapsed % 3600) / 60;
    int detik = (int)elapsed % 60;

    // Tampilkan papan dan timer
    printBoard(board);
    printf("Waktu bermain: %02d:%02d:%02d\n", jam, menit, detik); // Menampilkan waktu dalam format HH:MM:SS
}

//input pemain
int processPlayerMove(int board[SIZE][SIZE], int row, int col, int num) {
    row--; // Konversi ke indeks array (0-based)
    col--; // Konversi ke indeks array (0-based)

    int moveResult = attemptMove(board, board, row, col, num);
    return moveResult;
}

//menang atau kalah
void handleGameEnd(int board[SIZE][SIZE], clock_t startTime, int lives, int won, char difficultyLevel[16]) {
    // Menghitung waktu yang telah berlalu menggunakan startTime yang sudah ada
    clock_t endTime = clock();
    double finalElapsed = ((double)(endTime - startTime)) / CLOCKS_PER_SEC;

    // Format waktu dalam format jam:menit:detik
    int jam = (int)finalElapsed / 3600;
    int menit = ((int)finalElapsed % 3600) / 60;
    int detik = (int)finalElapsed % 60;

    if (won) {
        printf("Selamat, Anda menang! Waktu bermain: %02d:%02d:%02d\n", jam, menit, detik);
        displayAndLogTime("player_history.dat", finalElapsed, "MENANG");
    } else {
        printf("Game Over! Anda bermain selama %02d:%02d:%02d\n", jam, menit, detik);
        displayAndLogTime("player_history.dat", finalElapsed, "KALAH");
    }

    printf("Tingkat kesulitan: %s\n", difficultyLevel);
    printf("Tekan tombol apapun untuk keluar...\n");
    getchar(); // Menunggu input
    getchar();
}
//nyawa berkurang
void handleLives(int *lives) {
    (*lives)--;
    printf("Nyawa Anda tersisa %d\n", *lives);
}

//Prosedur untuj meyalin papan dari papan solusi ke papan game

void copySolutionBoard(int board[SIZE][SIZE]) {
    int solution[SIZE][SIZE] = {
        {5, 3, 4, 6, 7, 8, 9, 1, 2},
        {6, 7, 2, 1, 9, 5, 3, 4, 8},
        {1, 9, 8, 3, 4, 2, 5, 6, 7},
        {8, 5, 9, 7, 6, 1, 4, 2, 3},
        {4, 2, 6, 8, 5, 3, 7, 9, 1},
        {7, 1, 3, 9, 2, 4, 8, 5, 6},
        {9, 6, 1, 5, 3, 7, 2, 8, 4},
        {2, 8, 7, 4, 1, 9, 6, 3, 5},
        {3, 4, 5, 2, 8, 6, 1, 7, 9}
    };

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = solution[i][j];
        }
    }
}

// Prosedur untuk menghapus cell yang sudah ada di papan dengan jumlah tertentu
void RemovedCell(int board[SIZE][SIZE], int removedCells) {
    int indices[SIZE * SIZE];
    for (int i = 0; i < SIZE * SIZE; i++) {
        indices[i] = i;
    }

    srand(time(NULL)); 
    for (int i = SIZE * SIZE - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = indices[i];
        indices[i] = indices[j];
        indices[j] = temp;
    }

    for (int k = 0; k < removedCells; k++) {
        int row = indices[k] / SIZE;
        int col = indices[k] % SIZE;
        board[row][col] = 0;
    }
}

//Prosedur untuk memulai game permainan jika pemain memilih 1
void startGame() {
    int board[SIZE][SIZE];
    int lives = 10;
    int row, col, num, moveResult;
    int difficulty;
    clock_t startTime;
    char difficultyLevel[16];

    // Pilih tingkat kesulitan
    difficulty = chooseDifficulty();

    // Set tingkat kesulitan
    switch (difficulty) {
        case 1:
            strcpy(difficultyLevel, "Mudah");
            break;
        case 2:
            strcpy(difficultyLevel, "Menengah");
            break;
        case 3:
            strcpy(difficultyLevel, "Sulit");
            break;
    }

    // Set papan dan solusi berdasarkan tingkat kesulitan
    setDifficulty(board, difficulty);
    copySolutionBoard(board);
    int removedCells = setDifficulty(board, difficulty);
    RemovedCell(board, removedCells);

    // Clear layar
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    // Tampilkan status awal
    printf("Selamat datang di Sudoku!\n");
    printf("Tingkat kesulitan: %s\n", difficultyLevel);
    printf("Tebak angka yang hilang. Anda memiliki %d nyawa.\n", lives);

    startTime = clock(); // Mulai timer

    // Permainan utama
    while (lives > 0) {
        displayGameStatus(board, startTime);

        if (isBoardComplete(board)) {
            handleGameEnd(board, startTime, lives, 1, difficultyLevel);
            break;
        }

        printf("Masukkan baris (1-9), kolom (1-9), dan angka (1-9) (misal: 1 2 5): ");
        scanf("%d %d %d", &row, &col, &num);

        moveResult = processPlayerMove(board, row, col, num);

        // Jika langkah salah, kurangi nyawa
        if (moveResult == 0) {
            handleLives(&lives);
        }

        // Jika nyawa habis, selesai
        if (lives == 0) {
            handleGameEnd(board, startTime, lives, 0, difficultyLevel);
            break;
        }
    }
}
