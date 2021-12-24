FILE=prcHead.h.gch
echo "Checking if the precompiled file exists"

if test -f "$FILE"; then
    echo "$FILE exists."
    g++ -std=c++1z Main.cpp Game.cpp EnergyBar.cpp IOFile.cpp Player.cpp TileMap.cpp AudioGame.cpp HpBar.cpp prcHead.cpp Tile.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio  -g -o output 
    ./output
else
    echo "The precompiled file does not exist !"
    g++ -std=c++1z prcHead.h
    g++ -std=c++1z Main.cpp Game.cpp EnergyBar.cpp IOFile.cpp Player.cpp TileMap.cpp AudioGame.cpp HpBar.cpp prcHead.cpp Tile.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio  -g -o output
    ./output
fi