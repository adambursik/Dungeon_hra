#include <iostream>

using namespace std;
int main(){
system("cls");
        cout << " ===============================================================\n";
        cout << "                         VYBER SI CLASSU                        \n";
        cout << " ===============================================================\n\n";

        string znaky[4] = {"  [ * ]  ", "  [ |> ] ", "  [ x ]  ", "  [ >> ] "}; 

        // 1. Řádek: Čísla pro volbu
        for(int i = 0; i < 4; i++) { cout << "      [" << i + 1 << "]      "; }
        cout << "\n";

        // 2. Řádek: Znaky zbraní
        for(int i = 0; i < 4; i++) { cout << "    " << setw(11) << left << znaky[i]; }
        cout << "\n ---------------------------------------------------------------\n";

        // 3. Řádek: Jména tříd
        for(int i = 0; i < 4; i++) { cout << "    " << setw(11) << left << typy[i]; }
        cout << "\n\n";

        // 4. Řádek: HP
        for(int i = 0; i < 4; i++) { cout << "   " << setw(3) << right << staty[i][0] << " HP      "; }
        cout << "\n";

        // 5. Řádek: DMG
        for(int i = 0; i < 4; i++) { cout << "   " << setw(3) << right << staty[i][1] << " DMG     "; }
        cout << "\n";

        // 6. Řádek: Mana
        for(int i = 0; i < 4; i++) { cout << "   " << setw(3) << right << staty[i][2] << " MN      "; }
        
        cout << "\n\n ===============================================================\n";
        cout << " Volba: ";
        cin >> vybertyp;
}