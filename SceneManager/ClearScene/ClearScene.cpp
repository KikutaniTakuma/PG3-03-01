#include "ClearScene.h"
#include "KeyInput/KeyInput.h"
#include "Novice.h"
#include <numbers>

ClearScene::ClearScene() :
	BaseScene(BaseScene::ID::Clear)
{}

void ClearScene::Initialize() {

}

void ClearScene::Finalize() {

}

void ClearScene::Update() {
	if (KeyInput::Pushed(DIK_SPACE)) {
		sceneManager_->SceneChange(BaseScene::ID::Title);
	}
}

void ClearScene::Draw() {
	Novice::ScreenPrintf(0, 0, "clear");
	Novice::ScreenPrintf(0, 20, "push to space");
}