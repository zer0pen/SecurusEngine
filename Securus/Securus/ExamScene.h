#pragma once

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
