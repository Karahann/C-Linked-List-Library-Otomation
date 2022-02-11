#include <stdio.h>
#include <stdlib.h>
#include <string.h>

oduncA *oduncVerme(oduncA *ilkAlan,char girilenAd1[40]){
    oduncA *x=ilkAlan;
    int y=0;
    while (x!=NULL)
    {
        if (strcmp(x->kullaniciAdi,girilenAd1)==0)
        {
            y=1;
            break;
        }
        x=x->sonraki;
    }
    return (oduncA*)y;
}