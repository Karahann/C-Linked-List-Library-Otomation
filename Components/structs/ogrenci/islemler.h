#include <stdio.h>
#include <stdlib.h>

ogrenciler *hesapOlustur(ogrenciler *ilkOgrenci){
    ogrenciler *yeniHesap =(ogrenciler*)malloc(sizeof(ogrenciler));
    printf("Ogrenci numaraniz: "); scanf(" %s",&yeniHesap->kullaniciAdi);
    printf("Sifre: "); scanf(" %s",&yeniHesap->sifre);

    if (ilkOgrenci==NULL)
    {
        ilkOgrenci=yeniHesap;
    }
    else
    {
        ogrenciler *temp=ilkOgrenci;
        while (temp->sonraki!=NULL)
        {
            temp=temp->sonraki;
        }
        temp->sonraki=yeniHesap;
    }
    printf("\nHesabiniz olusturulmustur...\n");
    return ilkOgrenci;
}