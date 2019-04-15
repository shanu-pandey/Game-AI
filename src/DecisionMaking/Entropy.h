#pragma once
#include "Example.h"
#include <vector>
#include <functional>
#include "IDecisionTreeNode.h"
#include "DecisionNode.h"
#include "ActionNode.h"
#include <map>
namespace AIForGames
{
	namespace DecisionMaking
	{
		namespace Learning
		{
			class Entropy
			{
			public:
				float GetEntropy(std::vector<Example*> i_Examples);
				std::vector<std::vector<Example*>> SplitByAttribute(std::vector<Example*> i_Examples, std::string i_Attribute);
				float GetEntropyOfSets(std::vector<std::vector<Example*>> i_Sets, size_t i_ExampleCount);
				void MakeDecisionTree(std::vector<Example*> i_Examples, std::vector<std::string> i_Attributes, DecisionNode* i_RootNode);
				DecisionNode* GetDecision(std::string i_Decision) { return m_DecisionNodes[i_Decision]; }
				ActionNode* GetAction(std::string i_Decision) { return m_ActionNodes[i_Decision]; }				
			private:
				std::map<std::string, DecisionNode*> m_DecisionNodes;
				std::map<std::string, ActionNode*> m_ActionNodes;
			};
		}
	}
}