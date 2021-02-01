#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//アプリの設定
	ofSetWindowTitle(u8"着せ替えアプリ");

	
	//ウィンドウサイズのキャッシュ
	_cachedhWindowRect.set(0, 0, ofGetWindowWidth(), ofGetWindowHeight());

	
	//背景の設定
	ofBackground(255, 255, 255);


	//ボーンの名前の羅列(主にクリックボックス用)
	_boneNameList.insert(std::make_pair(0, u8"頭"));
	_boneNameList.insert(std::make_pair(1, u8"左肩"));
	_boneNameList.insert(std::make_pair(2, u8"右肩"));
	_boneNameList.insert(std::make_pair(3, u8"腰"));
	_boneNameList.insert(std::make_pair(4, u8"左足"));
	_boneNameList.insert(std::make_pair(5, u8"右足"));

	//ボーンの座標の初期化
	_bonePointArray.insert(std::make_pair(static_cast<int>(boneName::head), ofVec2f(0, 0)));
	_bonePointArray.insert(std::make_pair(static_cast<int>(boneName::r_shoulder), ofVec2f(0, 0)));
	_bonePointArray.insert(std::make_pair(static_cast<int>(boneName::l_shoulder), ofVec2f(0, 0)));
	//_bonePointArray.insert(std::make_pair(static_cast<int>(boneName::chest), ofVec2f(0, 0)));
	_bonePointArray.insert(std::make_pair(static_cast<int>(boneName::waist), ofVec2f(0, 0)));
	_bonePointArray.insert(std::make_pair(static_cast<int>(boneName::r_leg), ofVec2f(0, 0)));
	_bonePointArray.insert(std::make_pair(static_cast<int>(boneName::l_leg), ofVec2f(0, 0)));

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


	//guiのセットアップ
	//3Dモデルが表示される限界座標の設定
	_minPos = ofVec2f(_cachedCharacterWindow.getX(), _cachedCharacterWindow.getY());
	_maxPos = ofVec2f(_cachedCharacterWindow.getWidth(), _cachedCharacterWindow.getHeight());
	//3dモデルの回転限界角を設定
	_minRotate = ofVec3f(-180, -180, -180);
	_maxRotate = ofVec3f(180, 180, 180);
	//初期回転角
	_neutralRotate = ofVec3f(0, 0, 0);
	
	//GUIグループの初期化
	_groupGui.setup("", "", _cachedhWindowRect.getWidth() - 200, _verticalPadding);
	
	//GUIの代入
	//ヘアアクセ
	_groupGui.add(_model_0_Pos.setup("Cap_Pos", 
		_bonePointArray.at(0), 
		_minPos, _maxPos));
	_groupGui.add(_model_0_Rotate.setup("Cap_Rotate", _neutralRotate, _minRotate,_maxRotate));
	_groupGui.add(_model_0_Size.setup("Cap_Size",0.5, 0, 1.0));
	
	//トップス
	_groupGui.add(_model_1_Pos.setup("Tops_Pos", 
		_bonePointArray.at(1), 
		_minPos, _maxPos));
	_groupGui.add(_model_1_Rotate.setup("Tops_Rotate", _neutralRotate, _minRotate, _maxRotate));
	_groupGui.add(_model_1_Size.setup("Tops_Size", 0.5, 0, 1.0));
	
	//ボトムス
	_groupGui.add(_model_2_Pos.setup("Bottoms_Pos", 
		_bonePointArray.at(3), 
		_minPos, _maxPos));
	_groupGui.add(_model_2_Rotate.setup("Bottoms_Rotate", _neutralRotate, _minRotate, _maxRotate));
	_groupGui.add(_model_2_Size.setup("Bottoms_Size", 0.5, 0, 1.0));
	
	//シューズ(左)
	_groupGui.add(_model_3_Pos.setup("LeftShoes_Pos", 
		_bonePointArray.at(4), 
		_minPos, _maxPos));
	_groupGui.add(_model_3_Rotate.setup("LeftShoes_Rotate", _neutralRotate, _minRotate, _maxRotate));
	_groupGui.add(_model_3_Size.setup("LeftShoes_Size", 0.5, 0, 1.0));
	
	//シューズ(右)
	_groupGui.add(_model_4_Pos.setup("RightShoes_Pos",
		_bonePointArray.at(5),
		_minPos, _maxPos));
	_groupGui.add(_model_4_Rotate.setup("RightShoes_Rotate", _neutralRotate, _minRotate, _maxRotate));
	_groupGui.add(_model_4_Size.setup("RightShoes_Size", 0.5, 0, 1.0));


	//mWindowArrayにmWindowを追加
	_mWindowArray.insert(std::make_pair(0, _mWindow0));
	_mWindowArray.insert(std::make_pair(1, _mWindow1));
	_mWindowArray.insert(std::make_pair(2, _mWindow2));
	_mWindowArray.insert(std::make_pair(3, _mWindow3));
	_mWindowArray.insert(std::make_pair(4, _mWindow4));

	//clickWindowArrayにwindowたちを追加
	_clickWindowArray.insert(std::make_pair(0, _clickWindow0));
	_clickWindowArray.insert(std::make_pair(1, _clickWindow1));
	_clickWindowArray.insert(std::make_pair(2, _clickWindow2));
	_clickWindowArray.insert(std::make_pair(3, _clickWindow3));
	_clickWindowArray.insert(std::make_pair(4, _clickWindow4));
	_clickWindowArray.insert(std::make_pair(5, _clickWindow5));


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
	_parameterWindow.setUp(ofGetWindowWidth() - _pWWidth, _verticalPadding, 
		_pWWidth, _windowHeight);

	//クリックウィンドウのsetUp
	for (int i = 0; i < _boneNum; i++) {
		_clickWindowArray.at(i).setUp(
			ofGetWindowWidth() * 0.5
			- (_horizontalPadding * 0.5)
			- (2.0 * _horizontalPadding)
			- (3.0 * _clickWindowWidth)
			+ i * (_clickWindowWidth + _horizontalPadding),
			_verticalPadding + 668 + 10,
			_clickWindowWidth, _clickWindowHeight, i,_boneNameList.at(i));
	}


	//3Dモデルのライトの初期化
	_light.setPosition(0, 0, 500);
}

