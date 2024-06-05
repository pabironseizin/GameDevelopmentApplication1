#pragma once

#include "GameObject.h"

class Bonber : public GameObject
{
private:
	int bonber;
	Vector2D direction;  //is•ûŒü

public:
	Bonber();
	~Bonber();

	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Draw() const override;
	virtual void Finalize() override;

	////“–‚½‚è”»’è’Ê’mˆ—
	//virtual void OnHitCollision(GameObject* hit_object) override;
private:
	void Move();
};

