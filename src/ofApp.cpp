#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//フレームレートの設定
	ofSetFrameRate(60);


	//アプリの設定
	ofSetWindowTitle(u8"着せ替えアプリ");

	
	//ウィンドウサイズのキャッシュofgetwindow
	_cachedhWindowRect.set(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
	std::cout << "WindowCached : " << _cachedhWindowRect.getWidth() << " * " << _cachedhWindowRect.getHeight() << endl;
	
	//背景の設定
	ofBackground(255, 255, 255);


	//ボーンの名前の羅列(主にクリックボックス用)
	/*_boneNameList.insert(std::make_pair(0, u8"頭"));
	_boneNameList.insert(std::make_pair(1, u8"左肩"));
	_boneNameList.insert(std::make_pair(2, u8"右肩"));
	_boneNameList.insert(std::make_pair(3, u8"腰"));
	_boneNameList.insert(std::make_pair(4, u8"左足"));
	_boneNameList.insert(std::make_pair(5, u8"右足"));*/

	//ボーンの座標の初期化
	_bonePointArray.insert(std::make_pair(0, ofVec2f(0, 0)));
	_bonePointArray.insert(std::make_pair(1, ofVec2f(0, 0)));
	_bonePointArray.insert(std::make_pair(2, ofVec2f(0, 0)));
	_bonePointArray.insert(std::make_pair(3, ofVec2f(0, 0)));
	_bonePointArray.insert(std::make_pair(4, ofVec2f(0, 0)));
	_bonePointArray.insert(std::make_pair(5, ofVec2f(0, 0)));

	//クリックポイントの初期化
	/*for (int i = 0; i < NUM; i++)
	{
		_pos[i].x = 0;
		_pos[i].y = 0;
	}*/

	//キャラクターウィンドウのキャッシュ
	_cachedCharacterWindow.set(_cachedhWindowRect.getWidth() * 0.5 - _cWWidth * 0.5,
		_verticalPadding,
		_cWWidth - 60, _windowHeight - _horizontalPadding - _clickWindowHeight);
	std::cout << "CharacterWindowCached : " << _cachedCharacterWindow.getWidth() << " * " << _cachedCharacterWindow.getHeight() << endl;

	//フォント設定
	/*ofTrueTypeFontSettings settings("fonts/VL-Gothic-Regular.ttf", 10);
	settings.antialiased = true;
	settings.addRanges(ofAlphabet::Japanese);
	_timerFont.load(settings);*/


	//guiのセットアップ
	//3Dモデルが表示される限界座標の設定
	_minPos = ofVec2f(_cachedCharacterWindow.getX(), _cachedCharacterWindow.getY());
	_maxPos = ofVec2f(_cachedCharacterWindow.getWidth(), _cachedCharacterWindow.getHeight());
	//3dモデルの回転限界角を設定
	_minRotate = ofVec3f(-180, -180, -180);
	_maxRotate = ofVec3f(180, 180, 180);
	//初期回転角
	_neutralRotate = ofVec3f(0, 0, 0);
	
	//ボタンGUIグループの初期化
	_buttonGroup.setup("", "", _cachedhWindowRect.getWidth() - 200, _verticalPadding);
	_buttonGroup.setDefaultHeight(24);
	//ボタンGUIの設定・グループ化
	_buttonGroup.add(_buttonNo0.setup("Head"));
	_buttonNo0.addListener(this, &ofApp::setBone0);
	_buttonGroup.add(_buttonNo1.setup("L_Shoulder"));
	_buttonNo1.addListener(this, &ofApp::setBone1);
	_buttonGroup.add(_buttonNo2.setup("R_Shoulder"));
	_buttonNo2.addListener(this, &ofApp::setBone2);
	_buttonGroup.add(_buttonNo3.setup("Waist"));
	_buttonNo3.addListener(this, &ofApp::setBone3);
	_buttonGroup.add(_buttonNo4.setup("L_Foot"));
	_buttonNo4.addListener(this, &ofApp::setBone4);
	_buttonGroup.add(_buttonNo5.setup("R_Foot"));
	_buttonNo5.addListener(this, &ofApp::setBone5);

	//ofxPanelの初期化
	_guiGroup.setup("", "", _cachedhWindowRect.getWidth() - 200, _verticalPadding);
	_guiGroup.setDefaultHeight(15);
	//ヘアアクセサリー
	_guiGroup.add(_model0PosSlider.set("Cap_Position", _bonePointArray.at(0), 
		_minPos, _maxPos));
	_guiGroup.add(_model0RotateSlider.set("Cap_Rotation", _neutralRotate, _minRotate, _maxRotate));
	_guiGroup.add(_model_0_Size.setup("Cap_Size", 0.5, 0, 1.0));
	_model0PosSlider.addListener(this, &ofApp::setModel0BonePosition);
	_model0RotateSlider.addListener(this, &ofApp::setModel0Rotation);
	_model_0_Size.addListener(this, &ofApp::setModel0Size);
	//トップス
	_guiGroup.add(_model1PosSlider.set("Tops_Position", _bonePointArray.at(1),
		_minPos, _maxPos));
	_guiGroup.add(_model1RotateSlider.set("Tops_Rotation", _neutralRotate, _minRotate, _maxRotate));
	_guiGroup.add(_model_1_Size.setup("Tops_Size", 0.5, 0, 1.0));
	_model1PosSlider.addListener(this, &ofApp::setModel1BonePosition);
	_model1RotateSlider.addListener(this, &ofApp::setModel1Rotation);
	_model_1_Size.addListener(this, &ofApp::setModel1Size);
	//ボトムス
	_guiGroup.add(_model2PosSlider.set("Bottoms_Position", _bonePointArray.at(3),
		_minPos, _maxPos));
	_guiGroup.add(_model2RotateSlider.set("Bottoms_Rotation", _neutralRotate, _minRotate, _maxRotate));
	_guiGroup.add(_model_2_Size.setup("Bottoms_Size", 0.5, 0, 1.0));
	_model2PosSlider.addListener(this, &ofApp::setModel2BonePosition);
	_model2RotateSlider.addListener(this, &ofApp::setModel2Rotation);
	_model_2_Size.addListener(this, &ofApp::setModel2Size);
	//シューズ（左）
	_guiGroup.add(_model3PosSlider.set("L_Shoes_Position", _bonePointArray.at(4),
		_minPos, _maxPos));
	_guiGroup.add(_model3RotateSlider.set("L_Shoes_Rotation", _neutralRotate, _minRotate, _maxRotate));
	_guiGroup.add(_model_3_Size.setup("L_Shoes_Size", 0.5, 0, 1.0));
	_model3PosSlider.addListener(this, &ofApp::setModel3BonePosition);
	_model3RotateSlider.addListener(this, &ofApp::setModel3Rotation);
	_model_3_Size.addListener(this, &ofApp::setModel3Size);
	//シューズ（右）
	_guiGroup.add(_model4PosSlider.set("R_Shoes_Position", _bonePointArray.at(5),
		_minPos, _maxPos));
	_guiGroup.add(_model4RotateSlider.set("R_Shoes_Rotation", _neutralRotate, _minRotate, _maxRotate));
	_guiGroup.add(_model_4_Size.setup("R_Shoes_Size", 0.5, 0, 1.0));
	_model4PosSlider.addListener(this, &ofApp::setModel4BonePosition);
	_model4RotateSlider.addListener(this, &ofApp::setModel4Rotation);
	_model_4_Size.addListener(this, &ofApp::setModel4Size);
	//スクリーンショットボタン
	_guiGroup.add(_screenShotButton.setup("Generate"));
	_screenShotButton.addListener(this, &ofApp::takeScreenShot);

	////ofxGuiPanelの初期化
	//_groupGui.setup("", "", _cachedhWindowRect.getWidth() - 200, _verticalPadding);
	//_groupGui.setDefaultHeight(15);
	////ヘアアクセ
	//_groupGui.add(_model_0_Pos.setup("Cap_Pos", 
	//	_bonePointArray.at(0), 
	//	_minPos, _maxPos));
	//_groupGui.add(_model_0_Rotate.setup("Cap_Rotate", _neutralRotate, _minRotate,_maxRotate));
	//_groupGui.add(_model_0_Size.setup("Cap_Size",0.5, 0, 1.0));
	////トップス
	//_groupGui.add(_model_1_Pos.setup("Tops_Pos", 
	//	_bonePointArray.at(1), 
	//	_minPos, _maxPos));
	//_groupGui.add(_model_1_Rotate.setup("Tops_Rotate", _neutralRotate, _minRotate, _maxRotate));
	//_groupGui.add(_model_1_Size.setup("Tops_Size", 0.5, 0, 1.0));
	////ボトムス
	//_groupGui.add(_model_2_Pos.setup("Bottoms_Pos", 
	//	_bonePointArray.at(3), 
	//	_minPos, _maxPos));
	//_groupGui.add(_model_2_Rotate.setup("Bottoms_Rotate", _neutralRotate, _minRotate, _maxRotate));
	//_groupGui.add(_model_2_Size.setup("Bottoms_Size", 0.5, 0, 1.0));
	////シューズ(左)
	//_groupGui.add(_model_3_Pos.setup("LeftShoes_Pos", 
	//	_bonePointArray.at(4), 
	//	_minPos, _maxPos));
	//_groupGui.add(_model_3_Rotate.setup("LeftShoes_Rotate", _neutralRotate, _minRotate, _maxRotate));
	//_groupGui.add(_model_3_Size.setup("LeftShoes_Size", 0.5, 0, 1.0));
	////シューズ(右)
	//_groupGui.add(_model_4_Pos.setup("RightShoes_Pos",
	//	_bonePointArray.at(5),
	//	_minPos, _maxPos));
	//_groupGui.add(_model_4_Rotate.setup("RightShoes_Rotate", _neutralRotate, _minRotate, _maxRotate));
	//_groupGui.add(_model_4_Size.setup("RightShoes_Size", 0.5, 0, 1.0));
	////スクリーンショットボタン
	//_groupGui.add(_screenShotButton.setup("Generate"));
	//_screenShotButton.addListener(this, &ofApp::takeScreenShot);

	

	//mWindowArrayにmWindowを追加
	_mWindowArray.insert(std::make_pair(0, _mWindow0));
	_mWindowArray.insert(std::make_pair(1, _mWindow1));
	_mWindowArray.insert(std::make_pair(2, _mWindow2));
	_mWindowArray.insert(std::make_pair(3, _mWindow3));
	_mWindowArray.insert(std::make_pair(4, _mWindow4));

	//clickWindowArrayにwindowたちを追加
	/*_clickWindowArray.insert(std::make_pair(0, _clickWindow0));
	_clickWindowArray.insert(std::make_pair(1, _clickWindow1));
	_clickWindowArray.insert(std::make_pair(2, _clickWindow2));
	_clickWindowArray.insert(std::make_pair(3, _clickWindow3));
	_clickWindowArray.insert(std::make_pair(4, _clickWindow4));
	_clickWindowArray.insert(std::make_pair(5, _clickWindow5));*/


	//DDRectを初期化
	//キャラウィンドウ
	_characterWindow.setUp(_cachedCharacterWindow.getX() ,
		_cachedCharacterWindow.getY(), 
		_cachedCharacterWindow.getWidth(), _cachedCharacterWindow.getHeight());

	//モデルウィンドウをmapから呼び出してsetUpする
	for (int i = 0; i < _modelNum; i++) {
		_mWindowArray.at(i).setUp(_horizontalPadding, _verticalPadding
			+ i * _mWHeight + (i * _arrayPadding), _mWWidth, _mWHeight);
	}

	//パラメータウィンドウのsetUp
	/*_parameterWindow.setUp(_cachedhWindowRect.getWidth() - _pWWidth, _verticalPadding, 
		_pWWidth, _windowHeight);*/

	//クリックウィンドウのsetUp
	/*for (int i = 0; i < _boneNum; i++) {
		_clickWindowArray.at(i).setUp(
			_cachedhWindowRect.getWidth() * 0.5
			- (_horizontalPadding * 0.5)
			- (2.0 * _horizontalPadding)
			- (3.0 * _clickWindowWidth)
			+ i * (_clickWindowWidth + _horizontalPadding),
			_verticalPadding + 668 + 10,
			_clickWindowWidth, _clickWindowHeight, i,_boneNameList.at(i));
	}*/


	//3Dモデルのライトの初期化
	_light.setPosition(0, 0, 500);
	_camera.enableOrtho();
	_camera.setPosition(0, 0, 500);
}

