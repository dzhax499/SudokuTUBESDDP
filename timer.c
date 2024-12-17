// Nama Program : timer.c
// Deskripsi    : Program ini mencatat dan menampilkan durasi permainan Sudoku ke dalam file log. 
//                Durasi waktu permainan dicatat dalam format HH:MM:SS bersama status permainan 
//                (MENANG atau KALAH). File log digunakan untuk menyimpan riwayat waktu bermain pemain.
// Pembuat      : Dzakir Tsabit Asy Syafiq / 241511071
//                Muhammad Raihan Abubakar / 241511084
#include <stdio.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "game.h"

// Prosedur displayAndLogTime
// Deskripsi    : Fungsi ini menghitung dan mencatat durasi permainan ke file log. 
//                Durasi waktu dihitung dari waktu mulai hingga waktu selesai dan 
//                ditampilkan dalam format HH:MM:SS. Status permainan (MENANG/KALAH) juga 
//                disertakan dalam file log.
// Parameter    : 
//   - filename: Nama file tempat riwayat waktu akan disimpan (contoh: "player_history.dat").
//   - elapsedTime: Waktu yang telah berlalu sejak awal permainan dalam satuan detik (double).
//   - status: Status permainan ("MENANG" atau "KALAH").
// 
// Algoritma    : 
// 1. Hitung jam, menit, dan detik dari elapsedTime.
// 2. Buat string log yang memuat durasi waktu dan status permainan.
// 3. Buka file log dalam mode append ("a").
// 4. Jika file gagal dibuka, tampilkan pesan kesalahan.
// 5. Tulis string log ke file dan tutup file.
// 6. Tampilkan pesan bahwa riwayat waktu telah disimpan.
void displayAndLogTime(const char *filename, double elapsedTime, const char *status) {
    int jam = (int) elapsedTime / 3600;
    int menit = ((int) elapsedTime % 3600) / 60;
    int detik = (int) elapsedTime % 60;

    char logEntry[50];
    snprintf(logEntry, sizeof(logEntry), "Durasi: %02d:%02d:%02d - %s\n", jam, menit, detik, status);

    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        perror("Gagal membuka file untuk menyimpan riwayat waktu");
        return;
    }

    fwrite(logEntry, sizeof(char), strlen(logEntry), file);
    fclose(file);

    printf("Durasi permainan telah disimpan ke file '%s'.\n", filename);
}
