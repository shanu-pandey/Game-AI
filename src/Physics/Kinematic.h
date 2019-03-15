#pragma once
#include "ofVec2f.h"
//#include "../Movement/IMovementAlgorithm.h"


struct KinematicSteeringOutput;
struct DynamicSteeringOutput;

namespace AIForGames
{
	namespace Physics
	{
		class Kinematic
		{
		public:
			Kinematic();
			Kinematic(float i_x, float i_y);
			Kinematic(ofVec2f i_position);
			Kinematic(float i_x, float i_y, float i_orientation);
			Kinematic(ofVec2f i_position, float i_orientation);
			Kinematic(float i_x, float i_y, float i_orientation, float i_velX, float i_velY);
			Kinematic(ofVec2f i_position, ofVec2f i_velocity, float i_orientation);
			Kinematic(float i_x, float i_y, float i_orientation, float i_velX, float i_velY, float i_rotation);
			Kinematic(ofVec2f i_position, ofVec2f i_velocity, float i_orientation, float i_rotation);
			~Kinematic();
			ofVec2f GetPosition();
			void SetPosition(ofVec2f i_position);
			float GetOrientation();
			void SetOrientation(float i_orientation);
			ofVec2f GetVelocity();
			void SetVelocity(ofVec2f i_velocity);
			float GetRotation();
			void SetRotation(float i_rotation);
			void Stop();
			void Update(KinematicSteeringOutput i_steering);
			void Update(DynamicSteeringOutput i_steering);

		private:
			ofVec2f m_position;
			float m_orientation;
			ofVec2f m_velocity;
			float m_rotation;
		};
	}
}