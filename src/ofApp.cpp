#include "ofApp.h"
#include "Movement/Arrive.h"
#include "Movement/Wander.h"
#include "Movement/Align.h"
#include "Movement/Seek.h"
#include "Movement/BlendedSteering.h"
#include "Movement/DynamicSeperation.h"
#include "Movement/DynamicVelocityMatch.h"
#include "PathFinding\Dijkstra.h"
#include "PathFinding\A-Star.h"
#include "AI\AIController.h"

#pragma region Assignment 1

//#define BASICMOTION
//#define SEEK_STEERING_01
//#define SEEK_STEERING_02
//#define WANDER_STEERING_01
//#define WANDER_STEERING_02
//#define FLOCKING

# pragma endregion 

#pragma region Assignment 2
//#define DIJKSTRA
//#define ASTARSMALLSAMPLE
//#define ASTARTILEMAP
#pragma endregion

#pragma region Assignment 3
//#define DECISIONTREE
#define BEHAVIORTREE
//#define DECISIONLEARNING
#pragma endregion

//--------------------------------------------------------------


void DrawDijkstraGraph()
{
	float nodeRadius = 3.0f;
	float arrowHeadRadius = 8.0f;
	ofSetColor(0, 0, 0);

	
	ofDrawCircle(ofVec2f(300, 400), nodeRadius);
	ofDrawCircle(ofVec2f(400, 320), nodeRadius);
	ofDrawCircle(ofVec2f(500, 320), nodeRadius);
	ofDrawCircle(ofVec2f(600, 320), nodeRadius);
	ofDrawCircle(ofVec2f(700, 400), nodeRadius);
	ofDrawCircle(ofVec2f(600, 500), nodeRadius);
	ofDrawCircle(ofVec2f(500, 500), nodeRadius);
	ofDrawCircle(ofVec2f(400, 500), nodeRadius);
	ofDrawCircle(ofVec2f(500, 400), nodeRadius);
	
	ofDrawArrow(ofVec3f(300, 400, 0), ofVec3f(400, 320, 0), arrowHeadRadius);
	ofDrawArrow(ofVec3f(400, 320, 0), ofVec3f(500, 320, 0), arrowHeadRadius);
	ofDrawArrow(ofVec3f(500, 320, 0), ofVec3f(600, 320, 0), arrowHeadRadius);
	ofDrawArrow(ofVec3f(600, 320, 0), ofVec3f(700, 400, 0), arrowHeadRadius);
	ofDrawArrow(ofVec3f(700, 400, 0), ofVec3f(600, 500, 0), arrowHeadRadius);
	ofDrawArrow(ofVec3f(600, 500, 0), ofVec3f(500, 500, 0), arrowHeadRadius);
	ofDrawArrow(ofVec3f(500, 500, 0), ofVec3f(400, 500, 0), arrowHeadRadius);
	ofDrawArrow(ofVec3f(500, 400, 0), ofVec3f(400, 500, 0), arrowHeadRadius);
	ofDrawArrow(ofVec3f(500, 320, 0), ofVec3f(500, 400, 0), arrowHeadRadius);
	ofDrawArrow(ofVec3f(500, 400, 0), ofVec3f(500, 500, 0), arrowHeadRadius);
	ofDrawArrow(ofVec3f(600, 500, 0), ofVec3f(500, 320, 0), arrowHeadRadius);
	ofDrawArrow(ofVec3f(600, 320, 0), ofVec3f(600, 500, 0), arrowHeadRadius);
	ofDrawArrow(ofVec3f(400, 320, 0), ofVec3f(400, 500, 0), arrowHeadRadius);
	ofDrawArrow(ofVec3f(400, 500, 0), ofVec3f(300, 400, 0), arrowHeadRadius);

}

