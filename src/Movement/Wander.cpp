#pragma once
#include "Wander.h"
#include "Face.h"
#include "../Physics/Kinematic.h"
#include "../ofApp.h"

namespace AIForGames
{
	namespace Movement
	{
		Wander::Wander(Physics::Kinematic* i_character, float i_maxSpeed, float i_maxRotation)
		{
			m_pInputs = new MovementInputs();
			m_pInputs->source = i_character;			
			m_pInputs->maxSpeed = i_maxSpeed;
			m_pInputs->maxRotation = i_maxRotation;		
			m_pInputs->maxAcceleration = i_maxSpeed;
		}

		Wander::Wander(Physics::Kinematic* i_character, Physics::Kinematic* i_target, float i_maxSpeed, float i_maxAcc, float i_wanderOffset, float i_wanderRadius, float i_wanderRate)
		{
			m_pInputs = new MovementInputs();
			m_pInputs->source = i_character;
			m_pInputs->destination = i_target;
			m_pInputs->maxSpeed = i_maxSpeed;
			m_pInputs->maxAcceleration = i_maxAcc;		
			m_pInputs->wanderOffset = i_wanderOffset;
			m_pInputs->wanderRadius = i_wanderRadius;
			m_pInputs->wanderRate = i_wanderRate;
		}

		Wander::Wander(MovementInputs* i_pInput)
		{
			m_pInputs = new MovementInputs();
			m_pInputs = i_pInput;
		}

		float Wander::CalculateNewOrientation(float i_orientation, ofVec2f i_velocity)
		{
			if (std::sqrt((i_velocity.x * i_velocity.x) + (i_velocity.y * i_velocity.y)) > 0)
				return std::atan2(i_velocity.y, i_velocity.x);

			return i_orientation;
		}

		KinematicSteeringOutput Wander::GetKinematicSteering()
		{
			KinematicSteeringOutput output;
			output.velocity = ofVec2f(0, 0);
			output.rotation = 0;

			//Keep in bounds
			if (m_pInputs->source->GetPosition().x <= 0)
			{
				m_pInputs->source->SetPosition(ofVec2f(ofGetWidth(), m_pInputs->source->GetPosition().y));				
			}
			else if (m_pInputs->source->GetPosition().x >= ofGetWidth())
			{
				m_pInputs->source->SetPosition(ofVec2f(0, m_pInputs->source->GetPosition().y));
			}
			else if (m_pInputs->source->GetPosition().y <= 0)
			{
				m_pInputs->source->SetPosition(ofVec2f(m_pInputs->source->GetPosition().x, ofGetHeight()));
			}
			else if (m_pInputs->source->GetPosition().y >= ofGetHeight())
			{
				m_pInputs->source->SetPosition(ofVec2f(m_pInputs->source->GetPosition().x, 0));
			}

			ofVec2f orientationVector = ofVec2f(std::cos(m_pInputs->source->GetOrientation()), std::sin(m_pInputs->source->GetOrientation()));

			output.velocity = orientationVector * m_pInputs->maxSpeed;
			output.rotation = m_pInputs->maxRotation * (ofRandom(1) - ofRandom(1));

			//m_pInputs->source->SetOrientation(output.rotation);
			return output;
		}

		DynamicSteeringOutput Wander::GetDynamicSteering()
		{
			DynamicSteeringOutput output;
			output.angular = 0;
			output.linear = ofVec2f(0, 0);

			//Keep in bounds
			if (m_pInputs->source->GetPosition().x <= 0)
			{
				m_pInputs->source->SetPosition(ofVec2f(ofGetWidth(), m_pInputs->source->GetPosition().y));
			}
			else if (m_pInputs->source->GetPosition().x >= ofGetWidth())
			{
				m_pInputs->source->SetPosition(ofVec2f(0, m_pInputs->source->GetPosition().y));
			}
			else if (m_pInputs->source->GetPosition().y <= 0)
			{
				m_pInputs->source->SetPosition(ofVec2f(m_pInputs->source->GetPosition().x, ofGetHeight()));
			}
			else if (m_pInputs->source->GetPosition().y >= ofGetHeight())
			{
				m_pInputs->source->SetPosition(ofVec2f(m_pInputs->source->GetPosition().x, 0));
			}

			float wanderOrientation = (ofRandom(1) - ofRandom(1)) * m_pInputs->wanderRate;
			float targetOrientation = wanderOrientation + m_pInputs->source->GetOrientation();
			ofVec2f targetPos = m_pInputs->source->GetPosition() + m_pInputs->wanderOffset * ofVec2f(std::cos(m_pInputs->source->GetOrientation()), std::sin(m_pInputs->source->GetOrientation()));
			targetPos += m_pInputs->wanderRadius*ofVec2f(std::cos(targetOrientation), std::sin(targetOrientation));
			
			Physics::Kinematic* i_newTarget = new Physics::Kinematic(targetPos, targetOrientation);
			m_pInputs->destination = i_newTarget;			
			Face* p_faceSteering = new Face(m_pInputs->source, m_pInputs->destination, 1200, 200, 8, 15, 1);
			output = p_faceSteering->GetDynamicSteering();
			
			output.linear = m_pInputs->maxAcceleration * ofVec2f(std::cos(m_pInputs->source->GetOrientation()), std::sin(m_pInputs->source->GetOrientation()));
			return output;
		}

		void Wander::SetWanderParameters(float i_wanderOffset, float i_wanderRadius, float i_wanderRate)
		{
			m_pInputs->wanderOffset = i_wanderOffset;
			m_pInputs->wanderRadius = i_wanderRadius;
			m_pInputs->wanderRate = i_wanderRate;
		}
	}
}