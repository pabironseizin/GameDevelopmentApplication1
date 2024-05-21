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

//�R���g���N�^
Scene::Scene() : objects()
{

}

//�f�X�g���N�^
Scene::~Scene()
{
	//�Y��h�~
	Finalize();
}

//����������
void Scene::Initialize()
{
	//�摜�̕`��
	CreateObject<BG>(Vector2D(320.0f, 240.0f));
	CreateObject<Time>(Vector2D(20.0f, 460.0f));
	CreateObject<Score>(Vector2D(150.0f, 460.0f));
	CreateObject<High_Score>(Vector2D(360.0f, 460.0f));
	//�v���C���[�𐶐�����
	CreateObject<Player>(Vector2D(50.0f, 50.0f));
	//�G�𐶐�����
	CreateObject<Enemy>(Vector2D(-10.0f, 400.0f));
	CreateObject<Enemy2>(Vector2D(-10.0f, 320.0f));
	CreateObject<Enemy3>(Vector2D(-10.0f, 260.0f));
	CreateObject<Enemy4>(Vector2D(-10.0f, 180.0f));

	
}

//�X�V����
void Scene::Update()
{
	//�V�[���ɑ��݂���I�u�W�F�N�g�̍X�V����
	for (GameObject* obj : objects)
	{
		obj->Update();
	}
}

//�`�揈��
void Scene::Draw() const
{
	//�V�[���ɑ��݂���I�u�W�F�N�g�̕`�揈��
	for (GameObject* obj : objects)
	{
		obj->Draw();
	}
}

//�I��������
void Scene::Finalize()
{
	//���I�z�񂪋�Ȃ珈�����I������
	if (objects.empty())
	{
		return;
	}

	//�e�I�u�W�F�N�g���폜����
	for (GameObject* obj : objects)
	{
		obj->Finalize();
		delete obj;
	}

	//���I�z��̉��
	objects.clear();
}