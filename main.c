//
//  main.c
//  avp_donemprojesi
//
//  Created by Zeynep Erarslan & Enes Malik Alrınpınar on 12.12.2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define max_deger 100
#define min_deger 0
#define altın 10
#define beceri_deger 3
#define beceri_maxdeger 25


typedef struct {
    char isim[100];
    char ensturman[50];
    int para;
    int seviye;
    int tecrube;
    int can;
    int tokluk;
    int uyku;
    int hijyen;
    int moral;
    int tuvalet;
    int sosyal;
    int guc;
    int ceviklik;
    int dayaniklilik;
    int karizma;
    int toplayicilik;
    
} Karakter;


void menuGoster(Karakter *oyuncu);
void adaGit(Karakter *oyuncu);
void doktorGit(Karakter *oyuncu);
void carsiGit(Karakter *oyuncu);
void macera(Karakter *oyuncu);
void seviyeAtla(Karakter *oyuncu);
void durumGoster(Karakter *oyuncu);
void beceri(Karakter *oyuncu);
void arti_deger(int *ozellik, int miktar, int max);
void eksi_deger(int *ozellik, int miktar, int max);
int  input(int min, int max);
void canKontrol(Karakter *oyuncu);

int main(void) {
    
    Karakter oyuncu;
    
    printf("\tADAYA HOSGELDIN\n");
    printf("Karakter Adi: ");
    fgets(oyuncu.isim, sizeof(oyuncu.isim), stdin);
    oyuncu.isim[strcspn(oyuncu.isim, "\n")] = 0;
    
    printf("Karakterinin Kullanacagi Muzik Aleti: ");
    fgets(oyuncu.ensturman, sizeof(oyuncu.ensturman), stdin);
    oyuncu.ensturman[strcspn(oyuncu.ensturman, "\n")] = 0;
    
    printf("\n MERHABA %s\n",oyuncu.isim);
    
    
    oyuncu.can = max_deger;
    oyuncu.hijyen = 50;
    oyuncu.tokluk = 50;
    oyuncu.uyku = 50;
    oyuncu.moral = 50;
    oyuncu.sosyal = 50;
    oyuncu.tuvalet =50;
    oyuncu.ceviklik =beceri_deger;
    oyuncu.dayaniklilik =beceri_deger;
    oyuncu.guc =beceri_deger;
    oyuncu.karizma =beceri_deger;
    oyuncu.toplayicilik =beceri_deger;
    oyuncu.seviye = 1;
    oyuncu.para = altın;
    oyuncu.tecrube = 0;
    
    
    
   do {
       menuGoster(&oyuncu);
    }
    while (1);

    return 0;
}

void canKontrol(Karakter *oyuncu) {
    
       if (oyuncu->tokluk == 0) {
            printf("\nUYARI: Tokluk 0'a dustu. Caniniz 20 azaldi.\n");
            oyuncu->can -= 20;
        }

        if (oyuncu->uyku == 0) {
            printf("\nUYARI: Uyku 0'a dustu. Caniniz 10 azaldi.\n");
            oyuncu->can -= 10;
        }

        
        if (oyuncu->hijyen == 0) {
            printf("\nUYARI: Hijyen 0'a dustu. Caniniz 10 azaldi.\n");
            oyuncu->can -= 10;
        }

        if (oyuncu->moral == 0) {
            printf("\nUYARI: Moral 0'a dustu. Caniniz 4 azaldi.\n");
            oyuncu->can -= 4;
        }
       
        if (oyuncu->tuvalet == 0) {
        printf("\nUYARI: Moral 0'a dustu.  Caniniz 5 azaldi.\n");
        oyuncu->can -= 5;
       }
       
       if (oyuncu->sosyal == 0) {
        printf("\nUYARI: Moral 0'a dustu. Caniniz 4 azaldi.\n");
        oyuncu->can -= 4;
      }
       
       if (oyuncu->tokluk < 15) {
            printf("\nUYARI: Uyari! Tokluk seviyen cok dusuk (%d)\n", oyuncu->tokluk);
        }
    
      if (oyuncu->uyku < 20) {
          printf("\nUYARI: Uyari! Uyku seviyen cok dusuk (%d)\n", oyuncu->uyku);
      }
       
    if (oyuncu->hijyen < 15) {
        printf("\nUYARI: Uyari! Hijyen seviyen cok dusuk  (%d)\n", oyuncu->hijyen);
    }
    
    if (oyuncu->moral < 10) {
              printf("\nUYARI: Uyari! Moral seviyen cok dusuk  (%d)\n", oyuncu->moral);
    }
    
    if (oyuncu->tuvalet < 20) {
              printf("\nUYARI: Uyari! Tuvalet seviyen cok dusuk  (%d)\n", oyuncu->tuvalet);
    }
    
    if (oyuncu->sosyal < 10) {
              printf("\nUYARI: Uyari! Sosyallik seviyen cok dusuk (%d)\n", oyuncu->sosyal);
    }
    
      if (oyuncu->can <= 0) {
        
        printf("Karakter öldü!\n");
        printf("OYUN SONLANDIRILDI\n");
        exit(0);
    }
}

    
    void menuGoster(Karakter *oyuncu) {
                
        int secenek;
        printf("\n-------ANA MENU-------\n");
        printf("1.Adaya Git\n");
        printf("2.Doktorun Yanina Git \n");
        printf("3.Carsiya Git\n");
        printf("4.Maceraya Atil\n");
        printf("5.Seviye Atla\n");
        printf("6.Durumu Goster\n");
        printf("7.Oyundan Çık\n\n");
        
        printf("SECIM: ");
        
        secenek=input(1,7);
        
        switch(secenek) {
                
            case 1:
                adaGit(oyuncu);
                break;
                
            case 2:
                doktorGit(oyuncu);
                break;
                
            case 3:
                carsiGit(oyuncu);
                break;
                
            case 4:
                macera(oyuncu);
                break;
                
            case 5:
                seviyeAtla(oyuncu);
                break;
                
            case 6:
                durumGoster(oyuncu);
                break;
                
            case 7:
                printf("Oyundan cikmak mi istiyorsun?\n");
                printf("EVET-->1 HAYIR-->0\n");
                printf("SECIM: ");
                
                if (input(0, 1)) {
                    printf("OYUN SONLANDIRILDI\n");
                    exit(0);
                }
                break;
                
            default:
                
                break;
    
        }
    }


