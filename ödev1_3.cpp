// Öðrenci bilgilerini tutan bir yapý
struct ogrenci {
    int numara; 
    char isim[20]; 
    int yas; 
    struct ogrenci *sonraki; 
};

// Baðlý listenin baþýný ve sonunu tutan iki iþaretçi tanýmla
struct ogrenci *bas = NULL; // baþlangýç 
struct ogrenci *son = NULL; // bitiþ 

// Listedeki tüm düðümleri dolaþan ve öðrenci bilgilerini ekrana yazan fonksiyon
void printList() {
    struct ogrenci *gecici; // geçici tanýmla
    int sayac = 0; // düðüm sayýsýný tutan sayaç
    gecici = bas; // geçiciyi baþa ata
    while (gecici != NULL) { // baðlý liste boþ olana kadar döngüye gir
        sayac++; // sayacý artýr
        printf("%d- %s %d %d\n", sayac, gecici->isim, gecici->yas, gecici->numara); // bilgileri ekrana yaz
        gecici = gecici->sonraki; // geçiciyi sonraki düðüme kaydýr
    }
}

