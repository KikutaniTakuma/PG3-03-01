#include "Bullet.h"
#include "FrameInfo/FrameInfo.h"

void Bullet::Initalize() {
	pos_ = Vector2D::zero;
	velocity_ = 200.0f;
	radius_ = 10.0f;
	color_ = Vector4D::zIdy + Vector4D::wIdy;
}

void Bullet::Update() {
	Move();
}


void Bullet::Move() {
	moveVec_ = Vector2D::zero;
	if (isActive_) {
		moveVec_.x = velocity_;
		pos_ += moveVec_ * FrameInfo::GetInstance()->GetDelta();
	}
}

void Bullet::Active(const Vector2D& pos) {
	if (!isActive_) {
		pos_ = pos;
		isActive_ = true;
	}
}