#pragma once

#include "../GameObject.h"

class Time : public GameObject
{
private:
	int time;  //����
	int start_time;
	
public:
	Time();
	~Time();
	void Initialize();
	void Update();
	void Draw() const;
	void Finalize();

};

