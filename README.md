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

### Start
Gives the name of the starting region. For example:
```
start("seoul").
```

### Region
Provide the details for a given mapnode. This takes the form `region(regionName, continentName, [regions connected by land], [regions connected by water]).` 

Note that the square brackets may be empty, if a given region has no land or sea connections. Furthermore, *all regions must have at least one connection*.

For example:
```
region("ilsan", "south", ["pyongyang", "seoul"], []).
region("jeju", "south", [], ["seoul"]).
```

### Player
Provide the army and city details for a given player. This takes the form `player(name, region1, armiesInRegion1, cityInRegion1, region2, etc.`

Note that not every region needs to be listed, and the order does not matter. Furthermore, *the number of cities must be 0 or 1*.

For example:
```
player("green", "pyongyang", 1, 1, "seoul", 1, 1, "jeju", 1, 1).
```