//--------------------------------------------------------------
void ofApp::update(){
	//myModel.update();
	/*_camera.lookAt(ofVec3f(0, 0, 0));
	_camera.setPosition(500 * cos(ofGetElapsedTimef() / 10), 200,
		500 * sin(ofGetElapsedTimef() / 10));*/
	
	//カメラ設定
	_camera.lookAt(ofVec3f(0, 0, 0));


	/*
	* すべてのボーン選択ウィンドウのisclickedBoolを監視．
	* もしisClickedBoolがtrueになったらisSelectingBoneをtrueにし，ボーン指定以外のクリック操作をロック．
	* ボーンの指定が終わればロックを解除する．
	*/
	/*for (int i = 0; i < _boneNum; i++) {
		if(!_isSelectingBone && _clickWindowArray.at(i).getIsClickedBool())
		{
			std::cout << "Bone_" << i <<" Select Start" << endl;
			_isSelectingBone = true;
		}
	}*/

	/*
	* すべてのボーンが設定されていない時，ボーンがどれだけ設定サれているかを確認して，
	* すべてのボーンが設定されている時に初めてisAllBoneSettedをtrueにする
	*/
	if (!isAllBoneSetted) {
		bool isSomeVecZero = std::any_of(_bonePointArray.begin(), _bonePointArray.end(), 
			[](const auto& p) {
			return (p.second == ofVec2f(0, 0));
		}
		);
		if (!isSomeVecZero) {
			std::cout << "All Bone Setted!" << endl;
			//すべてのボーンが設定されたらGUIにボーンの座標を流し込む
			//トップスに関しては左肩座標と右肩座標間の線分の傾きをmodel1のRotateに代入する必要あり
			_model0PosSlider = _bonePointArray.at(0);
			_mWindowArray.at(0).setPosition(_camera.screenToWorld(ofVec3f(_bonePointArray.at(0).x,_bonePointArray.at(0).y,0)));
			_model1PosSlider = _bonePointArray.at(1).getMiddle(_bonePointArray.at(2));
			_mWindowArray.at(1).setPosition(_camera.screenToWorld(ofVec3f(ofVec2f(_model1PosSlider).x, ofVec2f(_model1PosSlider).y, 0)));
			_model1RotateSlider = ofVec3f(0, 0, ofVec2f(_bonePointArray.at(2).x, _bonePointArray.at(1).y).angle(_bonePointArray.at(2)));
			_model2PosSlider = _bonePointArray.at(3);
			_mWindowArray.at(2).setPosition(_camera.screenToWorld(ofVec3f(ofVec2f(_model2PosSlider).x, ofVec2f(_model2PosSlider).y,0)));
			_model3PosSlider = _bonePointArray.at(4);
			_mWindowArray.at(3).setPosition(_camera.screenToWorld(ofVec3f(ofVec2f(_model3PosSlider).x, ofVec2f(_model3PosSlider).y, 0)));
			_model4PosSlider = _bonePointArray.at(5);
			_mWindowArray.at(4).setPosition(_camera.screenToWorld(ofVec3f(ofVec2f(_model4PosSlider).x, ofVec2f(_model4PosSlider).y, 0)));
			isAllBoneSetted = true;
		}

		/*for (int i = 0; i < _boneNum; i++) {
			if (_bonePointArray.at(i) == ofVec2f(0, 0)) {
				break;
			}
			else {
				
			}
		}*/
	}

	//モデルウィンドウにひたすら座標，回転，拡縮を流し続ける
	/*if (!isAllBoneSetted) {
		for (int i = 0; i < _modelNum; i++) {
			_mWindowArray.at(i).update(_bonePointArray.at(i),ofVec3f(0,0,0),0.5);
		}
	}else if (isAllBoneSetted) 
	{
		for (int i = 0; i < _modelNum; i++) {
			switch (i)
			{
			case 0:
				_mWindowArray.at(i).update(ofVec2f(_model_0_Pos), ofVec3f(_model_0_Rotate),_model_0_Size);
				break;
			case 1:
				_mWindowArray.at(i).update(ofVec2f(_model_1_Pos), ofVec3f(_model_1_Rotate), _model_1_Size);
				break;
			case 2:
				_mWindowArray.at(i).update(ofVec2f(_model_2_Pos), ofVec3f(_model_2_Rotate), _model_2_Size);
				break;
			case 3:
				_mWindowArray.at(i).update(ofVec2f(_model_3_Pos), ofVec3f(_model_3_Rotate), _model_3_Size);
				break;
			case 4:
				_mWindowArray.at(i).update(ofVec2f(_model_4_Pos), ofVec3f(_model_4_Rotate), _model_4_Size);
				break;
			default:
				break;
			}
		}
	}*/
}

