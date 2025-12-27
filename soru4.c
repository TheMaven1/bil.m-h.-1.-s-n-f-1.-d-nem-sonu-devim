//Mustafa Doğan 252104038

#include <stdio.h>

void sifrele(char mesaj[], int anahtar);
//bu fonksiyon verilen mesajı verilen anahtara göre şifreleyecek
void coz(char mesaj[], int anahtar);
//bu fonksiyon verilen mesajı verilen anahtara göre çözecek
void yeniSatirTemizle(char mesaj[]);
//bu fonksiyon fgets ile alınan mesajdaki yeni satır karakterini temizleyecek

int main() {
    char mesaj[100];

    int anahtar;
    //alıştırma 1
    printf("sifrelemek istediginiz mesaji girin: ");
    fgets(mesaj, sizeof(mesaj), stdin);
    yeniSatirTemizle(mesaj);

    printf("anahtar degeri girin: ");
    scanf("%d", &anahtar);
    while(getchar() !='\n'); 
    //buffer temizleme

    sifrele(mesaj, anahtar);
    printf("sifrelenmis Mesaj: %s\n", mesaj);
    //alıştırma 2
    printf("\ncozmek istediginiz mesaji girin: ");
    fgets(mesaj, sizeof(mesaj), stdin);
    yeniSatirTemizle(mesaj);

    printf("anahtar degeri girin: ");
    scanf("%d", &anahtar);
    while(getchar() !='\n');

    coz(mesaj, anahtar);
    printf("cozulmus mesaj: %s\n", mesaj);


    return 0;
}

void yeniSatirTemizle(char mesaj[]) {
    int i = 0;

    int devamEt =1;
    //break gibi çalışacak bir değişken
    while (mesaj[i] !='\0' && devamEt == 1) {
        if (mesaj[i] =='\n') {
            mesaj[i] ='\0';
            devamEt =0;
            //yeni satır karakterini bulduktan sonra döngüyü sonlandırıyoruz
        }
        i++;
    }
}

void sifrele(char mesaj[], int anahtar) {
    for (int i = 0; mesaj[i] !='\0'; i++) {
        //büyük harf şifreleme
        if (mesaj[i] >= 'A' && mesaj[i] <= 'Z') {
            mesaj[i] = (mesaj[i] - 'A' + anahtar) % 26 + 'A';
        //küçük harf şifreleme    
        } else if (mesaj[i] >= 'a' && mesaj[i] <= 'z') {
            mesaj[i] = (mesaj[i] - 'a' + anahtar) % 26 + 'a';
        }
    }
}

void coz(char mesaj[], int anahtar) {
    for (int i = 0; mesaj[i] != '\0'; i++) {
        //büyük harf çözme
        if (mesaj[i] >= 'A' && mesaj[i] <= 'Z') {
            mesaj[i] = (mesaj[i] - 'A' - anahtar + 26) % 26 + 'A';
        //küçük harf çözme    
        } else if (mesaj[i] >= 'a' && mesaj[i] <= 'z') {
            mesaj[i] = (mesaj[i] - 'a' - anahtar + 26) % 26 + 'a';
        }
    }
}