#include "Bonber.h"
#include "DxLib.h"

Bonber::Bonber() : bonber(NULL)
{

}

Bonber::~Bonber()
{

}

void Bonber::Initialize()
{
	bonber = LoadGraph("Resource/Images/Bomb/Bomb.png");

	if (bonber == -1)
	{
		throw("���e�̉摜������܂���\n");
	}

	radian = 1.5;
}

void Bonber::Update()
{
	Move();
}

void Bonber::Draw() const
{
	DrawRotaGraphF(location.x, location.y, 0.5, radian, bonber, TRUE);

}

void Bonber::Finalize()
{
	DeleteGraph(bonber);

}

void Bonber::Move()
{
	Vector2D velocity = 0.0f;

	velocity.y += 1.0f;
}
