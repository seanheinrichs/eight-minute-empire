# eight-minute-empire
The board game Eight Minute Empire recreated as a C++ program. The final project for COMP 345.


## Creating a Map File
A map file must end with the extension `.map`. It contains the following components:
* players
* continents
* regions
* region
* player

### Players
List all players in the game. For example:
```
players("red", "blue", "green").
```
### Continents
List all continents in the game. For example:
```
continents("north", "south").
```

### Regions
List all regions in the game. For example:
```
regions("seoul", "ilsan", "pyongyang", "jeju").
```

### Region
Provide the details for a given mapnode. This takes the form `region(regionName, continentName, [regions connected by land], [regions connected by water]).` 

For example:
```
region("ilsan", "south", ["pyongyang", "seoul"], []).
region("jeju", "south", [], ["seoul"]).
```

### Player
Provide the army and city details for a given player. This takes the form `player(name, region1, armiesInRegion1, cityInRegion1, region2, etc.`

Note that not every region needs to be listed on each line, and the order does not matter.

For example:
```
player("green", "pyongyang", 1, 1, "seoul", 1, 1, "jeju", 1, 1).
```