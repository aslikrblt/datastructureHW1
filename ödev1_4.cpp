// Listede ��renci ad�na g�re kay�t arama yapan fonksiyon
int listeyiAra(char *isim) {
    struct ogrenci *gecici; // ge�ici 
    int index = 0; // indeks de�i�keni tan�mla
    gecici = bas; // ge�iciyi ba�a ata
    while (gecici != NULL) { // ba�l� liste bo� olana kadar d�ng�ye gir
        if (strcmp(gecici->isim, isim) == 0) { // ��renci ismini aranan isimle e�itse
            return index; // indeksi d�nd�r
        }
        index++; // indeksi art�r
        gecici = gecici->sonraki; // ge�iciyi sonraki d���me kayd�r
    }
    return -1; // isim bulunamazsa -1 d�nd�r
}

