#pragma once
#include <unordered_map>
#include <string>
#include <memory>
#include <vector>
#include <bitset>
#include <optional>
#include "Fade/Fade.h"
#include "FrameInfo/FrameInfo.h"

class BaseScene {
	friend class SceneManager;

public:
	enum class ID {
		Game,
		Title,
		Clear,
	};

public:
	BaseScene(BaseScene::ID sceneID);
	BaseScene(const BaseScene&) = delete;
	BaseScene(BaseScene&&) = delete;
	virtual ~BaseScene() = default;

	BaseScene& operator=(const BaseScene&) = delete;
	BaseScene& operator=(BaseScene&&) = delete;

public:
	void SceneInitialize(class SceneManager* sceneManager);

	virtual void Initialize() = 0;
	virtual void Finalize() = 0;

	virtual void Update() = 0;
	virtual void Draw() = 0;

	inline BaseScene::ID GetID() const {
		return sceneID_;
	}

protected:
	class SceneManager* sceneManager_;

	BaseScene::ID sceneID_;
};

class SceneManager final {
private:
	SceneManager() = default;
	SceneManager(const SceneManager&) = delete;
	SceneManager(SceneManager&&) = delete;
	~SceneManager() = default;

	SceneManager& operator=(const SceneManager&) = delete;
	SceneManager& operator=(SceneManager&&) = delete;

public:
	static SceneManager* const GetInstace();

public:
	void Initialize(std::optional<BaseScene::ID> firstScene);
	void Finalize();

	void SceneChange(std::optional<BaseScene::ID> next);

	void Update();

	void Draw();

	void MainLoop(std::optional<BaseScene::ID> finishID = BaseScene::ID::Title);

private:
	BaseScene* currentScene_;
	BaseScene* nextScene_;

	std::unordered_map<std::optional<BaseScene::ID>, std::unique_ptr<BaseScene>> scenes_;

	std::unique_ptr<Fade> fade_;

	FrameInfo* frameInfo_ = nullptr;
};