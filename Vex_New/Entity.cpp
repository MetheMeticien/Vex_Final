#include "Entity.h"

void Entity::initVariables()
{
	this->sprite = NULL;
	this->texture = NULL;
	this->movementSpeed = 100.f;
}


Entity::Entity()
{
	this->initVariables();
	
	
}

Entity::~Entity()
{
	delete this->sprite;
}

void Entity::createSprite(Texture* texture)
{
	this->texture = texture;
	this->sprite = new Sprite(*this->texture);
	
}

void Entity::setPosition(float x, float y)
{
	if (this->sprite) {
		this->sprite->setPosition(x, y);
	}
}

void Entity::move(const float& dt,const float dir_x, const float dir_y)
{
	if (this->sprite) {
		this->sprite->move(dir_x * this->movementSpeed * dt, dir_y * this->movementSpeed * dt);
	}
}

void Entity::update(const float& dt)
{
	

}

void Entity::render(RenderTarget* target)
{
	if (this->sprite) {
		target->draw(*this->sprite);
	}
}
