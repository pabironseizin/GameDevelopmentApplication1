#pragma once

#include "../GameObject.h"

class BG : public GameObject
{
private:
	int backscreen_image;  //�w�i�摜
	

public:
	BG();
	~BG();
	void Initialize();
	void Update();
	void Draw() const;
	void Finalize();

};

