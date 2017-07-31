#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <iomanip>
#include <string>

using namespace std;

#define PAUSE {cout << ("\n"); system("pause");}


struct data_buku {
        char kode_buku[10];
        char judul_buku[50];
        int stock;
        struct data_buku *next;
};
struct data_buku *awal, *akhir, *p, *Psbl, *baru;

//sorting kode buku ascending
void sort_kode_buku(int jml){

    int stock;
    char kode[10], judul[50];
    p=awal;

    for (int a=1;a<jml;a++){                    //melakukan looping sebanyak data buku
        while (p->next != NULL){                //melakukan looping jika pointer p->next tidak bernilai NUUL
            if (strcmp(p->kode_buku, p->next->kode_buku) ==1 ){     //membandingkan array kode buku jika birnilai 1 berarti (array p->kode_buku) lebih besar dari (array p->next->kode_buku)

                strcpy(kode, p->kode_buku);         //menyalin (array p->kode_buku) ke array kode;
                strcpy(p->kode_buku, p->next->kode_buku);       //menyalin (array p->next->kode_buku) ke array kode (array p->kode_buku);
                strcpy(p->next->kode_buku, kode);       //menyalin array kode ke (array p->next->kodebuku)

                strcpy(judul, p->judul_buku);
                strcpy(p->judul_buku, p->next->judul_buku);
                strcpy(p->next->judul_buku, judul);

                stock=p->stock;
                p->stock=p->next->stock;
                p->next->stock=stock;

            }
            p=p->next;
        }
        p=awal;
    }

}

void sort_judul_buku(int jml)
{
    int stock;
    char kode[10], judul[50];
    p=awal;

    for (int a=1;a<jml;a++){                    //melakukan looping sebanyak data buku
        while (p->next != NULL){                //melakukan looping jika pointer p->next tidak bernilai NUUL
            if (strcmp(p->judul_buku, p->next->judul_buku) ==1 ){     //membandingkan array judul buku jika birnilai 1 berarti (array p->judul_buku) lebih besar dari (array p->next->judul_buku)

                strcpy(kode, p->kode_buku);         //menyalin (array p->kode_buku) ke array kode;
                strcpy(p->kode_buku, p->next->kode_buku);       //menyalin (array p->next->kode_buku) ke array kode (array p->kode_buku);
                strcpy(p->next->kode_buku, kode);       //menyalin array kode ke (array p->next->kodebuku)

                strcpy(judul, p->judul_buku);
                strcpy(p->judul_buku, p->next->judul_buku);
                strcpy(p->next->judul_buku, judul);

                stock=p->stock;
                p->stock=p->next->stock;
                p->next->stock=stock;

            }
            p=p->next;
        }
        p=awal;
    }

}

void update_stock(){
    int up_stok;
    char kode[10];
    data_buku *prv;
    p=awal;

    if (p == NULL) {
        cout << "\n List Kosong\n";
        cout << "\n------------------------------------------\n";
    } else {
        while (p != NULL) {
            cout << "\nKode Buku   : " << p->kode_buku;
            cout << "\nJudul Buku  : " << p->judul_buku;
            cout << "\nStock : " << p->stock;
            cout << "\n==========================================\n";
            p = p->next;
        }

        cout<<"\nmasukan kode buku yang ingin di update : ";
        cin>>kode;
        cout<<"\nmasukan stok yang ingin di update : ";
        cin>>up_stok;

        p=awal;
        while (p!=NULL){
            if (strcmp(kode, p->kode_buku)==0 ){         //membandingkan aray kode dengan array (p->kode_buku) jika bernilai 0 maka data tersebut sama
                p->stock=up_stok;                           //lalu mengupdate stok buku
                cout<<"stok buku berhasil di update"<<endl;
                break;
            }
            p=p->next;
        }

        if (p==NULL){
            cout<<"kode buku tidak ada"<<endl;
        }

    }

}

// membandingkan sebuah string (ignore case)

