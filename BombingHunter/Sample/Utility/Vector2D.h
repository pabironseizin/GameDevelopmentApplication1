#pragma once

//２次元べクトクラス
class Vector2D
{
public:
	float x;
	float y;

public:
	Vector2D();
	Vector2D(float scalar);
	Vector2D(float mx, float my);
	~Vector2D();

public:
	//演算子オーバーロード
	Vector2D& operator=(const Vector2D& location);

	const Vector2D operator + (const Vector2D& location) const;
	Vector2D& operator += (const Vector2D& location);

	const Vector2D operator - (const Vector2D& location) const;
	Vector2D& operator -= (const Vector2D& location);

	const Vector2D operator * (const float& scalar) const;
	const Vector2D operator * (const Vector2D& location) const;
	Vector2D& operator *= (const float& scalar);
	Vector2D& operator *= (const Vector2D& location);

	const Vector2D operator / (const float& scalar) const;
	const Vector2D operator / (const Vector2D& location) const;
	Vector2D& operator /= (const float& scalar);
	Vector2D& operator /= (const Vector2D& location);

	//int型への変換
	void ToInt(int* x, int* y) const;
};

