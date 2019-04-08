#pragma once
#include "../GameObject/GameObject.h"
#include "../DecisionMaking/IDecisionMakingTechnique.h"
#include "../DecisionMaking/ActionManager.h"

namespace AIForGames
{
	class AIController
	{
	public:
		AIController();
		AIController(GameObject* i_owner, AIForGames::DecisionMaking::IDecisionMakingTechnique* i_decision, AIForGames::DecisionMaking::ActionManager* i_ActionManager);
		~AIController();
		GameObject* GetOwner() const;
		void Update();


	private:
		GameObject* m_pOwner;
		AIForGames::DecisionMaking::IDecisionMakingTechnique* m_pDecisionTechnique;
		AIForGames::DecisionMaking::ActionManager* m_pActionManager;
	};

}