#include "Collisionable.h"

bool Collisionable::isCollision(Collisionable &obj) const{
	return getBounds().findIntersection(obj.getBounds()).has_value();
}
