#pragma once

#include "ofMain.h"
#include "GameObject/GameObject.h"
#include "ofxGui.h"
#include "Movement/IMovementAlgorithm.h"
#include "Graph\Graph.h"
#include "Graph\TileMap.h"
#include "WorldData/WorldManager.h"
class ofApp : public ofBaseApp
{
public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);



private:

	void InitailizeGameWorld();
	void DrawGameWorld();

	AIForGames::GameObject* m_pBoidObject;
	AIForGames::GameObject* m_pTarget;
	AIForGames::GameObject* m_pNPC;
	std::vector<AIForGames::GameObject*> m_pObjects;
	AIForGames::Movement::IMovementAlgorithm* m_pMovementAlgo;
	std::vector<AIForGames::Movement::IMovementAlgorithm*> m_pBlendedMovement;
	std::vector<AIForGames::Physics::Kinematic*> allKinematics;
	AIForGames::Physics::Kinematic* matchKinematic;
	AIForGames::PathFinding::Graph* m_pGraph;
	std::vector<ofVec2f> m_WallTopLocation;
	std::vector<float> m_WallWidth;
	std::vector<float> m_WallHeight;
	std::list<DirectedWeightedEdge> o_path;
	AIForGames::PathFinding::TileMap* m_pTileMap;
	int m_noOfWalls;
	int m_numberOfBoids;
};
