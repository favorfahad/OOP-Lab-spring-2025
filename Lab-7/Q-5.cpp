#include "iostream"
using namespace std;

class Character {
    protected:
    int characterID;
    string name;
    int level;
    int healthPoints;
    string weaponType;
    public:
    Character(int id, string n, int lvl, int hp, string wt) : characterID(id), name(n), level(lvl), healthPoints(hp), weaponType(wt) {}
    virtual void attack() { cout << "Basic attack!" << endl; }
    virtual void defend() { cout << "Basic defense!" << endl; }
    virtual void displayStats() {
        cout << "ID: " << characterID << endl;
        cout << "Name: " << name << endl;
        cout << "Level: " << level << endl;
        cout << "HP: " << healthPoints << endl;
        cout << "Weapon: " << weaponType << endl;
    }
};

class Warrior : public Character {
    private:
    int armorStrength;
    int meleeDamage;
    public:
    Warrior(int id, string n, int lvl, int hp, string wt, int armor, int dmg) : Character(id, n, lvl, hp, wt), armorStrength(armor), meleeDamage(dmg) {}
    void attack() override {
        cout << "Warrior attacks with " << meleeDamage << " melee damage!" << endl;
    }
};

class Mage : public Character {
    private:
    int manaPoints;
    int spellPower;
    public:
    Mage(int id, string n, int lvl, int hp, string wt, int mana, int sp) : Character(id, n, lvl, hp, wt), manaPoints(mana), spellPower(sp) {}
    void defend() override {
        cout << "Mage creates a barrier using " << manaPoints << " mana!" << endl;
    }
};

class Archer : public Character {
    private:
    int arrowCount;
    int rangedAccuracy;
    public:
    Archer(int id, string n, int lvl, int hp, string wt, int arrows, int acc) : Character(id, n, lvl, hp, wt), arrowCount(arrows), rangedAccuracy(acc) {}
    void attack() override {
        cout << "Archer shoots with " << rangedAccuracy << "% accuracy!" << endl;
        arrowCount--;
    }
};

class Rogue : public Character {
    private:
    int stealthLevel;
    int agility;
    public:
    Rogue(int id, string n, int lvl, int hp, string wt, int stealth, int agi) : Character(id, n, lvl, hp, wt), stealthLevel(stealth), agility(agi) {}
    void displayStats() override {
        Character::displayStats();
        cout << "Stealth: " << stealthLevel << endl;
        cout << "Agility: " << agility << endl;
    }
};

int main() {
    Warrior war(401, "Conan", 10, 100, "Sword", 50, 30);
    Mage mage(402, "Gandalf", 15, 80, "Staff", 200, 50);
    Archer arch(403, "Legolas", 12, 90, "Bow", 30, 95);
    Rogue rogue(404, "Shadow", 8, 70, "Dagger", 85, 90);

    cout << "--- Warrior Action ---" << endl;
    war.attack();
    cout << "\n--- Mage Defense ---" << endl;
    mage.defend();
    cout << "\n--- Archer Attack ---" << endl;
    arch.attack();
    cout << "\n--- Rogue Stats ---" << endl;
    rogue.displayStats();
    return 0;
}
