#pragma once

#include "GameObject.h"
class Bullet : public GameObject
{
private:
	int bullet;
	Vector2D direction;

public:
	Bullet();
	~Bullet();

	void Initialize();
	void Update();
	void Draw() const;
	void Finalize();

private:
	void Move();
};

