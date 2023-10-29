// ��renci bilgilerini tutan bir yap�
struct ogrenci {
    int numara; 
    char isim[20]; 
    int yas; 
    struct ogrenci *sonraki; 
};

// Ba�l� listenin ba��n� ve sonunu tutan iki i�aret�i tan�mla
struct ogrenci *bas = NULL; // ba�lang�� 
struct ogrenci *son = NULL; // biti� 

// Listedeki t�m d���mleri dola�an ve ��renci bilgilerini ekrana yazan fonksiyon
void printList() {
    struct ogrenci *gecici; // ge�ici tan�mla
    int sayac = 0; // d���m say�s�n� tutan saya�
    gecici = bas; // ge�iciyi ba�a ata
    while (gecici != NULL) { // ba�l� liste bo� olana kadar d�ng�ye gir
        sayac++; // sayac� art�r
        printf("%d- %s %d %d\n", sayac, gecici->isim, gecici->yas, gecici->numara); // bilgileri ekrana yaz
        gecici = gecici->sonraki; // ge�iciyi sonraki d���me kayd�r
    }
}

