# Observer Pattern in Game System
This project implements the Observer Pattern, where the GameEngine acts as the subject and notifies Player observers when in-game events occur. The GameEngine maintains the list of observers and uses notify() method to inform all players in game about events, such as enemy or boss appearing, new requests starting, or rare items being found.
The benefits of observer pattern:
  1. It decouples the GameEngine from players because the GameEngine does not need to know the details of players how they respond to events.
  2. Players can be notified of events in real-time, like enemy enounters or new quests appeared.
  3. It's easy to add new players that can respond to game events without modifying the GameEngine.
The consequences of observer pattern:
  1. The high-cost of maintaining observers since the GameEngine must manage attachment and detachment of observers, which can add more overhead, especially if there are a large number of players.
  2. The cost of performance by notifying many observers can be inefficient if there are many notifications appeared at a time, which potentially impacting the game's performance.
