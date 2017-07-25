#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>

using namespace std;

struct data_buku
{
    string kode_buku;
    string judul_buku;
    string stok;
    data_buku *link;
};
int jml=0;
data_buku *buku[50];
data_buku *phead_buku = NULL;

struct data_user
{
    string nama;
    string alamat;
    string judul_buku;
};
int jml_user=0;
data_user *user[50];
data_user *phead_user = NULL;


void tambah_buku()
{
    buku[jml]= new data_buku;

    cout<<"masukan kode buku : ";
    cin>>buku[jml]->kode_buku;
    cout<<"masukan judul buku : ";
    cin>>buku[jml]->judul_buku;
    cout<<"masukan stok buku : ";
    cin>>buku[jml]->stok;
    buku[jml]->link= phead_buku;
    phead_buku=buku[jml];
    jml++;

    cout<<endl<<endl;

}

void hapus_buku()
{

    string input;
    cout<<"\n\nmasukan judul buku yang ingin di hapus : ";
    cin>>input;
    data_buku *ptemp=phead_buku;
    data_buku *pbefore;
    while (ptemp != NULL && ptemp->judul_buku != input){
        pbefore=ptemp;
        ptemp=ptemp->link;
    }
    pbefore->link=ptemp->link;

    cout<<endl<<endl;

}

void show_buku()
{
    cout<<left<<setw(20)<<"kode_buku"<<setw(20)<<"judul_buku"<<setw(10)<<"stok"<<endl;
    for(int z=0;z<50;z++){
        cout<<"-";
    }
    cout<<endl;

    data_buku *tr=phead_buku;
    while (tr !=NULL){
        cout << setw(20)<<tr->kode_buku<<setw(20)<<tr->judul_buku<<setw(10)<<tr->stok<<endl;
        tr=tr->link;
    }

    for(int z=0;z<50;z++){
        cout<<"-";
    }
}



int main()
{
    int chs,cod_p,cod_k;

    cout << "\nSelamat Datang Di Perpustakaan Kami\n\n";
    do{
        cout << "\n\tMenu Perpustakaan:\n\n";
        cout << "\t1. tambah buku\n";
        cout << "\t2. Hapus buku\n";
        cout << "\t3. peminjaman\n";
        cout << "\nPilih salahsatu : ";
        cin >> chs;
        system("cls");

        switch (chs)
        {
        case 1:
            tambah_buku();
            show_buku();
            break;
        case 2:
            show_buku();
            hapus_buku();
            show_buku();
            break;
        case 3:

            break;
        default:
            cout << "Tidak ada kode tersebut dalam data buku kami\n";
            cout << "Silahkan masukkan lagi";
        }

    }while (chs!=4);
    return 0;
}
