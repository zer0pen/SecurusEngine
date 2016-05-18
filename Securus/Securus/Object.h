#pragma once

class Object
{
public:
	Object() {}
	virtual ~Object() {}
	virtual void GraphicUpdate() = 0;
	virtual void PhysicsUpdate() = 0;
};
