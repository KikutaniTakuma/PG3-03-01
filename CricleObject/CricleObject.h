#pragma once
#include "Utils/Math/Vector2D.h"
#include "Utils/Math/Vector4D.h"

class CricleObject {
public:
	CricleObject() = default;
	CricleObject(const CricleObject&) = default;
	CricleObject(CricleObject&&) = default;
	~CricleObject() = default;

	CricleObject& operator=(const CricleObject&) = default;
	CricleObject& operator=(CricleObject&&) = default;

public:
	virtual void Initalize() = 0;

	virtual void Update() = 0;

	virtual void Draw();

	bool Collision(const CricleObject* other);

	inline bool GetIsCollision() const {
		return isCollision_;
	}

	inline const Vector2D& GetPos() const {
		return pos_;
	}

protected:
	virtual void Move() = 0;

protected:
	Vector2D pos_;
	float radius_;

	Vector2D moveVec_;
	float velocity_;

	Vector4D color_;

	bool isCollision_;
};