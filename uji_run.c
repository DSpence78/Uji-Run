#include <stdio.h>
#include <stdlib.h>
#define MAX 40
int tableF1[21][21], tableF2[21][21];

// prototype untuk fungsi hapusData
void hapusData();

// fungsi untuk menginput data ke dalam array
// parameter yang digunakan, array untuk menyimpan data kejadian
// dan size untuk ukuran banyaknya data
void inputData(int array[], int *size) {
    char refill; // digunakan pada saat konfirmasi penginputan ulang data

    // struktur pemilihan untuk u
    if (*size != 0) {
        printf("Data yang ada sebelumnya akan dihapus\n");
        z:
        printf("Apakah Anda yakin ingin input data lagi? (y/n): ");
        scanf("%c", &refill);
        system("cls");

        // meminta konfirmasi ke user apakah akan menghapus data yang ada sebelumnya atau tidak
        if (refill == 'n' || refill == 'N') {
            printf("Input data tidak jadi dilakukan\n");
            return;
        } else if (refill == 'y' || refill == 'Y') {
            hapusData(array,size);
            printf("Data sudah dihapus secara keseluruhan\n");
        } else {
            printf("Anda salah memasukkan input! Silakan input kembali\n");
            goto z;
        }
    }
    x:
    printf("Jumlah data (maksimal 40): ");
    scanf("%d", size);

    // memberi batasan untuk jumlah data yang dapat diinput
    if (*size <= 0 || *size > 40) {
        printf("Data harus berada pada rentang 1-40!\nSilakan input jumlah data!\n");
        goto x;
    }

    printf("Input 1 untuk m dan 0 untuk n\n");
    for (int i = 0; i < *size; i++) {
        y:
        printf("Kejadian[%d]  -----> ", i+1);
        scanf("%d", &array[i]);

        // kembali pada label y saat terjadi kondisi kesalahan input (tidak input 1/0)
        if (array[i] != 1 && array[i] != 0) {
            printf("\nInput yang Anda masukkan salah! Silakan input kembali!\n");
            goto y;
        }
    }

    system("cls");
    printf("Data sudah berhasil diinput\n");
}

// fungsi untuk menghapus data
// hapus data dilakukan dengan menetapkan semua nilai dalam array menjadi 0
// dan mereset variabel size menjadi 0
void hapusData(int array[], int *size) {
    for (int i = 0; i < *size; i++) {
        array[i] = 0;
    }
    (*size) = 0;
}

