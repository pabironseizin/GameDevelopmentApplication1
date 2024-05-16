#pragma once

#include "../GameObject.h"

class Enemy2 : public GameObject
{
private:
	int animation[2];  //�A�j���[�V�����摜
	int animation_count;  //�A�j���[�V��������
	int filp_flag;  //���]�t���O

public:
	Enemy2();
	~Enemy2();

	virtual void Initialize() override;  //����������
	virtual void Update() override;  //�X�V����
	virtual void Draw() const override;  //�`�揈��
	virtual void Finalize() override;  //�I��������

	//�����蔻��ʒm����
	virtual void OnHitCollision(GameObject* hit_object) override;

private:
	//�ړ�����
	void Movement();
	//�A�j���[�V��������
	void AnimeControl();
};



