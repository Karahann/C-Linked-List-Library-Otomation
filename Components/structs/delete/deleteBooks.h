#include <stdio.h>
#include <stdlib.h>
#include <string.h>

kitaplar *kitapSilme(kitaplar *ilk) { 
	char istenilenKitap[40];
	printf("Silmek istediginiz kitabin adi:");
	scanf(" %[^\t\n]s",&istenilenKitap);
	int m=0;
	kitaplar *x=ilk;
	while(x != NULL)
	{
		if (strcmp(x->kitapAdi,istenilenKitap) == 0)										//girilen iki stringin karsilastirilmasi
		{
			m=1;																			//silinecek kitabin kutuphanede olup olmadigini kontrol eden islem
		}
		x=x->sonraki;
	}
	if(ilk == NULL)
	{
		printf("Kitaplikta hicccc kitap yok");
		return ilk;
	}
	else if(m==1)
	{
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
					else{
						ilk->kitapAdedi--;
					}
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
					return ilk;
	            }
        	temp = temp->sonraki;
		}
	}
	else{
		printf("kitap yok");
		return ilk;
	}
}
