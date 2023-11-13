#include <Novice.h>
#include <string>
#include "KeyInput/KeyInput.h"
#include "SceneManager/SceneManager.h"
#include "SceneManager/GameScene/Game.h"

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {
	const std::string kWindowTitle = "LE2A_06_キクタニ_タクマ_タイトル";

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle.c_str(), 1280, 720);

	// シーンマネージャー初期化
	auto* const sceneManager = SceneManager::GetInstace();

	sceneManager->Initialize(BaseScene::ID::Title);

	// メインループ
	sceneManager->MainLoop(BaseScene::ID::Game);

	sceneManager->Finalize();

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
