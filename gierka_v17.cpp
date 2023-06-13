#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <unistd.h>
#include <conio.h>

int level = 1;
int check = 0;
float pktnalvl = 0.1;

struct postac {
    std::string nazwa;
    int sila;
    int magia;
    int intelekt;
    int obrona;
    int zycie;
};

postac ja;
postac pr;

void tnull(); // do losowania
void delaj(int czas); // zakres 0..100 sekundy
void cs(); // clear screen
void delajcs(int czas); // zakres 0..100 sekundy
void wstep();
std::string imie();
void statyprzeciwnika();
void mojestaty(int level);
float wybor();
float ruchpr();
void schematwalki(float ruch);
int walka();
void levl();

int main() {
    char xd = 't';
    imie();
    wstep();
    while (xd == 't') {
        if (check != level)
            mojestaty(level);

        statyprzeciwnika();
        walka();
        if (walka() == 1) {
            std::cout << "\n\nGratuluje wygranej grasz na trudniejszego przeciwnika?? \tWybierz t/n: ";
            std::cin >> xd;
        }
        else {
            std::cout << "\n\tPrzegrales\n";
            xd = 'n';
        }
    }
    return 0;
}

void tnull() {
    int los, zarodek;
    zarodek = time(NULL);
    srand(zarodek);
}

void delaj(int czas) {
    sleep(czas);
}

void cs() {
    cls;
}

void delajcs(int czas) {
    fflush(stdout);
    delaj(czas);
    cs();
}

void wstep() {
    ja.zycie = 50;
    ja.sila = 10;
    ja.magia = 10;
    ja.intelekt = 10;
    ja.obrona = 10;
    std::cout << "\n\t Witaj w tej gierce";
    delajcs(3);
}

std::string imie() {
    std::string zm_nazwa;
    std::cout << "\nJakie jest twoje imie:??\t";
    std::cin >> zm_nazwa;
    ja.nazwa = zm_nazwa;
    std::cout << ja.nazwa;

    return zm_nazwa;
}

void statyprzeciwnika() {
    int tab[5] = { pr.zycie = 40, pr.sila = 5, pr.magia = 5, pr.intelekt = 5, pr.obrona = 5 };
    int i, sttrud = 18 + (3 * level);
    tnull();
    while (sttrud != 0) {
        tab[rand() % 5]++;
        sttrud--;
    }
    pr.zycie = tab[0];
    pr.sila = tab[1];
    pr.magia = tab[2];
    pr.intelekt = tab[3];
    pr.obrona = tab[4];
}

void mojestaty(int level) {
    int a;
    int tab[5] = { ja.zycie, ja.sila, ja.magia, ja.intelekt, ja.obrona };
    if (check != level) {
        check = level;
        a = 5;
        std::cout << "\nAle najpierw przyjrzyjmy sie twojej postaci";
        fflush(stdout);
        delaj(2);
        while (a != 0) {
            int q;
            delajcs(0);
            std::cout << "Masz jeszcze " << a << " pkt do wydania";
            std::cout << "\nTwoje staty to:\n\n 1. zycie --> " << ja.zycie << "\n 2. sila --> " << ja.sila << "\n 3. magia --> " << ja.magia;
            std::cout << "\n 4. intelekt --> " << ja.intelekt << "\n 5. obrona --> " << ja.obrona << "\n";
            std::cout << "Wybierz nr 1/2/3/4/5 w zale¿nosci w co chcesz zainwestowac \n\t";
                    std::cin >> q;
            switch (q) {
            case 1:
                ja.zycie++;
                break;
            case 2:

                ja.sila++;
                break;
            case 3:
                ja.magia++;
                break;
            case 4:
                ja.intelekt++;
                break;
            case 5:
                ja.obrona++;
                break;
            default:
                std::cout << "\nPoza wart no i straciles pkt";
                fflush(stdout);
                delaj(3);
                break;
            }
            a--;
        }
    }
}

float wybor() {
    int ruch;
    std::cout << "\n\n 1.Atak wrecz\t 2.Atak magiczny\t 3.Atak intelektualny\t 4.Potka na zdrowie +10proc hp";
    std::cout << "\nWybierz twoj ruch 1/2/3/4: ";
    std::cin >> ruch;
    if (ruch != 1 && ruch != 2 && ruch != 3 && ruch != 4)
        ruch = 5;
    return (ruch + 0.05);
}

