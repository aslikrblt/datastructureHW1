// Listede aranan ��renci ad�n�n yer ald��� d���mden bir sonraki d���m� silen fonksiyon
void dugumSil(char *isim) {
    struct ogrenci *gecici, *onceki, *sonraki; // ge�ici, �nceki ve sonraki  tan�mla
    gecici = bas; // ge�iciyi ba�a ata
    while (gecici != NULL) { // ba�l� liste bo� olana kadar d�ng�ye gir
        if (strcmp(gecici->isim, isim) == 0) { // ��renci ismi aranan isimle e�itse
            sonraki = gecici->sonraki; // sonraki i�aret�isini ge�icinin sonrakine ata
            if (sonraki != NULL) { // sonraki i�aret�isi NULL de�ilse
                onceki = gecici; // �nceki i�aret�isini ge�iciye ata
                gecici = sonraki; // ge�iciyi sonrakiye ata
                onceki->sonraki = gecici->sonraki; // �ncekinin sonrakini ge�icinin sonrakine ba�la
                free(gecici); // ge�ici i�aret�inin g�sterdi�i d���m� sil
                break; // ��k
            }
        }
        gecici = gecici->sonraki; // ge�iciyi sonraki d���me kayd�r
    }
}

