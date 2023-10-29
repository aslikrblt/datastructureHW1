// Listede en uzun ismin oldu�u kayd� yazd�ran fonksiyon
void en_uzun_isim() {
    struct ogrenci *gecici; // ge�ici  tan�mla
    int max = 0; // en uzun ismin uzunlu�unu tutan de�i�ken tan�mla
    char isim[20]; // en uzun ismi tutan dizi tan�mla
    gecici = bas; // ge�iciyi ba�a ata
    while (gecici != NULL) { // ba�l� liste bo� olana kadar d�ng�ye gir
        if (strlen(gecici->isim) > max) { // ��renci isminin uzunlu�u max'tan b�y�kse
            max = strlen(gecici->isim); // max de�erini g�ncelle
            strcpy(isim, gecici->isim); // isim dizisine ��renci ismini kopyala
        }
        gecici = gecici->sonraki; // ge�ici i�aret�iyi sonraki d���me kayd�r
    }
    printf("Listedeki en uzun isim: %s\n", isim); // en uzun ismi ekrana yaz
    printf("Uzunluk: %d\n", max); // en uzun ismin uzunlu�unu ekrana yaz
}

