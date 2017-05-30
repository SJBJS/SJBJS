#pragma once
#ifndef  ACTOR_CLASS_H
#define ACTOR_CLASS_H


#include <directxmath.h>
#include"../../Engine/inputclass.h"
#include"RedMon\Engine\StopWatch.h"
using namespace DirectX;
using namespace std;

class ActorClass
{
public: //public data.
	
protected :
	XMFLOAT3 position;
	char* textureAddress;
	float Wight, Hight;
	char* tag;
private: //private data.

public: //public Function.
	ActorClass();
	~ActorClass();
	virtual XMFLOAT3 GetPosition() const;
	virtual char* GetTextureAddress() const;
	virtual XMFLOAT2 GetTextureWH() const;
	virtual char* GetTag()const;
	virtual void Initialize();
	virtual void Update(float dt);
	virtual void OnDestory();
	void SetPosition(const float &, const float &);
private: //private Function.

};

// operator
XMFLOAT3 operator+(const XMFLOAT3 & vec1, const XMFLOAT3 &vec2);
XMFLOAT3 operator-(const XMFLOAT3 & vec1, const XMFLOAT3 &vec2);
XMFLOAT3 operator*(const XMFLOAT3 & vec1, const float & scalar);
XMFLOAT3 operator/(const XMFLOAT3 & vec1, const float &scalar);
XMFLOAT3 operator+=(XMFLOAT3 & vec1, const XMFLOAT3 &vec2);
XMFLOAT3 operator-=(XMFLOAT3 & vec1, const XMFLOAT3 &vec2);
#endif
