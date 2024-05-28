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

	void Initialize();
	void Update();
	void Draw() const;
	void Finalize();

private:
	void Move();
};