void adaGit(Karakter *oyuncu) {
    
    int secenek;
    
    printf("---------------------------------------");
    printf("\n %s Adaya Ulasti \n", oyuncu->isim);
    printf("\n--> Adada ne yapmak istersin?\n");
    printf("1.Atesin basinda takim arkadaslarina calgi çal ya da sarki soyle.\n");
    printf("2.Okyanusa git ve yikan.\n");
    printf("3.Barakaya git ve uyu.\n");
    printf("4.Pilav yap ve ye.\n");
    printf("5.Arkadaslarinla birlikte okyanusta balik tut ve birlikte pisirin.\n");
    printf("6.Tuvalet ihtiyacini gider.\n");
    printf("7.Sehrine geri dön.\n\n");
    printf("SECIM: ");
    
    secenek = input(1,7);
    
    switch(secenek){
            
        case 1:
            printf("\n--> Harika bir secim!\n");
            printf("--> Takim arkadaslarin %s calisina bayildi.\n",oyuncu->ensturman);
            printf("--> Birlikte doyasıya eglendiniz!\n");
            
            arti_deger(&oyuncu->moral ,20, max_deger);
            printf("+ Moral seviyen 20 puan artti\n");
            
            arti_deger(&oyuncu->sosyal,20, max_deger);
            printf("+ Sosyallik seviyen 20 puan artti\n");
            
            arti_deger(&oyuncu->karizma, 5, beceri_maxdeger);
            printf("+ Karizma seviyen 5 puan artti\n");
            
                    
            break;
            
        case 2:
            printf("\n--> Harika bir secim!\n");
            printf("--> Tüm pisliklerden arinma zamani!\n");
            
            arti_deger(&oyuncu->hijyen,25, max_deger);
            printf("+ Hijyen seviyen 25 puan artti\n");
            
            arti_deger(&oyuncu->moral,25, max_deger);
            printf("+ Moral seviyen 25 puan artti\n");
            
            
            break;
            
        case 3:
            
            printf("\n--> Yogun bir gundu uyku zamani!\n");
            
            arti_deger(&oyuncu->uyku,20, max_deger);
            printf("+ Uyku seviyen 20 puan artti\n");
            
            arti_deger(&oyuncu->dayaniklilik,5, beceri_maxdeger);
            printf("+ Dayaniklilik seviyen 5 puan artti\n");
            
            arti_deger(&oyuncu->guc,7, beceri_maxdeger);
            printf("+ Guc seviyen 7 puan artti\n");
            
            eksi_deger(&oyuncu->tokluk,20, min_deger);
            printf("- Tokluk seviyen 20 puan azaldi\n");
            
            eksi_deger(&oyuncu->sosyal,20, min_deger);
            printf("- Sosyallik seviyen 20 puan  azaldi\n");
            
            eksi_deger(&oyuncu->hijyen,20, min_deger);
            printf("- Hijyen seviyen 20 puan azaldi\n");
            
            arti_deger(&oyuncu->tuvalet,20, max_deger);
            printf("+ Tuvalet seviyen 20 puan artti\n");
            
            
            break;
            
        case 4:
            printf("\n--> Pilavı cok guzel pisirdin afiyet olsun!\n");

            arti_deger(&oyuncu->tokluk,15, max_deger);
            printf("+ Tokluk seviyen 15 puan artti\n");
            
            arti_deger(&oyuncu->guc,3, beceri_maxdeger);
            printf("+ Guc seviyen 3 puan artti\n");
            
            eksi_deger(&oyuncu->uyku,20, min_deger);
            printf("- Uyku seviyen 20 puan azaldi\n");
            
            arti_deger(&oyuncu->tuvalet,10, max_deger);
            printf("+ Tuvalet seviyen 10 puan artti\n");
            
            
            break;
            
        case 5:
            printf("\n--> Okyanus harika.\n");
            printf("--> Tum takima yetecek kadar balik tuttunuz tebrikler!\n");
            printf("--> Simdi onlari afiyetle yiyin.");
        
            
            arti_deger(&oyuncu->tokluk,25, max_deger);
            printf("+ Tokluk seviyen 25 puan artti\n");
            
            arti_deger(&oyuncu->guc,5, beceri_maxdeger);
            printf("+ Guc seviyen 5 puan artti\n");
            
            arti_deger(&oyuncu->ceviklik,7, beceri_maxdeger);
            printf("+ Ceviklik seviyen 7 puan artti\n");
            
            eksi_deger(&oyuncu->uyku,30, min_deger);
            printf("- Uyku seviyen 30 puan azaldi\n");
            
            arti_deger(&oyuncu->tuvalet,15, max_deger);
            printf("+ Tuvalet seviyen 15 puan artti\n");
            
            arti_deger(&oyuncu->sosyal,20, max_deger);
            printf("+ Sosyallik seviyen 20 puan artti\n");
            
            break;
            
        case 6:
            
            if (oyuncu->tuvalet > 50) {
                    printf("\n--> Tuvalet ihtiyacını giderdin\n");
                    
                eksi_deger(&oyuncu->tuvalet,20, min_deger);
                printf("- Tuvalet seviyen 20 puan azaldi\n");
                
                arti_deger(&oyuncu->moral,15, max_deger);
                printf("+ Moral seviyen 15 puan artti\n");
                
                eksi_deger(&oyuncu->tokluk,15, min_deger);
                printf("- Tokluk seviyen 15 puan azaldi\n");
                
                } else {
                    printf("\n--> Şu anda tuvalet ihtiyacın yok.\n");
                }
        
            break;
        
        case 7:
            printf("\nAda hayati bu kadarmis...\n");
            printf("Sehrine geri donuyorsun.\n");
            printf("Kendine iyi bak\n");
    
            break;
            
        default:
            break;
            
    }
    canKontrol(oyuncu);
    }
   
