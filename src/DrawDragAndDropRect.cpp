#include "DrawDragAndDropRect.h"

//íZå`ÇÃèâä˙âª
void DrawDragAndDropRect::setUp(float _x, float _y, float _width, float _height) {
	xPos = _x;
	yPos = _y;
	width = _width;
	height = _height;
	model.setPosition(bpx, bpy, 0);
	model.setScale(0.5, 0.5, 0.5);
	thumbnailModel.setPosition(_x + _width, _y + _height, 0);
	thumbnailModel.setScale(0.1, 0.1, 0.1);
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
	if(boneSetted) model.drawFaces();
	thumbnailModel.drawFaces();
}

void DrawDragAndDropRect::update() {
	
	model.update();
	thumbnailModel.update();
	model.setPosition(bpx,bpy,0);
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
			for (int i = 0; i < dragInfo.files.size(); i++) {
				string ext = ofToLower(ofFilePath::getFileExt(dragInfo.files[i]));
				if (ext == "dae") {
					model.loadModel(dragInfo.files[i]);
					thumbnailModel.loadModel(dragInfo.files[i]);
				}
				else if (ext == "jpg" || ext == "jpeg" || ext == "png") {
					img.load(dragInfo.files[i]);
				}
			}
			
		}
	}
}

void DrawDragAndDropRect::setBonePosition(int x, int y) {
	if (!boneSetted) boneSetted = true;
	bpx = x;
	bpy = y;
}