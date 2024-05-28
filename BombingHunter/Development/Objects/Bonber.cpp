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

	//�傫���̐ݒ�
	box_size = 32.0;

	//�����i�s�����̐ݒ�
	direction = Vector2D(0.0f, 1.0f);
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
	//���݈ʒu���W�ɑ��������Z����
	location += direction;
}
