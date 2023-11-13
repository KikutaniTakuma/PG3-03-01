#pragma once

/// <summary>
/// 三次元配列
/// </summary>
class Vector3D final {
/// <summary>
/// コンストラクタ
/// </summary>
public:
	Vector3D() noexcept;
	Vector3D(float x, float y, float z) noexcept;
	Vector3D(const Vector3D& right) noexcept;
	Vector3D(const class Vector2D& right) noexcept;
	Vector3D(Vector3D&& right) noexcept;
public:
	~Vector3D() = default;

/// <summary>
/// 演算子のオーバーロード
/// </summary>
public:
	// 単項演算子

	Vector3D operator+() const noexcept;
	Vector3D operator-() const noexcept;


	// 二項演算子

	Vector3D& operator=(const Vector3D& right) noexcept;
	Vector3D& operator=(Vector3D&& right) noexcept;
	Vector3D operator+(const Vector3D& right) const noexcept;
	Vector3D operator-(const Vector3D& right) const noexcept;
	Vector3D& operator+=(const Vector3D& right) noexcept;
	Vector3D& operator-=(const Vector3D& right) noexcept;
	Vector3D operator*(float scalar) const noexcept;
	Vector3D& operator*=(float scalar) noexcept;
	Vector3D operator/(float scalar) const noexcept;
	Vector3D& operator/=(float scalar) noexcept;

	Vector3D& operator=(const class Vector2D& right) noexcept;


	// 等比演算子

	bool operator==(const Vector3D& right) const noexcept;
	bool operator!=(const Vector3D& right) const noexcept;

	// 
	float& operator[](size_t index) noexcept;
	const float& operator[](size_t index) const noexcept;


/// <summary>
/// メンバ関数
/// </summary>
public:
	float Dot(const Vector3D& right) const noexcept;
	Vector3D Cross(const Vector3D& right) const noexcept;
	float Length() const noexcept;
	Vector3D Normalize() const noexcept;

/// <summary>
/// 静的定数
/// </summary>
public:
	/// <summary>
	/// x = 1.0f, y = 1.0f, z = 1.0f
	/// </summary>
	static const Vector3D identity;
	/// <summary>
	/// x = 0.0f, y = 0.0f, z = 0.0f
	/// </summary>
	static const Vector3D zero;
	/// <summary>
	/// x = 1.0f, y = 0.0f, z = 0.0f
	/// </summary>
	static const Vector3D xIdy;
	/// <summary>
	/// x = 0.0f, y = 1.0f, z = 0.0f
	/// </summary>
	static const Vector3D yIdy;
	/// <summary>
	/// x = 0.0f, y = 0.0f, z = 1.0f
	/// </summary>
	static const Vector3D zIdy;

/// <summary>
/// メンバ変数
/// </summary>
public:
	float x;
	float y;
	float z;


/// <summary>
/// 静的関数
/// </summary>
public:
	static Vector3D Lerp(const Vector3D& start, const Vector3D& end, float t);
};

struct Ray {
	Vector3D origin;
	Vector3D diff;
};

struct Segment {
	Vector3D origin;
	Vector3D diff;
};

Vector3D Project(const Vector3D& vec1, const Vector3D& vec2);

Vector3D ClosestPoint(const Vector3D& point, const Segment& segment);