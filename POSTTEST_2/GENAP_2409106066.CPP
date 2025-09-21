#include <iostream>
#include <string>
using namespace std;


struct penerbangan 
{
    string kodepenerbangan ;
    string tujuan ;
    string status ;
    penerbangan* next ;
};

penerbangan* head = nullptr ;
int hitungkode = 0 ;

bool kosong ()
{
    return head == nullptr ;
}

void tambahjadwalpenerbangan (string tujuan, string status)
{
    hitungkode++ ;
    string kode = "JT-066" ;
    if (hitungkode > 1) kode += "-" + to_string(hitungkode) ;

    penerbangan* penerbanganbaru = new penerbangan ;
    penerbanganbaru->kodepenerbangan = kode ;
    penerbanganbaru->tujuan = tujuan ;
    penerbanganbaru->status = status ;
    penerbanganbaru->next = nullptr ;
    
    if (kosong())
    {
        head = penerbanganbaru ;
    }
    else 
    {
        penerbangan* temp = head ;
        while (temp->next != nullptr)
        {
            temp = temp->next ;
        }
        temp->next = penerbanganbaru ;
    }
    cout << "Jadwal penerbangan" << kode << " berhasil ditambahkan .\n" << endl ;
}

void sisipjadwalpenerbangan (string tujuan, string status )
{
    int posisi = (6 +1) ;
    hitungkode++ ;
    string kode = "JT-066" ;
    if (hitungkode > 1) kode += "-" + to_string(hitungkode) ;

    penerbangan* penerbanganbaru = new penerbangan ;
    penerbanganbaru->kodepenerbangan = kode ;
    penerbanganbaru->tujuan = tujuan ;
    penerbanganbaru->status = status ;

    if (posisi < 1 || head == nullptr)
    {
        penerbanganbaru ->next = head ;
        head = penerbanganbaru ;
    } else 
    {
        penerbangan* temp = head ;
        int mulai = 1 ;
        while (temp ->next != nullptr && mulai < posisi -1)
        {
            temp = temp->next ;
            mulai++ ;
        }
        penerbanganbaru->next = temp->next ;
        temp->next = penerbanganbaru ;   
    }
    cout << "Jadwal penerbangan" << kode << " berhasil disisipkan pada posisi ke " << posisi << ".\n" << endl ;
}

void hapusjadwalpenerbanganawal ()
{
    if (kosong())
    {
        cout << "Tidak ada jadwal penerbangan yang dapat dihapus.\n" << endl ;
        return ;
    }

    penerbangan* hapus = head ;
    head = head->next ;
    cout << "Jadwal penerbangan " << hapus->kodepenerbangan << " berhasil dihapus.\n" << endl ;
    delete hapus ;
}

void updatestatuspenerbangan (string kodepenerbangan)
{
    if (kosong())
    {
        cout << "Tidak ada jadwal penerbangan yang dapat diupdate.\n" << endl ;
        return ;
    }

    penerbangan* temp = head ;
    while ( temp != nullptr && temp->kodepenerbangan != kodepenerbangan)
    {
        temp = temp->next ;
    }
    if (temp == nullptr)
    {
        cout << "Jadwal penerbangan dengan kode " << kodepenerbangan << " tidak ditemukan.\n" << endl ;
    } else 
    {
       int pilih;
       cout << "Pilih status baru untuk jadwal penerbangan " << kodepenerbangan << ":\n" ;
       cout << "1. On Time\n" ;
       cout << "2. Delayed\n" ;
       cout << "3. Cancelled\n" ;
       cout << "Masukkan pilihan (1-3): " ;
       cin >> pilih ;

       switch (pilih)
       {
        case 1 : 
            temp->status = "On Time" ;
            break ;
        case 2 :
            temp->status = "Delayed" ;
            break ;
        case 3 :
            temp->status = "Cancelled" ;
            break ;
        default :
            cout << "Pilihan tidak valid. Status tidak diubah.\n" << endl ;
            return ;
       }
         cout << "Status jadwal penerbangan " << kodepenerbangan << " berhasil diupdate menjadi " << temp->status << ".\n" << endl ;
    }
}

