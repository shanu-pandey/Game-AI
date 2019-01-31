#pragma once

#include "ofMain.h"
#include "GameObject/GameObject.h"
#include "ofxGui.h"
#include "Movement/IMovementAlgorithm.h"

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
	AIForGames::GameObject* m_pBoidObject;
	AIForGames::GameObject* m_pTarget;
	std::vector<AIForGames::GameObject*> m_pObjects;
	AIForGames::Movement::IMovementAlgorithm* m_pMovementAlgo;
	int m_numberOfBoids;
};
