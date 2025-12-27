//Mustafa Doğan 252104038

#include <stdio.h>  
int ucgensayisibul(int sayi);
//verilen terim sayısına kadar olan sayıları toplar
void ucgenyazdir(int sayi);
//verilen terime göre terim sayısına kadar olan tüm üçgen sayılarını ekrana basar
void ucgensekliciz(int satirSayisi);
//verilen satır sayısına göre üçgen sayılarını sekliyle ekrana basar
int main (){
    int terim;
    printf("kac tane ucgen sayisi :");
    scanf("%d",&terim );

    printf("N=%d icin ucgen sayilari: ", terim);
    ucgenyazdir ( terim );
    printf("\n");

   
    
    printf("Ucgen sekliyle yazimi:\n");
    ucgensekliciz(terim);
    
    return 0;

}

int ucgensayisibul(int sayi){

    if(sayi<=1){
        return 1;
    }
    //Mevcut sayı ile bir önceki sayının toplamını döndürür
    return sayi+ ucgensayisibul( sayi-1);
}
void ucgenyazdir(int sayi){
    for (int i=1; i<=sayi;i++){
        // Her adımda ilgili terimin üçgen sayısını hesaplayıp yazdırır
        printf("%d ", ucgensayisibul(i));
    }
}
void ucgensekliciz(int satirSayisi) {
    int guncelSayi = 1; 

    // Dis dongu: Satirlari kontrol eder
    for (int satir = 1; satir <= satirSayisi; satir++) {
        
      
        for (int bosluk = 1; bosluk <= (satirSayisi - satir); bosluk++) {
            printf("   ");
        }

    
         
        for (int sutun = 1; sutun <= satir; sutun++) {
            printf("%3d   ", guncelSayi);
            guncelSayi++; // Bir sonraki sayiya gecer
        }
        
        
        printf("\n");
    }
}