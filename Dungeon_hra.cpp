#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int main(){
    system("cls");
    int vybertyp;
    int pokracovattyp=1;
    string typy[4] = {"Mage", "Warrior", "Assasin", "Archer"};

    int staty[4][3] = {
        {80, 80, 300},
        {150, 50, 100},
        {40, 100, 150},
        {80, 70, 200}
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