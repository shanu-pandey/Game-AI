#pragma once
#include "IHeuristics.h"

namespace AIForGames
{
	class EuclidianHeuristics : public IHeuristics
	{
	public:
		int GetEstimate(Node i_start, Node i_end);
	};
}
