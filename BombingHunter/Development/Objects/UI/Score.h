#pragma once

#include "../GameObject.h"

class Score : public GameObject
{
private:
	
	int score;  //�X�R�A

public:
	Score();
	~Score();
	void Initialize();
	void Update();
	void Draw() const;
	void Finalize();

};
