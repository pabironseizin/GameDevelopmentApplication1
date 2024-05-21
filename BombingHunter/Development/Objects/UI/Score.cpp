#include "Score.h"
#include "DxLib.h"

Score::Score() : score(NULL)
{

}

Score::~Score()
{

}

void Score::Initialize()
{
	score = LoadGraph("Resource/Images/Score/font-21.png");

	if (score == -1)
	{
		throw("ÉXÉRÉAÇ™Ç†ÇËÇ‹ÇπÇÒ\n");
	}

	radian = 0.0;
}

void Score::Update()
{

}

void Score::Draw() const
{
	DrawRotaGraphF(location.x, location.y, 1.2, radian, score, TRUE);
}

void Score::Finalize()
{
	DeleteGraph(score);
}