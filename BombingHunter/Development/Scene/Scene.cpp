#include "Scene.h"
#include "DxLib.h"
#include "../Utility/InputControl.h"
#include "../Objects/GameObject.h"
#include "../Objects/Enemy/Enemy.h"
#include "../Objects/Enemy/Enemy2.h"
#include "../Objects/Enemy/Enemy3.h"
#include "../Objects/Enemy/Enemy4.h"
#include "../Objects/Player/Player.h"
#include "../Objects/UI/BG.h"
#include "../Objects/UI/Time.h"
#include "../Objects/UI/Score.h"
#include "../Objects/UI/High_Score.h"
#include "../Objects/Bonber.h"
#include "../Objects/Bullet.h"

//#define D_PIVOT_CENTER

//�R���g���N�^
Scene::Scene() : objects(),BGM(NULL)

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
	BGM = LoadSoundMem("Resource/sounds/Evaluation/BGM_arrows.wav");

	//�摜�̕`��
	CreateObject<BG>(Vector2D(320.0f, 240.0f));
	CreateObject<Time>(Vector2D(20.0f, 460.0f));
	CreateObject<Score>(Vector2D(150.0f, 460.0f));
	CreateObject<High_Score>(Vector2D(360.0f, 460.0f));
	//�v���C���[�𐶐�����
	CreateObject<Player>(Vector2D(320.0f, 50.0f));
	//�G�𐶐�����
	CreateObject<Enemy>(Vector2D(100.0f, 400.0f));
	CreateObject<Enemy2>(Vector2D(100.0f, 320.0f));
	CreateObject<Enemy3>(Vector2D(100.0f, 260.0f));
	CreateObject<Enemy4>(Vector2D(100.0f, 180.0f));

	
}


//�X�V����
void Scene::Update()
{
	//BGM�Đ�
	PlaySoundMem(BGM, DX_PLAYTYPE_LOOP, FALSE);

	//�V�[���ɑ��݂���I�u�W�F�N�g�̍X�V����
	for (GameObject* obj : objects)
	{
		obj->Update();
	}

	////�I�u�W�F�N�g���m�̓����蔻��`�F�b�N
	//for (int i = 0; i < objects.size(); i++)
	//{
	//	for (int j = i + 1; j < objects.size(); j++)
	//	{
	//		//�����蔻��`�F�b�N����
	//		HitCheckObject(objects[i], objects[j]);
	//	}
	//}

	if (InputControl::GetKeyDown(KEY_INPUT_SPACE))
	{
		CreateObject<Bonber>(objects[4]->GetLocation());
	}

	if (InputControl::GetKeyDown(KEY_INPUT_Z))
	{
		CreateObject<Bullet>(objects[5]->GetLocation());
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

//#ifdef D_PIVOT_CENTER
//
////�����蔻��`�F�b�N����(�Z�`�̒��S�œ����蔻����Ƃ�)
//void Scene::HitCheckObject(GameObject* a, GameObject* b)
//{
//	//2�̃I�u�W�F�N�g�̋������擾
//	Vector2D diff = a->GetLocation() - b->GetLocation();
//
//	//2�̃I�u�W�F�N�g�̓����蔻��̑傫�����擾
//	Vector2D box_size = (a->GetBoxSize() + b->GetBoxSize()) / 2.0f;
//
//	//�������傫�����傫���ꍇ�AHIT����Ƃ���
//	if ((fabsf(diff.x) < box_size.x) && (fabsf(diff.y) < box_size.y))
//	{
//		//�����������Ƃ��I�u�W�F�N�g�ɒʒm����
//		a->OnHitCollision(b);
//		b->OnHitCollision(a);
//	}
//}
//
//#else
//
////�����蔻��`�F�b�N����(���㒸�_�̍��W���瓖���蔻��v�Z���s��)
//void Scene::HitCheckObject(GameObject* a, GameObject* b)
//{
//	//�E�����_���W���擾����
//	Vector2D a_lower_right = a->GetLocation() + a->GetBoxSize();
//	Vector2D a_lower_right = a->GetLocation() + a->GetBoxSize();
//
//	//
//	if ((a->GetLocation().x < b_lower_right.x) && (a->GetLocation().y < b_lower_right.y) && (a_lower_right.x > b->GetLocation().x) && (a_lower_right.y > b->GetLocation().y))
//	{
//		//�����������Ƃ��I�u�W�F�N�g�ɒʒm����
//		a->OnHitCollision(b);
//		b->OnHitCollision(a);
//	}
//}
//
//
//#endif // D_PIVOT_CENTER