//--------------------------------------------------------------
void ofApp::draw(){
	//3Dモデルパラメータ(ofxGui)の描画
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	if (!isAllBoneSetted) {
		_buttonGroup.draw();
	}
	else {
		_guiGroup.draw();
	}
	
	//_parameterWindow.draw();
	/*for (int i = 0; i < _boneNum; i++) {
		_clickWindowArray.at(i).draw();
	}*/

	//D&Dウィンドウの描画
	_characterWindow.draw();
	for (int i = 0; i < _modelNum; i++) {
		_mWindowArray.at(i).draw();
	}

	//ボーンポイントの描画
	for (int i = 0; i < _boneNum; i++) 
	{
		/*int x = _bonePointArray.at(i).x;
		int y = _bonePointArray.at(i).y;*/
		if (!isAllBoneSetted /*&& _bonePointArray.at(i).x != 0 && _bonePointArray.at(i).y != 0*/) {
			ofSetColor(0, 0, 255);
			ofFill();
			ofCircle(_bonePointArray.at(i).x, _bonePointArray.at(i).y, 15);
		}
	}

	//タイマーの描画
	/*ofSetColor(77, 77, 77);
	_timerFont.drawString(std::to_string(ofGetElapsedTimef()), _cachedCharacterWindow.getX() + 5, _cachedCharacterWindow.getY() + 5);*/
	ofDrawBitmapString(std::to_string(ofGetElapsedTimef()), _cachedCharacterWindow.getBottomLeft().x + 5, _cachedCharacterWindow.getBottomLeft().y - 5);

	//3Dモデルの描画
	ofEnableDepthTest();
	_light.enable();
		//ofPushMatrix();
			_camera.begin();
			for (int i = 0; i < _modelNum; i++)
			{
				
				_mWindowArray.at(i).drawModel();
				_mWindowArray.at(i).drawThumbnailModel();
			}
			_camera.end();
		//ofPopMatrix();
	_light.disable();
	ofDisableDepthTest();


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	//_characterWindow.keyReleased();
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
	/*_pos[_cCoutnerNum].x = x;
	_pos[_cCoutnerNum].y = y;
	_cCoutnerNum = ++_cCoutnerNum;*/

	//クリックウィンドウ内でマウスボタンがリリースされたらそのウィンドウに割り当てられたボーン指定モードに入る
	/*_clickWindow0.mouseReleased(x, y, button);
	_clickWindow1.mouseReleased(x, y, button);
	_clickWindow2.mouseReleased(x, y, button);
	_clickWindow3.mouseReleased(x, y, button);
	_clickWindow4.mouseReleased(x, y, button);
	_clickWindow5.mouseReleased(x, y, button);*/

	//キャラクター画像が設定されている，かつ，ボーン選択中でない時だけボーン指定モードを切り替えることができる
	/*if (_characterWindow.getCharacterAddedBool() && !_isSelectingBone) {
		std::cout << "You Can Select Bone" << endl;
		for (int i = 0; i < _boneNum; i++) {
			_clickWindowArray.at(i).mouseReleased(x, y, button);
		}
	}*/

	//ボーン選択中のみキャラクターウィンドウでボーンの指定が行える
	if (_cachedCharacterWindow.getX() <= x &&
		_cachedCharacterWindow.getY() <= y &&
		x <= _cachedCharacterWindow.getWidth() &&
		y <= _cachedCharacterWindow.getHeight())
	{
		/*for (pair<int, ClickRect> cw : _clickWindowArray) {
			cw.second.setIsClickedFalse();
		}*/
		_bonePointArray.at(_selectedBoneNum) = ofVec2f(x, y);
		//_isSelectingBone = false;
		std::cout << "CharacterWindow MouseReleased!! "
			<< "x : " << x << " , y : " << y << endl;
	}
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
	//すべてのボーンが設定されていない間とボーン選択中でないときだけキャラクター画像をD&Dできる
	if (!_characterWindow.getCharacterAddedBool()) 
	{
		_characterWindow.dragEvent(dragInfo);
	}

	//すべてのボーンを設定した後にだけ3Dモデルをドラッグ＆ドロップできる

	for (int i = 0; i < _modelNum; i++) 
	{
		_mWindowArray.at(i).modelDragEvent(dragInfo);
	}


	//ドラッグアンドドロップするウィンドウのドラッグイベント起動
	//picRect1.dragEvent(dragInfo);
}

