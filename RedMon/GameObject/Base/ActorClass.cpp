#include "ActorClass.h"
#include"ObjectManager.h"

/////////////////////////////////
// ActorClass
/////////////////////////////////

ActorClass::ActorClass()
{
	position.x = position.y = position.z = 0;
	textureAddress = tag = "";
	Wight = Hight = 0;
	collision.isCollision = false;
	collision.other = nullptr;
	ObjectManager::Instance()->CreateObject(this);
}

ActorClass::~ActorClass()
{
}
XMFLOAT3 ActorClass::GetPosition() const
{
	return position;
}
char* ActorClass::GetTextureAddress() const
{
	return textureAddress;
}

XMFLOAT2 ActorClass::GetTextureWH() const
{
	return XMFLOAT2(Wight, Hight);
}

char * ActorClass::GetTag() const
{
	return tag;
}

bool ActorClass::IsCollistion() const
{
	return collision.isCollision;
}

ActorClass * ActorClass::CollisionOther() const
{
	return collision.other;
}

CollisionMode ActorClass::GetCollisionMode() const
{
	return collision.mode;
}

void ActorClass::Initialize()
{
}

void ActorClass::Update(float dt)
{
}

void ActorClass::OnCollisionEnter(ActorClass * other)
{
}


void ActorClass::OnCollisionExit(ActorClass * other)
{
}

void ActorClass::OnDestory()
{
}

void ActorClass::Move(float x, float y)
{
	position.x += x;
	position.y += y;
}

void ActorClass::SetPosition(const float & x, const float & y)
{
	position.x = x;
	position.y = y;
}

void ActorClass::SetCollistion(bool isCollistion, ActorClass * other ,CollisionMode mode)
{
	collision.isCollision = isCollistion;
	collision.other = other;
	collision.mode = mode;
}

XMFLOAT3 operator+(const XMFLOAT3 & vec1, const XMFLOAT3 & vec2)
{
	return XMFLOAT3(vec1.x + vec2.x, vec1.y+ vec2.y, vec1.z + vec2.z);
}

XMFLOAT3 operator-(const XMFLOAT3 & vec1, const XMFLOAT3 & vec2)
{
	return XMFLOAT3(vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z);
}

XMFLOAT3 operator*(const XMFLOAT3 & vec1, const float & scalar)
{
	return XMFLOAT3(vec1.x*scalar, vec1.y*scalar, vec1.z*scalar);
}

XMFLOAT3 operator/(const XMFLOAT3 & vec1, const float & scalar)
{
	return XMFLOAT3(vec1.x / scalar, vec1.y / scalar, vec1.z / scalar);
}

XMFLOAT3 operator+=(XMFLOAT3 & vec1, const XMFLOAT3 & vec2)
{
	vec1 = vec1 + vec2;
	return vec1;
}

XMFLOAT3 operator-=(XMFLOAT3 & vec1, const XMFLOAT3 & vec2)
{
	vec1 = vec1 - vec2;
	return vec1;
}