void DrawAStarSampleGraph()
{
	float nodeRadius = 3.0f;
	float arrowHeadRadius = 8.0f;
	ofSetColor(0, 0, 0);

	ofDrawCircle(ofVec2f(80, 530), nodeRadius);
	ofDrawCircle(ofVec2f(50, 210), nodeRadius);
	ofDrawCircle(ofVec2f(30, 40), nodeRadius);
	ofDrawCircle(ofVec2f(400, 40), nodeRadius);
	ofDrawCircle(ofVec2f(730, 30), nodeRadius);
	ofDrawCircle(ofVec2f(710, 250), nodeRadius);
	ofDrawCircle(ofVec2f(750, 560), nodeRadius);
	ofDrawCircle(ofVec2f(450, 540), nodeRadius);
	ofDrawCircle(ofVec2f(420, 400), nodeRadius);
	ofDrawCircle(ofVec2f(120, 480), nodeRadius);

	ofDrawArrow(ofVec3f(80, 530, 0), ofVec3f(50, 210, 0), arrowHeadRadius);
	ofDrawArrow(ofVec3f(50, 210, 0), ofVec3f(30, 40, 0), arrowHeadRadius);
	ofDrawArrow(ofVec3f(30, 40, 0), ofVec3f(400, 40, 0), arrowHeadRadius);
	ofDrawArrow(ofVec3f(400, 40, 0), ofVec3f(730, 30, 0), arrowHeadRadius);
	ofDrawArrow(ofVec3f(730, 30, 0), ofVec3f(710, 250, 0), arrowHeadRadius);
	ofDrawArrow(ofVec3f(750, 560, 0), ofVec3f(710, 250, 0), arrowHeadRadius);
	ofDrawArrow(ofVec3f(450, 540, 0), ofVec3f(750, 560, 0), arrowHeadRadius);
	ofDrawArrow(ofVec3f(750, 560, 0), ofVec3f(420, 400, 0), arrowHeadRadius);
	ofDrawArrow(ofVec3f(730, 30, 0), ofVec3f(420, 400, 0), arrowHeadRadius);
	ofDrawArrow(ofVec3f(420, 400, 0), ofVec3f(120, 480, 0), arrowHeadRadius);
	ofDrawArrow(ofVec3f(80, 530, 0), ofVec3f(120, 480, 0), arrowHeadRadius);
	ofDrawArrow(ofVec3f(120, 480, 0), ofVec3f(50, 210, 0), arrowHeadRadius);
	ofDrawArrow(ofVec3f(50, 210, 0), ofVec3f(400, 40, 0), arrowHeadRadius);
	ofDrawArrow(ofVec3f(80, 530, 0), ofVec3f(450, 540, 0), arrowHeadRadius);

}

void ofApp::DrawGameWorld()
{
	for (int i = 0; i < m_noOfWalls; i++)
	{
		ofSetColor(0, 0, 0);
		ofDrawRectangle(m_WallTopLocation[i], m_WallWidth[i], m_WallHeight[i]);
	}
}

void ofApp::InitailizeGameWorld()
{
	m_noOfWalls = 9;
	//Initailize top left of walls
	{
		ofVec2f w1 = ofVec2f(0, 250);
		m_WallTopLocation.emplace_back(w1);
		ofVec2f w2 = ofVec2f(350, 0);
		m_WallTopLocation.emplace_back(w2);
		ofVec2f w3 = ofVec2f(100, 420);
		m_WallTopLocation.emplace_back(w3);
		ofVec2f w4 = ofVec2f(220, 440);
		m_WallTopLocation.emplace_back(w4);
		ofVec2f w5 = ofVec2f(550, 120);
		m_WallTopLocation.emplace_back(w5);
		ofVec2f w6 = ofVec2f(370, 460);
		m_WallTopLocation.emplace_back(w6);
		ofVec2f w7 = ofVec2f(550,600);
		m_WallTopLocation.emplace_back(w7);
		ofVec2f w8 = ofVec2f(750, 240);
		m_WallTopLocation.emplace_back(w8);
		ofVec2f w9 = ofVec2f(820, 520);
		m_WallTopLocation.emplace_back(w9);	
	}
	//Initialize width of walls
	{
		float w1 = 200;
		m_WallWidth.emplace_back(w1);
		float w2 = 40;
		m_WallWidth.emplace_back(w2);
		float w3 = 40;
		m_WallWidth.emplace_back(w3);
		float w4 = 380;
		m_WallWidth.emplace_back(w4);
		float w5 = 30;
		m_WallWidth.emplace_back(w5);
		float w6 = 70;
		m_WallWidth.emplace_back(w6);
		float w7 = 80;
		m_WallWidth.emplace_back(w7);
		float w8 = 320;
		m_WallWidth.emplace_back(w8);
		float w9 = 40;
		m_WallWidth.emplace_back(w9);
	}
	//Initialize height of walls
	{
		float h1 = 50;
		m_WallHeight.emplace_back(h1);
		float h2 = 150;
		m_WallHeight.emplace_back(h2);
		float h3 = 180;
		m_WallHeight.emplace_back(h3);
		float h4 = 40;
		m_WallHeight.emplace_back(h4);
		float h5 = 320;
		m_WallHeight.emplace_back(h5);
		float h6 = 150;
		m_WallHeight.emplace_back(h6);
		float h7 = 190;
		m_WallHeight.emplace_back(h7);
		float h8 = 60;
		m_WallHeight.emplace_back(h8);
		float h9 = 160;
		m_WallHeight.emplace_back(h9);
	}

	m_pTileMap = new AIForGames::PathFinding::TileMap(m_noOfWalls, m_WallTopLocation, m_WallWidth, m_WallHeight);

}

