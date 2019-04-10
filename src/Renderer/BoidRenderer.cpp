#include "../ofApp.h"
#include "BoidRenderer.h"

namespace AIForGames
{
	void Renderer::BoidRenderer::SetColor(float i_R, float i_G, float i_B)
	{
		R = i_R;
		G = i_G;
		B = i_B;
	}

	void Renderer::BoidRenderer::Draw()
	{
		ofSetColor(R, G, B);	
		ofDrawCircle(0,0, 10);
		DrawBoidHead(10, ofVec2f(0, 0), 0);
	}		
	
	void Renderer::BoidRenderer::Draw(float i_x, float i_y)
	{
		ofSetColor(R, G, B);
		ofDrawCircle(i_x, i_y, 10);
		DrawBoidHead(10, ofVec2f(i_x, i_y), 0);
	}

	void Renderer::BoidRenderer::Draw(float i_x, float i_y, float i_orientation)
	{
		ofSetColor(R, G, B);
		ofDrawCircle(i_x, i_y, 10);
		DrawBoidHead(10, ofVec2f(i_x, i_y), i_orientation);
	}

	void Renderer::BoidRenderer::Draw(ofVec2f i_position)
	{
		ofSetColor(R, G, B);	
		ofDrawCircle(i_position, 10);
		DrawBoidHead(10, i_position, 0);
		
	

		//ofSetRectMode(OF_RECTMODE_CENTER);
		//ofPushMatrix();
		//ofTranslate(200, 200);// , 0);//move pivot to centre
		//ofRotate(ofGetFrameNum() * 1, 0,0, 1);//rotate from centre
		//ofPushMatrix();
		//ofDrawTriangle(150,200,200,150,250,200);
		//
		//ofPopMatrix();
		//ofPopMatrix();
	}

	void Renderer::BoidRenderer::Draw(ofVec2f i_position, float i_orientation)
	{
		ofSetColor(R, G, B);
		ofDrawCircle(i_position, 10);
		DrawBoidHead(10, i_position, i_orientation);
		
	}

	void Renderer::BoidRenderer::Draw(float i_radius, ofVec2f i_position, float i_orientation)
	{
		ofSetColor(R, G, B);
		ofDrawCircle(i_position, i_radius);
		DrawBoidHead(i_radius, i_position, i_orientation);

	}

	void Renderer::BoidRenderer::DrawBoidHead(float i_radius, ofVec2f i_position, float i_orientation)
	{
		//ofDrawTriangle(i_position, i_orientation);
		ofVec2f pos1, pos2, pos3;
		//i_radius = 100;
		

		pos1.x = i_position.x + std::cos(i_orientation) * 2 * i_radius;
		pos1.y = i_position.y + std::sin(i_orientation) * 2 * i_radius;
		
		pos2.x = i_position.x + std::cos(i_orientation + 3.14 / 2) * i_radius;
		pos2.y = i_position.y + std::sin(i_orientation + 3.14 / 2) * i_radius;

		pos3.x = i_position.x + std::cos(i_orientation - 3.14 / 2) * i_radius;
		pos3.y = i_position.y + std::sin(i_orientation - 3.14 / 2) * i_radius;

		ofDrawTriangle(pos1.x, pos1.y, pos2.x, pos2.y, pos3.x, pos3.y);
	}
}