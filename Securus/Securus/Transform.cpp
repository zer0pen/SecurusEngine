#include "stdafx.h"

Transform::Transform():position(0.0f, 0.0f, 0.0f),scale(1.0f ,1.0f, 1.0f),rotate(0.0f, 0.0f, 0.0f), degree(0)
{
}

Transform::~Transform()
{
}

glm::vec3 Transform::getPosition()
{
	return position;
}

glm::vec3 Transform::getScale()
{
	return scale;
}

glm::vec3 Transform::getRotate()
{
	return rotate;
}

float Transform::getDegree()
{
	return degree;
}

bool Transform::getIsChange()
{
	return isChange;
}

void Transform::setPosition(glm::vec3 _position)
{
	position.x = -_position.x;
	position.y = -_position.y;
	position.z = -_position.z;
}

void Transform::setScale(glm::vec3 _scale)
{
	scale = _scale;
}

void Transform::setRotate(glm::vec3 _rotate)
{
	rotate = _rotate;
}

void Transform::setDegree(float _degree)
{
	degree = _degree;
}

void Transform::setIsChange(bool _isChange)
{
	isChange = _isChange;
}
