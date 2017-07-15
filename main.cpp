#include <iostream>

using namespace std;

void daftar_buku()
{
    cout << "Daftar Buku :";
    cout << "\n\t1. Pintar Bahasa Indonesia";
    cout << "\n\t2. Surat Kecil Untuk TUhan";
    cout << "\n\t3. ";
}

void peminjaman ()
{
    switch ()
    {
    case '1':
        cout << ;
        break;
    case '2':
        cout << ;
        break;
    case '3':
        cout << ;
        break;
    default:
        cout << "Tidak ada kode tersebut dalam data buku kami\n";
        cout << "Silahkan masukkan lagi";
    }
}

void pengembalian ()
{
    switch ()
    {
    case '1':
        cout << ;
        break;
    case '2':
        cout << ;
        break;
    case '3':
        cout << ;
        break;
    default:
        cout << "Tidak ada kode tersebut dalam data buku kami\n";
        cout << "Silahkan masukkan lagi";
    }
}

int main()
{
    int chs,cod_p,cod_k;
    cout << "\nSelamat Datang Di Perpustakaan Kami\n\n";
    cout << "\n\tMenu Perpustakaan:\n\n";
    cout << "\t1. Daftar Buku\n";
    cout << "\t2. Peminjaman\n";
    cout << "\t3. Pengembalian\n";
    cout << "\nPilih salahsatu : ";
    cin >> chs;

    switch (chs)
    {
    case '1':
        cout << daftar_buku();
        break;
    case '2':
        cout << "Tuliskan kode buku yang akan anda pinjam : ";
        cin >> cod_p;
        break;
    case '3':
        cout << "Tuliskan kode buku yang di kembalikan : ";
        cin >> cod_k
        break;
    default:
        cout << "Tidak ada kode tersebut dalam data buku kami\n";
        cout << "Silahkan masukkan lagi";
    }
    return 0;
}
