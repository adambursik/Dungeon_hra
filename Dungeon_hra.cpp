#include <iostream>
#include <ctime>
#include <iomanip>
#include <conio.h>

using namespace std;
struct Hrac{
string jmeno="nic";
int zlato=50;
int akt_hp=0;
int max_hp=0;
int max_dmg=0;
int akt_mn=0;
int max_mn=0;
int lvl;
    int akt_xp;
    int max_xp;
};
Hrac hrac;
double nasobkySchopnosti[4][3] = {
    {0.75, 1.5, 3.125}, 
    {0.9, 0.6, 6.0},  
    {0.6, 0.4, 4.0}, 
    {0.71, 1.07, 2.57} 
};


struct Monstrum {
    int id;
    string jmeno;
    int hp;
    int dmg;
    int zlato;
    int dmg2;
    int xp_drop;
};

Monstrum seznamMonster[18] = {
    {1, "Goblin Scout", 40, 10, 20, 0, 15},
    {2, "Goblin Warrior", 60, 15, 35, 0, 25},
    {3, "Goblin Archer", 45, 12, 30, 0, 20},
    {4, "Goblin Merchant", 30, 2, 250, 0, 10},
    {5, "Skeleton Pawn", 50, 12, 15, 0, 20},
    {6, "Skeleton Warrior", 70, 18, 40, 0, 30},
    {7, "Skeleton Archer", 55, 15, 30, 0, 25},
    {8, "Zombie", 90, 8, 20, 0, 30},
    {9, "Giant Rat", 35, 10, 10, 0, 12},
    {10, "Cave Spider", 50, 14, 10, 0, 22},
    {11, "Vampire Bat", 30, 12, 10, 0, 15},
    {12, "Werewolf", 65, 20, 10, 0, 35},
    {13, "Orc Scout", 70, 15, 50, 0, 40},
    {14, "Orc Warrior", 110, 25, 100, 0, 60},
    {15, "Goblin Miner", 60, 14, 75, 0, 35},
    {16, "Slime", 40, 8, 10, 0, 10},
    {17, "Drak (Miniboss)", 250, 30, 200, 20, 200},
    {18, "Temny Rytir (Miniboss)", 240, 32, 190, 22, 180}
};

struct ManaCost {
    int id;
    int basic;
    int ability;
    int super;
};

ManaCost seznamMANY[4] = {
    {1, 10, 40, 150},
    {2, 0, 30, 80},
    {3, 0, 50, 120},
    {4, 0, 45, 130}
};

