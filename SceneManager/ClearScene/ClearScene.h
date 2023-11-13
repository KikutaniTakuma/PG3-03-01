#pragma once

#include "SceneManager/SceneManager.h"

class ClearScene : public BaseScene {
public:
	ClearScene();
	ClearScene(const ClearScene&) = delete;
	ClearScene(ClearScene&&) = delete;
	~ClearScene() = default;

	ClearScene& operator=(const ClearScene&) = delete;
	ClearScene& operator=(ClearScene&&) = delete;

public:
	void Initialize() override;

	void Finalize() override;

	void Update() override;

	void Draw() override;
};