#pragma once

#include <directxmath.h>
#include"ObjectManager.h"
#include"RedMon/Engine/inputclass.h"
#include"RedMon\Engine\StopWatch.h"

using namespace DirectX;
using namespace std;

class ActorClass;

enum CollisionMode { None, Enter, Stay, Exit };
enum BodyType { StaticBody, KinematicBody, DynamicBody };
enum ShapeType{BoxShape, TriangleShape};
struct CollisionData {
	bool isCollision;
	ActorClass * other;
	CollisionMode mode;
	bool isPhysics;
	BodyType type;
	ShapeType shape;
	bool bullet;
	float density; // ¹Ðµµ.
	float friction; // ¸¶Âû·Â.
	float restitution; // Åº¼º·Â.
	float gravityScale;
	bool isRotateFrozen;
	
};
class ActorClass
{
public: //public data.
	
protected : //protected data.
	XMFLOAT3 position;
	float rotate;
	char* textureAddress;
	float Width, Hight;
	char* tag;
	XMFLOAT2 imgOriginalSize;
private: //private data.
	CollisionData collision;
	XMFLOAT2 textureTranslate;
	XMFLOAT4 textureUV;
public: //public Function.
	ActorClass();
	virtual ~ActorClass();

	// texture.
	void TextureTranslate(float x, float y);
	void SetTextureUV(float u, float v, float w, float h);
	void SetOriginalImgSize(XMFLOAT2 original);
	char* GetTextureAddress() const;
	XMFLOAT2 GetTextureTranlsate()const;
	XMFLOAT4 GetTextureUV()const;
	
	// Position, Move, Rotate.
	void SetPosition(const float &, const float &);
	XMFLOAT3 GetPosition() const;
	float GetRotate() const;
	void SetRotate(float rot);
	void Move(float x, float y);
	void LocalMove(float x, float y);
	void Rotate(float angle);

	// Collistion.
	bool IsCollistion()const;
	bool IsPhysics() const;
	ActorClass* GetCollisionOther()const;
	CollisionMode GetCollisionMode()const;
	CollisionData GetCollisionData()const;
	void SetCollistion(bool isCollistion, ActorClass * other, CollisionMode mode);
	void SetPhysics(bool active);
	void SetCollistionType(BodyType type);
	void SetCollistionShape(ShapeType shape);
	void SetDensity(float d);
	void SetFriction(float f);
	void SetRestitution(float r);
	void SetGravityScale(float s);
	void SetRotateFrozen(bool isFrozen);
	void SetBullet(bool isBullet);

	// other.
	XMFLOAT2 GetActorWH() const;
	virtual char* GetTag()const;

	// virtual Function.
	virtual void Initialize();
	virtual void Update(float dt);

	virtual void OnCollisionEnter(ActorClass * other);
	virtual void OnCollisionExit(ActorClass * other);

	virtual void OnDestory();



private: //private Function.

};

// operator
XMFLOAT3 operator+(const XMFLOAT3 & vec1, const XMFLOAT3 &vec2);
XMFLOAT3 operator-(const XMFLOAT3 & vec1, const XMFLOAT3 &vec2);
XMFLOAT3 operator*(const XMFLOAT3 & vec1, const float & scalar);
XMFLOAT3 operator/(const XMFLOAT3 & vec1, const float &scalar);
XMFLOAT3 operator+=(XMFLOAT3 & vec1, const XMFLOAT3 &vec2);
XMFLOAT3 operator-=(XMFLOAT3 & vec1, const XMFLOAT3 &vec2);