void doktorGit(Karakter *oyuncu) {
    
    int secenek;
    
    printf("---------------------------------------");
    printf("\n %s Doktorun Yanina Gitti\n",oyuncu->isim);
    printf("\n--> Doktordan talebin nedir?\n");
    printf("1.Yara bolgelerini sargi beziyle sardir\n");
    printf("2.Antibiyotikli krem sürmesini iste\n");
    printf("3.Agri kesici hap iste\n");
    printf("4.Serum taktir.\n");
    printf("5.Sehrine geri dön\n\n");
    printf("SECIM: ");
    
    secenek = input(1,5);
    
    switch(secenek){
            
        case 1:
            printf("\n--> Yara bolgelerin sargi beziyle sarildi.\n");
            arti_deger(&oyuncu->can,10,max_deger);
            printf("+ Can seviyen 10 puan artti\n");
            
            arti_deger(&oyuncu->hijyen,10,max_deger);
            printf("+ Hijyen seviyen 10 puan artti\n");
            
            arti_deger(&oyuncu->dayaniklilik,5, beceri_maxdeger);
            printf("+ Dayaniklilik seviyen 5 puan artti\n");
            
            break;
            
        case 2:
            printf("\n--> Gerekli yerlere antibiyotikli krem sürüldü.\n");
            arti_deger(&oyuncu->can,15,max_deger);
            printf("+ Can seviyen 15 puan  artti\n");
            
            arti_deger(&oyuncu->dayaniklilik,4, beceri_maxdeger);
            printf("+ Dayaniklilik seviyen 4 puan artti\n");
            
            arti_deger(&oyuncu->moral,15, max_deger);
            printf("+ Moral seviyen 15 puan artti\n");
            
            
            break;
            
        case 3:
            printf("\n--> Agri kesici hap alındı.\n");
            arti_deger(&oyuncu->can,20,max_deger);
            printf("+ Can seviyen 20 puan artti\n");
            
            arti_deger(&oyuncu->dayaniklilik,5, beceri_maxdeger);
            printf("+ Dayaniklilik seviyen 5 puan artti\n");
            
            arti_deger(&oyuncu->guc,4, beceri_maxdeger);
            printf("+ Guc seviyen 4 puan artti\n");
            
            arti_deger(&oyuncu->moral,20, max_deger);
            printf("+ Moral seviyen 20 puan artti\n");
            
            eksi_deger(&oyuncu->uyku,15, min_deger);
            printf("- Uyku seviyen 15 puan azaldi\n");
            
            break;
            
        case 4:
            printf("\n--> Revirde serum baglandi\n");
            arti_deger(&oyuncu->can,30,max_deger);
            printf("+ Can seviyen 30 puan artti\n");
            
            arti_deger(&oyuncu->dayaniklilik,7, beceri_maxdeger);
            printf("+ Dayaniklilik seviyen 7 puan  artti\n");
            
            arti_deger(&oyuncu->guc,5, beceri_maxdeger);
            printf("+ Guc seviyen 5 puan artti\n");
            
            eksi_deger(&oyuncu->hijyen,15, min_deger);
            printf("- Hijyen seviyen 15 puan azaldi\n");
            
            arti_deger(&oyuncu->moral,25, max_deger);
            printf("+ Moral seviyen 25 puan artti\n");
            
            break;
            
        case 5:
            printf("\nDoktordan ayrılıyorsun.\n");
            printf("Sehrine geri donuyorsun.\n");
            printf("Kendine iyi bak!!\n");
            break;
            
        default:
            break;
            
    }
            
    canKontrol(oyuncu);
    
}

