#pragma once
#include "ofMain.h"
#include "ofxAssimpModelLoader.h"

class DrawDragAndDropRect
{
	public:
		void setUp(float _x, float _y, float _width, float _height);
		void draw();
		void keyReleased();
		void dragEvent(ofDragInfo dragInfo);
		//void setBonePosition(int x,int y);
		void update( int x, int y);

	private:
		ofImage img;
		ofxAssimpModelLoader model;
		ofxAssimpModelLoader thumbnailModel;
		ofVec2f _bonePoint;
		float xPos, yPos, width, height;
		int bpx, bpy = 0;
		bool boneSetted = false;

		//’ZŒa“à‚ÉŽw’è‚ÌÀ•W‚ªŠÜ‚Ü‚ê‚Ä‚¢‚ê‚Îtrue,‚»‚¤‚Å‚È‚¯‚ê‚Îfalse
		/*bool inside(float px, float py) {
			if (px > x && py > y && px < x + width && py < y + height) {
				return true;
			}
			return false;
		}*/
};