void Statistiky(Hrac hrac) {
    system("cls");
    cout << "=====================================================================\n";
    cout << " HRDINA: " << setw(12) << left << hrac.jmeno
         << " ZLATO: " << hrac.zlato << " G\n";
    cout << " ZIVOTY: " << hrac.akt_hp << "/" << hrac.max_hp 
         << "   |   MANA: " << hrac.akt_mn << "/" << hrac.max_mn 
         << "   |   DMG: " << hrac.max_dmg << "\n";
    cout << "=====================================================================\n\n";
}
void boj_monstra(int hrdina){
int vyberAtck;
int protivnik_monstrum = rand ()%17;
do{
do{
Statistiky(hrac);
cout << "   =========================================\n";
cout << "     POTKAL JSI: " << seznamMonster[protivnik_monstrum].jmeno << "\n";
cout << "     HP: " << seznamMonster[protivnik_monstrum].hp << " | DMG: " << seznamMonster[protivnik_monstrum].dmg << "\n";
cout << "   =========================================\n\n";

cout << "   [1] BASIC UTOK  ( "<<hrac.max_dmg * nasobkySchopnosti[hrdina][0]<<" DMG, -"<<seznamMANY[hrdina].basic<<" MN)\n";
cout << "   [2] ABILITKU  ( "<<hrac.max_dmg * nasobkySchopnosti[hrdina][1]<<" DMG, -"<<seznamMANY[hrdina].ability<<" MN)\n";
cout << "   [3] SUPER ABILITKA  ( "<<hrac.max_dmg * nasobkySchopnosti[hrdina][2]<<" DMG, -"<<seznamMANY[hrdina].super<<" MN)\n";
cout << "   Volba: ";
cin >> vyberAtck;

switch (vyberAtck)
{
case 1:
    if (hrac.akt_mn >= seznamMANY[hrdina].basic) {
        int udelenoDmg = hrac.max_dmg * nasobkySchopnosti[hrdina][0];
        seznamMonster[protivnik_monstrum].hp -= udelenoDmg;
        hrac.akt_mn -= seznamMANY[hrdina].basic;
        
        Statistiky(hrac);
        cout << "   =========================================\n";
        cout << "               >> TVUJ TAH <<               \n";
        cout << "   =========================================\n";
        cout << "    Pouzil jsi Basic utok!\n";
        cout << "    Zasahl jsi " << seznamMonster[protivnik_monstrum].jmeno << " za " << udelenoDmg << " DMG.\n";
        cout << "   -----------------------------------------\n";
        if (seznamMonster[protivnik_monstrum].hp < 0) seznamMonster[protivnik_monstrum].hp = 0;
        cout << "    Zbyvajici HP monstra: " << seznamMonster[protivnik_monstrum].hp << "\n";
        cout << "   =========================================\n\n";
    } else {
        cout << "Nemas dostatek many pro tento utok!\n";
    }break;
    case 2:
    if (hrac.akt_mn >= seznamMANY[hrdina].ability) {
        int udelenoDmg = hrac.max_dmg * nasobkySchopnosti[hrdina][1];
        seznamMonster[protivnik_monstrum].hp -= udelenoDmg;
        hrac.akt_mn -= seznamMANY[hrdina].ability;
        
        Statistiky(hrac);
        cout << "   =========================================\n";
        cout << "               >> TVUJ TAH <<               \n";
        cout << "   =========================================\n";
        cout << "    Pouzil jsi Abilitku!\n";
        cout << "    Zasahl jsi " << seznamMonster[protivnik_monstrum].jmeno << " za " << udelenoDmg << " DMG.\n";
        cout << "   -----------------------------------------\n";
        if (seznamMonster[protivnik_monstrum].hp < 0) seznamMonster[protivnik_monstrum].hp = 0;
        cout << "    Zbyvajici HP monstra: " << seznamMonster[protivnik_monstrum].hp << "\n";
        cout << "   =========================================\n\n";
    } else {
        cout << "Nemas dostatek many pro tento utok!\n";}
    break;
case 3:
    if (hrac.akt_mn >= seznamMANY[hrdina].super) {
        int udelenoDmg = hrac.max_dmg * nasobkySchopnosti[hrdina][2];
        seznamMonster[protivnik_monstrum].hp -= udelenoDmg;
        hrac.akt_mn -= seznamMANY[hrdina].super;
        
        Statistiky(hrac);
        cout << "   =========================================\n";
        cout << "               >> TVUJ TAH <<               \n";
        cout << "   =========================================\n";
        cout << "    Pouzil jsi Super abilitku!\n";
        cout << "    Zasahl jsi " << seznamMonster[protivnik_monstrum].jmeno << " za " << udelenoDmg << " DMG.\n";
        cout << "   -----------------------------------------\n";
        if (seznamMonster[protivnik_monstrum].hp < 0) seznamMonster[protivnik_monstrum].hp = 0;
        cout << "    Zbyvajici HP monstra: " << seznamMonster[protivnik_monstrum].hp << "\n";
        cout << "   =========================================\n\n";
    } else {
        cout << "Nemas dostatek many pro tento utok!\n";}
        break;
default:
cout<<"BLBE ZADANE CISLO!!";
    break;}

cout << "   Stiskni Enter pro kolo monstra...";
_getch();
    }while(vyberAtck<=0||vyberAtck>=4);
Statistiky(hrac);
if (seznamMonster[protivnik_monstrum].hp <= 0) {
    break;
}
int monstrumsila = (rand() % 3) + 1;
int monstrumDmg = 0;
switch (monstrumsila)
{
case 1:
    monstrumDmg = (seznamMonster[protivnik_monstrum].dmg*0.75);
    break;
case 2:
    monstrumDmg = seznamMonster[protivnik_monstrum].dmg;
    break;
case 3:
    monstrumDmg = (seznamMonster[protivnik_monstrum].dmg*1.25);
    break;

default:cout<<"NEFAKAJI MONSTRA!!!!";
    break;
}

hrac.akt_hp -= monstrumDmg;
cout << "   =========================================\n";
cout << "             >> TAH MONSTRA <<              \n";
cout << "   =========================================\n";
cout << "    " << seznamMonster[protivnik_monstrum].jmeno << " zveda svou zbran!\n";
cout << "    Zasahl te za " << monstrumDmg << " DMG.\n";
cout << "   -----------------------------------------\n";
if (hrac.akt_hp < 0) hrac.akt_hp = 0;
cout << "    Tvoje zbyvajici HP: " << hrac.akt_hp << "/" << hrac.max_hp << "\n";
cout << "   =========================================\n\n";

cout << "   Stiskni Enter pro dalsi kolo...";
_getch();

}while (hrac.akt_hp>0 && seznamMonster[protivnik_monstrum].hp>0);
system("cls");
    if (hrac.akt_hp <= 0) {
        cout << "=========================================\n";
        cout << "            Konec hry: ZEMREL JSI!       \n";
        cout << "=========================================\n";
    } 
    else if (seznamMonster[protivnik_monstrum].hp <= 0) {
        Statistiky(hrac);
        cout << "=========================================\n";
        cout << "            NEPRITEL PORAZEN!            \n";
        cout << "=========================================\n";
        
        hrac.akt_xp += seznamMonster[protivnik_monstrum].xp_drop;
        hrac.zlato += seznamMonster[protivnik_monstrum].zlato;
        
        cout << " Ziskal jsi: " << seznamMonster[protivnik_monstrum].xp_drop << " XP\n";
        cout << " Ziskal jsi: " << seznamMonster[protivnik_monstrum].zlato << " G\n";
        cout << "=========================================\n";

        if (hrac.akt_xp >= hrac.max_xp) {
            hrac.lvl++;
            hrac.akt_xp -= hrac.max_xp;
            hrac.max_xp = hrac.max_xp * 1.5; 
            hrac.max_hp += 15;
            hrac.max_mn += 10;
            hrac.max_dmg += 5;
            hrac.akt_hp = hrac.max_hp;
            hrac.akt_mn = hrac.max_mn;
            
            cout << "\n=== LEVEL UP! ===\n";
            cout << " Nyni jsi level " << hrac.lvl << "!\n";
            cout << " Tvoje statistiky se zvysily!\n";
            cout << "=========================================\n";
        }
    }

    _getch();
}

