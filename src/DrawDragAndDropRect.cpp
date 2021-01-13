#include "DrawDragAndDropRect.h"

//íZå`ÇÃèâä˙âª
void DrawDragAndDropRect::setUp(float _x, float _y, float _width, float _height) {
	xPos = _x;
	yPos = _y;
	width = _width;
	height = _height;
}

//íZå`ÇÃï`âÊ
void DrawDragAndDropRect::draw() {
	ofNoFill();
	ofSetColor(0);
	ofDrawRectangle(xPos, yPos, width, height);
	ofFill();
	ofSetColor(255);
	if (img.isAllocated()) {
		img.draw(xPos, yPos, width, height);
	}
}

void DrawDragAndDropRect::keyReleased() {
	if (img.isAllocated()) img.clear();
}

void DrawDragAndDropRect::dragEvent(ofDragInfo dragInfo) {
	for (int i = 0; i < dragInfo.files.size(); i++) {
		if (xPos <= dragInfo.position.x &&
			yPos <= dragInfo.position.y &&
			dragInfo.position.x <= xPos + width &&
			dragInfo.position.y <= yPos + height) {
			img.load(dragInfo.files[i]);
		}
	}
}