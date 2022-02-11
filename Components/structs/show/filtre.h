#include <stdio.h>
#include <stdlib.h>
#include <string.h>

kitaplar *filtrele(kitaplar *ilk) {
    printf("Hangi türdeki kitaplari görmek istiyorsunuz?:");
    char tur[40];
    int sayac = 0;
    int kontrol = 0;
    scanf(" %[^\t\n]s",&tur);
    if(ilk == NULL){
        printf("Kitap yok\n");
    }
    else
    {
        kitaplar *temp = ilk;
        printf("%s turundeki kitaplar:\n",tur);
        while(temp!=NULL){
            if(strcmp(temp->kitapTuru,tur)==0)
            { 
                sayac++;
                printf("** \n");
                printf("%d.Kitabin adi:%s ,sayfasi:%d,adeti:%d\n",sayac,temp->kitapAdi,temp->kitapSayfasi,temp->kitapAdedi);
                kontrol = 1;
            }
            temp = temp->sonraki;
        }
        if(kontrol !=1)
        {
            printf("Bu turden kitaplar kutuphanede bulunmamaktadir.\n");
            printf("**\n");
        }

    }
    return ilk;
}