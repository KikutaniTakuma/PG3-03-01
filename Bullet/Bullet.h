#pragma once
#include "CricleObject/CricleObject.h"

class Bullet : public CricleObject {
public:
	Bullet() = default;
	Bullet(const Bullet&) = default;
	Bullet(Bullet&&)= default;
	~Bullet() = default;

	Bullet& operator=(const Bullet&) = default;
	Bullet& operator=(Bullet&&) = default;

public:
	void Initalize() override;
	void Active(const Vector2D& pos);

	inline void Inactive() {
		if (isCollision_) {
			isActive_ = false;
		}
	}

	inline bool GetIsActive() const {
		return isActive_;
	}

	void Update() override;

protected:
	void Move() override;

private:
	bool isActive_;
};