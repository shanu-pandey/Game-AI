#pragma once
#include "ofVec2f.h"
#include "ofVectorMath.h"

namespace AIForGames
{
	namespace Renderer
	{
		class IRenderer
		{
		public:			
			virtual void Draw() = 0;
			virtual void Draw(float i_x, float i_y) = 0;
			virtual void Draw(float i_x, float i_y, float i_orientation) = 0;
			virtual void Draw(ofVec2f i_position) = 0;
			virtual void Draw(ofVec2f i_position, float i_orientation) = 0;
			virtual void Draw(float i_radius, ofVec2f i_position, float i_rotation) = 0;
		};
	}
}
