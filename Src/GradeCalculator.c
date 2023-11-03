#include <stdio.h>

int main() {
    char okulTuru;
    int toplamDersSayisi, kalanDersSayisi = 0;
    double sinifGecmeNotu, toplamNot = 0, ortalamaNot;

    printf("Lise mi (L) yoksa Üniversite mi (Ü) okuyorsunuz? (L/Ü): ");
    scanf(" %c", &okulTuru);

    printf("Toplam ders sayısını girin: ");
    scanf("%d", &toplamDersSayisi);

    printf("Sınıf geçme notunu girin: ");
    scanf("%lf", &sinifGecmeNotu);

    for (int i = 1; i <= toplamDersSayisi; i++) {
        double dersNotu;
        printf("Ders %d notunu girin: ", i);
        scanf("%lf", &dersNotu);

        toplamNot += dersNotu;

        if (dersNotu < sinifGecmeNotu) {
            kalanDersSayisi++;
        }
    }

    ortalamaNot = toplamNot / toplamDersSayisi;

    printf("Ortalama Not: %.2lf\n", ortalamaNot);
    printf("Başarılı Ders Sayısı: %d\n", toplamDersSayisi - kalanDersSayisi);
    printf("Kalan Ders Sayısı: %d\n", kalanDersSayisi);

    if (okulTuru == 'L' || okulTuru == 'l') {
        if (kalanDersSayisi > 3 || ortalamaNot < 55) {
            printf("Sınıfta kaldınız!\n");
        } else {
            printf("Sınıfı geçtiniz!\n");
        }
    } else if (okulTuru == 'Ü' || okulTuru == 'ü') {
        if (kalanDersSayisi > 2 || ortalamaNot < 60) {
            printf("Sınıfta kaldınız!\n");
        } else {
            printf("Sınıfı geçtiniz!\n");
        }
    } else {
        printf("Geçersiz okul türü seçimi.\n");
    }

    return 0;
}
