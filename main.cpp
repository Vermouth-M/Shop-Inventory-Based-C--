#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Book
{
    string kode;
    string nama;
    int stok;
    int harga;
};

void bubblesort(vector<Book> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].kode > arr[j + 1].kode)
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    int q;
    cin >> q;
    Book b;

    vector<Book> books;

    while (q--)
    {
        string operation;
        cin >> operation;

        if (operation == "TAMBAH")
        {
            cin >> b.kode >> b.nama >> b.stok >> b.harga;
            bool exists = false;
            for (auto &bk : books)
            {
                if (bk.kode == b.kode)
                {
                    exists = true;
                    break;
                }
            }

            if (exists)
            {
                cout << "KODE SUDAH DIMASUKAN" << endl;
            }
            else
            {
                books.push_back(b);
            }
        }
        else if (operation == "CARI")
        {
            string code;
            cin >> code;

            bool found = false;
            for (auto &b : books)
            {
                if (b.kode == code)
                {
                    found = true;
                    break;
                }
            }
            cout << (found ? "ADA" : "TIDAK ADA") << endl;
        }
        else if (operation == "JUAL")
        {
            string code;
            int jmljual;
            cin >> code;
            cin >> jmljual;

            bool found = false;
            for (auto &b : books)
            {
                if (b.kode == code)
                {
                    b.stok -= jmljual;
                    cout << ("Berhasil Terjual") << endl;
                    break;
                }
                else
                {
                    cout << ("BARANG TIDAK DITEMUKAN") << endl;
                    break;
                }
                if (b.kode == code)
                {
                    b.stok -= jmljual;
                    cout << ("Berhasil Terjual") << endl;
                    break;
                }
                else if (jmljual > b.stok)
                {
                    cout << ("Berlebih hasil -") << endl;
                }
            }
        }
        else if (operation == "LAPORAN")
        {
            bubblesort(books);
            for (auto &b : books)
            {
                cout << b.kode << " " << b.nama << " "
                     << b.stok << " " << b.harga << endl;
            }
        }
    }

    return 0;
}
