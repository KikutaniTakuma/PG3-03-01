#include "Vector3D.h"
#include <cmath>
#include "Vector2D.h"
#include <cassert>
#include <array>

Vector3D::Vector3D() noexcept :
	x(0.0f),
	y(0.0f),
	z(0.0f)
{}

Vector3D::Vector3D(float x, float y, float z) noexcept :
	x(x),
	y(y),
	z(z)
{}

Vector3D::Vector3D(const Vector3D& right) noexcept
{
	*this = right;
}
Vector3D::Vector3D(const Vector2D& right) noexcept {
	x = right.x;
	y = right.y;
	z = 0.0f;
}

Vector3D::Vector3D(Vector3D&& right) noexcept
{
	*this = std::move(right);
}

const Vector3D Vector3D::identity = { 1.0f,1.0f,1.0f };
const Vector3D Vector3D::zero = { 0.0f, 0.0f,0.0f };
const Vector3D Vector3D::xIdy = { 1.0f,0.0f,0.0f };
const Vector3D Vector3D::yIdy = { 0.0f,1.0f,0.0f };
const Vector3D Vector3D::zIdy = { 0.0f,0.0f,1.0f };

Vector3D Vector3D::operator+() const noexcept {
	return *this;
}
Vector3D Vector3D::operator-() const noexcept {
	return Vector3D(-x, -y, -z);
}

Vector3D& Vector3D::operator=(const Vector3D& right) noexcept {
	x = right.x;
	y = right.y;
	z = right.z;

	return *this;
}

Vector3D& Vector3D::operator=(Vector3D&& right) noexcept {
	x = std::move(right.x);
	y = std::move(right.y);
	z = std::move(right.z);

	return *this;
}

Vector3D Vector3D::operator+(const Vector3D& right) const noexcept {
	Vector3D tmp(x + right.x, y + right.y, z + right.z);

	return tmp;
}
Vector3D Vector3D::operator-(const Vector3D& right) const noexcept {
	Vector3D tmp(x - right.x, y - right.y, z - right.z);

	return tmp;
}
Vector3D& Vector3D::operator+=(const Vector3D& right) noexcept {
	*this = *this + right;

	return *this;
}
Vector3D& Vector3D::operator-=(const Vector3D& right) noexcept {
	*this = *this - right;

	return *this;
}

Vector3D Vector3D::operator*(float scalar) const noexcept {
	Vector3D tmp(x * scalar, y * scalar, z * scalar);

	return tmp;
}
Vector3D& Vector3D::operator*=(float scalar) noexcept {
	*this = *this * scalar;

	return *this;
}

Vector3D Vector3D::operator/(float scalar) const noexcept {
	Vector3D tmp(x / scalar, y / scalar, z / scalar);

	return tmp;
}
Vector3D& Vector3D::operator/=(float scalar) noexcept {
	*this = *this / scalar;

	return *this;
}

Vector3D& Vector3D::operator=(const Vector2D& right) noexcept {
	x = right.x;
	y = right.y;

	return *this;
}

bool Vector3D::operator==(const Vector3D& right) const noexcept {
	return x == right.x && y == right.y && z == right.z;
}
bool Vector3D::operator!=(const Vector3D& right) const noexcept {
	return x != right.x || y != right.y || z != right.z;
}

float& Vector3D::operator[](size_t index) noexcept {
	assert(index < 3llu);
	std::array<float*,3> tmp = { &x,&y,&z };
	return *tmp[index];
}

const float& Vector3D::operator[](size_t index) const noexcept {
	assert(index < 3llu);
	std::array<const float*, 3> tmp = { &x,&y,&z };
	return *tmp[index];
}

float Vector3D::Length() const noexcept {
	return std::sqrt(x*x + y*y + z*z);
}

float Vector3D::Dot(const Vector3D& right) const noexcept {
	return x * right.x + y * right.y + z * right.z;
}

Vector3D Vector3D::Cross(const Vector3D& right) const noexcept {
	Vector3D result;

	result.x = y * right.z - z * right.y;
	result.y = z * right.x - x * right.z;
	result.z = x * right.y - y * right.x;

	return result;
}

Vector3D Vector3D::Normalize() const noexcept {
	if (*this == Vector3D::zero) {
		return Vector3D::zero;
	}

	return *this / this->Length();
}


Vector3D Vector3D::Lerp(const Vector3D& start, const Vector3D& end, float t) {
	Vector3D result;

	result.x = std::lerp(start.x, end.x, t);
	result.y = std::lerp(start.y, end.y, t);
	result.z = std::lerp(start.z, end.z, t);

	return result;
}

Vector3D Project(const Vector3D& vec1, const Vector3D& vec2) {
	return vec2 * (vec1.Dot(vec2) / std::pow(vec2.Length(), 2.0f));
}

Vector3D ClosestPoint(const Vector3D& point, const Segment& segment) {
	return segment.origin + Project(point - segment.origin, segment.diff);
}