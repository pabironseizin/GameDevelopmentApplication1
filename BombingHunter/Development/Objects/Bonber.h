#pragma once

#include "GameObject.h"

class Bonber : public GameObject
{
private:
	int bonber;
	Vector2D direction;  //�i�s����

public:
	Bonber();
	~Bonber();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Draw() const override;
	virtual void Finalize() override;

	////�����蔻��ʒm����
	//virtual void OnHitCollision(GameObject* hit_object) override;
private:
	void Move();
};

