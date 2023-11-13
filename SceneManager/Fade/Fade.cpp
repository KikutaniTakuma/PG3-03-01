#include "Fade.h"
#include "imgui.h"
#include "Novice.h"
#include "Utils/Math/Vector4D.h"

Fade::Fade():
	isInStart_(false),
	isOutStart_(false),
	fadeTime_(0.75f),
	color_()
{
	
}

void Fade::OutStart() {
	if (!isInStart_ && !isOutStart_) {
		isOutStart_ = true;
		ease_.Start(
			false,
			fadeTime_
		);
	}
}
void Fade::InStart() {
	if (!isInStart_ && !isOutStart_) {
		isInStart_ = true;
		ease_.Start(
			false,
			fadeTime_
		);
	}
}
bool Fade::OutEnd() const {
	return isOutStart_.OnExit();
}
bool Fade::OutStay() const {
	return isOutStart_.OnStay();
}

bool Fade::InEnd() const {
	return isInStart_.OnExit();
}
bool Fade::InStay() const {
	return isInStart_.OnStay();
}

void Fade::Update() {
	isOutStart_.Update();
	isInStart_.Update();

	if (ease_.ActiveExit()) {
		isInStart_ = false;
		isOutStart_ = false;
	}
	
	if (isInStart_) {
		color_ = ColorLerp(0xff, 0x00, ease_.GetT());
	}
	else if (isOutStart_) {
		color_ = ColorLerp(0x00, 0xff, ease_.GetT());
	}

	ease_.Update();
}
void Fade::Draw() {
	Novice::DrawBox(0, 0, 1280, 720, 0.0f, color_, FillMode::kFillModeSolid);
}