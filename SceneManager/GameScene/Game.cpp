#include "Game.h"
#include "KeyInput/KeyInput.h"
#include "Novice.h"
#include <numbers>

Game::Game() :
	BaseScene(BaseScene::ID::Game),
	player_{},
	enemy_{}
{}

void Game::Initialize() {
	player_ = std::make_unique<Player>();
	player_->Initalize();
	enemy_ = std::make_unique<Enemy>();
	enemy_->Initalize();
}

void Game::Finalize() {

}

void Game::Update() {
	player_->Update();
	enemy_->Update();

	for (const auto& i : player_->GetBulletlist()) {
		i->Collision(enemy_.get());
	}

	for (const auto& i : player_->GetBulletlist()) {
		if (i->GetIsCollision()){
			sceneManager_->SceneChange(BaseScene::ID::Clear);
		}
	}
}

void Game::Draw() {
	Novice::ScreenPrintf(0,0,"stage");

	player_->Draw();
	enemy_->Draw();
}