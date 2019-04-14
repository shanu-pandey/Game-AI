#pragma once
#include "ofVec2f.h"
#include "Physics/Kinematic.h"

//Forward Declaration
//namespace AIForGames
//{
//	namespace Physics
//	{
//		class Kinematic;
//	}
//}

namespace AIForGames
{
	namespace Movement
	{
		class IMovementAlgorithm;
	}
}

struct BehaviorAndWeight
{
	AIForGames::Movement::IMovementAlgorithm* p_behavior;
	float weight;

	BehaviorAndWeight()
	{
		p_behavior = nullptr;
		weight = 0;
	}
};

struct MovementInputs
{
	AIForGames::Physics::Kinematic* source;
	AIForGames::Physics::Kinematic* destination;
	float maxSpeed;
	float maxRotation;
	float maxAcceleration;
	float maxAngularAcceleration;
	float timeToTarget;
	float slowRadius;
	float targetRadius;		//threshold for separation
	float slowAngleThreshold;
	float targetAngleThreshold;
	float wanderOffset;
	float wanderRadius;
	float wanderRate;


	MovementInputs()
	{
		source = new AIForGames::Physics::Kinematic();
		destination = new AIForGames::Physics::Kinematic();
		maxSpeed = 0;
		maxRotation = 0;
		maxAcceleration = 0;
		maxAngularAcceleration = 0;
		timeToTarget = 0;
		slowRadius = 0;
		targetRadius = 0;
		wanderOffset = 0;
		wanderRadius = 0;
		wanderRate = 0;	
	}
};

struct KinematicSteeringOutput
{
	ofVec2f velocity;
	float rotation;
};

struct DynamicSteeringOutput
{
	ofVec2f linear;
	float angular;
};

struct Node
{
	int index;
	ofVec2f position;

	Node()
	{
		index = 0;
		position = ofVec2f(0, 0);
	}

	Node(int i_index, ofVec2f i_pos)
	{
		index = i_index;
		position = i_pos;
	}
	
	inline bool operator==(Node i_Node) 
	{		
		if (this->index == i_Node.index && this->position == i_Node.position)
			return true;
		else
			return false;
	}
};

struct DirectedWeightedEdge
{
	float cost;
	Node source;
	Node sink;

	DirectedWeightedEdge()
	{
		cost = 0;
		source = Node();
		sink = Node();
	}

	DirectedWeightedEdge(float i_cost, Node i_source, Node i_sink)
	{
		cost = i_cost;
		source = i_source;
		sink = i_sink;
	}

	inline bool operator==(DirectedWeightedEdge i_Edge) 
	{
		if (this->source == i_Edge.source && this->sink == i_Edge.sink)
			return true;
		else
			return false;
	}
};

struct NodeRecord
{
	Node node;
	DirectedWeightedEdge incomingEdge;
	float costSoFar;
	float estimatedTotalCost;

	NodeRecord()		
	{
		node = Node();
		costSoFar = 0.0f;
		estimatedTotalCost = 0.0f;
	}

	NodeRecord(Node i_node, DirectedWeightedEdge i_edge, float i_cost, float i_totalCost) :
		node(i_node),
		incomingEdge(i_edge),
		costSoFar(i_cost),
		estimatedTotalCost(i_totalCost)
	{

	}

	inline bool operator==(NodeRecord i_record)
	{
		if (this->node == i_record.node && this->incomingEdge == i_record.incomingEdge)
			return true;
		else
			return false;
	}
};

enum BTStatus
{
	SUCCESS,
	FAILURE,
	RUNNING,
	FAILED,
};