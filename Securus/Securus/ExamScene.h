#pragma once
#include "Scene.h"
#include "Sprite.h"

class ExamScene : public Scene
{
public:
	ExamScene();
	~ExamScene();

	void PhysicsUpdate();
	void GraphicUpdate();

private:
	Sprite *sprite;
};

