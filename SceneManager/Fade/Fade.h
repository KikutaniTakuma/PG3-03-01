#pragma once
#include "Utils/UtilsLib/UtilsLib.h"
#include "Utils/Easeing/Easeing.h"

class Fade {
public:
	Fade();
	Fade(const Fade&) = default;
	Fade(Fade&&) = default;
	~Fade() = default;

	Fade& operator=(const Fade&) = default;
	Fade& operator=(Fade&&) = default;

public:
	/// <summary>
	/// フェードアウトをスタートさせる
	/// </summary>
	void OutStart();

	/// <summary>
	/// フェードインをスタートさせる
	/// </summary>
	void InStart();

	/// <summary>
	/// フェードアウトが終わった瞬間を取得
	/// </summary>
	/// <returns>終わった瞬間true</returns>
	bool OutEnd() const;

	/// <summary>
	/// フェードアウト中
	/// </summary>
	/// <returns>フェードアウト中はtrue</returns>
	bool OutStay() const;

	/// <summary>
	/// フェードインが終わった瞬間を取得
	/// </summary>
	/// <returns>終わった瞬間</returns>
	bool InEnd() const;

	/// <summary>
	/// フェードイン中
	/// </summary>
	/// <returns>フェードイン中はtrue</returns>
	bool InStay() const;

	/// <summary>
	/// 更新関数
	/// </summary>
	void Update();

	/// <summary>
	/// 描画関数
	/// </summary>
	/// <param name="viewProjection">カメラ行列</param>
	void Draw();

private:
	/// <summary>
	/// フェードインしてるか
	/// </summary>
	UtilsLib::Flg isInStart_;

	/// <summary>
	/// フェードアウトしてるか
	/// </summary>
	UtilsLib::Flg isOutStart_;

	uint32_t color_;

	Easeing ease_;
	/// <summary>
	/// seconds
	/// </summary>
	float fadeTime_;
};