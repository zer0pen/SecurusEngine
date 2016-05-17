#include "ExamScene.h"

ExamScene::ExamScene()
{
	sprite = new Sprite(0, 0, "./image/asdf.png");
}

ExamScene::~ExamScene()
{
}

void ExamScene::PhysicsUpdate()
{

}

void ExamScene::GraphicUpdate()
{
	sprite->GraphicUpdate();
}
