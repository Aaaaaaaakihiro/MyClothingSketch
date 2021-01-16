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
		void setBonePosition(int x,int y);
		void update();

	private:
		ofImage img;
		ofxAssimpModelLoader model;
		ofxAssimpModelLoader thumbnailModel;
		float xPos, yPos, width, height;
		int bpx, bpy = -500;
		bool boneSetted = false;

		//�Z�a���Ɏw��̍��W���܂܂�Ă����true,�����łȂ����false
		/*bool inside(float px, float py) {
			if (px > x && py > y && px < x + width && py < y + height) {
				return true;
			}
			return false;
		}*/
};

