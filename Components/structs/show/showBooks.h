#include <stdio.h>
#include <stdlib.h>
#include <string.h>

kitaplar *kitaplariGoster(kitaplar *ilk)
{
	if(ilk == NULL)
	{
		printf("Kitap yok");
	} 
	else {
		kitaplar *temp = ilk;
		int sayac = 1;																				//kitaplarin dogru sirayla siralanmasi icin kitap numarasini burada kaydettik
		while(temp != NULL)
		{
			temp->kitapNo=sayac;
			printf("******************************************* \n");
        	printf("%d.Kitabin adi:%s ,sayfasi:%d ,turu:%s ,adeti:%d\n",temp->kitapNo,temp->kitapAdi,temp->kitapSayfasi,temp->kitapTuru,temp->kitapAdedi);
    	    temp = temp->sonraki;
			sayac++;
	    }
    }  
    return ilk;
}
