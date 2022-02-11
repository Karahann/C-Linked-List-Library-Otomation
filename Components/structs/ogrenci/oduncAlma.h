#include <stdio.h>
#include <stdlib.h>
#include <string.h>

kitaplar *oduncAlma(kitaplar *ilk,char istenilenKitap[40]) { 
	int m=0;
	kitaplar *x=ilk;
	while(x != NULL)
	{
		if (strcmp(x->kitapAdi,istenilenKitap) == 0)
		{
			m=1;
		}
		x=x->sonraki;
	}
	if(m==0) {
		printf("Malesef kutuphanemizde hic kitap yok\n");
		return ilk;
	}else if(m==1){
  	    kitaplar *temp = ilk;
		kitaplar *q = NULL;
	    while(temp != NULL)
		{
	        if(strcmp(ilk->kitapAdi,istenilenKitap) == 0)
			{
				kitaplar *p = ilk->sonraki;
				if (ilk->kitapAdedi==1)
				{
					free(ilk);
					ilk=p;
					temp=ilk;
				}
				else
				{
					ilk->kitapAdedi--;
				}
                printf("\nKitap hesabiniza islenmistir 15 gun sonra getirmeyi veya getirip suresini uzatmayi unutmayiniz...\n");
				return ilk;
			}
			else if (strcmp(temp->sonraki->kitapAdi,istenilenKitap) == 0)
			{
				if (ilk->kitapAdedi==1)
				{
					q=temp->sonraki->sonraki;
					free(temp->sonraki);
					temp->sonraki=q;
					temp=ilk;
				}
				else
				{
					temp->sonraki->kitapAdedi--;
				}
  	            printf("\nKitap hesabiniza islenmistir 15 gun sonra getirmeyi veya getirip suresini uzatmayi unutmayiniz...\n");
				return ilk;
            }
        	temp = temp->sonraki;
		}
	}
	else
	{
		printf("\nAradiginiz kitap kutuphanemizde bulunmamaktadir.\n");
		return ilk;
	}
}