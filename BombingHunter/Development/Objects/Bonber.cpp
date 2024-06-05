#include "Bonber.h"
#include "../Utility/InputControl.h"
#include "DxLib.h"

Bonber::Bonber() : bonber(NULL), direction(0.0f)
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

	box_size = 32.0f;

	
	////�����i�s�����̐ݒ�
	//direction = Vector2D(0.0f, 1.0f);

	if (InputControl::GetKey(KEY_INPUT_LEFT) || InputControl::GetKeyDown(KEY_INPUT_LEFT))
	{
		radian = 2.0;
		direction = Vector2D(-1.5f, 1.0f);
	}
	else if (InputControl::GetKey(KEY_INPUT_RIGHT)|| InputControl::GetKeyDown(KEY_INPUT_RIGHT))
	{
		radian = 1.0;
		direction = Vector2D(1.5f, 1.0f);
	}
	else
	{
		radian = 1.5;
		direction = Vector2D(0.0f, 1.0f);
	}
}

void Bonber::Update()
{
	Move();
}

void Bonber::Draw() const
{
	DrawRotaGraphF(location.x, location.y, 0.5, radian, bonber, TRUE);

	////�e�N���X�̕`�揈�����Ăяo��
	//__super::Draw();
}

////�����蔻��ʒm����
//void Bonber::OnHitCollision(GameObject* hit_object)
//{
//	//�����������̏���
//	direction = 0.0f;
//}

void Bonber::Finalize()
{
	DeleteGraph(bonber);

}



void Bonber::Move()
{
	//���݈ʒu���W�ɑ��������Z����
	location += direction;
}
