/*
Name: Josh
Description: This is just a short project made to get experience with C++ maps 
*/

#include <iostream>
#include <map>
#include <list>
#include <string>

using namespace std;

//Generate starting pokedex entries 
map<int, list<string>> createPokedex(map<int, list<string>> &pokedex){
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
    pokedex.insert(pair<int, list<string>>(1, bulbasaur));
    pokedex.insert(pair<int, list<string>>(2, ivysaur));
    pokedex.insert(pair<int, list<string>>(3, venusaur));
    pokedex.insert(pair<int, list<string>>(4, charmander));
    pokedex.insert(pair<int, list<string>>(5, charmeleon));
    pokedex.insert(pair<int, list<string>>(6, charizard));
    pokedex.insert(pair<int, list<string>>(7, squirtle));
    pokedex.insert(pair<int, list<string>>(8, wartortle));
    pokedex.insert(pair<int, list<string>>(9, blastoise));

    return pokedex;
}

//takes in string parameters to add a new entry to the pokedex... does not persist after program ends
map<int, list<string>> appendPokemon(map<int, list<string>> &pokedex,string name, string type, string gen){
    int addAt = pokedex.size() + 1;
    list<string> newPokemon{name, type, gen};
    pokedex.insert(pair<int, list<string>>(addAt, newPokemon));

    return pokedex;
}

int main() {

    //create the Pokedex holding a string as key and list of strings as data
    map<int, list<string>> pokedex;
    createPokedex(pokedex);
  
    //Use append function to add the next 3 entires automatically
    appendPokemon(pokedex, "Caterpie", "Bug", "Gen1");
    appendPokemon(pokedex, "Metapod", "Bug", "Gen1");
    appendPokemon(pokedex, "Butterfree", "Bug/Flying", "Gen1");


    //print out pokedex
    cout << "Starting Pokedex..." << endl;
    for(auto pair : pokedex){
        cout << pair.first << " --- ";
            for(auto info : pair.second){
                cout << info << ", " ;
            }
        cout << endl;
    }

    //adding some interaction for the user
    int userEntry;

    //Loop until user enters 3 or an incorrect entry to exit
    do{
        //Create a menu 
        cout << endl;
        cout << "Welcome to the pokedex, what would you like to do?: " << endl;
        cout << "1: Insert a new pokemon!" << endl;
        cout << "2: Print the current pokedex." << endl;
        cout << "3: Exit the program..." << endl;
        cin >> userEntry;
        cout << endl; 

        //If the entry is valid (1-3) perform correct operation
        if(userEntry == 1 || userEntry == 2 || userEntry == 3){

            //1 is the option to append a pokemon to the list 
            if(userEntry == 1){
                string name, type, gen;
                cout << "Please enter the name of the new pokemon: ";
                cin >> name;
                cout << "\n" << "Please enter the typing of the new pokemon: "; 
                cin >> type; 
                cout << "\n" << "Please enter the generation of the pokemon (Ex: Gen1):" ;
                cin >> gen;
                cout << endl; 
                appendPokemon(pokedex, name, type, gen);
            }

            //This prints out the list, practical use is to see your entries made using option 1 
            else if(userEntry == 2){

                //print out pokedex
                for(auto pair : pokedex){
                    cout << pair.first << " --- ";
                        for(auto info : pair.second){
                            cout << info << ", " ;
                        }
                    cout << endl;
    }
            }
            else{
                "Thanks for checking out the pokedex program!";
            }
        }
        //if entry is invalid, exit and notify them 
        else{
            cout << "Please enter a valid option... ending program";
            userEntry = 3;
        }
        

    }while(userEntry != 3);

	return 0;
}

