#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//DDRectを初期化
	picRect1.setUp(ofGetWindowWidth() * 0.5 - 125, ofGetWindowHeight() * 0.5 - 300, 350, 600);
	

	//クリックポイントの初期化
	for (int i = 0; i < NUM; i++) 
	{
		pos[i].x = 0;
		pos[i].y = 0;
	}
	myModel.setScale(0.5, 0.5, 0.5);
	myModel.setRotation(0, 90, 1, 0, 0);
	
	light.setPosition(0, 0, 500);
}

//--------------------------------------------------------------
void ofApp::update(){
	myModel.update();
	camera.lookAt(ofVec3f(0, 0, 0));
	camera.setPosition(500 * cos(ofGetElapsedTimef() / 10), 200, 500 * sin(ofGetElapsedTimef() / 10));
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	picRect1.draw();
	ofSetColor(255, 0, 0);
	for (int i = 0; i < NUM; i++) 
	{
		ofCircle(pos[i].x, pos[i].y, 4);
	}

	ofEnableDepthTest();

	light.enable();

		ofPushMatrix();
			ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
			camera.begin();
				ofRotateX(-90);
				ofSetLineWidth(1);
				myModel.drawFaces();
			camera.end();
		ofPopMatrix();

		light.disable();

	ofDisableDepthTest();
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	picRect1.keyReleased();

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	//マウスボタンを押して離したときにクリックポイントの座標が0～４番の順で更新される
	//4番まで更新し終えたら、また0番から更新する
	pos[cCoutnerNum].x = x;
	pos[cCoutnerNum].y = y;
	cCoutnerNum = ++cCoutnerNum;
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
	for (int i = 0; i < dragInfo.files.size(); i++) {
		string ext = ofToLower(ofFilePath::getFileExt(dragInfo.files[i]));
		if (ext == "dae") {
			myModel.loadModel(dragInfo.files[i]);
		}
	}
	//ドラッグアンドドロップするウィンドウのドラッグイベント起動
	//picRect1.dragEvent(dragInfo);
}
