#include <stdio.h> //Menyediakan fungsi-fungsi printf() dan scanf()
#include <stdlib.h> //Menyediakan fungsi-fungsi standar untuk alokasi memori dinamis, malloc()

void koboImaginaryChess(int i, int j, int size, int *chessBoard) {
    //Mendefinisikan langkah-langkah yang mungkin dilakukan oleh bidak kuda.
    int moves[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
                       {1, -2}, {1, 2}, {2, -1}, {2, 1}};

    //Melakukan pengecekan dan menandai posisi yang valid di papan catur.
    for (int k = 0; k < 8; k++) { //Looping melalui setiap kemungkinan langkah kuda.
        int newRow = i + moves[k][0]; //Menghitung baris baru berdasarkan langkah kuda.
        int newCol = j + moves[k][1]; //Menghitung kolom baru berdasarkan langkah kuda.

        //Memastikan posisi baru berada dalam batas papan catur.
        if (newRow >= 0 && newRow < size && newCol >= 0 && newCol < size) {
            *(chessBoard + newRow * size + newCol) = 1; //Menandai posisi yang valid di papan catur.
        }
    }
}
int main() {
    int i, j; //Deklarasi variabel i dan j untuk menyimpan posisi awal bidak di papan catur.
    printf(""); //Menampilkan pesan yang meminta input posisi awal bidak dari pengguna.
    scanf("%d %d", &i, &j); //Membaca input posisi awal bidak dari pengguna.

    int size = 8; //Deklarasi dan inisialisasi variabel size yang menentukan ukuran papan catur.
    int chessBoard[size][size]; //Deklarasi matriks 8x8 sebagai papan catur.

    //Menginisialisasi papan catur dengan nilai awal 0
    for (int row = 0; row < size; row++) { //Looping melalui setiap baris papan catur.
        for (int col = 0; col < size; col++) { //Looping melalui setiap kolom papan catur.
            chessBoard[row][col] = 0; //Mengatur nilai pada posisi (row, col) menjadi 0.
        }
    }

    //Memanggil fungsi koboImaginaryChess untuk menandai posisi yang dapat dicapai
    koboImaginaryChess(i, j, size, (int *)chessBoard); //Memanggil fungsi untuk melakukan simulasi pergerakan bidak dan menandai posisi yang dapat dicapai.

    //Menampilkan output hasil simulasi
    printf("\n"); //Menampilkan pesan untuk output hasil simulasi.
    for (int row = 0; row < size; row++) { //Looping melalui setiap baris papan catur.
        for (int col = 0; col < size; col++) { //Looping melalui setiap kolom papan catur.
            printf("%d", chessBoard[row][col]); //Menampilkan nilai pada posisi (row, col) dari papan catur.
        }
        printf("\n"); //Pindah ke baris baru setelah setiap baris papan catur ditampilkan.
    }

    return 0; //Mengembalikan nilai 0 yang menandakan program berakhir dengan sukses.
}