void ofApp::takeScreenShot() {
	_screenShotImage.grabScreen(_cachedCharacterWindow.getX(), _cachedCharacterWindow.getY(), _cachedCharacterWindow.getWidth(), _cachedCharacterWindow.getHeight());
	_screenShotImage.save("screenshot.png");
}

void ofApp::setBone0() {
	std::cout << "Bone_0 Selected" << endl;
	_selectedBoneNum = 0;
}

void ofApp::setBone1() {
	std::cout << "Bone_1 Selected" << endl;
	_selectedBoneNum = 1;
}

void ofApp::setBone2() {
	std::cout << "Bone_2 Selected" << endl;
	_selectedBoneNum = 2;
}

void ofApp::setBone3() {
	std::cout << "Bone_3 Selected" << endl;
	_selectedBoneNum = 3;
}

void ofApp::setBone4() {
	std::cout << "Bone_4 Selected" << endl;
	_selectedBoneNum = 4;
}

void ofApp::setBone5() {
	std::cout << "Bone_5 Selected" << endl;
	_selectedBoneNum = 5;
}

void ofApp::setModel0BonePosition(ofVec2f &position) {
	std::cout << "Model_0_Position Changed.  x : " << position.x << " y : " << position.y << endl;
	_mWindowArray.at(0).setPosition(_camera.screenToWorld(ofVec3f(position.x, position.y, 0)));
}

