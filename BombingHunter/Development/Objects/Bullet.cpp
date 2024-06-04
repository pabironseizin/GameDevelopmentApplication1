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
		throw("敵弾の画像がありません\n");
	}

	radian = 1.5;

	//大きさの設定
	box_size = 32.0;

	//初期進行方向の設定
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
	//現在位置座標に速さを加算する
	location += direction;
}