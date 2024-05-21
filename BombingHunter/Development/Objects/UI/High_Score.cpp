#include "High_Score.h"
#include "DxLib.h"

High_Score::High_Score() :  high_score(NULL)
{

}

High_Score::~High_Score()
{

}

void High_Score::Initialize()
{

	high_score = LoadGraph("Resource/Images/Score/hs.png");

	if (high_score == -1)
	{
		throw("ハイスコアがありません\n");
	}

	radian = 0.0;

}

void High_Score::Update()
{

}

void High_Score::Draw() const
{
	
	DrawRotaGraphF(location.x, location.y, 1.2, radian, high_score, TRUE);
}

void High_Score::Finalize()
{
	DeleteGraph(high_score);
}
