#include <stdio.h> //Menyediakan fungsi-fungsi printf() dan scanf()
#include <stdlib.h> //Menyediakan fungsi-fungsi standar untuk alokasi memori dinamis, malloc()

//Deklarasi fungsi untuk mencetak array karakter dengan langkah pertukaran
void printArray(char *arr, int size, int step) {
    printf("pertukaran %d: ", step); //Menampilkan langkah pertukaran
    for (int i = 0; i < size; i++) {
        printf("%c ", arr[i]); //Mencetak setiap elemen dari array
    }
    printf("\n");
}

//Deklarasi fungsi untuk menukar dua elemen karakter
void swap(char *a, char *b) {
    char temp = *a; //Menyimpan nilai a ke dalam variabel sementara temp
    *a = *b; //Mengganti nilai a dengan nilai b
    *b = temp; //Mengganti nilai b dengan nilai yang disimpan di temp
}

//Deklarasi fungsi untuk mencari indeks nilai minimum dalam array karakter dalam rentang tertentu
int findMinIndex(char *arr, int start, int end) {
    int min_index = start; //Menginisialisasi indeks minimum dengan indeks awal
    for (int i = start + 1; i <= end; i++) {
        //Mengecek apakah nilai saat ini lebih kecil dari nilai minimum yang ada
        //atau jika nilai saat ini adalah 'Q' dan nilai minimum adalah 'K'
        if (arr[i] < arr[min_index] || (arr[i] == 'Q' && arr[min_index] == 'K')) {
            min_index = i; //Jika kondisi terpenuhi, memperbarui indeks minimum
        }
    }
    return min_index; //Mengembalikan indeks nilai minimum
}

void selectionSort(char *arr, int n) {
    int steps = 0; //Inisialisasi langkah untuk menghitung jumlah langkah yang diperlukan untuk melakukan sorting.
    for (int i = 0; i < n - 1; i++) { //Looping melalui seluruh elemen array kecuali elemen terakhir.
        int min_index = findMinIndex(arr, i, n - 1); //Mencari indeks elemen terkecil dari subarray yang belum diurutkan.
        if (min_index != i) { //Jika elemen terkecil tidak berada di posisi awal subarray, lakukan pertukaran.
            swap(&arr[i], &arr[min_index]); //Menukar elemen terkecil dengan elemen pertama dari subarray yang belum diurutkan.
            printArray(arr, n, ++steps); //Mencetak array setelah pertukaran dilakukan dan meningkatkan jumlah langkah.
        }
    }
    printf("%d\n", steps); //Mencetak jumlah total langkah yang diperlukan untuk melakukan sorting.
}

int main() {
    int n;
    printf(""); //Menampilkan pesan untuk meminta input pengguna.
    scanf("%d", &n); //Membaca jumlah kartu dari pengguna.

    char *cards = (char *)malloc(n * sizeof(char)); //Mengalokasikan memori untuk menyimpan kartu.

    printf(""); //Menampilkan pesan untuk meminta input pengguna.
    for (int i = 0; i < n; i++) {
        scanf(" %c", &cards[i]); //Membaca karakter kartu dari pengguna.
    }
    selectionSort(cards, n); //Memanggil fungsi selection sort untuk mengurutkan kartu.

    free(cards); //Membuang memori yang dialokasikan untuk array kartu.
    return 0;
}
