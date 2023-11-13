#include "Vector2D.h"
#include <assert.h>
#include <cmath>
#include <numbers>

Vector2D::Vector2D() noexcept :
	x(0.0f),
	y(0.0f)
{}

Vector2D::Vector2D(const Vector2D& right) noexcept {
	*this = right;
}
Vector2D::Vector2D(float x, float y) noexcept :
	x(x),
	y(y)
{}

Vector2D::Vector2D(Vector2D&& right) noexcept {
	*this = std::move(right);
}

const Vector2D Vector2D::identity = { 1.0f,1.0f };
const Vector2D Vector2D::zero = {0.0f, 0.0f};
const Vector2D Vector2D::xIdy = { 1.0f,0.0f };
const Vector2D Vector2D::yIdy = { 0.0f,1.0f };


Vector2D Vector2D::operator+(const Vector2D& right) const noexcept {
	Vector2D result;

	result.x = this->x + right.x;
	result.y = this->y + right.y;

	return result;
};
Vector2D Vector2D::operator-(const Vector2D& right) const noexcept {
	Vector2D result;

	result.x = this->x - right.x;
	result.y = this->y - right.y;

	return result;
}


Vector2D Vector2D::operator*(float scalar) const noexcept {
	Vector2D result;

	result.x = this->x * scalar;
	result.y = this->y * scalar;

	return result;
}
Vector2D Vector2D::operator/(float scalar) const noexcept {
	Vector2D result;

	result.x = this->x / scalar;
	result.y = this->y / scalar;

	return result;
}

Vector2D& Vector2D::operator=(const Vector2D& right) noexcept {
	this->x = right.x;
	this->y = right.y;

	return *this;
}

Vector2D& Vector2D::operator=(Vector2D&& right) noexcept {
	this->x = std::move(right.x);
	this->y = std::move(right.y);

	return *this;
}


Vector2D& Vector2D::operator+=(const Vector2D& right) noexcept {
	this->x += right.x;
	this->y += right.y;

	return *this;
}
Vector2D& Vector2D::operator-=(const Vector2D& right) noexcept {
	this->x -= right.x;
	this->y -= right.y;

	return *this;
}

Vector2D& Vector2D::operator*=(float scalar) noexcept {
	this->x *= scalar;
	this->y *= scalar;

	return *this;
}
Vector2D& Vector2D::operator/=(float scalar) noexcept {
	this->x /= scalar;
	this->y /= scalar;

	return *this;
}

bool Vector2D::operator==(const Vector2D& right) const noexcept {
	return this->x == right.x && this->y == right.y;
}
bool Vector2D::operator!=(const Vector2D& right) const noexcept {
	return this->x != right.x || this->y != right.y;
}

void Vector2D::Rotate(float rad) noexcept {
	x *= cosf(rad);
	y *= sinf(rad);
}

float Vector2D::Cross(const Vector2D& right) const noexcept {
	return x * right.y - y * right.x;
}
float Vector2D::Dot(const Vector2D& right) const noexcept {
	return x * right.x + y * right.y;
}

float Vector2D::Length() const noexcept {
	return std::hypot(x, y);
}

Vector2D Vector2D::Normalize() const noexcept {
	if (*this == Vector2D::zero) {
		return *this;
	}
	return *this / Length();
}

Vector2D Vector2D::Lerp(const Vector2D& start, const Vector2D& end, float easeSpd) {
	Vector2D result;

	result.x = std::lerp(start.x, end.x, easeSpd);
	result.y = std::lerp(start.y, end.y, easeSpd);

	return result;
}