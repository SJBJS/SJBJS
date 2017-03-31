#pragma once
#ifndef  ACTOR_CLASS_H
#define ACTOR_CLASS_H

#include <iostream>
#include <d3d11.h>
#include <directxmath.h>
using namespace DirectX;

class ActorClass
{
public:
	XMFLOAT3 postion;
	std::string texture;
	float Wight, Hight;

};

#endif
