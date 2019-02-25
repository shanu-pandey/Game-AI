#pragma once
#include "EuclidianHeuristics.h"
#include <math.h>
namespace AIForGames
{
	int EuclidianHeuristics::GetEstimate(Node i_start, Node i_end)
	{
		float distance = (i_start.position.x - i_end.position.x)*(i_start.position.x - i_end.position.x);
		distance += (i_start.position.y - i_end.position.y)*(i_start.position.y - i_end.position.y);
		std::sqrt(distance);
		return distance;
	}
}
