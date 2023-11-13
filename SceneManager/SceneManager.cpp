#include "SceneManager.h"
#include "KeyInput/KeyInput.h"
#include "GameScene/Game.h"
#include "TitleScene/TitleScene.h"
#include "ClearScene/ClearScene.h"
#include <Novice.h>
#include <filesystem>
#include <fstream>
#include <format>
#include <cassert>

BaseScene::BaseScene(BaseScene::ID sceneID):
	sceneManager_(nullptr),
	sceneID_(sceneID)
{}

void BaseScene::SceneInitialize(SceneManager* sceneManager) {
	sceneManager_ = sceneManager;
}

SceneManager* const SceneManager::GetInstace() {
	static SceneManager instance;
	return &instance;
}

void SceneManager::Initialize(std::optional<BaseScene::ID> firstScene) {
	fade_ = std::make_unique<Fade>();

	frameInfo_ = FrameInfo::GetInstance();
	scenes_[BaseScene::ID::Game] = std::make_unique<Game>();
	scenes_[BaseScene::ID::Title] = std::make_unique<TitleScene>();
	scenes_[BaseScene::ID::Clear] = std::make_unique<ClearScene>();


	currentScene_ = scenes_[firstScene].get();
	currentScene_->SceneInitialize(this);
	currentScene_->Initialize();

}

void SceneManager::SceneChange(std::optional<BaseScene::ID> next) {
	if (nextScene_) {
		return;
	}
	nextScene_ = scenes_[next].get();
	nextScene_->SceneInitialize(this);

	fade_->OutStart();
}

void SceneManager::Update() {
	if (currentScene_ && !nextScene_ && !fade_->InStay()) {
		currentScene_->Update();
	}
	else {
		fade_->Update();
	}

	if (fade_->OutEnd()) {
		fade_->InStart();
		currentScene_->Finalize();
		currentScene_ = nextScene_;
		nextScene_ = nullptr;
		currentScene_->Initialize();
		currentScene_->Update();
		fade_->Update();
	}
	else if (fade_->InEnd()) {
		fade_->Update();
	}
}

void SceneManager::Draw() {
	if (currentScene_) {
		currentScene_->Draw();
	}

	fade_->Draw();
}

void SceneManager::MainLoop(std::optional<BaseScene::ID> finishID) {
	/// 
	/// メインループ
	/// 
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		frameInfo_->Start();
		Novice::BeginFrame();

		// fps
		frameInfo_->Debug();

		// キー入力を受け取る
		KeyInput::Input();

#ifdef _DEBUG
		if (frameInfo_->GetIsDebugStop() && frameInfo_->GetIsOneFrameActive()) {
			this->Update();
			frameInfo_->SetIsOneFrameActive(false);
		}
		else if (!frameInfo_->GetIsDebugStop()) {
			// 更新処理
			this->Update();
		}
#else
		// 更新処理
		this->Update();
#endif

		// 描画処理
		this->Draw();

		// フレームの終了
		Novice::EndFrame();
		frameInfo_->End();

		// ESCキーが押されたらループを抜ける
		if (KeyInput::Released(DIK_ESCAPE) && currentScene_->GetID() == finishID) {
			break;
		}
	}
}


void SceneManager::Finalize() {
	fade_.reset();
}
