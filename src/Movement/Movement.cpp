#include "Movement.h"
#include "../GameObject/GameObject.h"
#include "../ofApp.h"

namespace AIForGames
{
	namespace Movement
	{
		float MovementAlgorithms::CalculateNewOrientation(float i_orientation, ofVec2f i_velocity)
		{
			if (std::sqrt((i_velocity.x * i_velocity.x) + (i_velocity.y * i_velocity.y)) > 0)
				return std::atan2(i_velocity.y, i_velocity.x);

			return i_orientation;

		}

		//KinematicSteeringOutput MovementAlgorithms::BasicMotion(GameObject* i_player, float i_maxSpeed)
		//{
		//	KinematicSteeringOutput output;
		//	output.velocity = ofVec2f(0, 0);
		//	output.rotation = 0;
		//	if (i_player->GetKinematic()->GetPosition().x < ofGetWidth() - i_player->Getradius() * 2 - 10)
		//	{
		//		if (i_player->GetKinematic()->GetVelocity().x < i_maxSpeed)
		//		{
		//			output.velocity.x = i_player->GetKinematic()->GetVelocity().x + 1;
		//		}
		//		else
		//		{
		//			output.velocity.x = i_player->GetKinematic()->GetVelocity().x;
		//		}
		//	}
		//	else if (i_player->GetKinematic()->GetOrientation() < 1.60)
		//	{
		//		output.velocity.x = 0;
		//		output.rotation = i_player->GetKinematic()->GetOrientation() + 0.1;
		//	}
		//	else if (i_player->GetKinematic()->GetPosition().y < ofGetHeight() - i_player->Getradius() * 2 - 10)
		//	{
		//		if (i_player->GetKinematic()->GetVelocity().y < i_maxSpeed)
		//		{
		//			output.velocity.y = i_player->GetKinematic()->GetVelocity().y + 1;
		//		}
		//		else
		//		{
		//			output.velocity.y = i_player->GetKinematic()->GetVelocity().y;
		//		}
		//	}
		//	else if (i_player->GetKinematic()->GetOrientation() < 3.10)
		//	{
		//		output.velocity.y = 0;
		//		output.rotation = i_player->GetKinematic()->GetOrientation() + 0.1;
		//	}
		//	else if (i_player->GetKinematic()->GetPosition().x > 0 + i_player->Getradius() * 2 + 10)
		//	{
		//		if (std::abs(i_player->GetKinematic()->GetVelocity().x) < i_maxSpeed)
		//		{
		//			output.velocity.x = i_player->GetKinematic()->GetVelocity().x - 1;
		//		}
		//		else
		//		{
		//			output.velocity.x = i_player->GetKinematic()->GetVelocity().x;
		//		}
		//	}


		//	/*else if (i_player->GetKinematic()->GetPosition().x >= ofGetWidth() - i_player->Getradius())
		//	{
		//		output.velocity.x = 0;
		//		output.velocity.y = i_player->GetKinematic()->GetVelocity().y + 1;
		//		output.rotation = 90;
		//	}*/

		//	return output;
		//}
	}
}