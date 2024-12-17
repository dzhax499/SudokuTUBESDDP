# Sudoku Berbasis Teks

## Deskripsi
Program ini adalah permainan **Sudoku** berbasis teks yang memungkinkan pemain untuk:
1. Memilih **tingkat kesulitan** (Mudah, Menengah, Sulit).
2. Mengisi angka kosong pada papan Sudoku sesuai aturan.
3. Memantau waktu bermain dan sisa nyawa.
4. Menyimpan riwayat permainan (MENANG/KALAH) ke dalam file log.

Program ini dikembangkan sebagai bagian dari tugas oleh:
- **Dzakir Tsabit Asy Syafiq** / 241511071
- **Muhammad Raihan Abubakar** / 241511084

## Aturan Permainan Sudoku

1. **Isi papan Sudoku 9x9**:
   - Setiap baris harus berisi angka **1-9** tanpa duplikat.
   - Setiap kolom harus berisi angka **1-9** tanpa duplikat.
   - Setiap kotak kecil **3x3** harus berisi angka **1-9** tanpa duplikat.
2. Anda memiliki sejumlah **nyawa** (kesempatan) untuk memasukkan angka yang benar. Setiap kesalahan akan mengurangi nyawa.
3. Permainan akan berakhir jika Anda:
   - Berhasil menyelesaikan papan Sudoku (MENANG).
   - Kehabisan nyawa (KALAH).

## Cara Bermain

### 1. Menjalankan Program
Pastikan Anda memiliki file berikut:
- `utils.c`
- `history.c`
- `timer.c`
- `game.c`
- `header.h`

Kompilasi semua file menggunakan perintah berikut (pada terminal atau cmd):

```
gcc -o sudoku game.c utils.c history.c timer.c
```

Jalankan program dengan:

```
./sudoku
```

### 2. Memilih Tingkat Kesulitan
Setelah program dijalankan, Anda akan diminta memilih tingkat kesulitan:
- **1** = Mudah
- **2** = Menengah
- **3** = Sulit

Contoh:
```
Pilih tingkat kesulitan:
1. Mudah
2. Menengah
3. Sulit
Pilih (1-3): 2
```

### 3. Mengisi Papan Sudoku
Setelah papan ditampilkan, Anda diminta memasukkan angka dengan format berikut:

```
Masukkan baris, kolom, dan angka (contoh: 3 5 7):
```

- **Baris**: Nomor baris (1-9).
- **Kolom**: Nomor kolom (1-9).
- **Angka**: Angka yang ingin dimasukkan (1-9).

Jika langkah tidak valid, program akan memberi tahu alasannya (misalnya angka sudah ada di baris, kolom, atau kotak 3x3).

Contoh input:
```
Masukkan baris, kolom, dan angka (contoh: 3 5 7): 3 5 7
```

### 4. Memantau Waktu dan Nyawa
- Program akan menampilkan **waktu bermain** dalam format **HH:MM:SS**.
- Jika Anda salah memasukkan angka, nyawa akan berkurang.

Contoh:
```
Nyawa Anda tersisa 2
```

### 5. Menang atau Kalah
- Anda menang jika berhasil mengisi semua sel dengan angka yang benar.
- Anda kalah jika kehabisan nyawa.

Pesan kemenangan atau kekalahan akan ditampilkan beserta durasi permainan:
```
Selamat, Anda menang! Waktu bermain: 00:10:45
```
atau
```
Game Over! Anda bermain selama 00:15:30
```

## Riwayat Permainan
Setiap sesi permainan akan dicatat dalam file `player_history.dat`. Riwayat mencakup:
- **Durasi permainan** (HH:MM:SS).
- **Status** (MENANG/KALAH).

Untuk melihat riwayat permainan, jalankan program ini:

```
./sudoku_history
```

## Persyaratan Sistem
- Compiler **GCC** untuk menjalankan program C.
- Sistem operasi **Windows** atau **Linux**.

## Kontributor
- **Dzakir Tsabit Asy Syafiq** / 241511071
- **Muhammad Raihan Abubakar** / 241511084

Selamat bermain dan semoga menyelesaikan papan Sudoku dengan sukses!
