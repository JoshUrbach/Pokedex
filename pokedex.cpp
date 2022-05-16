/*
Name: Josh
Description: This is just a short project made to get experience with C++ maps 
*/

#include <iostream>
#include <map>
#include <list>
#include <string>

using namespace std;

int main() {

    //create the Pokedex holding a string as key and list of strings as data
    map<string, list<string>> pokedex;

    //create each list of info
    list<string> bulbasaur{"Bulbasaur", "Grass/Poison", "Gen1"};
    list<string> ivysaur{"Ivysaur", "Grass/Poison", "Gen1"};
    list<string> venusaur{"Venusaur", "Grass/Poison", "Gen1"};
    list<string> charmander{"Charmander", "Fire", "Gen1"};
    list<string> charmeleon{"Charmeleon", "Fire", "Gen1"};
    list<string> charizard{"Charizard", "Fire/Flying", "Gen1"};
    list<string> squirtle{"Squirtle", "Water", "Gen1"};
    list<string> wartortle{"Wartortle", "Water", "Gen1"};
    list<string> blastoise{"Blastoise", "Water", "Gen1"};
  
    //insert
    pokedex.insert(pair<string, list<string>>("1", bulbasaur));
    pokedex.insert(pair<string, list<string>>("2", ivysaur));
    pokedex.insert(pair<string, list<string>>("3", venusaur));
    pokedex.insert(pair<string, list<string>>("4", charmander));
    pokedex.insert(pair<string, list<string>>("5", charmeleon));
    pokedex.insert(pair<string, list<string>>("6", charizard));
    pokedex.insert(pair<string, list<string>>("7", squirtle));
    pokedex.insert(pair<string, list<string>>("8", wartortle));
    pokedex.insert(pair<string, list<string>>("9", blastoise));

    //print
    for(auto pair : pokedex){
        cout << pair.first << " --- ";
            for(auto info : pair.second){
                cout << info << ", " ;
            }
        cout << endl;
    }

	return 0;
}
