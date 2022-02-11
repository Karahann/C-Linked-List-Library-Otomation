#include <stdio.h>
#include <stdlib.h>

struct kitap{
	int kitapNo;
	char kitapAdi[40];
	int kitapSayfasi;
	char kitapTuru[40];
	int kitapAdedi;
	struct kitap *sonraki;
};

typedef struct kitap kitaplar;

struct yetkili{
    char kullaniciAdi[40];
    char yetkiliSifre[40];
    char yetkiliSifre2[40];
    char yetkiliAnahtarKelime[40];
	struct yetkili *sonraki;
};

typedef struct yetkili yetkililer;

struct ogrenci{
	char kullaniciAdi[40];
	char sifre[40];
	struct ogrenci *sonraki;
};

typedef struct ogrenci ogrenciler;

struct odunc{
	char *kullaniciAdi;
	char *aldigiKitap;
	char *kitabinturu;
	int kitabinsayfasi;
	struct odunc *sonraki;
};

typedef struct odunc oduncA;