void carsiGit(Karakter *oyuncu) {
    
    int secenek;
    int secim_yemek;
    int secim_icecek;
    int kazanc;
    
    printf("---------------------------------------");
    printf("\n%s Carsiya Ulasti \n",oyuncu->isim);
    printf("\n--> Carsida yapmak istersin?\n");
    printf("1.Cok aciktin hemen yiyecek satin al ve ye\n");
    printf("2.İcecek satin al, onu ic ve eglen\n");
    printf("3.Carsinin meydaninda enstruman cal ve sarki soyle\n");
    printf("4.Sehrine geri dön\n\n");
    printf("SECIM: ");
    
    secenek = input(1,4);
    
    switch(secenek){
            
        case 1:
            
                printf("\nNe yemek istersin?\n");
                printf("1. Et Yahni\n");
                printf("2. Izgara Tavuk\n");
                printf("3. Sebze Corbasi\n");
                printf("4. Gozleme\n");
                printf("5. Salata\n");

                printf("Seciminizi yapiniz: ");
                scanf("%d",&secim_yemek);
            
            switch(secim_yemek){
                    
                case 1:
                    printf("\n--> Et yahni afiyetle yendi.\n");
                    printf("--> Afiyet olsun!!!\n");
                    printf("--> Ucret:200 altin\n");
                    
                    oyuncu->para -= 200;
                    
                    arti_deger(&oyuncu->tokluk,30,max_deger);
                    printf("+ Tokluk seviyen 30 puan artti\n");
                    
                    arti_deger(&oyuncu->guc,10, beceri_maxdeger);
                    printf("+ Guc seviyen 10 puan artti\n");
                    
                    arti_deger(&oyuncu->dayaniklilik,10, beceri_maxdeger);
                    printf("+ Dayaniklilik seviyen 10 puan artti\n");
                    
                    arti_deger(&oyuncu->ceviklik,10, beceri_maxdeger);
                    printf("+ Ceviklik seviyen 10 puan artti\n");
                    
                    
                    eksi_deger(&oyuncu->uyku,25, min_deger);
                    printf("- Uyku seviyen  25 puan azaldi\n");
                    
                    arti_deger(&oyuncu->tuvalet,20,max_deger);
                    printf("+ Tuvalet seviyen 20 puan artti\n");
                    
                    arti_deger(&oyuncu->moral,20,max_deger);
                    printf("+ Moral seviyen 20 puan artti\n");
                    
                    
                    break;
                    
                case 2:
                    printf("\n--> Izgara Tavuk afiyetle yendi.\n");
                    printf("--> Afiyet olsun!!!\n");
                    printf("--> Ucret:150 altin\n");
                    
                    oyuncu->para -= 150;
                    
                    arti_deger(&oyuncu->tokluk,25,max_deger);
                    printf("+ Tokluk seviyen 25 puan artti\n");
                    
                    arti_deger(&oyuncu->guc,7, beceri_maxdeger);
                    printf("+ Guc seviyen 7 puan artti\n");
                    
                    arti_deger(&oyuncu->dayaniklilik,7, beceri_maxdeger);
                    printf("+ Dayaniklilik seviyen 7 puan artti\n");
                    
                    arti_deger(&oyuncu->ceviklik,7, beceri_maxdeger);
                    printf("+ Ceviklik seviyen 7 puan artti\n");
                    
                    eksi_deger(&oyuncu->uyku,15, min_deger);
                    printf("- Uyku seviyen 15 puan azaldi\n");
                    
                    arti_deger(&oyuncu->tuvalet,20,max_deger);
                    printf("+ Tuvalet seviyen 20 puan artti\n");
                    
                    arti_deger(&oyuncu->moral,10,max_deger);
                    printf("+ Moral seviyen 10 puan artti\n");
                    
                    break;
                    
                case 3:
                    printf("\n--> Sebze Corbasi afiyetle yendi.\n");
                    printf("--> Afiyet olsun!!!\n");
                    printf("--> Ucret:80 altin\n");
                    
                    oyuncu->para -= 80;
                    
                    arti_deger(&oyuncu->tokluk,20,max_deger);
                    printf("+ Tokluk seviyen 20 puan artti\n");
                    
                    arti_deger(&oyuncu->guc,5, beceri_maxdeger);
                    printf("+ Guc seviyen 5 puan artti\n");
                    
                    arti_deger(&oyuncu->dayaniklilik,5, beceri_maxdeger);
                    printf("+ Dayaniklilik seviyen 5 puan artti\n");
                    
                    arti_deger(&oyuncu->ceviklik,5, beceri_maxdeger);
                    printf("+ Ceviklik seviyen 5 puan artti\n");
                    
                    eksi_deger(&oyuncu->uyku,5, min_deger);
                    printf("- Uyku seviyen 5 puan azaldi\n");
                    
                    arti_deger(&oyuncu->tuvalet,20,max_deger);
                    printf("+ Tuvalet seviyen 20 puan artti\n");
                    
                    arti_deger(&oyuncu->moral,10,max_deger);
                    printf("+ Moral seviyen 10 puan artti\n");
                    
                    break;
                    
                    
                case 4:
                    printf("\n--> Gozleme afiyetle yendi.\n");
                    printf("--> Afiyet olsun!!!\n");
                    printf("--> Ucret:50 altin\n");
                    
                    oyuncu->para -= 50;
                    
                    arti_deger(&oyuncu->tokluk,15,max_deger);
                    printf("+ Tokluk seviyen  15 puan artti\n");
                    
                    arti_deger(&oyuncu->guc,4, beceri_maxdeger);
                    printf("+ Guc seviyen 4 puan artti\n");
                    
                    arti_deger(&oyuncu->dayaniklilik,4, beceri_maxdeger);
                    printf("+ Dayaniklilik seviyen 4 puan artti\n");
                    
                    arti_deger(&oyuncu->ceviklik,3, beceri_maxdeger);
                    printf("+ Ceviklik seviyen 3 puan artti\n");
                    
                    eksi_deger(&oyuncu->uyku,7, min_deger);
                    printf("- Uyku seviyen 7 puan azaldi\n");
                    
                    arti_deger(&oyuncu->tuvalet,15,max_deger);
                    printf("+ Tuvalet seviyen 15 puan artti\n");
                    
                    arti_deger(&oyuncu->moral,5,max_deger);
                    printf("+ Moral seviyen 5 puan artti\n");
                    
                    break;
                    
                case 5:
                    printf("\n--> Salata afiyetle yendi.\n");
                    printf("--> Afiyet olsun!\n");
                    printf("--> Ucret:55 altin\n");
                    
                    oyuncu->para -= 55;
                    
                    arti_deger(&oyuncu->tokluk,10,max_deger);
                    printf("+ Tokluk seviyen 10 puan artti\n");
                    
                    arti_deger(&oyuncu->guc,3, beceri_maxdeger);
                    printf("+ Guc seviyen 3 puan artti\n");
                    
                    arti_deger(&oyuncu->dayaniklilik,3, beceri_maxdeger);
                    printf("+ Dayanaiklilik seviyen 3 puan artti\n");
                    
                    arti_deger(&oyuncu->ceviklik,2, beceri_maxdeger);
                    printf("+ Ceviklik seviyen 2 puan artti\n");
                    
                    eksi_deger(&oyuncu->uyku,5, min_deger);
                    printf("- Uyku seviyen 5 puan azaldi\n");
                    
                    arti_deger(&oyuncu->tuvalet,10,max_deger);
                    printf("+ Tuvalet seviyen 10 puan artti\n");
                    
                    arti_deger(&oyuncu->moral,5,max_deger);
                    printf("+ Moral seviyen 5 puan artti\n");
                    
                    break;
                    
                default:
                    printf("Hatali secim!!");
                    break;

            }
            break;
            
        case 2:
            printf("\nNe icmek istersin?\n");
            printf("1. Meyve suyu\n");
            printf("2. Asitli Icecek\n");
            printf("3. Enerji Icecegi\n");
            scanf("%d",&secim_icecek);
            
            switch(secim_icecek){
                    
                case 1:
                    printf("\n--> Meyve suyu ictin.\n");
                    printf("-->Afiyet Olsun!\n");
                    printf("--> Ucret: 15 altin\n");
                    
                    oyuncu->para -= 15;
                    
                    arti_deger(&oyuncu->tokluk,2,max_deger);
                    printf("+ Tokluk seviyen 2 puan artti\n");
                    
                    arti_deger(&oyuncu->tuvalet,10,max_deger);
                    printf("+ Tuvalet seviyen 10 puan artti\n");
                    
                    printf("->Icecegini ictin ve eglendin!\n");
                    
                    arti_deger(&oyuncu->moral,15,max_deger);
                    printf("+ Moral seviyen 15 puan artti\n");
                    
                    arti_deger(&oyuncu->karizma,5,beceri_maxdeger);
                    printf("+ Karizma seviyen 5 puan artti\n");
                    
                    break;
                    
                case 2:
                    printf("\n--> Asitli Icecek ictin.\n");
                    printf("--> Afiyet Olsun!!\n");
                    printf("--> Ucret:20 altin\n");
                    
                    oyuncu->para -= 20;
                    
                    arti_deger(&oyuncu->tokluk,3,max_deger);
                    printf("+ Tokluk seviyen 3 puan artti\n");
                    
                    arti_deger(&oyuncu->tuvalet,15,max_deger);
                    printf("+ Tuvalet seviyen 15 puan artti\n");
                    
                    printf("-> Icecegini ictin ve eglendin\n");
                    
                    arti_deger(&oyuncu->moral,20,max_deger);
                    printf("+ Moral seviyen 20 puan artti\n");
                    
                    arti_deger(&oyuncu->karizma,5,beceri_maxdeger);
                    printf("+ Karizma seviyen 5 puan artti\n");
                    
                    break;
                    
                case 3:
                    printf("\n--> Enerji Icecegi ictin.\n");
                    printf("--> Afiyet Olsun!!\n");
                    printf("--> Ucret: 30 altin\n");
                    
                    oyuncu->para -= 30;
                    
                    arti_deger(&oyuncu->tokluk,5,max_deger);
                    printf("+ Tokluk seviyen 5 puan artti\n");
                    
                    arti_deger(&oyuncu->tuvalet,20,max_deger);
                    printf("+ Tuvalet seviyen 20 puan artti\n");
                    
                    arti_deger(&oyuncu->dayaniklilik,10,beceri_maxdeger);
                    printf("+ Dayaniklilik seviyen 10 puan artti\n");
                    
                    printf("-> Icecegini ictin ve eglendin!\n");
                    
                    arti_deger(&oyuncu->moral,20,max_deger);
                    printf("+ Moral seviyen 20 puan artti\n");
                    
                    arti_deger(&oyuncu->karizma,5,beceri_maxdeger);
                    printf("+ Karizma seviyen 5 puan artti\n");
                    
                    break;
                    
                default:
                    break;
                    
            }
            
            break;
            
        case 3:
            
            if (oyuncu->hijyen <= 20) {
                printf("Hijyenin cok dusuk!\n");
                printf("Sarki soyleyemezsin!!\n");
                
                       }
            else {
                
                 kazanc = 10 + (oyuncu->karizma * oyuncu->hijyen);
                
                printf("\n--> Carsinin meydaninda sarki soyledin! Tebrikler!!\n");
                printf("--> Kazandigin para: %d\n",kazanc);
                 oyuncu->para += kazanc;
                
                arti_deger(&oyuncu->moral,30,max_deger);
                printf("+ Moral seviyen 30 puan artti\n");
                
                arti_deger(&oyuncu->sosyal,30,max_deger);
                printf("+ Sosyallik seviyen 30 puan artti\n");
                
                oyuncu->tecrube +=20;
                printf("--> Tecrube seviyen 20 puan artti!\n");
                
                if(oyuncu->tecrube >= 100) {
                    printf("--> Seviye atlamak icin yeterli tecrube puanina ulastin!\n");
                    seviyeAtla(oyuncu);
                }
                
                       }
            break;
            
        case 4:
            printf("\nCarsidan ayriliyorsun.\n");
            printf("Sehrine geri donuyorsun.\n");
            printf("Kendine iyi bak!\n");
            break;
            
        default:
            break;
            
    }
            
    canKontrol(oyuncu);
}

