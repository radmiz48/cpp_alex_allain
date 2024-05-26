#include <iostream>

using namespace std;

struct WrogiStatekKosmiczy
{
    int wspolrzedna_x;
    int wspolrzedna_y;
    int sila_broni;
};

WrogiStatekKosmiczy generujNowegoWroga()
{
    WrogiStatekKosmiczy statek;
    statek.wspolrzedna_x = 0;
    statek. wspolrzedna_y = 0;
    statek.sila_broni = 20;
    return statek;
}

WrogiStatekKosmiczy ulepszBron(WrogiStatekKosmiczy statek)
{
    statek.sila_broni += 10;
    return statek;
}

int main() 
{
    WrogiStatekKosmiczy wrog = generujNowegoWroga();
    wrog = ulepszBron(wrog);
    
    return 0;
}