void ofApp::setup()
{
	float orientation = 0;
	float radius = 5;

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
	m_pMovementAlgo = new AIForGames::Movement::Arrive(m_pBoidObject->GetKinematic(), m_pTarget->GetKinematic(), 400, 100, 20, 5, 1);

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
	m_pMovementAlgo = new AIForGames::Movement::Wander(m_pBoidObject->GetKinematic(), m_pTarget->GetKinematic(), 500, 200, 100, 200, 10);
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

	m_pGraph = new AIForGames::PathFinding::Graph();
	std::vector<Node> nodeList;
	
#ifdef DIJKSTRA

	//Create Nodes
	{
		Node n1 = Node(0, ofVec2f(300, 400));
		nodeList.emplace_back(n1);
		Node n2 = Node(1, ofVec2f(400, 320));
		nodeList.emplace_back(n2);
		Node n3 = Node(2, ofVec2f(500, 320));
		nodeList.emplace_back(n3);
		Node n4 = Node(3, ofVec2f(600, 320));
		nodeList.emplace_back(n4);
		Node n5 = Node(4, ofVec2f(700, 400));
		nodeList.emplace_back(n5);
		Node n6 = Node(5, ofVec2f(600, 500));
		nodeList.emplace_back(n6);
		Node n7 = Node(6, ofVec2f(500, 500));
		nodeList.emplace_back(n7);
		Node n8 = Node(7, ofVec2f(400, 500));
		nodeList.emplace_back(n8);
		Node n9 = Node(8, ofVec2f(500, 400));
		nodeList.emplace_back(n9);
	}

	//Create Edges for Graph
	{
		DirectedWeightedEdge* p1 = new DirectedWeightedEdge(4, nodeList[0], nodeList[1]);
		m_pGraph->AddEdge(p1);

		DirectedWeightedEdge* p2 = new DirectedWeightedEdge(8, nodeList[1], nodeList[2]);
		m_pGraph->AddEdge(p2);

		DirectedWeightedEdge* p3 = new DirectedWeightedEdge(17, nodeList[2], nodeList[3]);
		m_pGraph->AddEdge(p3);

		DirectedWeightedEdge* p4 = new DirectedWeightedEdge(9, nodeList[3], nodeList[4]);
		m_pGraph->AddEdge(p4);

		DirectedWeightedEdge* p5 = new DirectedWeightedEdge(10, nodeList[4], nodeList[5]);
		m_pGraph->AddEdge(p5);

		DirectedWeightedEdge* p6 = new DirectedWeightedEdge(2, nodeList[5], nodeList[6]);
		m_pGraph->AddEdge(p6);

		DirectedWeightedEdge* p7 = new DirectedWeightedEdge(1, nodeList[6], nodeList[7]);
		m_pGraph->AddEdge(p7);

		DirectedWeightedEdge* p8 = new DirectedWeightedEdge(7, nodeList[8], nodeList[7]);
		m_pGraph->AddEdge(p8);

		DirectedWeightedEdge* p9 = new DirectedWeightedEdge(2, nodeList[2], nodeList[8]);
		m_pGraph->AddEdge(p9);

		DirectedWeightedEdge* p10 = new DirectedWeightedEdge(6, nodeList[8], nodeList[6]);
		m_pGraph->AddEdge(p10);

		DirectedWeightedEdge* p11 = new DirectedWeightedEdge(4, nodeList[5], nodeList[2]);
		m_pGraph->AddEdge(p11);

		DirectedWeightedEdge* p12 = new DirectedWeightedEdge(24, nodeList[3], nodeList[5]);
		m_pGraph->AddEdge(p12);

		DirectedWeightedEdge* p13 = new DirectedWeightedEdge(11, nodeList[1], nodeList[7]);
		m_pGraph->AddEdge(p13);

		DirectedWeightedEdge* p14 = new DirectedWeightedEdge(8, nodeList[7], nodeList[0]);
		m_pGraph->AddEdge(p14);
	}

	m_pBoidObject->GetKinematic()->SetPosition(ofVec2f(300, 400));
	m_pTarget->SetRadius(4.0f);
	o_path = AIForGames::PathFinding::Dijkstra::FindPath(nodeList[0], nodeList[5], m_pGraph);
#endif 

#ifdef ASTARTILEMAP
	//Create Nodes
	InitailizeGameWorld();
	m_pTarget->SetRadius(6.0f);
	m_pBoidObject->GetKinematic()->SetPosition(ofVec2f(2, 2));
	m_pGraph = m_pTileMap->GetGraph();
	//o_path = AIForGames::PathFinding::AStar::FindPath(Node(5, m_pTileMap->GetTile(5)->GetPosition()), Node(186, m_pTileMap->GetTile(186)->GetPosition()), m_pGraph);
#endif


#ifdef ASTARSMALLSAMPLE
	//Create Nodes
	{
		Node n1 = Node(0, ofVec2f(80, 530));
		nodeList.emplace_back(n1);
		Node n2 = Node(1, ofVec2f(50, 210));
		nodeList.emplace_back(n2);
		Node n3 = Node(2, ofVec2f(30, 40));
		nodeList.emplace_back(n3);
		Node n4 = Node(3, ofVec2f(400, 40));
		nodeList.emplace_back(n4);
		Node n5 = Node(4, ofVec2f(730, 30));
		nodeList.emplace_back(n5);
		Node n6 = Node(5, ofVec2f(710, 250));
		nodeList.emplace_back(n6);
		Node n7 = Node(6, ofVec2f(750, 560));
		nodeList.emplace_back(n7);
		Node n8 = Node(7, ofVec2f(450, 540));
		nodeList.emplace_back(n8);
		Node n9 = Node(8, ofVec2f(420, 400));
		nodeList.emplace_back(n9);
		Node n10 = Node(9, ofVec2f(120, 480));
		nodeList.emplace_back(n9);
	}

	//Create Edges for Graph
	{
		DirectedWeightedEdge* p1 = new DirectedWeightedEdge(45, nodeList[0], nodeList[1]);
		m_pGraph->AddEdge(p1);

		DirectedWeightedEdge* p2 = new DirectedWeightedEdge(20, nodeList[1], nodeList[2]);
		m_pGraph->AddEdge(p2);

		DirectedWeightedEdge* p3 = new DirectedWeightedEdge(47, nodeList[2], nodeList[3]);
		m_pGraph->AddEdge(p3);

		DirectedWeightedEdge* p4 = new DirectedWeightedEdge(42, nodeList[3], nodeList[4]);
		m_pGraph->AddEdge(p4);

		DirectedWeightedEdge* p5 = new DirectedWeightedEdge(31, nodeList[4], nodeList[5]);
		m_pGraph->AddEdge(p5);

		DirectedWeightedEdge* p6 = new DirectedWeightedEdge(44, nodeList[6], nodeList[5]);
		m_pGraph->AddEdge(p6);

		DirectedWeightedEdge* p7 = new DirectedWeightedEdge(39, nodeList[7], nodeList[6]);
		m_pGraph->AddEdge(p7);

		DirectedWeightedEdge* p8 = new DirectedWeightedEdge(50, nodeList[6], nodeList[8]);
		m_pGraph->AddEdge(p8);

		DirectedWeightedEdge* p9 = new DirectedWeightedEdge(67, nodeList[4], nodeList[8]);
		m_pGraph->AddEdge(p9);

		DirectedWeightedEdge* p10 = new DirectedWeightedEdge(49, nodeList[8], nodeList[9]);
		m_pGraph->AddEdge(p10);

		DirectedWeightedEdge* p11 = new DirectedWeightedEdge(12, nodeList[0], nodeList[9]);
		m_pGraph->AddEdge(p11);

		DirectedWeightedEdge* p12 = new DirectedWeightedEdge(45, nodeList[9], nodeList[1]);
		m_pGraph->AddEdge(p12);

		DirectedWeightedEdge* p13 = new DirectedWeightedEdge(55, nodeList[1], nodeList[3]);
		m_pGraph->AddEdge(p13);

		DirectedWeightedEdge* p14 = new DirectedWeightedEdge(52, nodeList[0], nodeList[7]);
		m_pGraph->AddEdge(p14);
	}

	m_pTarget->SetRadius(6.0f);
	m_pBoidObject->GetKinematic()->SetPosition(ofVec2f(80, 530));
	o_path = AIForGames::PathFinding::AStar::FindPath(nodeList[0], nodeList[5], m_pGraph);
#endif

#ifdef DECISIONTREE

	AIForGames::WorldData::WorldManager& m_pWorldManager = AIForGames::WorldData::WorldManager::Get();
	InitailizeGameWorld();
	m_pGraph = m_pTileMap->GetGraph();
	m_pWorldManager.SetWorldMap(m_pTileMap);

	m_pBoidObject = new AIForGames::GameObject(radius, ofVec3f(radius, radius), orientation);
	m_pTarget = new AIForGames::GameObject(-100, -100);
	m_pMovementAlgo = new AIForGames::Movement::Arrive(m_pBoidObject->GetKinematic(), m_pTarget->GetKinematic(), 800, 10, 1);
	m_pWorldManager.RegisterPlayerCharacter(m_pBoidObject);
	
	m_pNPC = new AIForGames::GameObject(radius, ofVec3f(200, 200), orientation);
	m_pNPC->GetAIController()->CreateDecisionTree();

	m_pTarget->GetRenderer()->SetColor(0, 255, 0);
	m_pNPC->GetRenderer()->SetColor(255, 0, 0);

#endif // DECISIONTREE

#ifdef BEHAVIORTREE

	AIForGames::WorldData::WorldManager& m_pWorldManager = AIForGames::WorldData::WorldManager::Get();
	InitailizeGameWorld();
	m_pGraph = m_pTileMap->GetGraph();
	m_pWorldManager.SetWorldMap(m_pTileMap);

	m_pBoidObject = new AIForGames::GameObject(radius, ofVec3f(radius, radius), orientation);
	m_pTarget = new AIForGames::GameObject(-100, -100);
	m_pMovementAlgo = new AIForGames::Movement::Arrive(m_pBoidObject->GetKinematic(), m_pTarget->GetKinematic(), 800, 10, 1);
	m_pWorldManager.RegisterPlayerCharacter(m_pBoidObject);

	m_pNPC = new AIForGames::GameObject(radius, ofVec3f(200, 200), orientation);	
	m_pNPC->GetAIController()->CreateBehaviorTree();

	m_pTarget->GetRenderer()->SetColor(0, 255, 0);
	m_pNPC->GetRenderer()->SetColor(255, 0, 0);

#endif // BEHAVIORTREE

}

