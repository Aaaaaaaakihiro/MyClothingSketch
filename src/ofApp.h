#pragma once

#include "ofMain.h"
#include "DrawDragAndDropRect.h"
#include "ofxAssimpModelLoader.h"
#include "ofxGui.h"
#define NUM 5

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	DrawDragAndDropRect picRect1;

	ofVec2f pos[NUM];
	ofxAssimpModelLoader myModel;
	ofCamera camera;
	ofLight light;
	

	int cCoutnerNum = 0;
private:
	float mPosX, mPosY;
};
