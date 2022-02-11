#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ogrenciler *ogrenciKontrol(ogrenciler *ilkOgrenci,char girilenAd1[40]){

	char girilenSifre1[40],geciciAd1,geciciSifre1;
	int kontrol1=0,sayac1=1;
    ogrenciler *x=ilkOgrenci;

	while(x != NULL)
	{
		if (strcmp(x->kullaniciAdi,girilenAd1) == 0)
		{
			kontrol1=1;
            break;
		}
		x=x->sonraki;
	}
	
	if (kontrol1==0)
	{
		printf("\nOnce kayit olunuz...\n");
		return (ogrenciler *)kontrol1;
	}
	else if (kontrol1==1)
	{
		while (sayac1!=4)
		{
			printf("Sifre: "); scanf(" %s",&girilenSifre1);
			if (strcmp(x->sifre,girilenSifre1)==0)
			{
				printf("\nGiris yaptiniz...\n");
				return (ogrenciler *)ilkOgrenci;
			}
			else
			{
				printf("Sifre yanlis tekrar deneyiniz...(kalan hak %d)\n",3-sayac1);
			}
			sayac1++;
		}
		printf("Sifreyi 3 kere yanlis girdiniz.\n");
		return (ogrenciler *)kontrol1;
	}
	return (ogrenciler *)ilkOgrenci;
}