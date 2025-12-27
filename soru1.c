//Mustafa Doğan 252104038

#include <stdio.h>
#include <stdlib.h>//rastgele sayı üretmek için bu kütüpaneyi aldık
#include <time.h>//her çalışmada o anki saate göre farklı cevaplar görmej için aldık
void aylikciro(int ciro[], int boyut);
  //bu fonsiyon bize aylık cirolar dizisindeki her diziye zaman göre 1 ile 1o arasında sayılar aytıyacak
void yatayGrafikCiz (int ciro[], int boyut);
  //bu fonksiyon bize aylık cirolara göre yatay grafik çizecek 
int maxcirobulma(int ciro[], int boyut);
  //bu fonksiyon bize aylık cirolar dizisindeki en yüksek ciroyu bulacak
void dikeyGrafikCiz (int ciro[], int boyut);
  //bu fonksiyon bize aylık cirolara göre dikey grafik çizecek

int main(){
    int cirolar[12];
    srand(time(NULL));

    aylikciro(cirolar,12);
    for(int j=0;j<12;j++){
        printf("%2d. ayin geliri: %dk \n",(j+1),cirolar[j]);
        //(j+1)'in olamasının sebebi j'nin 0 ile başlamsaıdır
    }
    printf("\nYatay Grafik:\n");
    yatayGrafikCiz (cirolar,12);
    printf("\nDikey Grafik:\n");    
    dikeyGrafikCiz (cirolar,12);
    return 0;


}
void aylikciro(int ciro[], int boyut){
    for(int i=0;i<boyut;i++){
        ciro[i]=(rand()%10)+1;
    }
}
void yatayGrafikCiz (int ciro[], int boyut){
    for(int i=0;i<12;i++){
        printf("%2d. ayda: ",(i+1));
        //(%2d) yazmamızın sebebi ayların maximum iki basamaklı sayılardan oluşmasıdır
        for(int j=0;j<ciro[i];j++){
            printf(" * ");

        }
        printf("\n");
    }
}
int maxcirobulma(int ciro[], int boyut){
    int max=ciro[0];
    //bu fonksiyonda int kullanma sebebimiz ciro değerlerinin integer türünde olmasıdır

    for(int i=1;i<boyut;i++){
        if(ciro[i]>max){
            max=ciro[i];
        }
    }
    return max;
}
void dikeyGrafikCiz (int ciro[], int boyut){
  
    int maxYukseklik = maxcirobulma (ciro, boyut);
    //maxYukseklik değişkeni en yüksek cironun değerini tutacak
    for (int kat = maxYukseklik;kat>=1; kat--){
        for(int i=0; i< boyut; i++){
            if(ciro[i]>=kat){
                printf("  *  ");

            }
            else{
                printf("     ");
            }
            
        }
        printf("\n");
    }
    for(int i=1 ; i<=(boyut);i++){
        printf(" %2d  ",(i));
    }
    //son kısımda printf ile yazmak istediğimiz şeyin 5 karakterlik yer kaplamasını istiyoruz
    printf("\n");
}