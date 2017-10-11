#pragma once
#ifndef ACTOR_CLASS_H
#define ACTOR_CLASS_H


#include <directxmath.h>
#include"RedMon/Engine/inputclass.h"
#include"RedMon\Engine\StopWatch.h"

using namespace DirectX;
using namespace std;

class ActorClass;

enum CollisionMode { None, Enter, Stay, Exit };
struct CollisionData {
	bool isCollision;
	ActorClass * other;
	CollisionMode mode;
	bool isPhysics;
};
class ActorClass
{
public: //public data.
	
protected :
	XMFLOAT3 position;
	char* textureAddress;
	float Wight, Hight;
	char* tag;
private: //private data.
	CollisionData collision;
	XMFLOAT2 imgOriginalSize;
	XMFLOAT2 textureTranslate;
	XMFLOAT4 textureUV;
public: //public Function.
	ActorClass();
	~ActorClass();

	virtual XMFLOAT3 GetPosition() const;
	virtual char* GetTextureAddress() const;
	virtual XMFLOAT2 GetTextureWH() const;
	virtual char* GetTag()const;

	bool IsCollistion()const;
	ActorClass* CollisionOther()const;
	CollisionMode GetCollisionMode()const;
	bool IsPhysics() const;
	void SetPhysics(bool active);

	void SetOriginalImgSize(XMFLOAT2 original);
	void SetPosition(const float &, const float &);
	void SetCollistion(bool isCollistion, ActorClass * other , CollisionMode mode);

	virtual void Initialize();
	virtual void Update(float dt);

	virtual void OnCollisionEnter(ActorClass * other);
	virtual void OnCollisionExit(ActorClass * other);

	virtual void OnDestory();

	void Move(float x, float y);
	void TextureTranslate(float x, float y);
	void SetTextureUV(float u, float v, float w, float h);
	XMFLOAT2 GetTextureTranlsate()const;
	XMFLOAT4 GetTextureUV()const;

	bool operator<(const ActorClass& ref)const;
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
