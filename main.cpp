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
            bool found = false;
            for (auto &bk : books)
            {
                if (bk.kode == b.kode)
                {
                    found = true;
                    break;
                }
            }

            if (found)
            {
                cout << "KODE SUDAH ADA" << endl;
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
            if (!found)
            {
                cout << "BARANG TIDAK DITEMUKAN" << endl;
            }
            else if (found)
            {
                cout << b.kode << " " << b.nama << " "
                     << b.stok << " " << b.harga << endl;
            }
        }
        else if (operation == "JUAL")
        {
            string code;
            int jmljual;
            cin >> code >> jmljual;

            bool found = false;
            for (auto &b : books)
            {
                if (b.kode == code)
                {
                    found = true;
                    if (jmljual <= b.stok)
                    {
                        b.stok -= jmljual;
                        cout << "BERHASIL TERJUAL" << endl;
                    }
                    else
                    {
                        cout << "STOK TIDAK CUKUP" << endl;
                    }
                    break;
                }
            }

            if (!found)
            {
                cout << "BARANG TIDAK DITEMUKAN" << endl;
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