void ofApp::setModel1BonePosition(ofVec2f& position) {
	std::cout << "Model_1_Position Changed.  x : " << position.x << " y : " << position.y << endl;
	_mWindowArray.at(1).setPosition(_camera.screenToWorld(ofVec3f(position.x, position.y, 0)));
}

void ofApp::setModel2BonePosition(ofVec2f& position) {
	std::cout << "Model_2_Position Changed.  x : " << position.x << " y : " << position.y << endl;
	_mWindowArray.at(2).setPosition(_camera.screenToWorld(ofVec3f(position.x, position.y, 0)));
}

void ofApp::setModel3BonePosition(ofVec2f& position) {
	std::cout << "Model_3_Position Changed.  x : " << position.x << " y : " << position.y << endl;
	_mWindowArray.at(3).setPosition(_camera.screenToWorld(ofVec3f(position.x, position.y, 0)));
}

void ofApp::setModel4BonePosition(ofVec2f& position) {
	std::cout << "Model_4_Position Changed.  x : " << position.x << " y : " << position.y << endl;
	_mWindowArray.at(4).setPosition(_camera.screenToWorld(ofVec3f(position.x, position.y, 0)));
}

void ofApp::setModel0Rotation(ofVec3f &rotate) {
	
	_mWindowArray.at(0).setRotate(rotate);
}

