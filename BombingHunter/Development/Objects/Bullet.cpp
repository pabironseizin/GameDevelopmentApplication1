#include "Bullet.h"
#include "DxLib.h"

Bullet::Bullet() : bullet(NULL)
{

}

Bullet::~Bullet()
{

}

void Bullet::Initialize()
{
	bullet = LoadGraph("Resource/Images/EnemyBullet/1.png");

	if (bullet == -1)
	{
		throw("�G�e�̉摜������܂���\n");
	}

	radian = 1.5;

	//�傫���̐ݒ�
	box_size = 32.0;

	//�����i�s�����̐ݒ�
	direction = Vector2D(0.0f, -1.0f);

}

void Bullet::Update()
{
	Move();
}

void Bullet::Draw() const
{
	DrawRotaGraphF(location.x, location.y, 0.5, radian, bullet, TRUE);

}

void Bullet::Finalize()
{
	DeleteGraph(bullet);

}

void Bullet::Move()
{
	//���݈ʒu���W�ɑ��������Z����
	location += direction;
}