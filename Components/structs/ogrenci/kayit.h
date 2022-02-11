#include <stdio.h>
#include <stdlib.h>

oduncA *kayit(oduncA *ilkAlan,char istenilenKitap[40],char girilenAd1[40],kitaplar *ilk,ogrenciler *ilkOgrenci){
    oduncA *yeniAlan =(oduncA*)malloc(sizeof(oduncA));
    kitaplar *temp=(kitaplar*)malloc(sizeof(kitaplar));
    temp=ilk;
    ogrenciler *x=ilkOgrenci;
    int kontrolx=0,kitabinsayfasii;
    char *istenilen,*adi,*kitabinturuu;

    while(temp != NULL){
		if (strcmp(temp->kitapAdi,istenilenKitap) == 0)
		{
			kontrolx=1;
            break;
		}
		temp=temp->sonraki;
	}

    istenilen=istenilenKitap;
    adi=girilenAd1;

    yeniAlan->aldigiKitap=istenilen;
    yeniAlan->kullaniciAdi=adi;

    kitabinsayfasii=temp->kitapSayfasi;
    kitabinturuu=temp->kitapTuru;
    yeniAlan->kitabinsayfasi=kitabinsayfasii;
    yeniAlan->kitabinturu=kitabinturuu;


    if(ilkAlan == NULL) {
        ilkAlan = yeniAlan;
        ilkAlan -> sonraki = NULL;
    } else {
        oduncA *temp = ilkAlan;
        while(temp -> sonraki != NULL){
            temp = temp -> sonraki;
        }
        temp -> sonraki = yeniAlan;
    }
    return ilkAlan;
}