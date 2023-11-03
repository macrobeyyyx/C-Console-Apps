#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ürün yapısı
struct Urun {
    char ad[50];
    double fiyat;
};

// Sipariş yapısı
struct Siparis {
    char urunAdi[50];
    int adet;
};

int main() {
    // Ürünleri ve siparişleri saklamak için struct dizilerini tanımla
    struct Urun urunler[4];
    struct Siparis siparisler[50];

    // Ürün bilgilerini doldur
    strcpy(urunler[0].ad, "Çay");
    urunler[0].fiyat = 2.0;

    strcpy(urunler[1].ad, "Kahve");
    urunler[1].fiyat = 3.0;

    strcpy(urunler[2].ad, "Sandviç");
    urunler[2].fiyat = 5.0;

    strcpy(urunler[3].ad, "Meyve Suyu");
    urunler[3].fiyat = 4.0;

    int urunSayisi = 4;
    int siparisSayisi = 0;

    // Sonsuz bir döngü oluştur ve kullanıcının işlemlerini seçmesini sağla
    while (1) {
        printf("Kantin Ürünleri:\n");
        for (int i = 0; i < urunSayisi; i++) {
            printf("%s - %.2lf TL\n", urunler[i].ad, urunler[i].fiyat);
        }

        printf("Lütfen bir işlem seçin:\n");
        printf("1. Ürün Satın Alma\n");
        printf("2. Sipariş Geçmişi Görüntüle\n");
        printf("3. Çıkış\n");

        int secim;
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                urunSatınAl(urunler, siparisler, &siparisSayisi);
                break;
            case 2:
                siparisGecmisiGoruntule(siparisler, siparisSayisi);
                break;
            case 3:
                printf("Çıkış yapılıyor...\n");
                return 0;
            default:
                printf("Geçersiz seçenek. Lütfen tekrar deneyin.\n");
        }
    }

    return 0;
}

// Ürün satın alma işlemi
void urunSatınAl(struct Urun urunler[], struct Siparis siparisler[], int *siparisSayisi) {
    printf("Satın almak istediğiniz ürünü seçin: ");
    char urunAdi[50];
    scanf("%s", urunAdi);

    // Ürünün varlığını kontrol et
    int urunIndex = -1;
    for (int i = 0; i < 4; i++) {
        if (strcmp(urunler[i].ad, urunAdi) == 0) {
            urunIndex = i;
            break;
        }
    }

    if (urunIndex != -1) {
        printf("Kaç adet almak istiyorsunuz: ");
        int adet;
        scanf("%d", &adet);

        // Siparişi ekleyin
        strcpy(siparisler[*siparisSayisi].urunAdi, urunAdi);
        siparisler[*siparisSayisi].adet = adet;
        (*siparisSayisi)++;

        // Toplam fiyatı hesaplayın
        double toplamFiyat = urunler[urunIndex].fiyat * adet;
        printf("Siparişiniz alındı. Toplam Tutar: %.2lf TL\n", toplamFiyat);
    } else {
        printf("Geçersiz ürün seçimi.\n");
    }
}

// Sipariş geçmişi görüntüleme işlemi
void siparisGecmisiGoruntule(struct Siparis siparisler[], int siparisSayisi) {
    printf("Sipariş Geçmişi:\n");
    for (int i = 0; i < siparisSayisi; i++) {
        printf("%s - %d adet\n", siparisler[i].urunAdi, siparisler[i].adet);
    }
}
