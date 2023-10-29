// Listede öðrenci adýna göre kayýt arama yapan fonksiyon
int listeyiAra(char *isim) {
    struct ogrenci *gecici; // geçici 
    int index = 0; // indeks deðiþkeni tanýmla
    gecici = bas; // geçiciyi baþa ata
    while (gecici != NULL) { // baðlý liste boþ olana kadar döngüye gir
        if (strcmp(gecici->isim, isim) == 0) { // öðrenci ismini aranan isimle eþitse
            return index; // indeksi döndür
        }
        index++; // indeksi artýr
        gecici = gecici->sonraki; // geçiciyi sonraki düðüme kaydýr
    }
    return -1; // isim bulunamazsa -1 döndür
}