//--------------------------------------------------------------
void ofApp::update() {

	//m_pBoidObject->Update(m_pMovementAlgo->GetDynamicSteering());

#ifdef DIJKSTRA
	   m_pBoidObject->Update(m_pMovementAlgo->GeneratePath(o_path));
#endif 

#ifdef ASTARSMALLSAMPLE
	   m_pBoidObject->Update(m_pMovementAlgo->GeneratePath(o_path));
#endif 

#ifdef ASTARTILEMAP	  
		   m_pBoidObject->Update(m_pMovementAlgo->GeneratePath(o_path));
#endif


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
	//m_pBoidObject->Update(m_pMovementAlgo->GetDynamicSteering());
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
		AIForGames::Movement::IMovementAlgorithm* m_pMovementAlgo1 = new AIForGames::Movement::DynamicSeparation(m_pObjects[i]->GetKinematic(), allKinematics, 100, 9000.0f, 1200);
		AIForGames::Movement::IMovementAlgorithm* m_pMovementAlgo2 = new AIForGames::Movement::DynamicVelocityMatch(m_pObjects[i]->GetKinematic(), matchKinematic, 1000, 1);
		AIForGames::Movement::IMovementAlgorithm* m_pMovementAlgo3 = new AIForGames::Movement::Seek(m_pObjects[i]->GetKinematic(), matchKinematic, 200);
		AIForGames::Movement::IMovementAlgorithm* m_pMovementAlgo4 = new AIForGames::Movement::Align(m_pObjects[i]->GetKinematic(), matchKinematic, 3, 20, 20, 5, 2);

		std::vector<BehaviorAndWeight*> behaviorAndWeight;
		BehaviorAndWeight* b1 = new BehaviorAndWeight();
		b1->p_behavior = m_pMovementAlgo1;
		b1->weight = 0.9;
		behaviorAndWeight.push_back(b1);

		BehaviorAndWeight* b2 = new BehaviorAndWeight();
		b2->p_behavior = m_pMovementAlgo2;
		b2->weight = 0.2;
		behaviorAndWeight.push_back(b2);

		BehaviorAndWeight* b3 = new BehaviorAndWeight();
		b3->p_behavior = m_pMovementAlgo3;
		b3->weight = 0.1;
		behaviorAndWeight.push_back(b3);


		BehaviorAndWeight* b4 = new BehaviorAndWeight();
		b4->p_behavior = m_pMovementAlgo4;
		b4->weight = 0.3;
		behaviorAndWeight.push_back(b4);

		AIForGames::Movement::IMovementAlgorithm* m_pMovementAlgoBlended = new AIForGames::Movement::BlendedSteering(behaviorAndWeight, 200, 5);
		m_pBlendedMovement.push_back(m_pMovementAlgoBlended);
	}


	for (int i = 0; i < 10; i++)
	{
		m_pObjects[i]->Update(m_pBlendedMovement[i]->GetDynamicSteering());
	}
