#include "ofApp.h"
#include "Movement/Arrive.h"
#include "Movement/Wander.h"
#include "Movement/Align.h"
#include "Movement/Seek.h"


#define BASICMOTION
//#define SEEK_STEERING_01
//#define SEEK_STEERING_02
//#define WANDER_STEERING_01
//#define WANDER_STEERING_02
#define FLOCKING


//--------------------------------------------------------------
void ofApp::setup()
{
	float orientation = 0;
	float radius = 15;

#ifdef BASICMOTION
	//Kinematic Seek
	m_pBoidObject = new AIForGames::GameObject(radius, ofVec3f(radius, ofGetHeight() - 40), orientation);
	m_pTarget = new AIForGames::GameObject(radius, ofGetHeight()-20 );
	m_pMovementAlgo = new AIForGames::Movement::Seek(m_pBoidObject->GetKinematic(), m_pTarget->GetKinematic(), 600);
	//m_pMovementAlgo = new AIForGames::Movement::Arrive(m_pBoidObject->GetKinematic(), m_pTarget->GetKinematic(), 800, 0.2, 0.1);
#endif // BASICMOTION

#ifdef SEEK_STEERING_01
	m_pBoidObject = new AIForGames::GameObject(radius, ofVec3f(radius, radius), orientation);
	m_pTarget = new AIForGames::GameObject(-100, -100);
	//Kinematic Arrive
	m_pMovementAlgo = new AIForGames::Movement::Arrive(m_pBoidObject->GetKinematic(), m_pTarget->GetKinematic(), 800, 10, 1);
#endif // SEEK_STEERING

#ifdef SEEK_STEERING_02
	m_pBoidObject = new AIForGames::GameObject(radius, ofVec3f(radius, radius), orientation);
	m_pTarget = new AIForGames::GameObject(-100, -100);	
	//Dynamic Arrive
	m_pMovementAlgo = new AIForGames::Movement::Arrive(m_pBoidObject->GetKinematic(), m_pTarget->GetKinematic(), 800, 200, 20, 5, 1);

#endif // SEEK_STEERING


#ifdef WANDER_STEERING_01
	m_pBoidObject = new AIForGames::GameObject(radius, ofVec3f(500, 500), orientation);
	m_pTarget = new AIForGames::GameObject(-100, -100);
	//Kinematic Wander
	m_pMovementAlgo = new AIForGames::Movement::Wander(m_pBoidObject->GetKinematic(), 100,6.8);
#endif // WANDER_STEERING_01


#ifdef WANDER_STEERING_02
	m_pBoidObject = new AIForGames::GameObject(radius, ofVec3f(500, 500), orientation);
	m_pTarget = new AIForGames::GameObject(-100, -100);
	//Dynamic Wander
	m_pMovementAlgo = new AIForGames::Movement::Wander(m_pBoidObject->GetKinematic(), m_pTarget->GetKinematic(), 500, 120, 50, 200, 50);
#endif // WANDER_STEERING_02


#ifdef FLOCKING
	m_numberOfBoids = 10;
	m_pObjects.reserve(m_numberOfBoids);

	//Fill all boids
	for (int i = 0; i < 10; i++)
	{
		AIForGames::GameObject* temp = new AIForGames::GameObject(radius, ofVec3f(radius, radius), orientation);
		m_pObjects.push_back(temp);
	}
#endif // FLOCKING
}

//--------------------------------------------------------------
void ofApp::update() {

	//m_pBoidObject->Update(m_pMovementAlgo->GetDynamicSteering());

#ifdef BASICMOTION	
	{
		m_pBoidObject->Update(m_pMovementAlgo->GetKinematicSteering());
		if (m_pBoidObject->GetKinematic()->GetPosition().x <= 50 && m_pBoidObject->GetKinematic()->GetPosition().y <= 50)
		{
			m_pTarget->GetKinematic()->SetPosition(ofVec2f(ofGetWidth()-40, m_pBoidObject->GetKinematic()->GetPosition().y));
		}
		else if (m_pBoidObject->GetKinematic()->GetPosition().x > ofGetWidth()-50 && m_pBoidObject->GetKinematic()->GetPosition().y < 50)
		{
			m_pTarget->GetKinematic()->SetPosition(ofVec2f(m_pBoidObject->GetKinematic()->GetPosition().x, ofGetHeight()-40));
		}
		else if (m_pBoidObject->GetKinematic()->GetPosition().x > ofGetWidth() - 50 && m_pBoidObject->GetKinematic()->GetPosition().y > ofGetHeight() - 50)
		{
			m_pTarget->GetKinematic()->SetPosition(ofVec2f(40, m_pBoidObject->GetKinematic()->GetPosition().y));
		}
		else if (m_pBoidObject->GetKinematic()->GetPosition().x < 50 && m_pBoidObject->GetKinematic()->GetPosition().y > ofGetHeight() - 50)
		{
			m_pTarget->GetKinematic()->SetPosition(ofVec2f(40, 40));
		}
	}
#endif // BASICMOTION

#ifdef SEEK_STEERING_01
	//For Kinematic Align
	m_pBoidObject->Update(m_pMovementAlgo->GetKinematicSteering());
#endif // SEEK_STEERING_01

#ifdef SEEK_STEERING_02
	//For Dynamic Align
	m_pBoidObject->Update(m_pMovementAlgo->GetDynamicSteering());
#endif // SEEK_STEERING_02

#ifdef WANDER_STEERING_01
	//For Kinematic Wander
	m_pBoidObject->Update(m_pMovementAlgo->GetKinematicSteering());
#endif // WANDER_STEERING_01

#ifdef WANDER_STEERING_02
	//For Dynamic Wander
	m_pBoidObject->Update(m_pMovementAlgo->GetDynamicSteering());
#endif // WANDER_STEERING_02

}

//--------------------------------------------------------------
void ofApp::draw() {		
	m_pBoidObject->DrawObject();
#ifdef BASICMOTION		
	m_pBoidObject->DrawBreadCrumbs();
#endif // BASICMOTION

#ifdef SEEK_STEERING_01 
	m_pTarget->DrawObject();
#endif // SEEK_STEERING

#ifdef SEEK_STEERING_02 
	m_pTarget->DrawObject();
#endif // SEEK_STEERING

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

#ifdef SEEK_STEERING_01
	if (button == 0)
		m_pTarget->GetKinematic()->SetPosition(ofVec2f(x, y));
	else
		m_pTarget->GetKinematic()->SetPosition(ofVec2f(-300, -300));
#endif // SEEK_STEERING_01

#ifdef SEEK_STEERING_02
	if (button == 0)
		m_pTarget->GetKinematic()->SetPosition(ofVec2f(x, y));
	else
		m_pTarget->GetKinematic()->SetPosition(ofVec2f(-300, -300));
#endif // SEEK_STEERING_02
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
