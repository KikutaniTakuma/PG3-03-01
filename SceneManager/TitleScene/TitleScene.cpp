#include "TitleScene.h"
#include "KeyInput/KeyInput.h"
#include "Novice.h"
#include <numbers>

TitleScene::TitleScene() :
	BaseScene(BaseScene::ID::Title)
{}

void TitleScene::Initialize() {
	
}

void TitleScene::Finalize() {

}

void TitleScene::Update() {
	if (KeyInput::Pushed(DIK_SPACE)) {
		sceneManager_->SceneChange(BaseScene::ID::Game);
	}
}

void TitleScene::Draw() {
	Novice::ScreenPrintf(0, 0, "title");
	Novice::ScreenPrintf(0, 20, "push to space");
}