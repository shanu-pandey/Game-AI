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
				m_pBlackBoard = new Blackboard();
			}

			BehaviorTree::~BehaviorTree()
			{

			}

			Action* BehaviorTree::GetAction()
			{
				return m_pBlackBoard->GetAction("ActiveAction", m_id, m_pRoot->ID());				
			}

			ITask* BehaviorTree::GetRoot() const
			{
				return m_pRoot;
			}

			void BehaviorTree::SetRoot(ITask* i_root)
			{
				m_pRoot = i_root;
			}

			void BehaviorTree::Update()
			{
				m_pRoot->Run();
			}
		}
	}
}