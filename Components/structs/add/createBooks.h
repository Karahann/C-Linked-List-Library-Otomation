#include <stdio.h>
#include <stdlib.h>
#include <string.h>

kitaplar *kitapEkleme(kitaplar *ilk) {
    kitaplar *yeniKitap =(kitaplar*)malloc(sizeof(kitaplar));
    printf("Kutuphaneye eklemek istediginiz Kitabin Adi:"); scanf(" %[^\t\n]s",&yeniKitap->kitapAdi);   //iki kelime veya daha fazla input almak icin
    printf("Kitap Sayfasi:"); scanf("%d",&yeniKitap->kitapSayfasi);
    printf("Kitap Turu:"); scanf(" %[^\t\n]s",&yeniKitap->kitapTuru);
    printf("Kac adet?:");
    int adet;
    scanf("%d",&adet);
    yeniKitap->kitapAdedi = adet;
    int ayniKitapMi = 0;
    if(ilk == NULL)
    {
        ilk = yeniKitap;
        ilk->kitapAdedi = adet;
        ilk -> sonraki = NULL;
        printf("Liste olusturuldu ilk kitap eklendi\n");
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
                printf("\nAradiginiz kitap kutuphanede zaten var ustune eklenmistir... \n");
                ayniKitapMi = 1;                                                                        //eger ayni kitap mevcut ise değisken degeri 1 olarak atanacak
                temp2->kitapAdedi = temp2->kitapAdedi + adet;                                           //bu sayede ayni olup olmama durumunun kontrolu saglanmis olur
            }
            temp2 = temp2 -> sonraki;
        }
        if(ayniKitapMi == 0)
           temp -> sonraki = yeniKitap;
    }
    return ilk;
}