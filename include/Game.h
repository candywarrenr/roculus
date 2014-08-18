#ifndef _GAME_H_
#define _GAME_H_

#include <OgreSceneManager.h>
#include <OgreEntity.h>
#include <WayPoint.h>
#include <GameCFGParser.h>
#include <Room.h>
#include <GameObject.h>
#include <Door.h>
#include <Key.h>
#include <Treasure.h>
#include <Lock.h>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>

using namespace Ogre;

class Game {
  protected:
	Game() : initiated(false) {}
	~Game();
	Game(const Game&);
	Game& operator=(const Game&);
	bool initiated;
	
	SceneManager* mSceneMgr;
	SceneNode *marker, *persMarker;
	std::vector<WayPoint*> wayPoints;
	std::vector<Room*> rooms;
	std::vector<Room*> corridors;
	std::vector<GameObject*> gameObjects;
	WayPoint *select;
	WayPoint *initWP;
	Real distMin;
	Real distance;
	GameState state;
	int lastWPId;
	Door *door;
	Treasure *treasure;
	bool running;
	
	Room *getRndRoom(std::set<int> &roomNRs);
	
  public:
	static Game &getInstance();
  
	void init(SceneManager*);
	WayPoint* getWPById(int);
	WayPoint* getWPByName(const String&);
	std::string getInitWP();
	String highlightClosestWP(const Vector3&);
	String getState();
	void placePersistentMarker(const String&);
	void print();
	
	void startGameSession();
	GameState frameEventQueued(int);
	bool isRunning();
};

#endif