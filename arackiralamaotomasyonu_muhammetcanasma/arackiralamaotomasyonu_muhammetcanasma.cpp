#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> // ID Marka Model Yil Gunluk Ucret Kiralik Yazılarının arasındaki boşluk için kullandım.

using namespace std;

struct Arac {
    int id;
    char marka[50];
    char model[50];
    int yil;
    double gunlukUcret;
    bool kiralik;
};

void aracEkle() {
    ofstream dosya("araclar.txt", ios::app);
    if (!dosya) {
        cerr << "Dosya acilamadi!" << endl;
        return;
    }

    Arac arac;
    cout << "Arac ID: ";
    cin >> arac.id;
    cin.ignore();
    cout << "Marka: ";
    cin.getline(arac.marka, 50);
    cout << "Model: ";
    cin.getline(arac.model, 50);
    cout << "Yil: ";
    cin >> arac.yil;
    cout << "Gunluk ucret: ";
    cin >> arac.gunlukUcret;
    arac.kiralik = false;

    dosya << arac.id << ' ' << arac.marka << ' ' << arac.model << ' ' << arac.yil << ' ' << arac.gunlukUcret << ' ' << arac.kiralik << '\n';
    dosya.close();

    cout << "Arac basariyla eklendi.\n";
}

void aracListele() {
    ifstream dosya("araclar.txt");
    if (!dosya) {
        cerr << "Dosya acilamadi!" << endl;
        return;
    }

    Arac arac;
    cout << left << setw(5) << "ID" << setw(15) << "Marka" << setw(15) << "Model" << setw(10) << "Yil"
        << setw(15) << "Gunluk Ucret" << setw(10) << "Kiralik" << endl;
    cout << string(70, '-') << endl;

    while (dosya >> arac.id >> arac.marka >> arac.model >> arac.yil >> arac.gunlukUcret >> arac.kiralik) {
        cout << left << setw(5) << arac.id << setw(15) << arac.marka << setw(15) << arac.model << setw(10)
            << arac.yil << setw(15) << arac.gunlukUcret << setw(10)
            << (arac.kiralik ? "Evet" : "Hayir") << endl;
    }

    dosya.close();
}

void aracSil(int id) {
    ifstream dosyaOku("araclar.txt");
    ofstream dosyaYaz("temp.txt");
    if (!dosyaOku || !dosyaYaz) {
        cerr << "Dosya acilamadi!" << endl;
        return;
    }

    Arac arac;
    bool bulundu = false;

    while (dosyaOku >> arac.id >> arac.marka >> arac.model >> arac.yil >> arac.gunlukUcret >> arac.kiralik) {
        if (arac.id != id) {
            dosyaYaz << arac.id << ' ' << arac.marka << ' ' << arac.model << ' ' << arac.yil << ' ' << arac.gunlukUcret << ' ' << arac.kiralik << '\n';
        }
        else {
            bulundu = true;
        }
    }

    dosyaOku.close();
    dosyaYaz.close();

    remove("araclar.txt");
    rename("temp.txt", "araclar.txt");

    if (bulundu) {
        cout << "Arac basariyla silindi.\n";
    }
    else {
        cout << "Belirtilen ID'ye sahip arac bulunamadi.\n";
    }
}

void aracGuncelle(int id) {
    ifstream dosyaOku("araclar.txt");
    ofstream dosyaYaz("temp.txt");
    if (!dosyaOku || !dosyaYaz) {
        cerr << "Dosya acilamadi!" << endl;
        return;
    }

    Arac arac;
    bool bulundu = false;

    while (dosyaOku >> arac.id >> arac.marka >> arac.model >> arac.yil >> arac.gunlukUcret >> arac.kiralik) {
        if (arac.id == id) {
            cout << "Yeni Marka: ";
            cin.ignore();
            cin.getline(arac.marka, 50);
            cout << "Yeni Model: ";
            cin.getline(arac.model, 50);
            cout << "Yeni Yil: ";
            cin >> arac.yil;
            cout << "Yeni Gunluk ucret: ";
            cin >> arac.gunlukUcret;
            bulundu = true;
        }
        dosyaYaz << arac.id << ' ' << arac.marka << ' ' << arac.model << ' ' << arac.yil << ' ' << arac.gunlukUcret << ' ' << arac.kiralik << '\n';
    }

    dosyaOku.close();
    dosyaYaz.close();

    remove("araclar.txt");
    rename("temp.txt", "araclar.txt");

    if (bulundu) {
        cout << "Arac bilgileri basariyla guncellendi.\n";
    }
    else {
        cout << "Belirtilen ID'ye sahip arac bulunamadi.\n";
    }
}

