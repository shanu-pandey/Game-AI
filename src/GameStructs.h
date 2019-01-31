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
	float targetRadius;
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

