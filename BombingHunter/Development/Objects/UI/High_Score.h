#pragma once

#include "../GameObject.h"

class High_Score : public GameObject
{
private:
	
	int high_score;  //�n�C�X�R�A

public:
	High_Score();
	~High_Score();
	void Initialize();
	void Update();
	void Draw() const;
	void Finalize();

};