void tampilkanjadwalpenerbangan ()
{
    if (kosong())
    {
        cout << "Tidak ada jadwal penerbangan yang tersedia.\n" << endl ;
        return ;
    }

   cout << "\n================= DAFTAR JADWAL PENERBANGAN =================\n";
    cout << "+------------------+------------------+------------------+\n";
    cout << "| Kode Penerbangan | Tujuan           | Status           |\n";
    cout << "+------------------+------------------+------------------+\n";

    penerbangan* temp = head;
    while (temp != nullptr)
    {
        cout << "| " << temp->kodepenerbangan;

        for (int i = temp->kodepenerbangan.length(); i < 16; i++) cout << " ";
        cout << " | " << temp->tujuan;

        for (int i = temp->tujuan.length(); i < 16; i++) cout << " ";
        cout << " | " << temp->status;

        for (int i = temp->status.length(); i < 16; i++) cout << " ";
        cout << " |\n";

        temp = temp->next;
    }

    cout << "+------------------+------------------+------------------+\n\n";
}

int main ()
{
    int pilihan ;
    do 
    {
        cout << "\n+------------------------------------------------------------+\n";
        cout << "|               SISTEM JADWAL PENERBANGAN                    |\n";
        cout << "|       [ Nou Julyanah Mazuwa -  2409106066 ]                |\n";
        cout << "+------------------------------------------------------------+\n";
        cout << "| 1. Tambah Jadwal Penerbangan                               |\n";
        cout << "| 2. Sisipkan Jadwal Penerbangan                             |\n";
        cout << "| 3. Hapus Jadwal Paling Awal                                |\n";
        cout << "| 4. Ubah Status Penerbangan                                 |\n";
        cout << "| 5. Tampilkan Semua Jadwal                                  |\n";
        cout << "| 0. Keluar                                                  |\n";
        cout << "+------------------------------------------------------------+\n";
        cout << "Masukkan pilihan (0-5): ";
        cin >> pilihan ;

        switch (pilihan)
        {
            case 1 :
            {
                string tujuan, status ;
                cout << "Masukkan tujuan penerbangan: " ;
                cin >> tujuan ;
                int pilihstatus;
                do {
                    cout << "Pilih status penerbangan:\n";
                    cout << "1. On Time\n";
                    cout << "2. Delayed\n";
                    cout << "3. Cancelled\n";
                    cout << "Masukkan pilihan (1-3): ";
                    cin >> pilihstatus;

                    if (pilihstatus < 1 || pilihstatus > 3)
                    {
                        cout << "Pilihan tidak valid! Silakan pilih lagi.\n\n";
                    }
                } while (pilihstatus < 1 || pilihstatus > 3);

                switch (pilihstatus)
                {
                    case 1: status = "On Time"; break;
                    case 2: status = "Delayed"; break;
                    case 3: status = "Cancelled"; break;
                }

                tambahjadwalpenerbangan(tujuan, status);
                cout << "Jadwal penerbangan berhasil ditambahkan.\n" << endl;
                break;
            
            }
            case 2 :
            {
                string tujuan, status ;
                cout << "Masukkan tujuan penerbangan: " ;
                cin >> tujuan ;
                 int pilihstatus;
                do {
                    cout << "Pilih status penerbangan:\n";
                    cout << "1. On Time\n";
                    cout << "2. Delayed\n";
                    cout << "3. Cancelled\n";
                    cout << "Masukkan pilihan (1-3): ";
                    cin >> pilihstatus;

                    if (pilihstatus < 1 || pilihstatus > 3)
                    {
                        cout << "Pilihan tidak valid! Silakan pilih lagi.\n\n";
                    }
                } while (pilihstatus < 1 || pilihstatus > 3);

                switch (pilihstatus)
                {
                    case 1: status = "On Time"; break;
                    case 2: status = "Delayed"; break;
                    case 3: status = "Cancelled"; break;
                }
                sisipjadwalpenerbangan(tujuan, status) ;
                break ;
            }
            case 3 :
                hapusjadwalpenerbanganawal() ;
                break ;
            case 4 :
            {
                tampilkanjadwalpenerbangan() ;
                string kodepenerbangan, statusbaru ;
                cout << "Masukkan kode penerbangan yang akan diupdate: " ;
                cin >> kodepenerbangan ;
                updatestatuspenerbangan(kodepenerbangan) ;
                break ;
            }
            case 5 :
                tampilkanjadwalpenerbangan() ;
                break ;
            case 0 :
                cout << "Keluar dari program.\n" << endl ;
                break ;
            default :
                cout << "Pilihan tidak valid. Silakan coba lagi.\n" << endl ;
        }
    } while (pilihan != 0) ;

    return 0 ;
}