#include "cController.h"


cController::cController() :cObject()
{
	this->setID();
}


cController::~cController()
{
}

void cController::setID()
{
	this->ID = typeid(this).name();
}