// fungsi untuk menampilkan data yang sudah diinput
void tampilData(int array[], int size) {
    printf("Data: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// fungsi untuk mencari nilai r
int rFind(int array[], int size) {
    int run = 1;
    for (int i = 1; i < size; i++) {

        // variabel run nilainya akan bertambah saat data yang pada indeks ke-i berbeda dengan indeks sebelumnya
        if (array[i] != array[i-1]) {
            run++;
        }
    }
    return run;
}

// fungsi untuk mencari nilai m dan n
void mnFind(int array[], int size, int *m, int *n) {
    *m = 0;
    *n = 0;
    
    for (int i = 0; i < size; i++) {
        if (array[i] == 1) {
            // nilai m akan bertambah satu jika data pada index ke-i bernilai 1
            (*m)++;
        } else {
            // nilai n akan bertambah satu jika data pada index ke-i bernilai 0
            (*n)++;
        }
    }
}

// fungsi untuk membuat tabel F1 dan F2
void makeTable(int *eror) {
    FILE *f1, *f2;
    f1 = fopen("./tabel run/F1.csv", "r"); // membuka file F1.csv
    f2 = fopen("./tabel run/F2.csv", "r"); // membuka file F2.csv

    // jika file tidak ada akan menampilkan pesan error
    if (f1 == NULL || f2 == NULL) {
        printf("File F1.csv atau F2.csv tidak ditemukan!\nTidak dapat membuat tabel\n");
        *eror = 1;
        return;
    }

    // menginputkan nilai dari file F1.csv dan F2.csv ke dalam array 2D tableF1 & tableF2
    // indeks array yang digunakan dari 2 sampai 20 untuk memudahkan dalam mencari nilai tabel
    for (int m = 2; m < 21; m++) {
        for (int n = 2; n < 21; n++) {
            fscanf(f1, "%d", &tableF1[m][n]);
            fscanf(f2, "%d", &tableF2[m][n]);
        }
    }

    // menutup file
    fclose(f1);
    fclose(f2);
}

// fungsi untuk analisis data
int analisisData(int array[], int size, int cetak, FILE *analisis) {
    int r, m, n, f1, f2;

    //mencari nilai r, m, n, f1, dan f2
    r = rFind(array,size);
    mnFind(array,size,&m,&n);
    f1 = tableF1[m][n];
    f2 = tableF2[m][n];

    // nilai cetak 1 akan print output ke dalam file 'analisis.txt'
    // nilai cetak selain 1 akan print output langsung ke layar console
    if (cetak == 1) {
        fprintf(analisis, "%s %-5d %s", "|   r = ", r, "|\n");
        fprintf(analisis, "%s %-5d %s", "|   m = ", m, "|\n");
        fprintf(analisis, "%s %-5d %s", "|   n = ", n, "|\n");
        fprintf(analisis, "%s", "================\n");
    } else {
        printf("==============\n");
        printf("|   r = %-5d|\n|   m = %-5d|\n|   n = %-5d|\n==============\n", r, m, n);
    }

    // memastikan data memenuhi syarat uji run sampel kecil
    // yaitu memenuhi syarat jika m <= 20 dan/atau n <= 20
    if (m > 20 || n > 20) {
        return 911;
    }

    // struktur pemilihan untuk mencetak f1 dan f2 berdasarkan ada tidaknya nilainya pada tabel run
    // nilai 0 seharusnya tidak terdefinisi sehingga akan ditulis '-' dalam outputnya
    if (f1 == 0 && f2 == 0) {
        if (cetak == 1) {
            fprintf(analisis, "%s %-5c %s", "|  F1 = ", '-', "|\n");
            fprintf(analisis, "%s %-5c %s", "|  F2 = ", '-', "|\n");
            fprintf(analisis, "%s", "================\n\n");
        } else {
            printf("|  F1 = %-5c|\n|  F2 = %-5c|\n==============\n\n", '-', '-');
        }
    } else if (f2 == 0) {
        if (cetak == 1) {
            fprintf(analisis, "%s %-5d %s", "|  F1 = ", f1, "|\n");
            fprintf(analisis, "%s %-5c %s", "|  F2 = ", '-', "|\n");
            fprintf(analisis, "%s", "================\n\n");
        } else {
            printf("|  F1 = %-5d|\n|  F2 = %-5c|\n==============\n\n", f1, '-');
        }
    } else {
        if (cetak == 1) {
            fprintf(analisis, "%s %-5d %s", "|  F1 = ", f1, "|\n");
            fprintf(analisis, "%s %-5d %s", "|  F2 = ", f2, "|\n");
            fprintf(analisis, "%s", "================\n\n");
        } else {
            printf("|  F1 = %-5d|\n|  F2 = %-5d|\n==============\n\n", f1, f2);
        }
    }

    // jika nilai f1 atau f2 bernilai 0 (yang menandakan tidak ada dalam tabel run),
    // fungsi akan dikembalikan langsung ke fungsi main
    if (f1 == 0 || f2 == 0) {
        return 212; // keputusan: gagal melakukan analisis
    }    

    // jika nilai r tidak berada di antara f1 dan f2, maka fungsi akan mengembalikan nilai 1
    if (r <= f1 || r >= f2) {
        return 1; // keputusan: tolak H0
    }

    // fungsi akan mengembalikan nilai 0 jika dua kondisi di atas tidak terpenuhi
    return 0; // keputusan: gagal tolak H0
}

void main() {
    // deklarasi variabel
    int data[MAX], size = 0, pilih, decide, error = 0;

    // buat tabel F1 dan F2
    makeTable(&error);
    if (error == 1) {
        printf("Pastikan file tersebut ada di dalam folder 'tabel run' terlebih dahulu!\n");
        goto e;
    }
    
    printf("[]==============================================[]\n"
           "||      Program Uji Run untuk Sampel Kecil      ||\n"
           "[]==============================================[]\n"
           "                  *tingkat signifikansi 5 persen\n");

    do {
        printf("\n  Pilih Menu: \n"
            "   1. Input data\n"
            "   2. Tampilkan data\n"
            "   3. Analisis data\n"
            "   4. Analisis dan cetak data\n"
            "   5. Keluar\n"
            "  -------------------------\n");
        printf("  Pilihan Anda: ");
        scanf("%d", &pilih);
        getchar();
        system("cls");
        switch (pilih) {
            case 1:
                printf("================\n");
                printf("|  Input data  |\n");
                printf("================\n\n");
                // jika data sudah terisi akan dilakukan konfirmasi ulang
                inputData(data,&size);
                getchar();
                break;
            case 2:
                // jika data kosong atau masih belum diisi, data tidak dapat ditampilkan
                if (size == 0) {
                    printf("Tidak ada data untuk ditampilkan!\n");
                    break;
                }
                
                printf("=================\n");
                printf("|  Tampil Data  |\n");
                printf("=================\n\n");
                tampilData(data,size);
                break;
            case 3:
                // jika data kosong atau masih belum diisi, data tidak dapat ditampilkan
                if (size == 0) {
                    printf("Data kosong!\n");
                    break;
                }

                printf("===================\n");
                printf("|  Analisis data  |\n");
                printf("===================\n\n");

                decide = analisisData(data,size,0,NULL);
                
                printf("Hasil: \n");
                if (decide == 1) {
                    printf("  - Tolak Hipotesis Nol\n"
                           "  - Urutan munculnya data bersifat tidak random\n");
                } else if (decide == 0) {
                    printf("  - Gagal Tolak Hipotesis Nol\n"
                           "  - Urutan munculnya data bersifat random\n");
                } else if (decide == 212) {
                    printf("Tabel F1/F2 dengan tingkat signifikansi 5 persen tidak memuat nilai tersebut\n"
                           "Analisis tidak dapat dilakukan\n");
                } else {
                    printf("Data yang dimasukkan tidak memenuhi syarat m dan n <= 20\n"
                           "Analisis tidak dapat dilakukan\n");
                }
                break;
            case 4:
                // jika data kosong atau masih belum diisi, data tidak dapat ditampilkan
                if (size == 0) {
                    printf("Data kosong!\n");
                    break;
                }

                // membuka file "analisis.txt" sebagai output
                FILE *analisis;
                analisis = fopen("analisis.txt", "w");

                printf("=============================\n");
                printf("|  Analisis dan Cetak Data  |\n");
                printf("=============================\n\n");
                fprintf(analisis, "%s", "Analisis Data:\n================\n");

                decide = analisisData(data,size,1,analisis);

                fprintf(analisis, "%s", "Hasil: \n");

                // menampilkan output ke dalam file yang ditunjuk oleh pointer 'analisis'
                // yaitu ke dalam file 'analisis.txt'
                if (decide == 1) {
                    fprintf(analisis, "%s", "  - Tolak Hipotesis Nol\n");
                    fprintf(analisis, "%s", "  - Urutan munculnya data bersifat tidak random\n");
                } else if (decide == 0) {
                    fprintf(analisis, "%s", "  - Gagal Tolak Hipotesis Nol\n");
                    fprintf(analisis, "%s", "  - Urutan munculnya data bersifat random\n");
                } else if (decide == 212) {
                    printf("Tabel F1/F2 dengan tingkat signifikansi 5 persen tidak memuat nilai tersebut\n"
                           "sehingga tidak dapat ditarik kesimpulan\n"
                           "Hasil penghitungan akan tetap dicetak dalam file analisis.txt\n\n");
                    fprintf(analisis, "%s", "Tabel F1/F2 dengan tingkat signifikansi 5 persen tidak memuat nilai tersebut\n");
                    fprintf(analisis, "%s", "Analisis tidak dapat dilakukan\n");
                } else {
                    printf("Data yang dimasukkan tidak memenuhi syarat m dan n <= 20\n"
                           "sehingga tidak dapat dilakukan analisis\n"
                           "Hasil penghitungan akan tetap dicetak dalam file analisis.txt\n\n");
                    fprintf(analisis, "%s", "Data yang dimasukkan tidak memenuhi syarat m dan n <= 20\n");
                    fprintf(analisis, "%s", "sehingga tidak dapat dilakukan analisis\n");

                }
                printf("Data telah dicetak pada file analisis.txt\n");
                fclose(analisis);
                break;
            case 5:
                printf("Terima kasih telah menggunakan program ini\n");
                break;
            default:
                printf("Anda salah input pilihan!\nSilakan input pilihan kembali\n");
                break;
        }
    } while (pilih != 5);
    e:
    printf("\n\n\n\n\n\n\n\n\n\nTekan enter untuk keluar...");
    getchar();
}

// Damar Septia Nugraha
// 222011829