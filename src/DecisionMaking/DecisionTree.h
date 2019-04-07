#pragma once
#include "IDecisionMakingTechnique.h"
#include "IDecisionTreeNode.h"

namespace AIForGames
{
	namespace DecisionMaking
	{
		class DecisionTree : public IDecisionMakingTechnique
		{
		public:
			DecisionTree();
			DecisionTree(IDecisionTreeNode* i_root);
			~DecisionTree();
			virtual Action* GetAction() override;
			IDecisionTreeNode* GetRoot() const;
			void SetRoot(IDecisionTreeNode* i_root);

		private:
			IDecisionTreeNode * m_pRoot;
		};
	}
}
