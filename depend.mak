build/maze.o: maze.cpp maze.h position.h tile.h entity.h entitycontroller.h \
 tilefactory.h
build/tile.o: tile.cpp tile.h
build/floor.o: floor.cpp floor.h tile.h
build/wall.o: wall.cpp wall.h tile.h
build/goal.o: goal.cpp goal.h tile.h
build/mysterytile.o: mysterytile.cpp mysterytile.h tile.h
build/tilefactory.o: tilefactory.cpp wall.h tile.h floor.h goal.h mysterytile.h \
 tilefactory.h
build/game.o: game.cpp game.h maze.h position.h tile.h entity.h \
 entitycontroller.h ui.h gamerules.h
build/entity.o: entity.cpp entity.h position.h entitycontroller.h
build/entitycontroller.o: entitycontroller.cpp entitycontroller.h position.h
build/uicontrol.o: uicontrol.cpp
build/chasehero.o: chasehero.cpp
build/astarchasehero.o: astarchasehero.cpp
build/inanimate.o: inanimate.cpp
build/mysterycontroller.o: mysterycontroller.cpp mysterycontroller.h \
 entitycontroller.h position.h
build/ecfactory.o: ecfactory.cpp uicontrol.h entitycontroller.h position.h \
 chasehero.h astarchasehero.h inanimate.h mysterycontroller.h ecfactory.h
build/ui.o: ui.cpp ui.h position.h
build/gamerules.o: gamerules.cpp gamerules.h game.h
build/basicgamerules.o: basicgamerules.cpp
build/tctestpp.o: tctestpp.cpp tctestpp.h
build/scriptedcontrol.o: scriptedcontrol.cpp scriptedcontrol.h \
 entitycontroller.h position.h
build/positiontest.o: positiontest.cpp
build/tiletest.o: tiletest.cpp
build/mazetest.o: mazetest.cpp
build/gametest.o: gametest.cpp