void vesnice () {
int pokracovat=0;
int nakup_vybaveni=0;
int vyberves=0;
do{
    do{
        Statistiky(hrac);
cout<< " - - - VESNICE - - - ";
cout<<endl;
cout<<"Vyberte co chcete delat ve vesnici.\n";
cout << "  " << setw(5) << left << "[1]" << setw(30) << left << "NAKUP VYBAVENI" << setw(25) << right << "( -80G +10 DMG/HP )" << endl;
cout << "  " << setw(5) << left << "[2]" << setw(30) << left << "UZDRAVENI" << setw(25) << right << "( -15G + fullHP )" << endl;
cout << "  " << setw(5) << left << "[3]" << setw(30) << left << "VYLEPSENI UTOKU / SCHOPNOSTI" << setw(25) << right << "( -120G +20 DMG )" << endl;
cout << "  " << setw(5) << left << "[4]" << setw(30) << left << "VYLEPSENI MANY" << setw(25) << right << "( -50G +30 MN )" << endl;
cout << "  " << setw(5) << left << "[5]" << setw(30) << left << "VYLEPSENI MAX ZIVOTU" << setw(25) << right << "( -100G +30 maxHP )" << endl;
cout << "  " << setw(5) << left << "[6]" << "NIC, JIT PRYC\n";
cout<< "Volba: ";

cin>>vyberves;
switch (vyberves){
            case 1:
            if (hrac.zlato >= 80){
                do{
                    cout<<"Vybrali jste si NAKUP VYBAVENI\n\n";
                    cout<<setw(10)<<"[1] Koupje zbrane: +10 DMG\n";
                    cout<<setw(10)<<"[2] Koupje brneni: +10 HP\n";
                    cin>>nakup_vybaveni;
                    if(nakup_vybaveni==1){ hrac.max_dmg+=10; hrac.zlato-=80; }
                    if(nakup_vybaveni==2){ hrac.akt_hp+=10; hrac.max_hp+=10; hrac.zlato-=80; }
                } while (nakup_vybaveni!=1&&nakup_vybaveni!=2);
            }else { cout << "Nemas dost zlata!\n"; }
            break;
            case 2:
            if (hrac.zlato >= 15) { hrac.akt_hp = hrac.max_hp; hrac.zlato -= 15; } else { cout << "Nemas dost zlata!\n"; }
            cout<<"Vybrali jste si UZDRAVENI\n";
            break;
            case 3:
            if (hrac.zlato >= 120) {hrac.max_dmg += 20; hrac.zlato -= 120; } else { cout << "Nemas dost zlata!\n"; }
            cout<<"Vybrali jste si VYLEPSENI UTOKU / SCHOPNOSTI\n";
            break;
            case 4:
            if (hrac.zlato >= 50) { hrac.akt_mn += 30; hrac.max_mn += 30; hrac.zlato -= 50; } else { cout << "Nemas dost zlata!\n"; }
            cout<<"Vybrali jste si VYLEPSENI MANY\n";
            break;
            case 5:
            if (hrac.zlato >= 100) { hrac.akt_hp += 30; hrac.max_hp+=30; hrac.zlato -= 100; } else { cout << "Nemas dost zlata!\n"; }
            cout<<"Vybrali jste si VYLEPSENI MAX ZIVOTU\n";
            break;
            case 6:
            cout<<"Nic nechcete.... \n";
            break;
            default:
            cout<<"SPATNE zadana hodnota!\n";
        }
    }while(vyberves<=0||vyberves>=7);
    
    cout<<"Chcete pokracovat v nakupu (ANO=1, NE=2): ";
    cin>>pokracovat;
}while(pokracovat==1);
}
int main(){
    system("cls");
    int vybertyp=0;
    int pokracovattyp=1;
srand(time(0));
    string typy[4] = {"Mage", "Warrior", "Assasin", "Archer"};

    int staty[4][3] = {
        {80, 80, 300},
        {150, 50, 100},
        {40, 100, 150},
        {80, 70, 200}
    };  
    do{
        do {
system("cls");
        cout << " ============================================================\n";
        cout << "                      VYBER SI CLASSU                       \n";
        cout << " ============================================================\n\n";

        for(int i = 0; i < 4; i++) { cout << "      [" << i + 1 << "]      "; } 
        cout << "\n ------------------------------------------------------------\n";
        
        for(int i = 0; i < 4; i++) { cout << "    " << setw(11) << left << typy[i]; } 
        cout << "\n\n";
        
        for(int i = 0; i < 4; i++) { cout << "    " << setw(3) << right << staty[i][0] << " HP     "; } 
        cout << "\n";
        for(int i = 0; i < 4; i++) { cout << "    " << setw(3) << right << staty[i][1] << " DMG    "; } 
        cout << "\n";
        for(int i = 0; i < 4; i++) { cout << "    " << setw(3) << right << staty[i][2] << " MN     "; } 
        cout << "\n";
        
        cout << "\n ============================================================\n";
        cout << " Volba: ";
        cin >> vybertyp;


switch (vybertyp) {
    case 1:
        cout << "Vybral sis classu: Mage\n";
        break;
    case 2:
        cout << "Vybral sis classu: Warrior\n";
        break;
    case 3:
        cout << "Vybral sis classu: Assasin\n";
        break;
    case 4:
        cout << "Vybral sis classu: Archer\n";
        break;
    default:
        cout << "Neznama classa!\n";
        break;
}
} while (vybertyp<1||vybertyp>4);

            cout << "\nChcete si vybrat jinou postavu? ( ANO=1 , NE=2 ): ";
            cin >> pokracovattyp;

            if (pokracovattyp < 1 || pokracovattyp > 2) {
                cout << "SPATNE ZADANA HODNOTA!! Zadej 1 nebo 2." << endl;
            }
                    } while (pokracovattyp == 1);

hrac.jmeno = typy[vybertyp-1];
hrac.akt_hp = staty[vybertyp-1][0];
hrac.max_hp = staty[vybertyp-1][0];

hrac.max_dmg = staty[vybertyp-1][1];

hrac.akt_mn = staty[vybertyp-1][2];
hrac.max_mn = staty[vybertyp-1][2];

hrac.lvl = 1;
hrac.akt_xp = 0;
hrac.max_xp = 100;

Statistiky (hrac);
    vesnice();
    boj_monstra (vybertyp-1);
    return 0;
}