void aracKirala(int id) {
    ifstream dosyaOku("araclar.txt");
    ofstream dosyaYaz("temp.txt");
    if (!dosyaOku || !dosyaYaz) {
        cerr << "Dosya acilamadi!" << endl;
        return;
    }

    Arac arac;
    bool bulundu = false;

    while (dosyaOku >> arac.id >> arac.marka >> arac.model >> arac.yil >> arac.gunlukUcret >> arac.kiralik) {
        if (arac.id == id) {
            if (!arac.kiralik) {
                arac.kiralik = true;
                cout << "Arac basariyla kiralandi.\n";
            }
            else {
                cout << "Bu arac zaten kiralanmis.\n";
            }
            bulundu = true;
        }
        dosyaYaz << arac.id << ' ' << arac.marka << ' ' << arac.model << ' ' << arac.yil << ' ' << arac.gunlukUcret << ' ' << arac.kiralik << '\n';
    }

    if (!bulundu) {
        cout << "Belirtilen ID'ye sahip arac bulunamadi.\n";
    }

    dosyaOku.close();
    dosyaYaz.close();

    remove("araclar.txt");
    rename("temp.txt", "araclar.txt");
}

void aracTeslimAl(int id) {
    ifstream dosyaOku("araclar.txt");
    ofstream dosyaYaz("temp.txt");
    if (!dosyaOku || !dosyaYaz) {
        cerr << "Dosya acilamadi!" << endl;
        return;
    }

    Arac arac;
    bool bulundu = false;

    while (dosyaOku >> arac.id >> arac.marka >> arac.model >> arac.yil >> arac.gunlukUcret >> arac.kiralik) {
        if (arac.id == id) {
            if (arac.kiralik) {
                arac.kiralik = false;
                cout << "Arac basariyla teslim alindi.\n";
            }
            else {
                cout << "Bu arac zaten teslim alinmis durumda.\n";
            }
            bulundu = true;
        }
        dosyaYaz << arac.id << ' ' << arac.marka << ' ' << arac.model << ' ' << arac.yil << ' ' << arac.gunlukUcret << ' ' << arac.kiralik << '\n';
    }

    if (!bulundu) {
        cout << "Belirtilen ID'ye sahip arac bulunamadi.\n";
    }

    dosyaOku.close();
    dosyaYaz.close();

    remove("araclar.txt");
    rename("temp.txt", "araclar.txt");
}

void menu() {
    cout << "\n--- Arac Kiralama Otomasyonu ---\n";
    cout << "1. Arac Ekle\n";
    cout << "2. Araclari Listele\n";
    cout << "3. Arac Kirala\n";
    cout << "4. Arac Teslim Al\n";
    cout << "5. Arac Sil\n";
    cout << "6. Arac Guncelle\n";
    cout << "7. Cikis\n";
    cout << "Seciminiz: ";
}

int main() {
    int secim;

    do {
        menu();
        cin >> secim;

        switch (secim) {
        case 1:
            aracEkle();
            break;
        case 2:
            aracListele();
            break;
        case 3: {
            int id;
            cout << "Kiralamak istediginiz aracin ID'sini girin: ";
            cin >> id;
            aracKirala(id);
            break;
        }
        case 4: {
            int id;
            cout << "Teslim almak istediginiz aracin ID'sini girin: ";
            cin >> id;
            aracTeslimAl(id);
            break;
        }
        case 5: {
            int id;
            cout << "Silmek istediginiz aracin ID'sini girin: ";
            cin >> id;
            aracSil(id);
            break;
        }
        case 6: {
            int id;
            cout << "Guncellemek istediginiz aracin ID'sini girin: ";
            cin >> id;
            aracGuncelle(id);
            break;
        }
        case 7:
            cout << "cikis yapiliyor...\n";
            break;
        default:
            cout << "Gecersiz secim, lutfen tekrar deneyin.\n";
        }

    } while (secim != 7);

    return 0;
}