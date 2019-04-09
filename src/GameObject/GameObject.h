#pragma once
#include "../Renderer/BoidRenderer.h"
#include "../Physics/Kinematic.h"
#include "../Renderer/TargetRenderer.h"
//#include "../AI/AIController.h"

#include <list>

using namespace std;

namespace AIForGames
{
	//forward Declaration
	class AIController;

	class GameObject
	{
	public:
		GameObject();
		GameObject(float i_x, float i_y);
		GameObject(ofVec2f i_position);
		GameObject(float i_x, float i_y, float orientation);
		GameObject(ofVec2f i_position, float i_orientation);
		GameObject(float i_radius, ofVec2f i_position, float i_orientation);
		GameObject(ofVec2f i_position, ofVec2f i_velocity, float i_orientation, float i_rotation);
		~GameObject();
		Renderer::IRenderer* GetRenderer();
		void SetRenderer(Renderer::IRenderer* i_renderer);
		void SetController(AIController* i_AI);
		Physics::Kinematic* GetKinematic();
		float Getradius();
		void SetRadius(float i_radius);
		void SetKinematic(Physics::Kinematic* i_kinematic);
		void DrawObject();
		void DrawBreadCrumbs();
		void AddBreadCrumb(ofVec2f i_position);
		void Update(KinematicSteeringOutput i_steering);
		void Update(DynamicSteeringOutput i_steering);
		void Stop();
	private:
		int counter = 0;
		std::list<ofVec2f> breadCrumbs;
		float m_radius = 10;
		//Renderer::BoidRenderer* m_pBoid;		
		Renderer::IRenderer* m_pBoid;
		Physics::Kinematic* m_pKinematic;
		AIController* m_pAIController;
	};
}