//--------------------------------------------------------------
void ofApp::update(){
	//myModel.update();
	/*_camera.lookAt(ofVec3f(0, 0, 0));
	_camera.setPosition(500 * cos(ofGetElapsedTimef() / 10), 200,
		500 * sin(ofGetElapsedTimef() / 10));*/
	
	/*
	* すべてのボーン選択ウィンドウのisclickedBoolを監視．
	* もしisClickedBoolがtrueになったらisSelectingBoneをtrueにし，ボーン指定以外のクリック操作をロック．
	* ボーンの指定が終わればロックを解除する．
	*/
	for (int i = 0; i < _boneNum; i++) {
		if(!_isSelectingBone && _clickWindowArray.at(i).getIsClickedBool())
		{
			_isSelectingBone = true;
		}
	}

	/*
	* すべてのボーンが設定されていない時，ボーンがどれだけ設定サれているかを確認して，
	* すべてのボーンが設定されている時に初めてisAllBoneSettedをtrueにする
	*/
	if (!isAllBoneSetted) {
		//int bCounter = 0;
		for (int i = 0; i < _boneNum; i++) {
			if (_bonePointArray.at(i) == ofVec2f(0, 0)) break;
		}
		std::cout << "All Bone Setted!" << endl;
		//すべてのボーンが設定されたらGUIにボーンの座標を流し込む
		//トップスに関しては左肩座標と右肩座標間の線分の傾きをmodel1のRotateに代入する必要あり
		_model_0_Pos = _bonePointArray.at(0);
		_model_1_Pos = _bonePointArray.at(1).getMiddle(_bonePointArray.at(2));
		_model_2_Pos = _bonePointArray.at(3);
		_model_3_Pos = _bonePointArray.at(4);
		_model_4_Pos = _bonePointArray.at(5);
		isAllBoneSetted = true;
		//if (bCounter == _boneNum) isAllBoneSetted = true;
	}

	//モデルウィンドウにひたすら座標を流し続ける
	if (!isAllBoneSetted) {
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
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	//3Dモデルパラメータ(ofxGui)の描画
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	_groupGui.draw();
	//D&Dウィンドウの描画
	_characterWindow.draw();
	for (int i = 0; i < _modelNum; i++) {
		_mWindowArray.at(i).draw();
	}
	//_parameterWindow.draw();
	for (int i = 0; i < _boneNum; i++) {
		_clickWindowArray.at(i).draw();
	}

	//ボーンポイントの描画
	for (int i = 0; i < _boneNum; i++) 
	{
		/*int x = _bonePointArray.at(i).x;
		int y = _bonePointArray.at(i).y;*/
		if (!isAllBoneSetted && _bonePointArray.at(i).x != 0 && _bonePointArray.at(i).y != 0) {
			ofSetColor(0, 0, 255);
			ofFill();
			ofCircle(_bonePointArray.at(i).x, _bonePointArray.at(i).y, 10);
		}
	}

	//3Dモデルの描画
	ofEnableDepthTest();
	_light.enable();
		ofPushMatrix();
			//ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
			_camera.begin();
				//ofRotateX(-90);
				//ofSetLineWidth(1);
				//myModel.drawFaces();
			_camera.end();
		ofPopMatrix();

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

	//ボーン選択中でない時だけボーン指定モードを切り替えることができる
	if (!_isSelectingBone) {
		for (int i = 0; i < _boneNum; i++) {
			_clickWindowArray.at(i).mouseReleased(x, y, button);
		}
	}

	//ボーン選択中のみキャラクターウィンドウでボーンの指定が行える
	if (_isSelectingBone && ofGetWindowWidth() * 0.5 - _cWWidth * 0.5 <= x &&
		_verticalPadding <= y &&
		x <= ofGetWindowWidth() * 0.5 - _cWWidth * 0.5 + _cWWidth - 60 &&
		y <= _verticalPadding + _windowHeight - _horizontalPadding - _clickWindowHeight)
	{
		_bonePointArray.at(_selectedBoneNum) = ofVec2f(x, y);
		_isSelectingBone = false;
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
	if(!_isSelectingBone || !isAllBoneSetted)
	_characterWindow.dragEvent(dragInfo);

	//すべてのボーンを設定した後にだけ3Dモデルをドラッグ＆ドロップできる
	if (isAllBoneSetted) 
	{
		for (int i = 0; i < _modelNum; i++) {
			_mWindowArray.at(i).dragEvent(dragInfo);
		}
	}

	//ドラッグアンドドロップするウィンドウのドラッグイベント起動
	//picRect1.dragEvent(dragInfo);
}