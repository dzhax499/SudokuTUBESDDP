// Nama Program : player_history.c
// Deskripsi    : Program ini menampilkan riwayat permainan dari file log. 
//                Riwayat berisi durasi waktu permainan dan status permainan (MENANG atau KALAH) 
//                yang sebelumnya dicatat ke file log.
// Pembuat      : Dzakir Tsabit Asy Syafiq / 241511071
//                Muhammad Raihan Abubakar / 241511084
#include <stdio.h>
#include "game.h"

// Prosedur displayPlayerHistory
// Deskripsi    : Fungsi ini membaca dan menampilkan isi file log riwayat pemain ke layar. 
//                Log mencakup durasi permainan dan status permainan (MENANG/KALAH).
// Parameter    : 
//   - filename: Nama file yang berisi riwayat permainan (contoh: "player_history.dat").
// 
// Algoritma    : 
// 1. Buka file log dalam mode baca ("r").
// 2. Jika file gagal dibuka, tampilkan pesan kesalahan dan keluar dari fungsi.
// 3. Tampilkan game.h "Riwayat pemain" di layar.
// 4. Baca setiap baris dari file menggunakan `fgets()` dan tampilkan ke layar.
// 5. Tutup file setelah selesai membaca semua isi file.
// 6. Tampilkan footer "----------------------" sebagai penutup tampilan riwayat.
void displayPlayerHistory(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Gagal membuka file riwayat");
        return;
    }

    char line[100];
    printf("\n--- Riwayat pemain ---\n");
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);
    printf("\n----------------------\n");
}
