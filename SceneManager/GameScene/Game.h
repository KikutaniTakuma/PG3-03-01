#pragma once
#include "SceneManager/SceneManager.h"
#include "Player/Player.h"
#include "Enemy/Enemy.h"

class Game : public BaseScene {
public:
	Game();
	Game(const Game&) = delete;
	Game(Game&&) = delete;
	~Game() = default;

	Game& operator=(const Game&) = delete;
	Game& operator=(Game&&) = delete;

public:
	void Initialize() override;

	void Finalize() override;

	void Update() override;

	void Draw() override;

public:
	std::unique_ptr<Player> player_;
	std::unique_ptr<Enemy> enemy_;
};