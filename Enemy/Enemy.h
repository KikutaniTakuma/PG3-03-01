#pragma once
#include "CricleObject/CricleObject.h"

class Enemy : public CricleObject {
public:
	Enemy() = default;
	Enemy(const Enemy&) = default;
	Enemy(Enemy&&) = default;
	~Enemy() = default;

	Enemy& operator=(const Enemy&) = default;
	Enemy& operator=(Enemy&&) = default;

public:
	void Initalize() override;

	void Update() override;

protected:
	void Move() override;

private:
	
};