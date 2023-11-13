#include "Vector4D.h"
#include <cmath>
#include <limits>

const Vector4D Vector4D::identity = { 1.0f,1.0f,1.0f,1.0f };
const Vector4D Vector4D::zero = { 0.0f, 0.0f, 0.0f, 0.0f };
const Vector4D Vector4D::xIdy= { 1.0f, 0.0f, 0.0f, 0.0f };
const Vector4D Vector4D::yIdy= { 0.0f, 1.0f, 0.0f, 0.0f };
const Vector4D Vector4D::zIdy= { 0.0f, 0.0f, 1.0f, 0.0f };
const Vector4D Vector4D::wIdy= { 0.0f, 0.0f, 0.0f, 1.0f };

Vector4D::Vector4D() noexcept :
	m{0.0f}
{}

Vector4D::Vector4D(const Vector4D& right) noexcept 
{
	*this = right;
}
Vector4D::Vector4D(Vector4D&& right)  noexcept :
	m(std::move(right.m))
{}

Vector4D::Vector4D(float x, float y, float z, float w) noexcept :
	m{x,y,z,w}
{}

Vector4D::Vector4D(uint32_t right) noexcept {
	*this = right;
}

Vector4D& Vector4D::operator=(const Vector4D& right) noexcept {
	std::copy(right.m.begin(), right.m.end(), m.begin());

	return *this;
}

Vector4D& Vector4D::operator=(Vector4D&& right) noexcept {
	m = std::move(right.m);

	return *this;
}

Vector4D& Vector4D::operator=(uint32_t right) noexcept {
	*this = UintToVector4(right);
	return *this;
}

Vector4D Vector4D::operator+(const Vector4D& right) const noexcept {
	Vector4D result;

	for (size_t i = 0; i < result.m.size(); i++) {
		result.m[i] = m[i] + right.m[i];
	}

	return result;
}

Vector4D& Vector4D::operator+=(const Vector4D& right) noexcept {
	*this = *this + right;

	return *this;
}

Vector4D Vector4D::operator-(const Vector4D& right) const noexcept {
	Vector4D result;

	for (size_t i = 0; i < result.m.size(); i++) {
		result.m[i] = m[i] - right.m[i];
	}

	return result;
}

Vector4D& Vector4D::operator-=(const Vector4D& right) noexcept {
	*this = *this - right;

	return *this;
}

Vector4D Vector4D::operator*(float scalar) const noexcept {
	Vector4D result;

	for (size_t i = 0; i < result.m.size(); i++) {
		result.m[i] = m[i] * scalar;
	}

	return result;
}
Vector4D& Vector4D::operator*=(float scalar) noexcept {
	*this = *this * scalar;

	return *this;
}

Vector4D Vector4D::operator/(float scalar) const noexcept {
	Vector4D result;
	scalar = 1.0f / scalar;

	for (size_t i = 0; i < result.m.size(); i++) {
		result.m[i] = m[i] * scalar;
	}

	return result;
}
Vector4D& Vector4D::operator/=(float scalar) noexcept {
	*this = *this / scalar;

	return *this;
}

bool Vector4D::operator==(const Vector4D& right) const noexcept {
	return m == right.m;
}
bool Vector4D::operator!=(const Vector4D& right) const noexcept {
	return m != right.m;
}

float& Vector4D::operator[](size_t index) noexcept {
	return m[index];
}

const float& Vector4D::operator[](size_t index) const noexcept {
	return m[index];
}

float Vector4D::Length() const noexcept {
	return std::sqrt(Dot(*this));
}

Vector4D Vector4D::Normalize() const noexcept {
	if (*this == Vector4D()) {
		return *this;
	}

	float nor = 1.0f / this->Length();

	return Vector4D(*this) * nor;
}

float Vector4D::Dot(const Vector4D& right) const noexcept {
	return _mm_cvtss_f32(_mm_dp_ps(m128, right.m128, 0xff));
}

Vector4D UintToVector4(uint32_t color) {
	static constexpr float normal = 1.0f / static_cast<float>(std::numeric_limits<uint8_t>::max());
	Vector4D result;

	result.color = {
		static_cast<float>((color & 0xff000000) >> 24) * normal,
		static_cast<float>((color & 0xff0000  ) >> 16) * normal,
		static_cast<float>((color & 0xff00    ) >>  8) * normal,
		static_cast<float>( color & 0xff             ) * normal
	};
	return result;
}

uint32_t Vector4ToUint(const Vector4D& color) {
	uint32_t result = 0u;

	result += static_cast<decltype(result)>(color.color.r * 255.0f) << 24;
	result += static_cast<decltype(result)>(color.color.g * 255.0f) << 16;
	result += static_cast<decltype(result)>(color.color.b * 255.0f) << 8;
	result += static_cast<decltype(result)>(color.color.a * 255.0f);

	return result;
}

Vector4D ColorLerp(const Vector4D& start, const Vector4D& end, float t) {
	Vector4D result;

	for (auto i = 0llu; i < result.m.size();i++) {
		result[i] = std::lerp(start[i], end[i], t);
	}

	return result;
}

uint32_t ColorLerp(uint32_t start, uint32_t end, float t) {
	Vector4D result;
	Vector4D&& startTmp = UintToVector4(start);
	Vector4D&& endTmp = UintToVector4(end);

	for (auto i = 0llu; i < result.m.size(); i++) {
		result[i] = std::lerp(startTmp[i], endTmp[i], t);
	}

	return Vector4ToUint(result);
}