#pragma once
#include "Seek.h"
#include "../Physics/Kinematic.h"
#include "../WorldData/WorldManager.h"
#include "../PathFinding/A-Star.h"

namespace AIForGames
{
	namespace Movement
	{
		Seek::Seek(Physics::Kinematic* i_character, Physics::Kinematic* i_target, float i_maxSpeed)
		{
			m_pInputs = new MovementInputs();
			m_pInputs->source = i_character;
			m_pInputs->destination = i_target;
			m_pInputs->maxSpeed = i_maxSpeed;		
			m_pSourceBody = i_character;
			m_pDestinationBody = i_target;
		}

		Seek::Seek(MovementInputs* i_pInput)
		{
			m_pInputs = new MovementInputs();
			m_pInputs = i_pInput;
		}

		float Seek::CalculateNewOrientation(float i_orientation, ofVec2f i_velocity)
		{
			if (std::sqrt((i_velocity.x * i_velocity.x) + (i_velocity.y * i_velocity.y)) > 0)
				return std::atan2(i_velocity.y, i_velocity.x);

			return i_orientation;
		}

		KinematicSteeringOutput Seek::GetKinematicSteering()
		{
			KinematicSteeringOutput output;
			output.velocity = ofVec2f(0, 0);
			output.rotation = 0;

			if (m_pInputs->destination->GetPosition().x < -50)
				return output;

			output.velocity = m_pInputs->destination->GetPosition() - m_pInputs->source->GetPosition();
			output.velocity.normalize();
			output.velocity *= m_pInputs->maxSpeed;
			
			m_pInputs->source->SetOrientation(CalculateNewOrientation(m_pInputs->source->GetOrientation(), output.velocity));
			return output;
		}

		DynamicSteeringOutput Seek::GetDynamicSteering()
		{
			DynamicSteeringOutput output;
			output.angular = 0;
			output.linear = ofVec2f(0, 0);

			if (m_pInputs->destination->GetPosition().x < -50)
				return output;

			output.linear = m_pInputs->destination->GetPosition() - m_pInputs->source->GetPosition();
			output.linear.normalize();
			output.linear *= m_pInputs->maxSpeed;			

			//output.angular = CalculateNewOrientation(m_pInputs->source->GetOrientation(), output.linear);
			//m_pInputs->source->SetOrientation(CalculateNewOrientation(m_pInputs->source->GetOrientation(), output.linear));

			return output;
		}
		
		DynamicSteeringOutput Seek::GeneratePath(std::list<DirectedWeightedEdge>& i_path)
		{
			DynamicSteeringOutput output;
			output.angular = 0;
			output.linear = ofVec2f(0, 0);

			AIForGames::WorldData::WorldManager& m_pWorldManager = AIForGames::WorldData::WorldManager::Get();

			AIForGames::PathFinding::Tile* t1 = m_pWorldManager.GetWorldMap()->GetTile(m_pSourceBody->GetPosition());
			n1 = Node(t1->GetIndex(), t1->GetPosition());

			if (m_pDestinationBody->GetPosition() != n2.position)
			{
				AIForGames::PathFinding::Tile* t2 = m_pWorldManager.GetWorldMap()->GetTile(m_pDestinationBody->GetPosition());
				n2 = Node(t2->GetIndex(), t2->GetPosition());
				o_path.clear();
				o_path = AIForGames::PathFinding::AStar::FindPath(n1, n2, m_pWorldManager.GetWorldMap()->GetGraph());
			}

			if (o_path.size() > 0)
			{
				DirectedWeightedEdge top = o_path.front();
				output.linear = top.sink.position - m_pInputs->source->GetPosition();
				output.linear.normalize();
				output.linear *= m_pInputs->maxSpeed;
				if (output.linear == ofVec2f(0, 0) && o_path.size() > 1)
				{
					o_path.pop_front();
				}
			}
			else
			{
				output = GetDynamicSteering();
			}
			return output;
		}
	}
}