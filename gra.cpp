#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

class Character {
private:
    string name;
    int strength;
    int speed;
    int agility;
    int level;
    int experience;
public:
    Character(const string& characterName, int characterStrength, int characterSpeed, int characterAgility,int characterExperience,int characterLevel)
        : name(characterName), strength(characterStrength), speed(characterSpeed), agility(characterAgility), level(characterLevel), experience(characterExperience)
    {}

    void createCharacter() {
        int points=20+level;
        level=1;
            cout << "Witaj w grze! \nNa poczatek wybierz nazwe swojej postaci:\n\n";
            cin >> name;
            cout << "Witaj " << name << " przyjrzyjmy sie twojej postaci!\n\n";

            while (points != 0) {
                int wybor;
                cout << "Masz jeszcze " << points << " pkt do wydania\n";
                cout << "Twoje statystyki to:\n\n[1] Sila --> " << strength << "\n[2] Szybkosc --> " << speed << "\n[3] Wytrzymalosc --> " << agility << "\nTwoj poziom postaci --> "<<level<< "\nTwoje punkty doswiadczenia --> "<<experience<<endl << endl;
                cout << "Wybierz [1/2/3] w ktora umiejetnosc chcialbys zainwestowac swoje punkty!\n";
                cin >> wybor;
                switch (wybor) {
                case 1:
                    strength++;
                    break;
                case 2:
                    speed++;
                    break;
                case 3:
                    agility++;
                    break;
                default:
                    cout << "Zly wybor! Straciles punkty! \n";
                    break;
                }
                points--;
            }

    }

    string getName() const {
        return name;
    }

    int getStrength() const {
        return strength;
    }

    int getSpeed() const {
        return speed;
    }

    int getAgility() const {
        return agility;
    }
    int getExperience() const {
        return experience;
    }
    int getLevel() const {
        return level;
    }
};

Character generateEnemy(string enemyName) {
    srand(time(0)); // Inicjalizacja ziarna losowości na podstawie bieżącego czasu
    int enemyLevel = rand() % 10 + 1;
    int enemyStrength = rand() % (10+enemyLevel) + (1+enemyLevel);   // Losowa siła między 1 a 10
    int enemySpeed = rand() % (10+enemyLevel) + (1+enemyLevel);       // Losowa szybkość między 1 a 10
    int enemyAgility = rand() % (10+enemyLevel) + (1+enemyLevel);     // Losowa zwinność między 1 a 10
    int enemyExperience=0;
    return Character(enemyName, enemyStrength, enemySpeed, enemyAgility, enemyLevel, enemyExperience);
}

void fight(const Character& player, const Character& enemy) {

    cout << "\nRozpoczyna się pojedynek!\n\n";
    cout << "Gracz: " << player.getName() << " vs. Przeciwnik: " << enemy.getName() << endl;
    int playerScore = player.getStrength() + player.getSpeed() + player.getAgility();
    int enemyScore = enemy.getStrength() + enemy.getSpeed() + enemy.getAgility();

cout<<"Punkty gracza "<<player.getName()<<": "<<playerScore<<endl;
cout<<"Punkty przeciwnika "<<enemy.getName()<<": "<<enemyScore<<endl;

if (playerScore > enemyScore) {
        cout << "Gracz wygrał pojedynek! Gratulacje!\n";
        int playerExperience=playerExperience+enemyScore*10;
        cout<< "Zdobyles "<<playerExperience<<" punktow doswiadczenia!"<<endl;
    } else if (playerScore < enemyScore) {
        cout << "Przeciwnik wygrał pojedynek. Niestety, przegrałeś.\n";
        int playerExperience=playerExperience-enemyScore*5;
        cout<< "Straciles "<<playerExperience<<" punktow doswiadczenia!"<<endl;
    } else {
        cout << "Remis! Nikt nie wygrał pojedynku.\n";
    }
}

int main() {
    Character myCharacter("",0,0,0,0,0);


    myCharacter.createCharacter();

    // Wyświetlenie informacji o stworzonej postaci

    cout << "Stworzona postać:" << endl;
    cout << "Nazwa: " << myCharacter.getName() << endl;
    cout << "Siła: " << myCharacter.getStrength() << endl;
    cout << "Szybkość: " << myCharacter.getSpeed() << endl;
    cout << "Zwinność: " << myCharacter.getAgility() << endl;
    cout << "Poziom postaci: " << myCharacter.getLevel() << endl;
    cout << "Poziom doswiadczenia: " << myCharacter.getExperience() << endl;

// Wygenerowanie losowego przeciwnika
Character enemy = generateEnemy("Goblin");

// Wyświetlenie informacji o przeciwniku
cout << "\nWygenerowany przeciwnik:" << endl;
cout << "Nazwa: " << enemy.getName() << endl;
cout << "Siła: " << enemy.getStrength() << endl;
cout << "Szybkość: " << enemy.getSpeed() << endl;
cout << "Zwinność: " << enemy.getAgility() << endl;
cout << "Poziom wroga: " << enemy.getLevel() << endl;

fight(myCharacter, enemy);
return 0;
}