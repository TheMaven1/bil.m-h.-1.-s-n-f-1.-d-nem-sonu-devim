//Mustafa Doğan 252104038

#include <stdio.h>
#include <stdlib.h> // rastgele sayı için
#include <time.h>   // zaman parametresi için

#define BOYUT 5

void labirentOlustur(int labirent[BOYUT][BOYUT]); 
// her seferinde farklı labirent kuran fonksiyon
int labirentiCoz(int labirent[BOYUT][BOYUT], int satir, int sutun, int cozum[BOYUT][BOYUT]);
//ozyinelemeli yol bulma fonksiyonu
int guvenliMi(int labirent[BOYUT][BOYUT],int satir,int sutun);
//gidilen konumun guvenli olup olmadigina bakar
void cozumuYazdir(int cozum[BOYUT][BOYUT]);
//bulunan yolu ekrana basar

int main() {
    int labirent[BOYUT][BOYUT];
    
    // her seferinde farklı sayılar üretmek için zamanı kullanıyoruz
    srand(time(NULL));

    // rastgele labirent oluşturuluyor
    labirentOlustur(labirent);

    // çözüm için boş matris oluşturma
    int cozum[BOYUT][BOYUT] = {0}; 

    // başlangıç noktasından çözmeye başlıyoruz
    if (labirentiCoz(labirent, 0, 0, cozum) == 1) {
        printf("cikis yolu bulundu:\n");
        cozumuYazdir(cozum);
    } 
    else {
        printf("maalesef bu sefer cikis yolu yok.\n");
    }

    return 0;
}

// labirenti rastgele dolduran fonksiyon
void labirentOlustur(int labirent[BOYUT][BOYUT]) {
    int i, j;
    for(i = 0; i < BOYUT; i++) {
        for(j = 0; j < BOYUT; j++) {
            // rastgele 0 veya 1 atıyoruz
            labirent[i][j] = rand() % 2; 
        }
    }
    
    // giriş ve çıkış noktaları her zaman açık olmalı
    labirent[0][0] = 1;
    labirent[4][4] = 1;
}

int labirentiCoz(int labirent[BOYUT][BOYUT], int satir, int sutun, int cozum[BOYUT][BOYUT]) {
    
    // eğer çıkışa yani 4,4 noktasına geldiysek bitir
    if (satir == BOYUT - 1 && sutun == BOYUT - 1) {
        cozum[satir][sutun] = 1;
        return 1;
    }

    // gidilen yer güvenli mi kontrolü
    if (guvenliMi(labirent,satir,sutun) == 1) {
        
        // burayı geçtiğimiz yol olarak işaretliyoruz
        cozum[satir][sutun] = 1;

        // aşağı doğru gitmeyi deniyoruz
        if (labirentiCoz(labirent, satir + 1, sutun, cozum) == 1) 
            return 1; 

        // sağa doğru gitmeyi deniyoruz
        if (labirentiCoz(labirent, satir, sutun + 1, cozum) == 1) {
            return 1;
        }

        // eğer iki taraf da kapalıysa geri adım atıyoruz 
        cozum[satir][sutun] = 0;
        return 0;
    }

    return 0;
}

int guvenliMi(int labirent[BOYUT][BOYUT], int satir, int sutun) {
    // koordinatların içeride olup olmadığı ve yolun 1 olup olmadığına bakarız
    if (satir >= 0 && satir < BOYUT && sutun >= 0 && sutun < BOYUT && labirent[satir][sutun] == 1) {
        return 1;
    }
    return 0;
}

void cozumuYazdir(int cozum[BOYUT][BOYUT]) {
    int i, j; 
    for (i = 0; i < BOYUT; i++) {
        for (j = 0; j < BOYUT; j++) {
            printf("%d ", cozum[i][j]);
        }
        printf("\n");
    }
}