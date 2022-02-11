#include <stdio.h>
#include <stdlib.h>

yetkililer *sifremiDegistir(yetkililer *ilkYetkili){
    char istenilenKullanici[30];
    char girilenEskiSifre[30];
    char girilenYeniSifre[30];
    int sayac = 3;
    printf("Hangi kullanicinin sifresini sifirlamak istiyorsunuz:");
    scanf(" %[^\t\n]s",&istenilenKullanici);
    yetkililer *temp = ilkYetkili;
    while(temp!= NULL)
    {
        if(strcmp(temp->kullaniciAdi,istenilenKullanici) == 0)
        {
            eskisifre:printf("Lutfen eski sifrenizi giriniz(kalan hak:%d):",sayac);
            if(sayac == 0)
            {
                system("cls");                                                                   //konsolu temizliyor
                printf("Cok fazla basarisiz deneme yaptiginiz icin islem iptal edildi");
                return;
            }
            scanf(" %[^\t\n]s",&girilenEskiSifre);
            if(strcmp(temp->yetkiliSifre,girilenEskiSifre) == 0)
            {
                printf("Lutfen yeni sifrenizi giriniz:");
                scanf(" %[^\t\n]s",&girilenYeniSifre);
                strcpy(temp->yetkiliSifre,girilenYeniSifre);
                system("cls");
                printf("Sifre Basariyla Guncellendi");
                return;
            }
            else
            {
                printf("Girilen Sifre eski sifreyle uyusmuyor\n");
                sayac--;
                goto eskisifre;
            }
        }
        temp = temp->sonraki;
    }
    printf("Boyle bir kullanici yok \n");
}