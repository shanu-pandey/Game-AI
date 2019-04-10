#pragma once
#include "BehaviorTree.h"


namespace AIForGames
{
	namespace DecisionMaking
	{
		namespace BehaviorTrees
		{
			BehaviorTree::BehaviorTree()
			{

			}

			BehaviorTree::~BehaviorTree()
			{

			}

			Action* BehaviorTree::GetAction()
			{
				return m_pRoot->GetAction();
			}

			ITask* BehaviorTree::GetRoot() const
			{
				return m_pRoot;
			}

			void BehaviorTree::SetRoot(ITask* i_root)
			{
				m_pRoot = i_root;
			}
		}
	}
}