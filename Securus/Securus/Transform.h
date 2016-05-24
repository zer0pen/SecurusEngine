#pragma once
class Transform : public Component
{
public:
	Transform();
	~Transform();

	glm::vec3 getPosition();
	glm::vec3 getScale();
	glm::vec3 getRotate();
	float getDegree();
	bool getIsChange();

	void setPosition(glm::vec3 _position);
	void setScale(glm::vec3 _scale);
	void setRotate(glm::vec3 _rotate);
	void setDegree(float _degree);
	void setIsChange(bool _isChange);

private:
	glm::vec3 position;
	glm::vec3 scale;
	glm::vec3 rotate;
	float degree;
	bool isChange;
};

