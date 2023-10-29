// Listede en uzun ismin olduðu kaydý yazdýran fonksiyon
void en_uzun_isim() {
    struct ogrenci *gecici; // geçici  tanýmla
    int max = 0; // en uzun ismin uzunluðunu tutan deðiþken tanýmla
    char isim[20]; // en uzun ismi tutan dizi tanýmla
    gecici = bas; // geçiciyi baþa ata
    while (gecici != NULL) { // baðlý liste boþ olana kadar döngüye gir
        if (strlen(gecici->isim) > max) { // öðrenci isminin uzunluðu max'tan büyükse
            max = strlen(gecici->isim); // max deðerini güncelle
            strcpy(isim, gecici->isim); // isim dizisine öðrenci ismini kopyala
        }
        gecici = gecici->sonraki; // geçici iþaretçiyi sonraki düðüme kaydýr
    }
    printf("Listedeki en uzun isim: %s\n", isim); // en uzun ismi ekrana yaz
    printf("Uzunluk: %d\n", max); // en uzun ismin uzunluðunu ekrana yaz
}

