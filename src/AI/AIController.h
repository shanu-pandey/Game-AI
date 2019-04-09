#pragma once
#include "../GameObject/GameObject.h"
#include "../DecisionMaking/IDecisionMakingTechnique.h"
#include "../DecisionMaking/ActionManager.h"
#include "../WorldData/WorldManager.h"

namespace AIForGames
{
	class AIController
	{
	public:
		AIController();
		AIController(GameObject* i_owner);
		AIController(GameObject* i_owner, AIForGames::DecisionMaking::IDecisionMakingTechnique* i_decision, AIForGames::DecisionMaking::ActionManager* i_ActionManager);
		~AIController();
		void CreateDecisionTree();
		void CreateBehaviorTree();
		void DecisionTreeLearning();
		GameObject* GetOwner() const;
		void SetDecisionTechniques(AIForGames::DecisionMaking::IDecisionMakingTechnique* i_decision);
		void Update(float i_dt);

	private:
		
		GameObject* m_pOwner;
		AIForGames::DecisionMaking::IDecisionMakingTechnique* m_pDecisionTechnique;
		AIForGames::DecisionMaking::ActionManager* m_pActionManager;
		//AIForGames::WorldData::WorldManager pWorldManager;
	};

}