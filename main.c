#include <stdio.h>
#include <windows.h>
#include "game.h"

int main() {
    int choice;

    do {
        printf(" ____  _   _ ____   ___  _  ___   _ \n");
        printf("/ ___|| | | |  _ \\ / _ \\| |/ / | | |\n");
        printf("\\___ \\| | | | | | | | | | ' /| | | |\n");
        printf(" ___) | |_| | |_| | |_| | . \\| |_| |\n");
        printf("|____/ \\___/|____/ \\___/|_|\\_\\\\___/ \n");
        printf(" \n");
        printf("Created by Dzakir Tsabit | 241511071\n");
        printf("Muhammad Raihan Abubakar | 241511084\n");
        printf("\n");
        printf("Menu Utama:\n");
        printf("1. Bermain\n");
        printf("2. Riwayat waktu pemain\n");
        printf("3. Keluar\n");
        printf("Pilih (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            startGame();
            break;
        case 2:
            displayPlayerHistory("player_history.dat");
            break;
        case 3:
            printf("Terima kasih telah bermain.\n");
            break;
        default:
            printf("Pilihan tidak valid. Coba lagi dalam 5 detik.\n");
            Sleep(5000);
            system("cls");
            break;
        }
    } while (choice != 3);

    return 0;
}
