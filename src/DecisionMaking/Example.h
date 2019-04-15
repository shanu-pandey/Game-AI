#pragma once
#include <string>

namespace AIForGames
{
	namespace DecisionMaking
	{
		namespace Learning
		{
			class Example
			{
			public:
				std::string GetAttribute() { return m_Attribute; }
				std::string GetAction() { return m_Action; }
			private:
				std::string m_Action;
				std::string m_Attribute;
			};
		}
	}
}


