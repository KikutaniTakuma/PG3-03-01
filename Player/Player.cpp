#include "Player.h"
#include "KeyInput/KeyInput.h"
#include "FrameInfo/FrameInfo.h"
#include <Novice.h>

void Player::Initalize() {
	pos_ = { 320.0f, 360.0f };
	velocity_ = 100.0f;
	radius_ = 20.0f;
	color_ = Vector4D::yIdy + Vector4D::wIdy;
}

void Player::Update() {
	Move();
	Fire();
	UpdateBullets();
	InActiveBullets();
}

void Player::Move() {
	moveVec_ = Vector2D::zero;

	if (KeyInput::LongPush(DIK_W)) {
		moveVec_.y -= 1.0f;
	}
	if (KeyInput::LongPush(DIK_S)) {
		moveVec_.y += 1.0f;
	}
	if (KeyInput::LongPush(DIK_D)) {
		moveVec_.x += 1.0f;
	}
	if (KeyInput::LongPush (DIK_A)) {
		moveVec_.x -= 1.0f;
	}

	pos_ += moveVec_.Normalize() * velocity_ * FrameInfo::GetInstance()->GetDelta();
}

void Player::Draw() {
	CricleObject::Draw();

	for (auto& i : bullets_) {
		i->Draw();
	}
}

void Player::Fire() {
	if (KeyInput::Pushed(DIK_SPACE)) {
		auto bullet = std::make_unique<Bullet>();
		bullet->Initalize();
		bullet->Active(pos_);
		bullets_.push_back(std::move(bullet));
	}
}

void Player::UpdateBullets() {
	for (auto& i : bullets_) {
		i->Update();
	}
}

void Player::InActiveBullets() {
	for (auto& i : bullets_) {
		if (i->GetIsCollision()) {
			i.reset();
		}
	}

	std::erase_if(bullets_,
		[](const std::unique_ptr<Bullet>& bullet) {
			if (bullet) {
				return 1280.0f < bullet->GetPos().x;
			}
			return static_cast<bool>(!bullet);
		}
	);
}