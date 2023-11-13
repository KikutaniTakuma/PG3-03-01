#include "CricleObject.h"
#include <Novice.h>

void  CricleObject::Draw() {
	Novice::DrawEllipse(
		static_cast<int32_t>(pos_.x),
		static_cast<int32_t>(pos_.y),
		static_cast<int32_t>(radius_),
		static_cast<int32_t>(radius_),
		0.0f,
		Vector4ToUint(color_),
		FillMode::kFillModeSolid
	);
}

bool CricleObject::Collision(const CricleObject* other) {
	if ((pos_ - other->pos_).Length() < radius_ + other->radius_) {
		isCollision_ = true;
		return true;
	}
	isCollision_ = false;
	return false;
}