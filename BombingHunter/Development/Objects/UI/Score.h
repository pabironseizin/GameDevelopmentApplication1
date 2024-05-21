#pragma once

#include "../GameObject.h"

class Score : public GameObject
{
private:
	
	int score;  //ÉXÉRÉA

public:
	Score();
	~Score();
	void Initialize();
	void Update();
	void Draw() const;
	void Finalize();

};
