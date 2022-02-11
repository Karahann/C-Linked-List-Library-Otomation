#include <stdio.h>
#include <stdlib.h>
#include <string.h>
    
kitaplar *kitapVerme(kitaplar *ilk,oduncA *ilkAlan){  
    kitaplar *yeniKitap =(kitaplar*)malloc(sizeof(kitaplar));
    oduncA *x=ilkAlan;
    int ayniKitapMi = 0,adet=1;
    printf("\nLutfen almis oldugunuz kitabin bilgilerini duzgun ve hatasiz bir sekilde giriniz...\n");
    printf("Kitabin adi: "); scanf(" %[^\t\n]s",&yeniKitap->kitapAdi);
    printf("Kitap Sayfasi:"); scanf("%d",&yeniKitap->kitapSayfasi);
    printf("Kitap Turu:"); scanf(" %[^\t\n]s",&yeniKitap->kitapTuru);
    
    if(ilk == NULL)
    {
        ilk = yeniKitap;
        yeniKitap->kitapAdedi=1;
        ilk -> sonraki = NULL;
        printf("\nListe olusturuldu ilk kitap eklendi\n");
    }
    else
    {
        kitaplar *temp = ilk;
        kitaplar *temp2 = ilk;
        while(temp -> sonraki != NULL)
        {
            temp = temp -> sonraki;
        }
        while(temp2 != NULL)
        {
            if(strcmp(temp2->kitapAdi,yeniKitap->kitapAdi) == 0)
            {
                printf("\nKitap kayitlanma islemi basariyla tamamlanmistir... \n");
                ayniKitapMi = 1;
                temp2->kitapAdedi = temp2->kitapAdedi + adet;
            }
            temp2 = temp2 -> sonraki;
        }
        if(ayniKitapMi == 0)
           temp -> sonraki = yeniKitap;
    }
    return ilk;
}