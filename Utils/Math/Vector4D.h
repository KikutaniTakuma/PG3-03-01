#pragma once
#include <array>
#include <immintrin.h>

class Vector4D final {
	/// <summary>
	/// コンストラクタ
	/// </summary>
public:
	Vector4D() noexcept;
	Vector4D(const Vector4D& right) noexcept;
	Vector4D(Vector4D&& right) noexcept;
	Vector4D(float x, float y, float z, float w) noexcept;
	Vector4D(uint32_t right) noexcept;
public:
	~Vector4D() = default;

	/// <summary>
	/// 演算子のオーバーロード
	/// </summary>
public:
	Vector4D& operator=(const Vector4D& right) noexcept;
	Vector4D& operator=(Vector4D&& right) noexcept;
	Vector4D& operator=(uint32_t right) noexcept;

	Vector4D operator+(const Vector4D& right) const noexcept;
	Vector4D& operator+=(const Vector4D& right) noexcept;

	Vector4D operator-(const Vector4D& right) const noexcept;
	Vector4D& operator-=(const Vector4D& right) noexcept;

	Vector4D operator*(float scalar) const noexcept;
	Vector4D& operator*=(float scalar) noexcept;
	Vector4D operator/(float scalar) const noexcept;
	Vector4D& operator/=(float scalar) noexcept;

	bool operator==(const Vector4D& right) const noexcept;
	bool operator!=(const Vector4D& right) const noexcept;

	float& operator[](size_t index) noexcept;
	const float& operator[](size_t index) const noexcept;

	/// <summary>
	/// メンバ関数
	/// </summary>
public:
	float Length() const noexcept;

	Vector4D Normalize() const noexcept;

	float Dot(const Vector4D& right) const noexcept;

/// <summary>
/// 静的定数
/// </summary>
public:
	/// <summary>
	/// x = 1.0f, y = 1.0f, z = 1.0f w = 1.0f
	/// </summary>
	static const Vector4D identity;
	/// <summary>
	/// x = 0.0f, y = 0.0f, z = 0.0f w = 0.0f
	/// </summary>
	static const Vector4D zero;
	/// <summary>
	/// x = 1.0f, y = 0.0f, z = 0.0f w = 0.0f
	/// </summary>
	static const Vector4D xIdy;
	/// <summary>
	/// x = 0.0f, y = 1.0f, z = 0.0f w = 0.0f
	/// </summary>
	static const Vector4D yIdy;
	/// <summary>
	/// x = 0.0f, y = 0.0f, z = 1.0f w = 0.0f
	/// </summary>
	static const Vector4D zIdy;
	/// <summary>
	/// x = 0.0f, y = 0.0f, z = 0.0f w = 1.0f
	/// </summary>
	static const Vector4D wIdy;


	/// <summary>
	/// メンバ変数
	/// </summary>
public:
	union {
		std::array<float, 4> m;
		struct {
			float x;
			float y;
			float z;
			float w;
		} vec;
		struct {
			float r;
			float g;
			float b;
			float a;
		} color;
		__m128 m128;
	};

};

/// <summary>
/// uint32_tからVector4Dへの変換
/// </summary>
Vector4D UintToVector4(uint32_t color);

/// <summary>
/// Vector4Dからuint32_tへの変換
/// </summary>
uint32_t Vector4ToUint(const Vector4D& color);

Vector4D ColorLerp(const Vector4D& start, const Vector4D& end, float t);

uint32_t ColorLerp(uint32_t start, uint32_t end, float t);