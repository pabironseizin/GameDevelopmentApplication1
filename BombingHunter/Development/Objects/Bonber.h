#pragma once

#include "GameObject.h"

class Bonber : public GameObject
{
private:
	int bonber;
	Vector2D direction;  //進行方向

public:
	Bonber();
	~Bonber();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Draw() const override;
	virtual void Finalize() override;

	////当たり判定通知処理
	//virtual void OnHitCollision(GameObject* hit_object) override;
private:
	void Move();
};