void macera(Karakter *oyuncu) {
    
    int secenek;
    
    printf("---------------------------------------");
    printf("\nMaceraya Hazir Misin %s \n\n",oyuncu->isim);
    printf("\n--> Seceneklerden birini sec:\n\n");
    printf("1.Sifali bitki topla ve ava cik.\n");
    printf("2.Arkadasinla birlikte ormanı kesfe cikin\n");
    printf("3.Kayaliklari kesfe çık\n");
    printf("4.Tekneyle okyanusa acil ve kesfet.\n");
    printf("5.Sehrine geri don\n\n");
    printf("SECIM: ");
    
    secenek = input(1,5);
    
    switch(secenek){
            
        case 1:
            
            srand((unsigned int)time(0));
            
            int sans = oyuncu->toplayicilik * 4;
            int rastgele_sayi = rand() % 100;
            
            printf("\nCevrene goz atiyorsun...\n\n");
            
            if (rastgele_sayi < sans) {
                
                printf("--> Sifali bitki buldunuz!!\n");
                printf("--> Tebrikler\n");
                
                arti_deger(&oyuncu->can,10,max_deger);
                printf("+ Can seviyen 10 puan artti\n");
                
            }
            
            else  {
                rastgele_sayi = rand() % 100;
                if (rastgele_sayi < sans) {
                    
                    printf("--> Meyve buldunuz!!\n");
                    printf("--> Tebrikler!!\n");
                    arti_deger(&oyuncu->tokluk,10,max_deger);
                    printf("+ Tokluk seviyen 10 puan artti\n");
                    
                    arti_deger(&oyuncu->tuvalet,10,max_deger);
                    printf("+ Tuvalet seviyen 10 puan artti\n");
                    
                    arti_deger(&oyuncu->moral,12,max_deger);
                    printf("+ Moral seviyen 12 puan artti\n");
                    
                    eksi_deger(&oyuncu->uyku,10,min_deger);
                    printf("- Uyku seviyen 10 puan azaldi\n");
                }
                else if (rastgele_sayi < sans / 2) {
                    
                    printf("--> Hayvan avladınız!\n");
                    printf("--> Tebrikler!!\n");
                    
                    arti_deger(&oyuncu->tokluk,50,max_deger);
                    printf("+ Tokluk seviyen 50 puan artti\n");
                    
                    arti_deger(&oyuncu->tuvalet,20,max_deger);
                    printf("+ Tuvalet seviyen 20 puan artti\n");
                    
                    arti_deger(&oyuncu->moral,15,max_deger);
                    printf("+ Moral seviyen 15 puan artti\n");
                    
                    arti_deger(&oyuncu->dayaniklilik,10, beceri_maxdeger);
                    printf("+ Dayaniklilik seviyen 5 puan artti\n");
                    
                    arti_deger(&oyuncu->guc,10, beceri_maxdeger);
                    printf("+ Guc seviyen 5 puan artti\n");
                    
                    eksi_deger(&oyuncu->uyku,15,min_deger);
                    printf("- Uyku seviyen 15 puan azaldi\n");
                }
                else {
                    
                    printf("--> Hiçbir şey bulamadınız.\n");
                    
                    eksi_deger(&oyuncu->moral,15,min_deger);
                    printf("- Moral seviyen 15 puan azaldi!!\n");
                    
                    eksi_deger(&oyuncu->tokluk,20,min_deger);
                    printf("- Tokluk seviyen 20 puan azaldi!!\n");
                }
                break;
                
            case 2:
                printf("\n--> Ormanda karsiniza kizil derililer cikti!!!\n");
                srand((unsigned int)time(0));
                
                int kizil_guc= rand() % 3 + 1;
                int kizil_dayaniklilik= rand() % 3 + 1;
                int kizil_ceviklik= rand() % 3 + 1;
                int n;
                
                printf("\nKizil Derililerin Ozellikleri\n");
                printf("Guc:%d\n",kizil_guc);
                printf("Dayaniklilik:%d\n",kizil_dayaniklilik);
                printf("Ceviklik:%d\n",kizil_ceviklik);
                
                printf("\nSavasmak ister misin?\n");
                printf("evet->1 hayir->2\n");
                printf("SECIM: ");
                scanf("%d",&n);
                
                if(n==2) {
                    
                    printf("\nKizil Derililerden kacmaya calisiliyor ---> ");
                    
                    int kacma_sansi = 4 * oyuncu->ceviklik;
                    int random_sans = rand() %100;
                    
                    if (random_sans < kacma_sansi) {
                        printf("Onlari arkanizda biraktiniz ,sizi bulamadi\n");
                        printf("Tebrikler!!\n");
                        
                        arti_deger(&oyuncu->moral,20,max_deger);
                        printf("+ Moral seviyen 15 puan artti\n");
                        
                        eksi_deger(&oyuncu->guc,10,beceri_deger);
                        printf("- Guc seviyen 10 puan azaldi\n");
    
                        
                        break;
                    }
                    
                    else {
                        printf("Eyvah!!! Sizi yakaladilar\n");
                        printf("Artik savasma zamani!!!\n");
                        
                    }
                    
                }
                
                while (oyuncu->can > 0 && kizil_dayaniklilik > 0) {
                    
                    int ilk_saldiri = (oyuncu->ceviklik > kizil_ceviklik) ? 1 : (oyuncu->ceviklik < kizil_ceviklik ? 0 : rand() % 2);
                    
                    if(ilk_saldiri == 1) {
                        
                        printf("\n--> Kizil Derililere saldirdin.\n");
                        
                        int verilen_hasar = oyuncu->guc * 4;
                        int alinan_hasar = verilen_hasar - (verilen_hasar * (4 * kizil_dayaniklilik)/100- 1);
                        
                        printf("Kizil Derililer %d hasar aldi.\n",alinan_hasar);
                        kizil_dayaniklilik -= alinan_hasar;
                        
                    }
                    
                    else {
                        
                        printf("\n--> Kizil derililerin saldirisina ugradin.\n");
                        
                        int verilen_hasar = kizil_guc * 4;
                        int alinan_hasar = verilen_hasar - (verilen_hasar * (4 * oyuncu->dayaniklilik)/100 -1);
                        
                        printf("%d hasar aldin.\n",alinan_hasar);
                        
                        eksi_deger(&oyuncu->can,alinan_hasar,min_deger);
                        printf("- Can seviyen %d puan azaldi!\n",alinan_hasar);
                    }
                    
                    if (oyuncu->can <= 0) {
                        printf("\nYENILDIN!\n\n");
                        
                        eksi_deger(&oyuncu->moral,15,min_deger);
                        printf("- Moral seviyen %d puan azaldi\n",oyuncu->moral);
                        
                        eksi_deger(&oyuncu->tokluk,15,min_deger);
                        printf("- Tokluk seviyen %d puan azaldi\n",oyuncu->tokluk);
                        
                        eksi_deger(&oyuncu->hijyen,20,min_deger);
                        printf("- Hijyen seviyen %d puan azaldi\n",oyuncu->hijyen);
                        
                        eksi_deger(&oyuncu->uyku,15,min_deger);
                        printf("- Uyku seviyen %d puan azaldi\n",oyuncu->tokluk);
                        

                        break;
                    }
                    else if (kizil_dayaniklilik <= 0) {
                        printf("\nYENDIN! TEBRIKLER!!!\n");
                        
                        int ganimet = rand() % 11 + 15;
                        
                        printf("--> Kesif sonucu kazandigin ganimet: %d altın\n\n", ganimet);
                        oyuncu->para += ganimet;
                        
                        arti_deger(&oyuncu->moral,25,max_deger);
                        printf("+ Moral seviyen %d puan artti\n",oyuncu->moral);
                        
                        eksi_deger(&oyuncu->tokluk,15,min_deger);
                        printf("- Tokluk seviyen %d puan azaldi\n",oyuncu->tokluk);
                        
                        eksi_deger(&oyuncu->hijyen,20,min_deger);
                        printf("- Hijyen seviyen %d puan azaldi\n",oyuncu->hijyen);
                        
                        eksi_deger(&oyuncu->uyku,15,min_deger);
                        printf("- Uyku seviyen %d puan azaldi\n",oyuncu->tokluk);
                        
                        break;
                        
                    }
                }
                
                oyuncu->tecrube +=30;
                printf("\n--> Tecrube puanin 30 artti\n\n");
                
                if(oyuncu->tecrube >= 100) {
                    printf("--> Seviye atlamak icin yeterli tecrube puanina ulastin!!\n");
                    seviyeAtla(oyuncu);
                }
                
                break;
                
            case 3:
                
                printf("\n--> Kayaliklarda karsiniza kimsesiz biri cikti!\n");
                srand((unsigned int)time(0));
                
                int kimsesiz_guc= rand() % 3 + 4;
                int kimsesiz_dayaniklilik= rand() % 3+ 4;
                int kimsesiz_ceviklik= rand() % 3 + 4;
                int s;
                
                printf("\nKimsesizin Ozellikleri\n");
                printf("Guc:%d\n",kimsesiz_guc);
                printf("Dayaniklilik:%d\n",kimsesiz_dayaniklilik);
                printf("Ceviklik:%d\n",kimsesiz_ceviklik);
                
                printf("\nSavasmak ister misin?\n");
                printf("evet->1 hayir->2\n");
                printf("SECIM: ");
                scanf("%d",&s);
                
                if(s==2) {
                    
                    printf("\nKimsesizden kacmaya calisiliyor ----> ");
                    
                    int kacma_sansi = 4 * oyuncu->ceviklik;
                    int random_sans = rand() %100;
                    
                    if (random_sans < kacma_sansi) {
                        printf("Kimsesizi arkanizda biraktiniz ,sizi bulamadi\n");
                        printf("Tebrikler!!\n");
                        break;
                    }
                    
                    else {
                        printf("Eyvah!! Sizi yakaladi\n");
                        printf("Artik savasma zamani!!\n");
                        
                    }
                    
                }
                
                while (oyuncu->can > 0 && kimsesiz_dayaniklilik > 0) {
                    
                    int ilk_saldiri = (oyuncu->ceviklik > kimsesiz_ceviklik) ? 1 : (oyuncu->ceviklik < kimsesiz_ceviklik ? 0 : rand() % 2);
                    
                    if(ilk_saldiri == 1) {
                        
                        printf("--> Kimsesize saldirdin.\n");
                        
                        int verilen_hasar = oyuncu->guc * 4;
                        int alinan_hasar = verilen_hasar - (verilen_hasar * (4 * kimsesiz_dayaniklilik)/100 -1);
                        
                        printf("Kimsesiz %d hasar aldi.\n",alinan_hasar);
                        kimsesiz_dayaniklilik -= alinan_hasar;
                        
                    }
                    
                    else {
                        
                        printf("--> Kimsesizin saldirisina ugradin.\n");
                        
                        int verilen_hasar = kimsesiz_guc * 4;
                        int alinan_hasar = verilen_hasar - (verilen_hasar * (4 * oyuncu->dayaniklilik)/100 -1);
                        
                        printf("%d hasar aldin.\n",alinan_hasar);
                        
                        eksi_deger(&oyuncu->can,alinan_hasar,min_deger);
                        printf("- Can seviyen %d puan azaldi!!\n",alinan_hasar);
                        
                    }
                    
                    if (oyuncu->can <= 0) {
                        printf("\nYENILDIN!\n\n");
                        
                        eksi_deger(&oyuncu->moral,15,min_deger);
                        printf("- Moral seviyen %d puan azaldi\n",oyuncu->moral);
                        
                        eksi_deger(&oyuncu->tokluk,15,min_deger);
                        printf("- Tokluk seviyen %d puan azaldi\n",oyuncu->tokluk);
                        
                        eksi_deger(&oyuncu->hijyen,20,min_deger);
                        printf("- Hijyen seviyen %d puan azaldi\n",oyuncu->hijyen);
                        
                        eksi_deger(&oyuncu->uyku,15,min_deger);
                        printf("- Uyku seviyen %d puan azaldi\n",oyuncu->tokluk);
                        
                        break;
                    }
                    else if (kimsesiz_dayaniklilik <= 0) {
                        printf("\nYENDIN! TEBRIKLER!!!\n");
                        
                        int ganimet = rand() % 21 + 30;
                        
                        
                        printf("--> Kesif sonucu kazandigin ganimet: %d altın\n\n", ganimet);
                        oyuncu->para += ganimet;
                        
                        arti_deger(&oyuncu->moral,25,max_deger);
                        printf("+ Moral seviyen %d puan artti\n",oyuncu->moral);
                        
                        eksi_deger(&oyuncu->tokluk,15,min_deger);
                        printf("- Tokluk seviyen %d puan azaldi\n",oyuncu->tokluk);
                        
                        eksi_deger(&oyuncu->hijyen,20,min_deger);
                        printf("- Hijyen seviyen %d puan azaldi\n",oyuncu->hijyen);
                        
                        eksi_deger(&oyuncu->uyku,15,min_deger);
                        printf("- Uyku seviyen %d puan azaldi\n",oyuncu->tokluk);
                        
                        break;
                        
                    }
                }
                
                oyuncu->tecrube +=60;
                printf("\n--> Tecrube puanin 60 artti!\n");
                
                if(oyuncu->tecrube >= 100) {
                    printf("--> Seviye atlamak icin yeterli tecrube puanina ulastin!!\n");
                    seviyeAtla(oyuncu);
                }
                
            }
            
            break;
            
                
            case 4:
                
                printf("\n--> Okyanusun ortasinda karsina korsan cikti!!!\n");
                srand((unsigned int)time(0));
                
                int korsan_guc= rand() % 4 + 7 ;
                int korsan_dayaniklilik= rand() % 3 + 1;
                int korsan_ceviklik= rand() % 3 + 1;
                int t;
                
                printf("\nKorsan Ozellikleri\n");
                printf("Guc:%d\n",korsan_guc);
                printf("Dayaniklilik:%d\n",korsan_dayaniklilik);
                printf("Ceviklik:%d\n",korsan_ceviklik);
                
                printf("\nSavasmak ister misin?\n");
                printf("evet->1 hayir->2\n");
                printf("SECIM: ");
                scanf("%d",&t);
                
                if(t==2) {
                    
                    printf("\nKorsandan kacmaya calisiliyor ----> ");
                    
                    int kacma_sansi = 4 * oyuncu->ceviklik;
                    int random_sans = rand() %100;
                    
                    if (random_sans < kacma_sansi) {
                        printf("Korsani arkanizda biraktiniz ,sizi bulamadi\n");
                        printf("Tebrikler!!\n");
                        break;
                    }
                    
                    else {
                        printf("Eyvah!!Sizi yakaladilar\n");
                        printf("Artik savasma zamani!!!\n");
                        
                    }
                    
                }
                
                while (oyuncu->can > 0 && korsan_dayaniklilik > 0) {
                    
                    int ilk_saldiri = (oyuncu->ceviklik > korsan_ceviklik) ? 1 : (oyuncu->ceviklik < korsan_ceviklik ? 0 : rand() % 2);
                    
                    if(ilk_saldiri == 1) {
                        
                        printf("\n--> Korsana saldirdin.\n");
                        
                        int verilen_hasar = oyuncu->guc * 4;
                        int alinan_hasar = verilen_hasar - (verilen_hasar * (4 * korsan_dayaniklilik)/100 -1);
                        
                        printf("Korsan %d hasar aldi.\n",alinan_hasar);
                        korsan_dayaniklilik -= alinan_hasar;
                        
                    }
                    
                    else {
                        
                        printf("\n--> Korsanin saldirisina ugradin.\n");
                        
                        int verilen_hasar = korsan_guc * 4;
                        int alinan_hasar = verilen_hasar - (verilen_hasar * (4 * oyuncu->dayaniklilik)/100 -1);
                        
                        printf("%d hasar aldin.\n",alinan_hasar);
                        
                        eksi_deger(&oyuncu->can,alinan_hasar,min_deger);
                        printf("- Can seviyen %d puan azaldi!\n",alinan_hasar);
                        
                    }
                    
                    if (oyuncu->can <= 0) {
                        printf("\nYENILDIN!\n");
                        
                        eksi_deger(&oyuncu->moral,30,min_deger);
                        printf("- Moral seviyen %d puan azaldi\n",oyuncu->moral);
                        
                        break;
                    }
                    else if (korsan_dayaniklilik <= 0) {
                        printf("\nYENDIN TEBRIKLER!!!\n");
                        
                        int ganimet = rand() % 21 + 55 ;
                        
                        printf("--> Kesif sonucu kazandigin ganimet: %d altin\n\n", ganimet);
                        oyuncu->para += ganimet;
                        
                        arti_deger(&oyuncu->moral,30,max_deger);
                        printf("+ Moral seviyen %d puan artti\n",oyuncu->moral);
                        
                        eksi_deger(&oyuncu->tokluk,20,min_deger);
                        printf("- Tokluk seviyen %d puan azaldi\n",oyuncu->tokluk);
                        
                        eksi_deger(&oyuncu->hijyen,20,min_deger);
                        printf("- Hijyen seviyen %d puan azaldi\n",oyuncu->hijyen);
                        
                        eksi_deger(&oyuncu->uyku,15,min_deger);
                        printf("- Uyku seviyen %d puan azaldi\n",oyuncu->tokluk);
    
                        break;
                        
                    }
                }
                
                oyuncu->tecrube +=90;
                printf("\n--> Tecrube puanin 90 artti\n");
                
                if(oyuncu->tecrube >= 100) {
                    printf("\n--> Seviye atlamak icin yeterli tecrube puanina ulastin!\n");
                    seviyeAtla(oyuncu);
                }
                
                break;
                
            case 5:
                
                printf("\n--> Sehrine geri donuyorsun.\n");
                printf("--> Kendine iyi bak!!\n");
                break;
                
            default:
                break;
                
            }
    canKontrol(oyuncu);
    }
    
    
    void seviyeAtla(Karakter *oyuncu) {
        
        if(oyuncu->tecrube < 100) {
            printf("\n--> Seviye atlamak icin yeterli tecrube puanina ulasmadin!\n");
        }
        else {
            printf("\nTebrikler 1 Seviye Atladin!!\n");
            printf("Yeni seviyen:%d\n",oyuncu->seviye +1 );
            oyuncu->seviye +=1;
            oyuncu->tecrube =0;
            
            printf("\nSeviye atladigin icin 5 Beceri Puani Verildi!\n");
            printf("UYARI: Bu puani becerilerine istedigin sekilde dagitabilirsin.\n");
            beceri(oyuncu);
            
        }
    
    }

