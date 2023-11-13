#include "Enemy.h"
#include "FrameInfo/FrameInfo.h"

void Enemy::Initalize() {
	pos_ = { 1280.0f - 320.0f, 360.0f };
	velocity_ = 200.0f;
	radius_ = 50.0f;
	color_ = Vector4D::zIdy + Vector4D::wIdy;
	moveVec_ = Vector2D::identity;
	moveVec_ *= velocity_;
}

void Enemy::Update() {
	Move();
}


void Enemy::Move() {
	if (pos_.x < radius_ || 1280.0f - radius_ < pos_.x) {
		moveVec_.x *= -1.0f;
	}
	if (pos_.y < radius_ || 720.0f - radius_ < pos_.y) {
		moveVec_.y *= -1.0f;
	}

	pos_ += moveVec_ * FrameInfo::GetInstance()->GetDelta();
}