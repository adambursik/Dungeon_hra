#include <iostream>
using namespace std;

int scitani(int a , int b){
return a+b;
}
int odcitani (int a , int b){
return a-b;
}
int nasobeni(int a , int b){
return a*b;
}
int deleni(int a , int b){
return a/b;
}


int main() {
  char pocet;
  int x;
  int y;
  double vysledek;
  cout<<"zadejte 2 èisla a znak. \n";
  cout<<"1. cislo: \n";
  cin>> x;
  cout<<"2. cislo: \n";
  cin>> y;
  cout<<"Zadejte znak. (+, -, *, /): ";
  cin>> pocet;

  switch (pocet){

  case '+':
      vysledek = scitani (x, y);
cout << "Souèet: " << vysledek << endl;
break;
  case '-':
      vysledek = odcitani (x, y);
cout << "Rozdil: " << vysledek << endl;
break;

  case '*':
      vysledek = nasobeni (x, y);
cout << "Nasobek: " << vysledek << endl;
break;

  case '/':
      vysledek = deleni (x, y);
cout << "Podil: " << vysledek << endl;
break;

  default:
    cout<<"Neco mas blbe blbecku";
  }
  }
