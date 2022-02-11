#include <stdio.h>
#include <stdlib.h>
#include "..\Components\structs\struct.h"
#include "..\Components\structs\add\createBooks.h"
#include "..\Components\structs\show\showBooks.h"
#include "..\Components\structs\show\filtre.h"
#include "..\Components\structs\delete\deleteBooks.h"
#include "..\Components\structs\kontrol\kontrol.h"
#include "..\Components\structs\kontrol\kontrol1.h"
#include "..\Components\structs\kontrol\sifremidegistir.h"
#include "..\Components\structs\kontrol\sifremiunuttum.h"
#include "..\Components\structs\ogrenci\islemler.h"
#include "..\Components\structs\ogrenci\ogrenciKontrol.h"
#include "..\Components\structs\ogrenci\oduncAlma.h"
#include "..\Components\structs\ogrenci\oduncVerme.h"
#include "..\Components\structs\ogrenci\verme.h"
#include "..\Components\structs\ogrenci\kayit.h"

kitaplar *ilk = NULL;
yetkililer *ilkYetkili=NULL;
ogrenciler *ilkOgrenci=NULL;
oduncA *ilkAlan=NULL;

int main() {
	char istenilenKitap[40], girilenAd1[40];
    int secim,secim1,secim2,secim3,kontrol,kontrol1,y;
	while (1==1)
	{
		
		git:printf("\n1-)Yetkili girisi:\n2-)Ogrenci girisi:\n3-)Yetkili sifresi unuttum:\nSecim:"); scanf(" %d",&secim1);
		
		if (secim1==1)
		{
			if(ilkYetkili==NULL){
				ilkYetkili=yetkiliKontrol(ilkYetkili);
			}
			else{
				kontrol=yetkiliKontrol1(ilkYetkili);
				if (kontrol==0||kontrol==1)
				{
					printf("Islemi bastan yapiniz...\n\n");
					goto git;
				}
			
			}
			while(1==1) {
				printf("\nYapmak istediginiz islemi seciniz:\n");
				printf("1)Kitap ekle\n");
				printf("2)Kitap sil\n");
				printf("3)Kitaplari goruntule\n");
				printf("4)Kitaplari ture gore siralama\n");
				printf("5)Yetkili hesabi olustur\n");
				printf("6)Sifremi degistir\n");
				printf("7)Yetkili hesabindan cikis yap\n");
				printf("Seciminiz: ");
				scanf("%d",&secim);
				switch (secim)
				{
				case 1:ilk=kitapEkleme(ilk);break;
				case 2:ilk=kitapSilme(ilk);break;
				case 3:ilk=kitaplariGoster(ilk);break;
				case 4:ilk=filtrele(ilk);break;
				case 5:ilkYetkili=yetkiliKontrol(ilkYetkili);break;
				case 6:sifremiDegistir(ilkYetkili);break;
				case 7:goto git;break;
				default:printf("\nBoyle bir secenek yoktur lutfen tekrar deneyiniz...\n");break;
				}
			}
		}
		else if (secim1==2)
		{
			while (1==1)
			{
				printf("\n1)Giris yap\n2)Kayit ol\nYapacaginiz islem:"); scanf(" %d",&secim2);
				if (secim2==1)
				{
					printf("Ogrenci numaraniz:"); scanf(" %s",&girilenAd1);
					kontrol1=ogrenciKontrol(ilkOgrenci,girilenAd1);
					if (kontrol1==0||kontrol1==1)
					{
						printf("Islemi bastan yapiniz...\n\n");
						goto git;
					}
					printf("\nYapacaginiz islemi seciniz:\n");
					printf("1)Kitap odunc alma.\n");
					printf("2)Kitap teslim etme.\n");
					printf("3)sevdiginiz turdeki kitaplara bakma\n");
					printf("4)Onceki menuye gecme.\n");
					printf("Seciminiz: "); scanf(" %d",&secim3);
					switch (secim3)
					{
					case 1:
						printf("Almak istediginiz kitabin adi:");
						scanf(" %[^\t\n]s",&istenilenKitap);
						ilkAlan=kayit(ilkAlan,istenilenKitap,girilenAd1,ilk,ilkOgrenci);
						ilk=oduncAlma(ilk,istenilenKitap);
						break;
					case 2:
						y=oduncVerme(ilkAlan,girilenAd1);
						if (y==1)
						{
							ilk=kitapVerme(ilk,ilkAlan);
							break;
						}
						else{
							printf("\nHic kitap almamissiniz...\n");
							goto git;
						}
						break;
					case 3:
						ilk=filtrele(ilk);
						break;		
					case 4:
						goto git;
						break;
					}			
				}
				else if (secim2==2)
				{
					ilkOgrenci=hesapOlustur(ilkOgrenci);
				}
			}	
		}
		else if(secim1 == 3) {
            sifremiUnuttum(ilkYetkili);
        }
		else
		{
			printf("\nYanlis giris denemesi tekrar deneyiniz...\n");
			goto git;
		}
	}
	return 0;
}