void ofApp::setModel1Rotation(ofVec3f& rotate) {

	_mWindowArray.at(1).setRotate(rotate);
}

void ofApp::setModel2Rotation(ofVec3f& rotate) {

	_mWindowArray.at(2).setRotate(rotate);
}

void ofApp::setModel3Rotation(ofVec3f& rotate) {

	_mWindowArray.at(3).setRotate(rotate);
}

void ofApp::setModel4Rotation(ofVec3f& rotate) {

	_mWindowArray.at(4).setRotate(rotate);
}

void ofApp::setModel0Size(float &size) {
	std::cout << "Model_0_Size Changed. Size : " << size << endl;
	_mWindowArray.at(0).setSize(size);
}

void ofApp::setModel1Size(float& size) {
	std::cout << "Model_1_Size Changed. Size : " << size << endl;
	_mWindowArray.at(1).setSize(size);
}

void ofApp::setModel2Size(float& size) {
	std::cout << "Model_2_Size Changed. Size : " << size << endl;
	_mWindowArray.at(2).setSize(size);
}

void ofApp::setModel3Size(float& size) {
	std::cout << "Model_3_Size Changed. Size : " << size << endl;
	_mWindowArray.at(3).setSize(size);
}

void ofApp::setModel4Size(float& size) {
	std::cout << "Model_4_Size Changed. Size : " << size << endl;
	_mWindowArray.at(4).setSize(size);
}
