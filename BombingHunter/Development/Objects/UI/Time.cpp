#include "Time.h"
#include "DxLib.h"

Time::Time() : time(NULL),start_time()
{

}

Time::~Time()
{

}

void Time::Initialize()
{
	start_time = 60;

	time = LoadGraph("Resource/Images/TimeLimit/timer-03.png");
	
	if (time == -1)
	{
		throw("ŽžŒv‚Ì‰æ‘œ‚ª‚ ‚è‚Ü‚¹‚ñ\n");
	}
	
	radian = 0.0;
}

void Time::Update()
{

}

void Time::Draw() const
{
	DrawRotaGraphF(location.x, location.y, 0.6, radian, time, TRUE);
}

void Time::Finalize()
{
	DeleteGraph(time);	
}