void durumGoster(Karakter *oyuncu) {
    printf("\n----GENEL DURUM----\n");
    printf("Karakter Durumu\n");
    printf("Isim: %s\n", oyuncu->isim);
    printf("Enstruman: %s\n", oyuncu->ensturman);
    printf("-------TEMEL NITELIKLER------\n");
    printf("Can: %d\nTokluk: %d\nUyku: %d\nHijyen: %d\nMoral: %d\nTuvalet: %d\nSosyallik: %d\n", oyuncu->can, oyuncu->tokluk, oyuncu->uyku, oyuncu->hijyen, oyuncu->moral,oyuncu->tuvalet,oyuncu->sosyal);
    printf("-------BECERILER-------\n");
    printf("Guc: %d\nCeviklik: %d\nDayaniklilik: %d\nKarizma: %d\nToplayicilik: %d\n", oyuncu->guc, oyuncu->ceviklik, oyuncu->dayaniklilik, oyuncu->karizma, oyuncu->toplayicilik);
    printf("------------------------------\n");
    printf("Para: %d\n", oyuncu->para);
    printf("Seviye: %d\nTecrube: %d\n",oyuncu->seviye,oyuncu->tecrube);
}
    
    int input(int min, int max) {
        int secenek;
        while (1) {
            if (scanf("%d", &secenek) == 1 && secenek >= min && secenek <= max) {
                return secenek;
            } else {
                printf("Gecersiz Giris! Tekrar Dene!\n");
                printf("--> ");
                while (getchar() != '\n');
            }
        }
    }
    
   void arti_deger(int *ozellik, int miktar, int max) {
    *ozellik += miktar;
    if (*ozellik > max) *ozellik = max;
    if (*ozellik < min_deger) *ozellik = min_deger;
}

   void eksi_deger(int *ozellik, int miktar, int min) {
    
    *ozellik -= miktar;
    
    if (*ozellik < min) {
        
        *ozellik = min;
    }
    if (*ozellik > max_deger) {
        
        *ozellik = max_deger;
    }
 }
 
