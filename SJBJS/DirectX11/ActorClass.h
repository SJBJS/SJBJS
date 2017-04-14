#pragma once
#ifndef  ACTOR_CLASS_H
#define ACTOR_CLASS_H

#include <iostream>
#include <d3d11.h>
#include <directxmath.h>
#include"inputclass.h"
using namespace DirectX;

class ActorClass
{
public: //public data.
	
protected :
	XMFLOAT3 postion;
	char* textureAddress;
	float Wight, Hight;

private: //private data.

public: //public Function.
	virtual XMFLOAT3 GetPosition() const;
	virtual char* GetTextureAddress() const;
	virtual XMFLOAT2 GetTextureWH() const;

	virtual void Initialize();
	virtual void Update();
private: //private Function.

};

#endif
