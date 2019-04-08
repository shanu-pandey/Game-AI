#pragma once
#include "DecisionTree.h"
#include "ActionNode.h"

namespace AIForGames
{
	namespace DecisionMaking
	{
		DecisionTree::DecisionTree()
		{
			
		}

		DecisionTree::DecisionTree(IDecisionTreeNode* i_root)
		{
			m_pRoot = i_root;
		}

		DecisionTree::~DecisionTree()
		{

		}
		
		IDecisionTreeNode* DecisionTree::GetRoot() const
		{
			return m_pRoot;
		}

		void DecisionTree::SetRoot(IDecisionTreeNode* i_root)
		{
			m_pRoot = i_root;
		}

		Action* DecisionTree::GetAction()
		{
			ActionNode* p_ActionNode = dynamic_cast<ActionNode*>(m_pRoot->MakeDecision());

			if (p_ActionNode)
			{
				Action* p_Action = p_ActionNode->GetAction();
				if (p_Action)
					return p_Action;
				else
					return nullptr;
			}
			else
				return nullptr;
		}
	}
}
