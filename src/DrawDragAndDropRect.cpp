#include "DrawDragAndDropRect.h"

//íZå`ÇÃèâä˙âª
void DrawDragAndDropRect::setUp(float _x, float _y, float _width, float _height) {
	xPos = _x;
	yPos = _y;
	width = _width;
	height = _height;
	model.setPosition(0, 0, 0);
	model.setScale(0.5, 0.5, 0.5);
	_cam.enableOrtho();
	_cam.setPosition(0, 0, 500);
	_cam.lookAt(ofVec3f(0, 0, 0));
	ofVec3f thumbPos = _cam.screenToWorld(ofVec3f(xPos + width * 0.5, yPos + height * 0.5, 0));
	thumbnailModel.setPosition(thumbPos.x, thumbPos.y, thumbPos.z);
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
}

void DrawDragAndDropRect::drawModel() {
	/*ofPushMatrix();
	
	ofRotateDeg(_rotateX, 1, 0, 0);
	ofRotateDeg(_rotateY, 0, 1, 0);
	ofRotateDeg(_rotateZ, 0, 0, 1);*/
	
	model.drawFaces();
	//ofPopMatrix();
}

void DrawDragAndDropRect::drawThumbnailModel() {
	//std::cout << "Draw Thumbnail Model" << endl;
	
	thumbnailModel.drawFaces();
}

void DrawDragAndDropRect::update() {
	model.update();
	thumbnailModel.update();
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
				if (ext == "jpg" || ext == "jpeg" || ext == "png") {
					std::cout << "Character Image Added" << endl;
					img.load(dragInfo.files[i]);
					_isCharacterImgAdded = true;
				}
			}
			
		}
	}
}

void DrawDragAndDropRect::modelDragEvent(ofDragInfo dragInfo) {
	for (int i = 0; i < dragInfo.files.size(); i++) {
		if (xPos <= dragInfo.position.x &&
			yPos <= dragInfo.position.y &&
			dragInfo.position.x <= xPos + width &&
			dragInfo.position.y <= yPos + height) {
			for (int i = 0; i < dragInfo.files.size(); i++) {
				string ext = ofToLower(ofFilePath::getFileExt(dragInfo.files[i]));
				if (ext == "dae") {
					std::cout << "3D Model Dropped" << endl;
					model.loadModel(dragInfo.files[i]);
					thumbnailModel.loadModel(dragInfo.files[i]);
				}
				else if (ext == "jpg" || ext == "jpeg" || ext == "png") {
					std::cout << "Texture Image Added" << endl;
					model.getTextureForMesh(dragInfo.files[i]);
					thumbnailModel.getTextureForMesh(dragInfo.files[i]);
				}
			}

		}
	}
}

void DrawDragAndDropRect::setPosition(ofVec3f modelPos) {
	model.setPosition(modelPos.x, modelPos.y, modelPos.z);
}

void DrawDragAndDropRect::setRotate(ofVec3f modelRotate) {
	model.setRotation(0, -modelRotate.x, 0, 1, 0);
	model.setRotation(1, -modelRotate.y, 1, 0, 0);
	model.setRotation(2, modelRotate.z, 0, 0, 1);
	/*_rotateX = modelRotate.x;
	_rotateY = modelRotate.y;
	_rotateZ = modelRotate.z;*/
	std::cout << "Model_0_Rotation Changed. x : " << modelRotate.x
		<< " y : " << modelRotate.y << " z : " 
		<< modelRotate.z << endl;
}

void DrawDragAndDropRect::setSize(float modelSize) {
	model.setScale(modelSize, modelSize, modelSize);
}

bool DrawDragAndDropRect::getCharacterAddedBool() {
	return _isCharacterImgAdded;
}

