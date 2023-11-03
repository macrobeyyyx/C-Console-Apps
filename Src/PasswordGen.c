#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Şifre oluştur
char *sifreOlustur(int uzunluk);

int main() {
    int uzunluk;
    printf("Şifre uzunluğunu girin: ");
    scanf("%d", &uzunluk);

    // Şifre oluştur
    char *sifre = sifreOlustur(uzunluk);

    // Oluşturulan şifreyi ekrana yazdır
    printf("Oluşturulan şifre: %s\n", sifre);

    // Dinamik belleği serbest bırak
    free(sifre);
    
    return 0;
}

// Şifre oluştur
char *sifreOlustur(int uzunluk) {
    const char karakterler[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-_=+";
    char *sifre = (char *)malloc(uzunluk + 1); // +1 null karakter için
    if (sifre == NULL) {
        perror("Bellek tahsisi hatası");
        exit(1);
    }

    srand((unsigned int)time(NULL));

    // Belirtilen uzunluğa kadar şifre oluşturan kod bloğu
    for (int i = 0; i < uzunluk; i++) {
        int rastgeleIndex = rand() % (sizeof(karakterler) - 1);
        sifre[i] = karakterler[rastgeleIndex];
    }
    sifre[uzunluk] = '\0';

    return sifre;
}
