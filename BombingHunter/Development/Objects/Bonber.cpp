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
		throw("爆弾の画像がありません\n");
	}

	radian = 1.5;

	//大きさの設定
	box_size = 32.0;

	//初期進行方向の設定
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
	//現在位置座標に速さを加算する
	location += direction;
}
