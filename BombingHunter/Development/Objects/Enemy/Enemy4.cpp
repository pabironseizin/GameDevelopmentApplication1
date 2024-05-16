#include "Enemy4.h"
#include "DxLib.h"

//コントラクタ
Enemy4::Enemy4() : animation_count(0), filp_flag(FALSE)
{
	animation[0] = NULL;
	animation[1] = NULL;
	animation[2] = NULL;
	animation[3] = NULL;
	animation[4] = NULL;
}

//デストラクタ
Enemy4::~Enemy4()
{

}

//初期化処理
void Enemy4::Initialize()
{
	//画像の読み込み
	animation[0] = LoadGraph("Resource/Images/GoldEnemy/1.png");
	animation[1] = LoadGraph("Resource/Images/GoldEnemy/2.png");
	animation[2] = LoadGraph("Resource/Images/GoldEnemy/3.png");
	animation[3] = LoadGraph("Resource/Images/GoldEnemy/4.png");
	animation[4] = LoadGraph("Resource/Images/GoldEnemy/5.png");

	//エラーチェック
	if (animation[0] == -1 || animation[1] == -1)
	{
		throw("金のテキの画像がありません\n");
	}

	//向きの設定
	radian = 0.0;

	//大きさの設定
	scale = 64.0;

	//初期画像の設定
	image = animation[0];

}

//更新処理
void Enemy4::Update()
{
	//移動処理
	Movement();
	//アニメーション制御
	AnimeControl();
}

//描画処理
void Enemy4::Draw() const
{

	//プレイヤー画像の描画
	DrawRotaGraphF(location.x, location.y, 0.5, radian, image, TRUE, filp_flag);

	//デバッグ用
#if _DEBUG
	//当たり判定の可視化
	Vector2D box_collision_upper_left = location - (Vector2D(1.0f) * (float)scale / 2.0f);
	Vector2D box_collision_lower_right = location + (Vector2D(1.0f) * (float)scale / 2.0f);

	DrawBoxAA(box_collision_upper_left.x, box_collision_upper_left.y, box_collision_lower_right.x, box_collision_lower_right.y, GetColor(255, 0, 0), FALSE);

#endif
}

//終了時処理
void Enemy4::Finalize()
{
	//使用した画像を解放する
	DeleteGraph(animation[0]);
	DeleteGraph(animation[1]);
}

//当たり判定通知処理
void Enemy4::OnHitCollision(GameObject* hit_object)
{
	//当たった時の処理

}

//移動処理
void Enemy4::Movement()
{
	//移動の速さ
	Vector2D velocity = 0.0f;

	velocity.x = 1.0f;

	//現在位置座標に速さを加算する
	location += velocity;
}

//アニメーション制御
void Enemy4::AnimeControl()
{
	//フレームカウントを加算する
	animation_count++;

	//60フレーム目に到達したら
	if (animation_count >= 60)
	{
		//カウントのリセット
		animation_count = 0;

		//画像の切り替え
		if (image == animation[0])
		{
			image = animation[1];
		}
		else
		{
			image = animation[0];
		}
	}
}



