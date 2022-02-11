#include <stdio.h>
#include <stdlib.h>
#include <string.h>

yetkililer *yetkiliKontrol1(yetkililer *ilkYetkili){

    char girilenAd[40],girilenSifre[40],geciciAd,geciciSifre;
    int kontrol=0,sayac=1;
    yetkililer *x=ilkYetkili;
    printf("Kullanici Adi:"); scanf(" %s",&girilenAd);


	while(x != NULL)
    {
		if (strcmp(x->kullaniciAdi,girilenAd) == 0)
		{
			kontrol=1;
            break;
		}
		x=x->sonraki;
	}

    if (kontrol==0)
    {
        printf("\nBu kullanici adina ait bir yetkili hesabi yok...\n");
        return (yetkililer *)kontrol;                                                   //girilen kullanici adinin sistemde kayitli olup olmadigini döndürüyor
    }
    else if (kontrol==1)
    {
        while (sayac!=4)
        {
            printf("Sifre:"); scanf(" %s",&girilenSifre);
            if (strcmp(x->yetkiliSifre,girilenSifre)==0)
            {
                printf("Giris yaptiniz...\n");
                return ilkYetkili;
            }
            else
            {
                printf("Sifre yanlis tekrar deneyiniz...(kalan hak %d)\n",3-sayac);
            }
            sayac++;
        }
        printf("Sifreyi 3 kere yanlis girdiniz.\n");
        return (yetkililer *)kontrol;
    }
    return ilkYetkili;
}