int compare(char *str1, char *str2) {
    int len = strlen(str1);
    int beda = 0;

    for (int i=0; i<len; i++) {
        if (str1[i] >= 'A' && str1[i] <= 'Z') str1[i] += 32;
        if (str2[i] >= 'A' && str2[i] <= 'Z') str2[i] += 32;

        if (str1[i] != str2[i]) beda++;
        if (str2[i] == 'beda') {
            beda++;
                return beda;
        }
    }
    if (strlen(str2) < len) {
        beda += strlen(str2) - len;
    }
    return beda;
}

int main()
{

    awal = akhir = NULL;

    int pilihan = 1, posisi, posisi_sekarang,posisi_data, jml;
    char cari[50], konfirmasi;
    cout << "SELAMAT DATANG DI PERPUSTAKAAN KAMI\n";
    do {
            cout << "\n\t||=======================||";
            cout << "\n\t||Menu Perpustakaan      ||";
            cout << "\n\t||1. Tambah Data Buku    ||"
                    "\n\t||2. Hapus Buku          ||"
                    "\n\t||3. Cari Buku           ||"
                    "\n\t||4. Tampilkan Data Buku ||"
                    "\n\t||5. update stok buku    ||"
                    "\n\t||0. EXIT                ||"
                    "\n\t||=======================||";
            cout << "\n\nMasukkan pilihan anda : ";
            cin >> pilihan;
            system("cls");

        switch (pilihan) {
            case 1: // tambah data kedalam list
                baru = (struct data_buku *) malloc(sizeof(struct data_buku)); // alokasikan list baru di memori
                if (baru == NULL) {
                    cout << "\nMemori tidak cukup.";
                    PAUSE;
                    break;
                }
                cout << "Kode buku: ";
                cin >> baru->kode_buku;
//                getchar();
                cout << "Judul Buku  : ";
                cin >> baru->judul_buku;
                cout << "Stock : ";
                cin >> baru->stock;

                if (awal == NULL) {
                    baru->next = NULL;
                    awal = baru;
                    akhir = baru;
                } else {
                    cout << "\nTambahkan Data di (Default = akhir) : \n";
                    cout << "1. Awal\n2. Tengah\n3. Akhir\n\nPilihan Anda : ";
                    cin >> posisi;
                    switch(posisi) {
                        case 1:
                            // tambah data di awal list
                            baru->next = awal;
                            awal = baru;
                            PAUSE;
                            break;
                        case 2:
                            cout << "Masukan posisi data : ";
                            cin >> posisi_data;
                            p = awal;
                            Psbl = NULL;
                            posisi_sekarang = 1;
                            while (p != NULL && posisi_sekarang < posisi_data) {
                                //Psbl = p;
                                p = p->next;
                                posisi_sekarang++;
                            }
                            if (p != NULL) {
                                // tambahkan data di tengah (posisi_data)
                                Psbl = p;
                                baru->next = p->next;
                                Psbl->next = baru;
                            }
                            break;
                        case 3:
                        default:
                            // tambah data di akhir list
                            akhir->next = baru;
                            akhir = baru;
                            baru->next = NULL;
                            PAUSE;
                            break;
                    }
                }
                break;
        case 2:
                p = awal;
                cout << "==========================================";
                if (p == NULL) {
                    cout << "\n List Kosong\n";
                    cout << "\n------------------------------------------\n";
                    break;
                } else {
                    while (p != NULL) {
                        cout << "\nKode Buku   : " << p->kode_buku;
                        cout << "\nJudul Buku  : " << p->judul_buku;
                        cout << "\nStock : " << p->stock;
                        cout << "\n==========================================\n";
                        p = p->next;
                    }
                }
                cout << "\nMasukan Kode Buku/Judul Buku dari data yang ingin dihapus : ";
                cin >> cari;
                Psbl = NULL;
                p = awal;
                while (p != NULL) {
                    if (compare(p->kode_buku, cari) == 0 || compare(p->judul_buku, cari) == 0) {
                        cout << "\n==========================================";
                        cout << "\nKode Buku   : " << p->kode_buku;
                        cout << "\nJudul Buku  : " << p->judul_buku;
                        cout << "\nStock : " << p->stock;
                        cout << "\n==========================================\n";
                        cout << "\nIngin menghapus data di atas (y/n) : ";
                        cin >> &konfirmasi;
                        if (konfirmasi == 'y' || konfirmasi == 'Y') {
                            if (awal->next == NULL) {
                                awal = NULL;
                                akhir = awal;
                            } else if (p == awal) {
                                // hapus di awal
                                Psbl = awal;
                                awal = Psbl->next;
                            } else if (p == akhir) {
                                // hapus di akhir
                                Psbl->next = NULL;
                                akhir = Psbl;
                            }
                            else {
                                // hapus di tengah
                                Psbl->next = p->next;
                            }
                            cout << "\nData berhasil dihapus.\n\n";
                        } else {
                            cout << "\nData tidak jadi dihapus.\n\n";
                        }
                        break;
                    }
                    Psbl = p;
                    p = p->next;
                }

                if (p == NULL) {
                    cout << "\n\nKode Buku/Judul Buku tidak ditemukan !\n\n";
                }
                PAUSE;
                break;
            case 3:
                cout << "\nMasukan Kode Buku/Judul Buku yang di cari : ";
                cin >> cari;
                p = awal;
                while (p != NULL) {
                    if (compare(p->kode_buku, cari) == 0 || compare(p->judul_buku, cari) == 0) {
                        cout << "\n==========================================";
                        cout << "\nKode Buku   : " << p->kode_buku;
                        cout << "\nJudul Buku  : " << p->judul_buku;
                        cout << "\nStock : " << p->stock;
                        cout << "\n==========================================\n";
                        PAUSE;
                        break;
                    }
                    p = p->next;
                }
                if (p == NULL) {
                    cout << "\nData tidak ditemukan ! \n\n";
                    PAUSE;
                }
                break;
        case 4: // tampilkan list
                int sort_pilih;
                p = awal;
                jml = 0;
                cout << "==========================================";
                if (p == NULL) {
                    cout << "\n List Kosong\n";
                    cout << "\n------------------------------------------\n";
                } else {
                    while (p != NULL) {
                        cout << "\nKode Buku   : " << p->kode_buku;
                        cout << "\nJudul Buku  : " << p->judul_buku;
                        cout << "\nStock       : " << p->stock;
                        cout << "\n==========================================\n";
                        p = p->next;
                        jml++;
                    }
                    do{
                    cout<<"\n1. Sorting Kode buku Ascending";
                    cout<<"\n2. Sorting Judul Buku Ascending";
                    cout<<"\n3. kembali ke menu";
                    cout<<"\n\nPilihan anda : ";
                    cin>>sort_pilih;
                    switch (sort_pilih){
                        case 1:
                            sort_kode_buku(jml);
                            system("cls");
                            cout<<"sorting kode buku ascending \n\n";
                                while (p != NULL) {
                                cout << "\nKode Buku   : " << p->kode_buku;
                                cout << "\nJudul Buku  : " << p->judul_buku;
                                cout << "\nStock       : " << p->stock;
                                cout << "\n==========================================\n";
                                p = p->next;
                                jml++;
                            }
                            break;
                        case 2:
                            sort_judul_buku(jml);
                            system("cls");
                            cout<<"sorting Judul buku ascending \n\n";
                                while (p != NULL) {
                                cout << "\nKode Buku   : " << p->kode_buku;
                                cout << "\nJudul Buku  : " << p->judul_buku;
                                cout << "\nStock       : " << p->stock;
                                cout << "\n==========================================\n";
                                p = p->next;
                                jml++;
                            }
                            break;
                        case 3:
                            break;

                    }
                    }while (sort_pilih!=3);

                }
                cout << "\n";
                PAUSE;
                break;
        case 5:
            update_stock();
            break;

        case 0: break;
            default:
                cout << "\nPilihan salah !\n";
                break;
        }
    } while (pilihan > 0);

    return 0;
}