void beceri(Karakter *oyuncu) {
    int secenek;
    int puan_durumu = 0;
    int puan = 5;
    
    printf("\nBecerilerini gelistirmen icin 5 puan hediye verildi.\n");
    
    while (puan_durumu < 5) {
        printf("Guncel Puan: %d\n",(puan-puan_durumu));
        printf("Beceri Sec:\n");
        printf("1.Guc\n");
        printf("2.Ceviklik\n");
        printf("3.Dayaniklilik\n");
        printf("4.Karizma\n");
        printf("5. Iptal et ve menüye geri don\n");
        printf("SECIM: ");
        
        secenek = input(1, 5);
        
        switch (secenek) {
            case 1:
                if (puan_durumu < 5) {
                    printf("--> Gücün 1 artti.\n");
                    arti_deger(&oyuncu->guc, 1, beceri_maxdeger);
                    puan_durumu++;
                } else {
                    printf("Puanlarin bitti!\n");
                }
                break;
            case 2:
                if (puan_durumu < 5) {
                    printf("--> Ceviklik 1 artti.\n");
                    arti_deger(&oyuncu->ceviklik, 1, beceri_maxdeger);
                    puan_durumu++;
                } else {
                    printf("Puanlarin bitti!\n");
                }
                break;
            case 3:
                if (puan_durumu < 5) {
                    printf("--> Dayaniklilik 1 artti.\n");
                    arti_deger(&oyuncu->dayaniklilik, 1, beceri_maxdeger);
                    puan_durumu++;
                } else {
                    printf("Puanlarin bitti!\n");
                }
                break;
            case 4:
                if (puan_durumu < 5) {
                    printf("--> Karizma 1 artti.\n");
                    arti_deger(&oyuncu->karizma, 1, beceri_maxdeger);
                    puan_durumu++;
                } else {
                    printf("Puanlarin bitti!\n");
                }
                break;
            case 5:
                printf("---> Menüye geri donuluyor.\n");
                return;
                break;
                
            default:
                printf("Gecersiz giris!!\n");
                break;
        }
        
        if (puan_durumu == 5) {
                printf("--> Bütün puanlari kullandin.\n");
                printf("--> Becerilerini gelistirdin.\n");
                }
        
    }

        printf("---> Ana menuye donuluyor\n");
        menuGoster(oyuncu);
    }
