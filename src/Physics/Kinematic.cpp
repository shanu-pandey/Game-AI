#pragma once
#include "Kinematic.h"
#include "ofTimer.h"
#include "../ofApp.h"
#include "../GameStructs.h"

namespace AIForGames
{
	Physics::Kinematic::Kinematic()
	{
		m_position = ofVec2f(0, 0);
		m_orientation = 0;
		m_velocity = ofVec2f(0, 0);
		m_rotation = 0;
	}

	Physics::Kinematic::Kinematic(float i_x, float i_y)
	{
		m_position = ofVec2f(i_x, i_y);
		m_orientation = 0;
		m_velocity = ofVec2f(0, 0);
		m_rotation = 0;
	}

	Physics::Kinematic::Kinematic(ofVec2f i_position)
	{
		m_position = i_position;
		m_orientation = 0;
		m_velocity = ofVec2f(0, 0);
		m_rotation = 0;
	}

	Physics::Kinematic::Kinematic(float i_x, float i_y, float i_orientation)
	{
		m_position = ofVec2f(i_x, i_y);
		m_orientation = i_orientation;
		m_velocity = ofVec2f(0, 0);
		m_rotation = 0;
	}

	Physics::Kinematic::Kinematic(ofVec2f i_position, float i_orientation)
	{
		m_position = i_position;
		m_orientation = i_orientation;
		m_velocity = ofVec2f(0, 0);
		m_rotation = 0;
	}

	Physics::Kinematic::Kinematic(float i_x, float i_y, float i_orientation, float i_velX, float i_velY)
	{
		m_position = ofVec2f(i_x, i_y);
		m_orientation = i_orientation;
		m_velocity = ofVec2f(i_velX, i_velY);
		m_rotation = 0;
	}

	Physics::Kinematic::Kinematic(ofVec2f i_position, ofVec2f i_velocity, float i_orientation)
	{
		m_position = i_position;
		m_orientation = i_orientation;
		m_velocity = i_velocity;
		m_rotation = 0;
	}

	Physics::Kinematic::Kinematic(float i_x, float i_y, float i_orientation, float i_velX, float i_velY, float i_rotation)
	{
		m_position = ofVec2f(i_x, i_y);
		m_orientation = i_orientation;
		m_velocity = ofVec2f(i_velX, i_velY);
		m_rotation = i_rotation;
	}

	Physics::Kinematic::Kinematic(ofVec2f i_position, ofVec2f i_velocity, float i_orientation, float i_rotation)
	{
		m_position = i_position;
		m_orientation = i_orientation;
		m_velocity = i_velocity;
		m_rotation = i_rotation;
	}

	ofVec2f Physics::Kinematic::GetPosition()
	{
		return m_position;
	}

	void Physics::Kinematic::SetPosition(ofVec2f i_position)
	{
		m_position = i_position;
	}

	float Physics::Kinematic::GetOrientation()
	{
		return m_orientation;
	}

	void Physics::Kinematic::SetOrientation(float i_orientation)
	{
		m_orientation = i_orientation;
	}

	ofVec2f Physics::Kinematic::GetVelocity()
	{
		return m_velocity;
	}

	void Physics::Kinematic::SetVelocity(ofVec2f i_velocity)
	{
		m_velocity = i_velocity;
	}

	float Physics::Kinematic::GetRotation()
	{
		return m_rotation;
	}

	void Physics::Kinematic::SetRotation(float i_rotation)
	{
		m_rotation = i_rotation;
	}

	Physics::Kinematic::~Kinematic()
	{

	}

	void Physics::Kinematic::Update(KinematicSteeringOutput i_steering)
	{
		m_position.x += m_velocity.x * ofGetLastFrameTime() ;
		m_position.y += m_velocity.y * ofGetLastFrameTime();
		m_orientation += i_steering.rotation * ofGetLastFrameTime();
		m_velocity = i_steering.velocity;

	}

	void Physics::Kinematic::Update(DynamicSteeringOutput i_steering)
	{
		m_position.x += m_velocity.x * ofGetLastFrameTime();
		m_position.y += m_velocity.y * ofGetLastFrameTime();
		m_orientation += i_steering.angular * ofGetLastFrameTime();
		m_velocity = i_steering.linear;
	}
}














































