#include <stdio.h>

int main() {
    printf("Basit Hesap Makinesi\n");
    printf("İşlem seçin (+, -, *, /): ");
    char islemTuru;
    scanf(" %c", &islemTuru);

    printf("Birinci sayıyı girin: ");
    int sayi1;
    scanf("%d", &sayi1);

    printf("İkinci sayıyı girin: ");
    int sayi2;
    scanf("%d", &sayi2);

    int sonuc = 0;

    // Eğer işlem türü bölme (/) ise
    if (islemTuru == '/') {
        if (sayi2 != 0) {
            double bolme = (double)sayi1 / sayi2;
            printf("Sonuç: %.2lf\n", bolme);
            return 0;
        } else {
            printf("Hata: Sıfıra bölme hatası!\n");
            return 1;
        }
    } else if (islemTuru == '+') {
        sonuc = sayi1 + sayi2;
    } else if (islemTuru == '-') {
        sonuc = sayi1 - sayi2;
    } else if (islemTuru == '*') {
        sonuc = sayi1 * sayi2;
    } else {
        printf("Geçersiz işlem.\n");
        return 1;
    }

    printf("Sonuç: %d\n", sonuc);
    return 0;
}
