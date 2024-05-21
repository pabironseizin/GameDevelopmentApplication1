#include "Scene.h"

#include "../Objects/Enemy/Enemy.h"
#include "../Objects/Enemy/Enemy2.h"
#include "../Objects/Enemy/Enemy3.h"
#include "../Objects/Enemy/Enemy4.h"
#include "../Objects/Player/Player.h"
#include "../Objects/UI/BG.h"
#include "../Objects/UI/Time.h"
#include "../Objects/UI/Score.h"
#include "../Objects/UI/High_Score.h"

//コントラクタ
Scene::Scene() : objects()
{

}

//デストラクタ
Scene::~Scene()
{
	//忘れ防止
	Finalize();
}

//初期化処理
void Scene::Initialize()
{
	//画像の描画
	CreateObject<BG>(Vector2D(320.0f, 240.0f));
	CreateObject<Time>(Vector2D(20.0f, 460.0f));
	CreateObject<Score>(Vector2D(150.0f, 460.0f));
	CreateObject<High_Score>(Vector2D(360.0f, 460.0f));
	//プレイヤーを生成する
	CreateObject<Player>(Vector2D(50.0f, 50.0f));
	//敵を生成する
	CreateObject<Enemy>(Vector2D(-10.0f, 400.0f));
	CreateObject<Enemy2>(Vector2D(-10.0f, 320.0f));
	CreateObject<Enemy3>(Vector2D(-10.0f, 260.0f));
	CreateObject<Enemy4>(Vector2D(-10.0f, 180.0f));

	
}

//更新処理
void Scene::Update()
{
	//シーンに存在するオブジェクトの更新処理
	for (GameObject* obj : objects)
	{
		obj->Update();
	}
}

//描画処理
void Scene::Draw() const
{
	//シーンに存在するオブジェクトの描画処理
	for (GameObject* obj : objects)
	{
		obj->Draw();
	}
}

//終了時処理
void Scene::Finalize()
{
	//動的配列が空なら処理を終了する
	if (objects.empty())
	{
		return;
	}

	//各オブジェクトを削除する
	for (GameObject* obj : objects)
	{
		obj->Finalize();
		delete obj;
	}

	//動的配列の解放
	objects.clear();
}