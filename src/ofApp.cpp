#include "ofApp.h"
#include "Movement/Arrive.h"
#include "Movement/Wander.h"
#include "Movement/Align.h"
#include "Movement/Seek.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	m_numberOfBoids = 10;
	float orientation = 0;
	float radius = 20;
	ofVec2f position = ofVec3f(radius, radius);
	m_pBoidObject = new AIForGames::GameObject(radius, position, orientation);
	m_pTarget = new AIForGames::GameObject(300, 420);

	//Kinematic Arrive
	//m_pMovementAlgo = new AIForGames::Movement::Arrive(m_pBoidObject->GetKinematic(), m_pTarget->GetKinematic(), 800, 10, 1);

	//Dynamic Arrive
	//m_pMovementAlgo = new AIForGames::Movement::Arrive(m_pBoidObject->GetKinematic(), m_pTarget->GetKinematic(), 800, 200, 20, 5, 1);

	//Kinematic Wander
	//m_pMovementAlgo = new AIForGames::Movement::Wander(m_pBoidObject->GetKinematic(), 300,5.5);

	//Dynamic Wander
	m_pMovementAlgo = new AIForGames::Movement::Wander(m_pBoidObject->GetKinematic(), m_pTarget->GetKinematic(), 300, 20, 100, 100, 10);
	//DynamicAlign
	//m_pMovementAlgo = new AIForGames::Movement::Seek(m_pBoidObject->GetKinematic(), m_pTarget->GetKinematic(), 800);
}

//--------------------------------------------------------------
void ofApp::update() {

	//m_pBoidObject->Update(m_pMovementAlgo->GetKinematicSteering());
	m_pBoidObject->Update(m_pMovementAlgo->GetDynamicSteering());

	//Basic Movement Area
	/*{
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
	}*/
}

//--------------------------------------------------------------
void ofApp::draw() {

	//ofSetRectMode(OF_RECTMODE_CENTER);
	//gui.draw();
	////ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	//ofRotateX(rotationX);
	//ofRotateY(rotationY);
	//
	////ofCircle(-300, 0, 130);
	////ofTriangle(150, 200, 200, 250, 200, 150);
	////m_pBoidObject->DrawObject();

	//
	//ofPushMatrix();
	//ofTranslate(300, 300);
	//ofRotateZ(rotationZ);
	////ofRotateZ(ofGetElapsedTimef() * 30);
	////ofRect(0, 0, 20, 20);
	//ofTriangle(0, -70, -30, 30, 30, 30);
	//ofPopMatrix();

	//To Draw breadcrumbs
	//m_pBoidObject->DrawBreadCrumbs();


	m_pBoidObject->DrawObject();
	m_pTarget->DrawObject();
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
	if (button == 0)
		m_pTarget->GetKinematic()->SetPosition(ofVec2f(x, y));
	else
		m_pTarget->GetKinematic()->SetPosition(ofVec2f(-300, -300));
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
