#include "BG.h"
#include "DxLib.h"

BG::BG() : backscreen_image(NULL)
{

}

BG::~BG()
{

}

void BG::Initialize()
{
	backscreen_image = LoadGraph("Resource/Images/BackGround.png");

	if (backscreen_image == -1)
	{
		throw("”wŒi‰æ‘œ‚ª‚ ‚è‚Ü‚¹‚ñ\n");
	}

	radian = 0.0;

}

void BG::Update()
{

}

void BG::Draw() const
{
	DrawRotaGraphF(location.x, location.y, 0.67, radian, backscreen_image, TRUE);
	
}

void BG::Finalize()
{
	DeleteGraph(backscreen_image);
	
}