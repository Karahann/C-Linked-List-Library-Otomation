#include <stdio.h>
#include <stdlib.h>

yetkililer *sifremiUnuttum(yetkililer *ilkYetkili){
    char istenilenKullanici[30];
    char girilenAnahtarDeger[30];
    char girilenEskiSifre[30];
    char girilenYeniSifre[30];
    int sayac = 3;
    printf("Hangi kullanicinin sifresini sifirlamak istiyorsunuz:");
    scanf(" %[^\t\n]s",&istenilenKullanici);
    yetkililer *temp = ilkYetkili;
    while(temp!=NULL)
    {
        if(strcmp(temp->kullaniciAdi,istenilenKullanici) == 0)
        {
            anahtardeger:printf("Lutfen anahtar degeri giriniz(kalan hak:%d):",sayac);
            if(sayac == 0)
            {
                system("cls");
                printf("Cok fazla basarisiz deneme yaptiginiz icin islem iptal edildi");
                return;
            }
            scanf(" %[^\t\n]s",&girilenAnahtarDeger);
            if(strcmp(temp->yetkiliAnahtarKelime,girilenAnahtarDeger) == 0)
            {
                printf("Lutfen yeni sifreyi giriniz:");
                scanf(" %[^\t\n]s",&girilenYeniSifre);
                strcpy(temp->yetkiliSifre,girilenYeniSifre);                                    //girilen sifreyi yetkilinin sifresine atama yapıyor
                system("cls");
                printf("Sifre Basariyla guncellendi.");
                return;
            } 
            else
            {
                printf("Girilen anahtar kelime dogru degil\n");
                sayac--;
                goto anahtardeger;
            }
        } 
        temp = temp->sonraki;
    }
    printf("Boyle bir kullanici yok");

}