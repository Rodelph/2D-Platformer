g++ -std=c++1z prcHead.h
g++ -std=c++1z Main.cpp Game.cpp EnergyBar.cpp IOFile.cpp Player.cpp TileMap.cpp AudioGame.cpp HpBar.cpp prcHead.cpp Tile.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio  -g -o output
./output