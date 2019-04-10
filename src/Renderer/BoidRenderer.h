#pragma once

#pragma once

#include "IRenderer.h"

namespace AIForGames
{
	namespace Renderer
	{
		class BoidRenderer : public IRenderer
		{
		public:
			BoidRenderer() : IRenderer() {}			
			void Draw();
			void Draw(float i_x, float i_y);
			void Draw(float i_x, float i_y, float i_rotation);
			void Draw(ofVec2f i_position);
			void Draw(ofVec2f i_position, float i_rotation);
			void Draw(float i_radius, ofVec2f i_position, float i_rotation);
			void SetColor(float i_R, float i_G, float i_B);

		private:
			void DrawBoidHead(float i_radius, ofVec2f i_position, float i_orientation);

		};
	}
}