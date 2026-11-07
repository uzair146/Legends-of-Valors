# Legends of Valors ⚔️🛡️


## 📖 Overview

**Legends of Valors** is an interactive, console-based Role-Playing Game (RPG) developed in **C++**. The project demonstrates fundamental and advanced Object-Oriented Programming paradigms through turn-based combat, a modular equipment and inventory system, an explorable world map with dynamic encounters, and persistent save/load features.

---

## 🏛️ OOP Concepts Demonstrated

This project is built from the ground up to showcase key OOP principles:

### 1. Inheritance & Class Hierarchies
- **Character Base Class:**
  - `Character` ➔ `Warrior`, `Mage`, `Rogue`, `Enemy`
    - `Warrior` ➔ `BerserkerWarrior`, `GuardianWarrior`, `BattleMasterWarrior`
    - `Mage` ➔ `FireMage`, `WaterMage`, `ElectricMage`
    - `Rogue` ➔ `AssassinRogue`, `TricksterRogue`, `ThiefRogue`
    - `Enemy` ➔ `BossEnemy` (multi-phase boss battles)
- **Item Base Class:**
  - `Item` (Abstract Base) ➔ `Weapon`, `Armor`, `Potion`, `MagicItem`
    - **Weapons:** `Sword`, `Axe`, `Bow`, `Dagger`, `Staff`
    - **Armors:** `PlateArmor`, `ChainMail`, `LeatherArmor`, `MageRobe`, `AssassinGarb`, etc.
    - **Potions:** `HealthPotion`, `ManaPotion`, `StrengthPotion`, `DefensePotion`
    - **Magic Items:** `FireWand`, `FrostWand`, `LightningRod`, `HealingStaff`

### 2. Polymorphism & Virtual Functions
- **Pure Virtual Functions:**
  - `virtual void useSkill() = 0` in `Character`
  - `virtual void useItem(Character* target) = 0` in `Item`
- **Dynamic Dispatch:** Calling overridden methods at runtime based on the actual object type.
- **Run-Time Type Identification (RTTI):** Utilizing `dynamic_cast` for class-specific serialization, item equipping, and combat skill calculations.

### 3. Encapsulation & Data Protection
- Controlled access to private/protected state (`health`, `mana`, `attackPower`, `defensePower`, `gold`) through dedicated accessors and mutators (`heal()`, `BuffAttack()`, `BuffDefense()`, `takeDamage()`).

### 4. Composition & Aggregation
- The `Game` engine aggregates `Character* player`, `Inventory inventory`, and an array of `MapArea* worldMap[5]`.
- `Inventory` manages dynamic arrays of polymorphic `Item*` pointers with capacity checking and bounds handling.

### 5. File Handling & Serialization
- Game state persistence using `std::ifstream` and `std::ofstream` to read/write character stats, gold, inventory items, and visited world map states (`game_save.txt`).

---

## 🎮 Game Features

- **Character Selection & Specializations:**
  - **Warrior:** High HP & Armor. Choose between *Berserker* (offensive rage), *Guardian* (defensive tank), or *Battle Master* (balanced).
  - **Mage:** Elemental spellcaster with Mana pool. Choose between *Fire Mage*, *Water Mage*, or *Electric Mage*.
  - **Rogue:** Critical damage and stealth. Choose between *Assassin*, *Trickster*, or *Thief*.
- **Tactical Turn-Based Combat:**
  - Attack, defend, cast skills, or consume potions.
  - Enemy AI with frenzy mode and multi-stage boss encounters.
- **Inventory & Shop System:**
  - Manage equipment, weapons, and buffs.
  - Earn gold from battles to purchase equipment and potions in the shop.
- **World Map Exploration:**
  - Travel across diverse areas: *Forest (Grassland)*, *Cave (Rocky)*, *Swamp (Wetland)*, *Mountain (Snowy)*, and *Castle (Stone)*.
- **Save & Load Functionality:**
  - Save progress anytime and resume your adventure without losing data.

---

## 📂 Project Structure

```text
├── main.cpp                    # Entry point
├── Game.h / game.cpp           # Main game loop, shop, battle, save/load
├── character.h / character.cpp # Base Character class
├── Warrior.h / Warrior.cpp     # Base Warrior class
├── Mage.h / Mage.cpp           # Base Mage class
├── Rogue.h / Rogue.cpp         # Base Rogue class
├── Enemy.h / Enemy.cpp         # Base Enemy class
├── BossEnemy.h / BossEnemy.cpp # Multi-phase Boss
├── Item.h / Item.cpp           # Abstract Item base class
├── Weapon.h / Weapon.cpp       # Weapon class & derived weapons
├── Armor.h / Armor.cpp         # Armor class & derived armors
├── Potion.h / Potion.cpp       # Potion class & derived potions
├── MagicItem.h / MagicItem.cpp # Magic items
├── Inventory.h / Inventory.cpp # Player inventory management
├── MapArea.h / MapArea.cpp     # Map area and encounter management
├── game_save.txt               # Saved game state file
└── README.md                   # Project documentation
```

---

## 🚀 How to Build and Run

### 1. Using Command Line (MinGW / GCC)
Open Terminal or PowerShell in the project directory and run:

```bash
# Compile all C++ files
g++ -std=c++11 *.cpp -o game.exe

# Run the game
.\game.exe
```

### 2. Using Visual Studio / Code::Blocks / Dev-C++
1. Create a new empty C++ Console Application project.
2. Add all `.h` and `.cpp` files into the project.
3. Build and run using **F5** or **Ctrl + F5**.

---

## 🛠️ System Requirements

- **Language Standard:** C++11 or newer
- **Compiler:** GCC / MinGW (g++), MSVC, or Clang
- **OS:** Windows / Linux / macOS (Supports ANSI color sequences in modern terminals)

---

## 👨‍💻 Authors & Project Contributors

| Name | Contribution | 
| :--- |:--- |
| **Muhammad Uzair Hussain** | Core Mechanics, Character Classes & OOP Design |
| **Muqarrab Mustafa** | Battle Engine, Inventory System & File I/O |

> **Department:** Department of Computer Science
> **Course:** Object-Oriented Programming (CS) - 2nd Semester Project
