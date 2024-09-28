#include <iostream>
#include <vector>
#include <string>
#include <algorithm>  // Required for remove
using namespace std;

// Player class: Abstract Observer interface
class Player {
public:
    virtual void update(const string& event) = 0; // Pure virtual function
    virtual ~Player() = default; // Virtual destructor
};

// Warrior class: Concrete observer
class Warrior : public Player {
public:
    void update(const string& event) override {
        cout << "[Warrior] Received event: " << event << endl;
    }
};

// Mage class: Concrete observer
class Mage : public Player {
public:
    void update(const std::string& event) override {
        cout << "[Mage] Received event: " << event << endl;
    }
};

// GameEngine class: Subject in the Observer pattern
class GameEngine {
private:
    vector<Player*> players; // List of observers

public:
    // Attach a player to the observer list
    void attach(Player* player) {
        players.push_back(player);
    }

    // Detach a player from the observer list
    void detach(Player* player) {
        players.erase(remove(players.begin(), players.end(), player), players.end());
    }

    // Notify all players of an event
    void notify(const std::string& event) {
        cout << "[GameEngine] Event Triggered: " << event << std::endl;
        for (Player* player : players) {
            player->update(event); // Notify each player
        }
    }
};

int main() {
    // Create the GameEngine (subject)
    GameEngine engine;

    // Create some players (observers)
    Player* warrior = new Warrior();
    Player* mage = new Mage();

    // Attach players to the engine
    engine.attach(warrior);
    engine.attach(mage);

    // Trigger different game events
    engine.notify("Enemy appeared!");
    engine.notify("New quest started!");

    // Players react to another event
    engine.notify("Boss appeared!");

    // Detach a player and trigger another event
    engine.detach(warrior);
    engine.notify("Rare item found!");

    // Clean up
    delete warrior;
    delete mage;

    return 0;
}
