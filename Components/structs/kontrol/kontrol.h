#include <stdio.h>
#include <stdlib.h>

yetkililer *yetkiliKontrol(yetkililer *ilkYetkili){

    yetkililer *yeniYetkili =(yetkililer*)malloc(sizeof(yetkililer));
    printf("Kullanici Adi:"); scanf(" %[^\t\n]s",&yeniYetkili->kullaniciAdi);
    sifre:printf("Sifre:"); scanf(" %[^\t\n]s",&yeniYetkili->yetkiliSifre);
    printf("Tekrardan Sifre:"); scanf(" %[^\t\n]s",&yeniYetkili->yetkiliSifre2); 
    printf("Yetkili Anahtar Kelime(sifreyi unuttugunuz zaman sifirlamak icin):"); scanf(" %[^\t\n]s",&yeniYetkili->yetkiliAnahtarKelime);

    if(strcmp(yeniYetkili->yetkiliSifre,yeniYetkili->yetkiliSifre2) != 0)
    {
        printf("Sifreler ayni degil lutfen tekrar sifre giriniz \n");
        goto sifre;
    }
    else
    { 
        if(ilkYetkili==NULL)
        {
        printf("Ilk yetkili kullaniciyi olusturdunuz...\n");
        ilkYetkili=yeniYetkili;
        } 
        else
        {
            yetkililer *temp=ilkYetkili;
            while (temp->sonraki!=NULL)
            {
                temp=temp->sonraki;
            }
            temp->sonraki=yeniYetkili;
        }
        return ilkYetkili;
    }
}