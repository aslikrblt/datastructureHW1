// Listede aranan öðrenci adýnýn yer aldýðý düðümden bir sonraki düðümü silen fonksiyon
void dugumSil(char *isim) {
    struct ogrenci *gecici, *onceki, *sonraki; // geçici, önceki ve sonraki  tanýmla
    gecici = bas; // geçiciyi baþa ata
    while (gecici != NULL) { // baðlý liste boþ olana kadar döngüye gir
        if (strcmp(gecici->isim, isim) == 0) { // öðrenci ismi aranan isimle eþitse
            sonraki = gecici->sonraki; // sonraki iþaretçisini geçicinin sonrakine ata
            if (sonraki != NULL) { // sonraki iþaretçisi NULL deðilse
                onceki = gecici; // önceki iþaretçisini geçiciye ata
                gecici = sonraki; // geçiciyi sonrakiye ata
                onceki->sonraki = gecici->sonraki; // öncekinin sonrakini geçicinin sonrakine baðla
                free(gecici); // geçici iþaretçinin gösterdiði düðümü sil
                break; // çýk
            }
        }
        gecici = gecici->sonraki; // geçiciyi sonraki düðüme kaydýr
    }
}

