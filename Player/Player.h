#pragma once
#include "CricleObject/CricleObject.h"
#include "Bullet/Bullet.h"
#include <list>
#include <memory>

class Player : public CricleObject {
public:
	Player() = default;
	Player(const Player&) = default;
	Player(Player&&) = default;
	~Player() = default;

	Player& operator=(const Player&) = default;
	Player& operator=(Player&&) = default;

public:
	void Initalize() override;

	void Update() override;

	void Draw() override;

	inline const std::list<std::unique_ptr<Bullet>>& GetBulletlist() const {
		return bullets_;
	}

protected:
	void Move() override;

	void Fire();

	void UpdateBullets();

	void InActiveBullets();

private:
	std::list<std::unique_ptr<Bullet>> bullets_;
};