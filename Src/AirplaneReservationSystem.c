#include <stdio.h>
#include <stdbool.h>

void BosKoltuklariGoster(bool koltuklar[], int koltukSayisi);
void RezervasyonYap(bool koltuklar[], int koltukSayisi);
void RezervasyonIptalEt(bool koltuklar[], int koltukSayisi);

int main() {
    int koltukSayisi = 10;
    bool koltuklar[10] = {false};

    while (1) {
        printf("Lütfen aşağıdaki seçeneklerden birini seçin:\n");
        printf("1. Boş koltukları göster\n");
        printf("2. Koltuk rezervasyonu yap\n");
        printf("3. Rezervasyonu iptal et\n");
        printf("4. Çıkış\n");

        int secim;
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                BosKoltuklariGoster(koltuklar, koltukSayisi);
                break;
            case 2:
                RezervasyonYap(koltuklar, koltukSayisi);
                break;
            case 3:
                RezervasyonIptalEt(koltuklar, koltukSayisi);
                break;
            case 4:
                printf("Çıkış yapılıyor...\n");
                return 0;
            default:
                printf("Geçersiz seçenek. Lütfen tekrar deneyin.\n");
                break;
        }
    }

    return 0;
}

void BosKoltuklariGoster(bool koltuklar[], int koltukSayisi) {
    printf("Boş koltuklar:\n");
    for (int i = 0; i < koltukSayisi; i++) {
        if (!koltuklar[i]) {
            printf("Koltuk %d\n", i + 1);
        }
    }
}

void RezervasyonYap(bool koltuklar[], int koltukSayisi) {
    printf("Rezervasyon yapmak istediğiniz koltuğun numarasını girin: ");
    int koltukNo;
    scanf("%d", &koltukNo);

    if (koltukNo < 1 || koltukNo > koltukSayisi) {
        printf("Geçersiz koltuk numarası. Lütfen tekrar deneyin.\n");
    } else if (koltuklar[koltukNo - 1]) {
        printf("Bu koltuk zaten rezerve edilmiş.\n");
    } else {
        koltuklar[koltukNo - 1] = true;
        printf("Rezervasyon tamamlandı. Koltuk %d sizin.\n", koltukNo);
    }
}

void RezervasyonIptalEt(bool koltuklar[], int koltukSayisi) {
    printf("Rezervasyonu iptal etmek istediğiniz koltuğun numarasını girin: ");
    int koltukNo;
    scanf("%d", &koltukNo);

    if (koltukNo < 1 || koltukNo > koltukSayisi) {
        printf("Geçersiz koltuk numarası. Lütfen tekrar deneyin.\n");
    } else if (!koltuklar[koltukNo - 1]) {
        printf("Bu koltuk zaten boş.\n");
    } else {
        koltuklar[koltukNo - 1] = false;
        printf("Rezervasyon iptal edildi. Koltuk %d boş.\n", koltukNo);
    }
}