float ruchpr() {
    int x, ruch;
    tnull();
    x = rand() % 46;
    if (x < 15)
        ruch = 1;
    else if (x > 14 && x < 25)
        ruch = 2;
    else if (x > 24 && x < 35)
        ruch = 3;
    else if (x > 34 && x < 44)
        ruch = 4;
    else
        ruch = 5;
    return ruch;
}

void schematwalki(float ruch) {
    int d, r, x, crit = 1;
    float zycie, sila, obrona, magia, intelekt, life;
    if (ruch != 1 && ruch != 2 && ruch != 3 && ruch != 4 && ruch != 5) {
        zycie = pr.zycie;
        sila = ja.sila;
        obrona = pr.obrona;
        magia = ja.magia;
        intelekt = ja.intelekt;
        life = ja.zycie;
        ruch = round(ruch);
        d = 1;
    }
    else {
        zycie = ja.zycie;
        sila = pr.sila;
        obrona = ja.obrona;
        magia = pr.magia;
        intelekt = pr.intelekt;
        life = pr.zycie;
        d = 2;
    }
    tnull();
    x = rand() % 10;
    if (x > 8)
        ruch = 5;
    else if (x < 3 && ruch != 5)
        crit = 2;

    r = ruch;
    switch (r) {
    case 1:
        x = abs(crit * ((obrona * 2) - (sila * 3)));
        zycie = zycie + crit * ((obrona * 2) - (sila * 3));
        if (d == 2)
            std::cout << "\n\tPrzeciwnik wykonal atak i zadal " << x << " obrazen";
        else
            std::cout << "\n\tZadales cios na " << x << " obrazen";
        break;
    case 2:
        x = abs(crit * (-floor(magia / 2) + floor(obrona / 9)));
        zycie = zycie + crit * (-floor(magia / 2) + floor(obrona / 9));
        if (d == 2)
            std::cout << "\n\tOtrzymales magiczny cios na " << x << " obrazen";
        else
            std::cout << "\n\tZadales magiczny cios na " << x << " obrazen";
        break;
    case 3:
        x = abs(crit * (ceil(intelekt / (2.1))));
        zycie = zycie - crit * (ceil(intelekt / (2.1)));
        if (d == 2)
            std::cout << "\n\tZostales zbesztany na " << x << " obrazen";
        else
            std::cout << "\n\tZbesztales go na " << x << " obrazen";
        break;
    case 4:
        x = crit * (ceil(life / 10));
        life = life + crit * (ceil(life / 10));
        if (d == 2)
            std::cout << "\n\tPrzeciwnik pije potke na " << x << " zdrowia";
        else
            std::cout << "\n\tPijesz potke na " << x << " zdrowia";
        break;
    case 5:
        if (d == 2)
            std::cout << "\n\tPrzeciwnik nie trafia";
        else
            std::cout << "\n\tNie trafiasz";
        break;
    }
    fflush(stdout);
    delaj(2);
    if (d == 1) {
        pr.zycie = zycie;
        ja.zycie = life;
    }
    else {
        ja.zycie = zycie;
        pr.zycie = life;
    }
}

int walka() {
    int x = 0;
    while (ja.zycie > 0 && pr.zycie > 0) {
        delajcs(1);
        std::cout << "\n\tMoje zycie " << ja.zycie << "\t\t Zycie przeciwnika " << pr.zycie;
        schematwalki(wybor());
        if (pr.zycie <= 0) {
            x = 1;
            break;
        }
        else if (ja.zycie <= 0)
            break;

        delajcs(2);
        std::cout << "\n\tMoje zycie " << ja.zycie << "\t\t Zycie przeciwnika " << pr.zycie;
        schematwalki(ruchpr());
    }
    return x;
}

void levl() {
    level++;
    ja.zycie = 50;
    ja.sila = ja.sila + (int)ceil((float)level * pktnalvl);
    ja.magia = ja.magia + (int)ceil((float)level * pktnalvl);
    ja.intelekt = ja.intelekt + (int)ceil((float)level * pktnalvl);
    ja.obrona = ja.obrona + (int)ceil((float)level * pktnalvl);
}
