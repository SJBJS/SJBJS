#include "ActorClass.h"

XMFLOAT3 ActorClass::GetPosition() const
{
	return postion;
}

std::string ActorClass::GetTextureAddress() const
{
	return textureAddress;
}

XMFLOAT2 ActorClass::GetTextureWH() const
{
	return XMFLOAT2(Wight, Hight);
}

void ActorClass::Initialize()
{

}

void ActorClass::Update()
{

}
