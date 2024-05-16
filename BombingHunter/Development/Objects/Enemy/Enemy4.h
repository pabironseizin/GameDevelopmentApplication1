#pragma once

#include "../GameObject.h"

class Enemy4 : public GameObject
{
private:
	int animation[5];  //�A�j���[�V�����摜
	int animation_count;  //�A�j���[�V��������
	int filp_flag;  //���]�t���O

public:
	Enemy4();
	~Enemy4();

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

