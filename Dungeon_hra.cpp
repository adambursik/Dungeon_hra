#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;
void vesnice () {
cout<< " - - - VESNICE - - - ";
cout<<endl;
int vyberves=0;
cout<<"Vyberte co chcete delat ve vesnici.\n";
cout<<endl<<setw(15)<<" [1]  NAKUP VYBAVENI\n";
cout<<endl<<setw(15)<<" [2] UZDRAVENI\n";
cout<<endl<<setw(15)<<" [3] VYLEPSENI UTOKU / SCHOPNOSTI\n";
cout<<endl<<setw(15)<<" [4] VYLEPSENI MANY\n";
cout<<endl<<setw(15)<<" [5] VYLEPSENI MAX ZIVOTU\n";

cin>>vyberves;
switch (vyberves){

case 1:
cout<<"Vybrali jste si NAKUP VYBAVENI\n";

break;
case 2:
cout<<"Vybrali jste si UZDRAVENI\n";
break;
case 3:
cout<<"Vybrali jste si VYLEPSENI UTOKU / SCHOPNOSTI\n";
break;
case 4:
cout<<"Vybrali jste si VYLEPSENI MANY\n";
break;
case 5:
cout<<"Vybrali jste si VYLEPSENI MAX ZIVOTU\n";
break;
default:
cout<<"SPATNE zadana hodnota!";
}

int main(){
    system("cls");
    int vybertyp;
    int pokracovattyp=1;
srand(time(0));
    string typy[4] = {"Mage", "Warrior", "Assasin", "Archer"};

    int staty[4][3] = {
        {80, 80, 300},
        {150, 50, 100},
        {40, 100, 150},
        {80, 70, 200}
    };
string monstra[16] = {"Goblin Scout", "Goblin Warrior", "Goblin Archer", "Goblin Merchant",
"Skeleton Pawn", "Skeleton Warrior", "Skeleton Archer", "Zombie",
    "Giant Rat", "Cave Spider", "Vampire Bat", "Dire Wolf",
    "Orc Scout", "Orc Warrior", "Kobold Miner", "Slime"
};
int statymonstra[16][3] = {
    {40, 10, 20},
    {60, 15, 35},
    {45, 12, 30},
    {30, 2, 250},
    {50, 12, 15},
    {70, 18, 40},
    {55, 15, 30},
    {90, 8, 20},
    {35, 10, 10},
    {50, 14, 0},
    {30, 12, 0},
    {65, 20, 0},
    {70, 15, 50},
    {110, 25, 100},
    {60, 14, 75},
    {40, 8, 10}
};

do{    
    do{

cout<<"Vyberte si classu: "<<endl;
cout<<endl;
for(int i=0;i<4;i++){
    cout<<" ["<<i+1<<"] "<<setw(10)<<typy[i]<<" | "<<endl;
}
cin>>vybertyp;

switch (vybertyp){
case 1:
    cout << "Vybrali jste si classu: Mage\n\n";
    
    cout << setw(10) << "CLASS" << " |" << setw(6) << "HP" << " |" << setw(6) << "STR" << " |" << setw(6) << "MP" << " |" << endl;
    cout << "------------------------------------------" << endl;

    cout << setw(10) << typy[0] << " |";
    
    for(int i = 0; i < 3; i++) {
        cout << setw(6) << staty[0][i] << " |";
    }
    cout << endl;
    break;
case 2:
    cout << "Vybrali jste si classu: Warrior\n\n";
    
    cout << setw(10) << "CLASS" << " |" << setw(6) << "HP" << " |" << setw(6) << "STR" << " |" << setw(6) << "MP" << " |" << endl;
    cout << "------------------------------------------" << endl;

    cout << setw(10) << typy[1] << " |";
    
    for(int i = 0; i < 3; i++) {
        cout << setw(6) << staty[1][i] << " |";
    }
    cout << endl;
    break;
case 3:
    cout << "Vybrali jste si classu: Assassin\n\n";
    
    cout << setw(10) << "CLASS" << " |" << setw(6) << "HP" << " |" << setw(6) << "STR" << " |" << setw(6) << "MP" << " |" << endl;
    cout << "------------------------------------------" << endl;

    cout << setw(10) << typy[2] << " |";
    
    for(int i = 0; i < 3; i++) {
        cout << setw(6) << staty[2][i] << " |";
    }
    cout << endl;
    break;
case 4:
    cout << "Vybrali jste si classu: Archer\n\n";
    
    cout << setw(10) << "CLASS" << " |" << setw(6) << "HP" << " |" << setw(6) << "STR" << " |" << setw(6) << "MP" << " |" << endl;
    cout << "------------------------------------------" << endl;

    cout << setw(10) << typy[3] << " |";
    
    for(int i = 0; i < 3; i++) {
        cout << setw(6) << staty[3][i] << " |";
    }
    cout << endl;
    break;

default:
cout<<"SPATNE ZADANA HODNOTA!\n";
    break;
}
} while (vybertyp<1||vybertyp>4);
do {
            cout << "\nChcete si vybrat jinou postavu? ( ANO=1 , NE=2 , STATISTIKY=3 ): ";
            cin >> pokracovattyp;

            if (pokracovattyp < 1 || pokracovattyp > 3) {
                cout << "SPATNE ZADANA HODNOTA!! Zadej 1, 2 nebo 3." << endl;
            }
        } while (pokracovattyp < 1 || pokracovattyp > 3);
if (pokracovattyp==3){
    for (int i = 0; i < 4; i++) {
        cout << setw(15) << typy[i]
             << " | HP: " << setw(3) << staty[i][0]
             << " | STR: " << setw(3) << staty[i][1] 
             << " | MP: "<<setw(3) << staty [i][2]<<endl;
    }
    cout<<"Pokracovat na vyber classy?( ANO=1, NE=any ) ";
    cin>>pokracovattyp;
}
    } while (pokracovattyp == 1);
    return 0;
}