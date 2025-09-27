#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;


struct penerbangan 
{
    string kodepenerbangan ;
    string tujuan ;
    string status ;
    penerbangan* prev ;
    penerbangan* next ;
};


penerbangan* head = nullptr ;
penerbangan* tail = nullptr ;
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
    penerbanganbaru->prev = nullptr ;
    
    if (kosong())
    {
        head = tail = penerbanganbaru ;
    }
    else 
    {
        tail->next = penerbanganbaru ;
        penerbanganbaru->prev = tail ;
        tail = penerbanganbaru ;
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
    penerbanganbaru->next = nullptr ;
    penerbanganbaru->prev = nullptr ;

    if (posisi < 1 || head == nullptr)
    {
        if (kosong())
        {
            head = tail = penerbanganbaru ;
        } else 
        {
            penerbanganbaru->next = head ;
            head->prev = penerbanganbaru ;
            head = penerbanganbaru ;
        }
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
        if (temp->next != nullptr)
        {
            temp->next->prev = penerbanganbaru ;
        } else 
        {
            tail = penerbanganbaru ;
        }
        temp->next = penerbanganbaru ;   
        penerbanganbaru->prev = temp ;
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
    if (head == tail)
    {
        head = tail = nullptr ;
    } else 
    {
        head = head->next ;
        head->prev = nullptr ;
    }
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
       cout << "3. Landed\n" ;
       cout << "4. Departed\n" ;
       cout << "Masukkan pilihan (1-4): " ;
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
            temp->status = "Landed" ;
            break ;
        case 4 :
            temp->status = "Departed" ;
            break;
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

void tampilanjadwaldaribelakang()
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

    penerbangan* temp = tail;
    while (temp != nullptr)
    {
        cout << "| " << temp->kodepenerbangan;

        for (int i = temp->kodepenerbangan.length(); i < 16; i++) cout << " ";
        cout << " | " << temp->tujuan;

        for (int i = temp->tujuan.length(); i < 16; i++) cout << " ";
        cout << " | " << temp->status;

        for (int i = temp->status.length(); i < 16; i++) cout << " ";
        cout << " |\n";

        temp = temp->prev;
    }

    cout << "+------------------+------------------+------------------+\n\n";
}

void detailjadwalpenerbangan ()
{
    if (kosong())
    {
        cout << "Tidak ada jadwal penerbangan yang tersedia.\n" << endl ;
        return ;
    }

    cin.ignore();
    string input;
    cout << "Masukkan kode penerbangan yang ingin ditampilkan detailnya: ";
    getline(cin, input);

    penerbangan* temp = head ;
    while (temp != nullptr ) 
    {if (temp->kodepenerbangan == input || temp->tujuan == input)
        {
            cout << "\nDetail Jadwal Penerbangan:\n";
            cout << "Kode Penerbangan: " << temp->kodepenerbangan << endl;
            cout << "Tujuan: " << temp->tujuan << endl;
            cout << "Status: " << temp->status << endl;
            return ;
        }
        temp = temp->next ;
    }
    if (temp == nullptr)
    {
        cout << "Jadwal penerbangan dengan kode atau tujuan " << input << " tidak ditemukan.\n" << endl ;
        return ;
    }
}

int main ()
{
    int pilihan ;
    do 
    {
        system("cls");
        cout << "\n+------------------------------------------------------------+\n";
        cout << "|               SISTEM JADWAL PENERBANGAN                    |\n";
        cout << "|       [ Nou Julyanah Mazuwa -  2409106066 ]                |\n";
        cout << "+------------------------------------------------------------+\n";
        cout << "| 1. Tambah Jadwal Penerbangan                               |\n";
        cout << "| 2. Sisipkan Jadwal Penerbangan                             |\n";
        cout << "| 3. Hapus Jadwal Paling Awal                                |\n";
        cout << "| 4. Ubah Status Penerbangan                                 |\n";
        cout << "| 5. Tampilkan Semua Jadwal (depan -> belakang)              |\n";
        cout << "| 6. Tampilkan Semua Jadwal (belakang -> depan)              |\n";
        cout << "| 7. Detail Jadwal Penerbangan                               |\n";
        cout << "| 0. Keluar                                                  |\n";
        cout << "+------------------------------------------------------------+\n";
        cout << "Masukkan pilihan (0-7): ";
        cin >> pilihan ;

        switch (pilihan)
        {
            case 1 :
            {
                cin.ignore();
                string tujuan, status ;
                cout << "Masukkan tujuan penerbangan: " ;
                getline(cin, tujuan) ;
                int pilihstatus;
                do {
                    cout << "Pilih status penerbangan:\n";
                    cout << "1. On Time\n";
                    cout << "2. Delayed\n"; 
                    cout << "3. Landed\n" ;
                    cout << "4. Departed\n";
                    cout << "Masukkan pilihan (1-4): ";
                    cin >> pilihstatus;

                    if (pilihstatus < 1 || pilihstatus > 4)
                    {
                        cout << "Pilihan tidak valid! Silakan pilih lagi.\n\n";
                    }
                } while (pilihstatus < 1 || pilihstatus > 4);

                switch (pilihstatus)
                {
                    case 1: status = "On Time"; break;
                    case 2: status = "Delayed"; break;
                    case 3: status = "Landed"; break;
                    case 4: status = "Departed"; break;
                }

                tambahjadwalpenerbangan(tujuan, status);
                break;
            
            }
            case 2 :
            {
                cin.ignore();
                string tujuan, status ;
                cout << "Masukkan tujuan penerbangan: " ;
                getline(cin, tujuan) ;
                int pilihstatus;
                do {
                    cout << "Pilih status penerbangan:\n";
                    cout << "1. On Time\n";
                    cout << "2. Delayed\n";
                    cout << "3. Landed\n";
                    cout << "4. Departed\n";
                    cout << "Masukkan pilihan (1-4): ";
                    cin >> pilihstatus;

                    if (pilihstatus < 1 || pilihstatus > 4)
                    {
                        cout << "Pilihan tidak valid! Silakan pilih lagi.\n\n";
                    }
                } while (pilihstatus < 1 || pilihstatus > 4);

                switch (pilihstatus)
                {
                    case 1: status = "On Time"; break;
                    case 2: status = "Delayed"; break;
                    case 3: status = "Landed"; break;
                    case 4: status = "Departed"; break;
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
            case 6 :
                tampilanjadwaldaribelakang() ;
                break ;
            case 7 :
                detailjadwalpenerbangan() ;
                break ;
            case 0 :
                cout << "Keluar dari program.\n" << endl ;
                break ;
            default :
                cout << "Pilihan tidak valid. Silakan coba lagi.\n" << endl ;
        }
        if (pilihan != 0) {
            cout << "Tekan Enter untuk melanjutkan..." ;
            cin.ignore() ;
            cin.get() ;
        }
    } while (pilihan != 0) ;

    return 0 ;
}