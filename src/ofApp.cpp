#include "ofApp.h"
#include "Movement/Arrive.h"
#include "Movement/Wander.h"
#include "Movement/Align.h"
#include "Movement/Seek.h"
#include "Movement/BlendedSteering.h"
#include "Movement/DynamicSeperation.h"
#include "Movement/DynamicVelocityMatch.h"



//#define BASICMOTION
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
	m_pMovementAlgo = new AIForGames::Movement::Wander(m_pBoidObject->GetKinematic(), m_pTarget->GetKinematic(), 500, 120, 10, 200, 1);
#endif // WANDER_STEERING_02


#ifdef FLOCKING
	
	m_numberOfBoids = 10;
	m_pObjects.reserve(m_numberOfBoids);
	allKinematics.reserve(m_numberOfBoids);
	m_pBlendedMovement.reserve(m_numberOfBoids);
	matchKinematic = new AIForGames::Physics::Kinematic();
	//Fill all boids
	for (int i = 0; i < 10; i++)
	{
		AIForGames::GameObject* temp = new AIForGames::GameObject(radius, ofVec3f(300+ofRandom(20), 400+ofRandom(30)), ofRandom(1));
		m_pObjects.push_back(temp);
		allKinematics.push_back(temp->GetKinematic());
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

#ifdef FLOCKING
	float centerX = 0;
	float centerY = 0;
	float sumX = 0;
	float sumY = 0;
	float velX = 0;
	float velY = 0;
	float sumVelX = 0;
	float sumVelY = 0;
	
	//calculate center of mass and velocity to match
	for (int i = 0; i < 10; i++)
	{		
		sumX += m_pObjects[i]->GetKinematic()->GetPosition().x;
		sumY += m_pObjects[i]->GetKinematic()->GetPosition().y;
		sumVelX += m_pObjects[i]->GetKinematic()->GetVelocity().x;
		sumVelY += m_pObjects[i]->GetKinematic()->GetVelocity().y;
	}
	velX = sumVelX / 10;
	velY = sumVelY / 10;
	sumX = sumX / 10;
	sumY = sumY / 10;
	matchKinematic->SetPosition(ofVec2f(sumX, sumY));
	matchKinematic->SetVelocity(ofVec2f(sumVelX, sumVelY));
	//Iterate through boids
	for (int i = 0; i < 10; i++)
	{
		AIForGames::Movement::IMovementAlgorithm* m_pMovementAlgo1 = new AIForGames::Movement::DynamicSeparation(m_pObjects[i]->GetKinematic(), allKinematics, 200, -5000.0f, 1200);
		AIForGames::Movement::IMovementAlgorithm* m_pMovementAlgo2 = new AIForGames::Movement::DynamicVelocityMatch(m_pObjects[i]->GetKinematic(), matchKinematic, 1000, 0.3);
		AIForGames::Movement::IMovementAlgorithm* m_pMovementAlgo3 = new AIForGames::Movement::Seek(m_pObjects[i]->GetKinematic(), matchKinematic, 1500);
		AIForGames::Movement::IMovementAlgorithm* m_pMovementAlgo4 = new AIForGames::Movement::Align(m_pObjects[i]->GetKinematic(), matchKinematic, 3, 20, 20, 5, 2);

		std::vector<BehaviorAndWeight*> behaviorAndWeight;
		BehaviorAndWeight* b1 = new BehaviorAndWeight();
		b1->p_behavior = m_pMovementAlgo1;
		b1->weight = 0.9;
		behaviorAndWeight.push_back(b1);

		BehaviorAndWeight* b2 = new BehaviorAndWeight();
		b2->p_behavior = m_pMovementAlgo2;
		b2->weight = 0.4;
		behaviorAndWeight.push_back(b2);

		BehaviorAndWeight* b3 = new BehaviorAndWeight();
		b3->p_behavior = m_pMovementAlgo3;
		b3->weight = 0.05;
		behaviorAndWeight.push_back(b3);


		BehaviorAndWeight* b4 = new BehaviorAndWeight();
		b4->p_behavior = m_pMovementAlgo4;
		b4->weight = 0.6;
		behaviorAndWeight.push_back(b4);

		AIForGames::Movement::IMovementAlgorithm* m_pMovementAlgoBlended = new AIForGames::Movement::BlendedSteering(behaviorAndWeight, 200, 5);
		m_pBlendedMovement.push_back(m_pMovementAlgoBlended);
	}


	for (int i = 0; i < 10; i++)
	{
		m_pObjects[i]->Update(m_pBlendedMovement[i]->GetDynamicSteering());
	}
#endif // FLOCKING

}

//--------------------------------------------------------------
void ofApp::draw() {		
	
#ifdef BASICMOTION	
	m_pBoidObject->DrawObject();
	m_pBoidObject->DrawBreadCrumbs();
#endif // BASICMOTION

#ifdef SEEK_STEERING_01 
	m_pBoidObject->DrawObject();
	m_pTarget->DrawObject();
#endif // SEEK_STEERING

#ifdef SEEK_STEERING_02 
	m_pBoidObject->DrawObject();
	m_pBoidObject->DrawObject();
	m_pTarget->DrawObject();
#endif // SEEK_STEERING

#ifdef WANDER_STEERING_01	
	m_pBoidObject->DrawObject();
#endif // WANDER_STEERING_01

#ifdef WANDER_STEERING_02	
	m_pBoidObject->DrawObject();
#endif // WANDER_STEERING_02

#ifdef FLOCKING
	for (int i = 0; i < 10; i++)
	{
		m_pObjects[i]->DrawObject();
	}
#endif // FLOCKING
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
