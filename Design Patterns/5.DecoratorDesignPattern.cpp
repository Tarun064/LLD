#include <bits/stdc++.h>
using namespace std;

//component interface:defines a common interface for all decorators
class Character {
public:
    virtual string getAbilities() = 0; // pure virtual function
    virtual ~Character() {} // virtual destructor
};

//concrete component: a basic character with no power ups
class Mario: public Character {
public:
    string getAbilities() override{
        return "Mario";
    }
};

//abstract decorator class: character decorator "is-a" character and "has-a" character
class CharacterDecorator: public Character {
protected:
    Character* character; // has-a relationship with Character (wrapped component)
public:
    CharacterDecorator(Character* character): character(character) {
        this->character = character; // initialize the wrapped component
    } // constructor to initialize the wrapped component
};

//concrete decorator: height increase power up
class HeightUp: public CharacterDecorator {
    public:
    HeightUp(Character* character): CharacterDecorator(character) {} // constructor to initialize the wrapped component
    string getAbilities() override{
        return character->getAbilities() + " with Height Up"; // add height up ability to the wrapped component
    }
};

//concrete decorator: gun shooting power up
class GunPowerUp: public CharacterDecorator {
    public:
    GunPowerUp(Character* character): CharacterDecorator(character) {} // constructor to initialize the wrapped component
    string getAbilities() override{
        return character->getAbilities() + " with Gun Power Up"; // add gun power up ability to the wrapped component
    }
};

//concrete decorator: star power up (temporary ability)
class StarPowerUp: public CharacterDecorator {
    public:
    StarPowerUp(Character* character): CharacterDecorator(character) {} // constructor to initialize the wrapped component
    string getAbilities() override{
        return character->getAbilities() + " with Star Power Up"; // add star power up ability to the wrapped component
    }
    ~StarPowerUp() {
        cout << "Star Power Up removed!" << endl; // notify when star power up is removed
    }
};

int main(){
//create a basic mario character
    Character* mario = new Mario();
    cout << "Abilities: " << mario->getAbilities() << endl; // Abilities: Mario

    //add height up power up
    mario = new HeightUp(mario);
    cout << "Abilities: " << mario->getAbilities() << endl; // Abilities: Mario with Height Up

    //add gun power up
    mario = new GunPowerUp(mario);
    cout << "Abilities: " << mario->getAbilities() << endl; // Abilities: Mario with Height Up with Gun Power Up

    //add star power up
    mario = new StarPowerUp(mario);
    cout << "Abilities: " << mario->getAbilities() << endl; // Abilities: Mario with Height Up with Gun Power Up with Star Power Up

    delete mario; // delete the character to free memory
    return 0;
}