#endif // FLOCKING

#ifdef DECISIONTREE
	//For Dynamic Align
	m_pBoidObject->Update(m_pMovementAlgo->GetKinematicSteering());
	//m_pTarget->Update();
	m_pNPC->Update();
#endif // DECISIONTREE


#ifdef BEHAVIORTREE
	//For Dynamic Align
	//m_pBoidObject->Update(m_pMovementAlgo->GetKinematicSteering());
	//m_pTarget->Update();
	m_pNPC->Update();
	//m_pBoidObject->Update(m_pMovementAlgo->GeneratePath(o_path));
#endif // BEHAVIORTREE
}

//--------------------------------------------------------------
void ofApp::draw() {
	
#ifdef DIJKSTRA	
	DrawDijkstraGraph();
#endif

#ifdef ASTARSMALLSAMPLE
	DrawAStarSampleGraph();
#endif

#ifdef ASTARTILEMAP	
	DrawGameWorld();
#endif


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
	m_pBoidObject->DrawBreadCrumbs();	
	//m_pTarget->DrawObject();
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

#ifdef DECISIONTREE	
	m_pBoidObject->DrawObject();
	m_pNPC->DrawObject();
	m_pTarget->DrawObject();
#endif // DECISIONTREE

#ifdef BEHAVIORTREE	
	DrawGameWorld();
	DrawGameWorld();
	m_pBoidObject->DrawObject();
	m_pNPC->DrawObject();
	m_pTarget->DrawObject();
#endif // BEHAVIORTREE
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

#ifdef DECISIONTREE
	if (button == 0)
		m_pTarget->GetKinematic()->SetPosition(ofVec2f(x, y));
	else
		m_pTarget->GetKinematic()->SetPosition(ofVec2f(-300, -300));
#endif // DECISIONTREE

#ifdef SEEK_STEERING_02
	if (button == 0)
		m_pTarget->GetKinematic()->SetPosition(ofVec2f(x, y));
	else
		m_pTarget->GetKinematic()->SetPosition(ofVec2f(-300, -300));
#endif // SEEK_STEERING_02

#ifdef ASTARTILEMAP	
	if (button == 0)
	{
		m_pBoidObject->Stop();
		o_path.clear();
		AIForGames::PathFinding::Tile* t1 = m_pTileMap->GetTile(m_pBoidObject->GetKinematic()->GetPosition());
		Node n1 = Node(t1->GetIndex(), t1->GetPosition());

		AIForGames::PathFinding::Tile* t2 = m_pTileMap->GetTile(ofVec2f(x, y));
		Node n2 = Node(t2->GetIndex(), t2->GetPosition());		
		
		m_pTarget->GetKinematic()->SetPosition(ofVec2f(x, y));
		o_path = AIForGames::PathFinding::AStar::FindPath(n1, n2, m_pGraph);		
	}
		
	else
	{
		o_path.clear();
		m_pBoidObject->Stop();
	}
		
	
#endif
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
