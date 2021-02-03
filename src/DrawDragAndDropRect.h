#pragma once
#include "ofMain.h"
#include "ofxAssimpModelLoader.h"

class DrawDragAndDropRect
{
	public:
		void setUp(float _x, float _y, float _width, float _height);
		void draw();
		void drawThumbnailModel();
		void drawModel();
		void keyReleased();
		void dragEvent(ofDragInfo dragInfo);
		void update();
		void setPosition(ofVec3f modelPos);
		void setRotate(ofVec3f modelRotate);
		void setSize(float modelSize);
		bool getCharacterAddedBool();

	private:
		ofImage img;
		ofxAssimpModelLoader model;
		ofxAssimpModelLoader thumbnailModel;
		ofVec2f _bonePoint;
		ofCamera _cam;
		float xPos, yPos, width, height;
		int bpx, bpy = 0;
		bool boneSetted = false;
		bool _isCharacterImgAdded = false;
};

