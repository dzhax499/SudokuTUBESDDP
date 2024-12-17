// Nama Program : utils.c
// Deskripsi    : Program ini mengelola tampilan papan Sudoku, memeriksa validitas langkah pemain, 
//                serta memeriksa status permainan (selesai atau belum). 
//                Program ini memungkinkan pemain memasukkan angka ke dalam papan dan 
//                memberi tahu pemain jika langkah tersebut valid atau tidak.
// Pembuat      : Dzakir Tsabit Asy Syafiq / 241511071
//                Muhammad Raihan Abubakar / 241511084
#include <stdio.h>
#include "game.h"

// Fungsi printBoard
// Deskripsi    : Menampilkan papan Sudoku ke layar dengan format yang rapi, termasuk garis pembatas 
//                antara baris dan kolom 3x3 untuk kejelasan tampilan.
// Parameter    : 
//   - board: Matriks 9x9 yang berisi angka-angka Sudoku (0 menunjukkan sel kosong).
// Algoritma    : 
// 1. Tampilkan game kolom (1-9) di bagian atas papan.
// 2. Loop melalui setiap baris (0-8) dan kolom (0-8) dari matriks board.
// 3. Untuk setiap 3 baris dan 3 kolom, tampilkan garis pembatas ('+-------+-------+-------+').
// 4. Angka pada papan ditampilkan. Jika angka adalah 0, tampilkan "." sebagai pengganti angka kosong.
void printBoard(int board[SIZE][SIZE])
{
    printf("\n    1 2 3   4 5 6   7 8 9\n");
    printf("  +-------+-------+-------+\n");
    for (int i = 0; i < SIZE; i++)
    {
        if (i % 3 == 0 && i != 0)
        {
            printf("  +-------+-------+-------+\n");
        }
        printf("%d | ", i + 1);
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == 0)
            {
                printf(". ");
            }
            else
            {
                printf("%d ", board[i][j]);
            }
            if ((j + 1) % 3 == 0 && j != SIZE - 1)
            {
                printf("| ");
            }
        }
        printf("|\n");
    }
    printf("  +-------+-------+-------+\n");
}

// Prosedur isBoardComplete
// Deskripsi    : Memeriksa apakah semua sel di papan telah terisi (tidak ada angka 0).
// Parameter    : 
//   - board: Matriks 9x9 yang berisi angka-angka Sudoku.
// Return       : 1 (True) jika papan lengkap (tidak ada sel kosong), 0 (False) jika masih ada sel kosong.
// Algoritma    : 
// 1. Loop melalui setiap baris dan kolom dari matriks board.
// 2. Jika ditemukan angka 0, return 0 (papan belum lengkap).
// 3. Jika tidak ada angka 0, return 1 (papan sudah lengkap).
int isBoardComplete(int board[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (board[i][j] == 0)
            {
                return 0;
            }
        }
    }
    return 1;
}

// Fungsi isValidMove
// Deskripsi    : Memeriksa apakah angka yang dimasukkan ke papan valid atau tidak.
// Parameter    : 
//   - board: Matriks 9x9 yang berisi angka-angka Sudoku.
//   - row, col: Indeks baris dan kolom dari sel di mana angka akan ditempatkan.
//   - num: Angka yang ingin dimasukkan ke dalam papan (1-9).
// Return       : 1 (True) jika langkah valid, 0 (False) jika langkah tidak valid.
// Algoritma    : 
// 1. Periksa apakah angka tersebut sudah ada di baris `row`. Jika ya, tampilkan pesan kesalahan dan return 0.
// 2. Periksa apakah angka tersebut sudah ada di kolom `col`. Jika ya, tampilkan pesan kesalahan dan return 0.
// 3. Periksa apakah angka tersebut sudah ada di kotak 3x3. Jika ya, tampilkan pesan kesalahan dan return 0.
// 4. Jika semua pemeriksaan lolos, return 1 (langkah valid).
int isValidMove(int board[SIZE][SIZE], int row, int col, int num)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (board[row][i] == num)
        {
            printf("angka yang anda masukan pada titik (%d,%d) tidak valid karena angka sudah berada pada baris %d. \n", row + 1, col + 1, row + 1);
            return 0; // jika angka yang dimasukan sudah ada dalam baris yang sama
        }
        if (board[i][col] == num)
        {
            printf("angka yang anda masukan pada titik (%d, %d) tidak valid karena angka sudah berada pada kolom %d. \n", row + 1, col + 1, col + 1);
            return 0; // jika angka yang dimasukan sudah ada dalam kolom yang sama
        }
    }
    int boxStartRow = row - row % 3;
    int boxStartCol = col - col % 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[boxStartRow + i][boxStartCol + j] == num)
            {
                printf("angka yang anda masukan pada titik (%d,%d) tidak valid karena angka sudah terdapat dalam papan 3x3 yang sama. \n", row + 1, col + 1);
                return 0; // Jika angka ada di kotak kecil 3x3, move tidak valid
            }
        }
    }
    return 1; // Angka bisa ditempatkan
}

// Fungsi attemptMove
// Deskripsi    : Mencoba memasukkan angka ke dalam papan, jika langkah valid, angka akan dimasukkan.
// Parameter    : 
//   - board: Matriks 9x9 yang berisi angka-angka Sudoku.
//   - solution: Matriks solusi (digunakan untuk memvalidasi langkah).
//   - row, col: Indeks baris dan kolom dari sel di mana angka akan ditempatkan.
//   - num: Angka yang ingin dimasukkan ke dalam papan (1-9).
// Return       : 1 (True) jika langkah berhasil, 0 (False) jika langkah gagal.
// Algoritma    : 
// 1. Jika angka lebih dari 9, tampilkan pesan kesalahan dan return 0.
// 2. Periksa apakah sel sudah terisi. Jika ya, tampilkan pesan kesalahan dan return 0.
// 3. Periksa apakah langkah valid dengan memanggil `isValidMove()`. 
//    Jika valid, masukkan angka ke dalam papan dan return 1.
int attemptMove(int board[SIZE][SIZE], int solution[SIZE][SIZE], int row, int col, int num)
{

    if (num > 9)
    {
        printf("angka yang dimasukan tidak valid!! \n");
        return 0; // jika angka yang dimasukan lebih dari 9, tidak valid
    }
    if (board[row][col] != 0)
    {
        printf("Sel sudah terisi! Coba tempatkan angka lain.\n");
        return 0; // Jika sel sudah terisi
    }

    if (isValidMove(board, row, col, num))
    {
        board[row][col] = num; // Tempatkan angka jika valid
        return 1;
    }
    else
    {
        return 0;
    }
}