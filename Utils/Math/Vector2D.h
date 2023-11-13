#pragma once

/// <summary>
///	二次元ベクトル
/// </summary>
class Vector2D final {
/// <summary>
/// コンストラクタ
/// </summary>
public:
	Vector2D() noexcept;
	Vector2D(float x, float y) noexcept;

	Vector2D(const Vector2D& right) noexcept;
	Vector2D(Vector2D&& right) noexcept;
public:
	~Vector2D() = default;

/// <summary>
/// 演算子のオーバーロード
/// </summary>
public:
	inline Vector2D operator+() const noexcept {
		return *this;
	}
	inline Vector2D operator-() const noexcept {
		return { -x, -y };
	}

	Vector2D operator+(const Vector2D& right) const noexcept;
	Vector2D operator-(const Vector2D& right) const noexcept;
	Vector2D operator*(float scalar) const noexcept;
	Vector2D operator/(float scalar) const noexcept;
	Vector2D& operator=(const Vector2D& right) noexcept;
	Vector2D& operator=(Vector2D&& right) noexcept;
	Vector2D& operator+=(const Vector2D& right) noexcept;
	Vector2D& operator-=(const Vector2D& right) noexcept;
	Vector2D& operator*=(float scalar) noexcept;
	Vector2D& operator/=(float scalar) noexcept;
	bool operator==(const Vector2D& right) const noexcept;
	bool operator!=(const Vector2D& right) const noexcept;

/// <summary>
/// メンバ関数
/// </summary>
public:
	void Rotate(float rad) noexcept;

	float Cross(const Vector2D& right) const noexcept;
	float Dot(const Vector2D& right) const noexcept;
	float Length() const noexcept;

	Vector2D Normalize() const noexcept;

/// <summary>
/// メンバ変数
/// </summary>
public:
	float x;
	float y;

/// <summary>
/// 静的関数
/// </summary>
public:
	static Vector2D Lerp(const Vector2D& start, const Vector2D& end, float easeSpd);

/// <summary>
/// 静的定数
/// </summary>
public:
	/// <summary>
	/// x = 1.0f, y = 1.0f
	/// </summary>
	static const Vector2D identity;
	/// <summary>
	/// x = 0.0f, y = 0.0f
	/// </summary>
	static const Vector2D zero;
	/// <summary>
	/// x = 1.0f, y = 0.0f
	/// </summary>
	static const Vector2D xIdy;
	/// <summary>
	/// x = 0.0f, y = 1.0f
	/// </summary>
	static const Vector2D yIdy;

};