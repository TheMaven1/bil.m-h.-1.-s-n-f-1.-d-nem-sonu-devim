//Mustafa Doğan 252104038

#include <stdio.h>

int unlumu(char harf);
//bize harfin ümlü olup olmadığını beliriitir
int asalmi(int sayi);
//bize sayının asal olup olmadığını belirtir
int main() {
    int sayac = 0;
    char harf1, harf2;
    //iki harf alıyoruz çünkü 3. harf birinci harfin aynısı olacak

    printf("Gecerli Gezegen Bob Isimleri:\n");
    printf("----------------------------\n");

    for (harf1 = 'a'; harf1 <= 'z'; harf1++) {
        for (harf2 = 'a'; harf2 <= 'z'; harf2++) {
            
            int h1unlu = unlumu(harf1);
            int h2unlu = unlumu(harf2);

            if ((h1unlu == 1 && h2unlu == 0) || (h1unlu == 0 && h2unlu == 1)) {
              //burda ünlü ve ünsüz harf kombinasyonlarını kontrol ediyoruz  
                int toplam = (int)harf1 + (int)harf2 + (int)harf1;
                // harflerin ASCII değerlerini topluyoruz
                if (asalmi(toplam)) {
                    //toplamın asal olup olmadığını kontrol ediyoruz
                    sayac++;
                    printf("%d. %c%c%c\n", sayac, harf1, harf2, harf1);
                }
            }
        }
    }

    return 0;
}

int unlumu(char harf) { 

    if (harf == 'a' || harf == 'e' || harf == 'i' || harf == 'o' || harf == 'u') {
        return 1;//doğru
    }
    return 0;// yanlıs
}

int asalmi(int sayi) {

    if (sayi < 2) {
        return 0;}
    for (int i = 2; i * i <= sayi; i++) {
        if (sayi % i == 0) return 0;
    }
    return 1;
}